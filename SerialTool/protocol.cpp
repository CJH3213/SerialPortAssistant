#include "protocol.h"
#include <QByteArrayList>
#include <QDebug>

// Protocol::Protocol() {}

QByteArray Protocol::ProtocolEncode(const QByteArray& data)
{
    QByteArray dstData;

    foreach (auto byte, data)
    {
        // 遇到0x7D或0x7E就转义
        if(byte == 0x7D || byte == 0x7E)
        {
            dstData.append(0x7E);
            dstData.append(byte - 0x20);
        }
        else
            dstData.append(byte);
    }

    dstData.append(CheckSumInt8(dstData));   // 数据末添加校验：8位校验和
    dstData.insert(0, 0x7D);    // 添加帧头0x7D作为分隔

    return dstData;
}

QByteArray Protocol::ProtocolEncode(const QByteArrayList &datas)
{
    QByteArray dstData;

    foreach (auto data, datas)
        dstData.append(ProtocolEncode(data));

    return dstData;
}

QByteArrayList Protocol::ProtocolDecode(const QByteArray &data)
{
    QByteArrayList dstDatas;
    QByteArray currentFrame;

    for(qsizetype l=0; l<data.size(); l++)
    {
        // 寻找一帧的左侧索引
        if(data[l] != 0x7D)
            continue;
        l++;

        // 寻找该帧右侧索引
        qsizetype r;
        for(r=l; r<data.size(); r++)
            if(data[r] == 0x7D)
                break;
        r--;

        // 去除帧内数据转义
        for(; l <= r; l++)
        {
            if((data[l] == 0x7E) && (l+1 < data.size()))
                currentFrame.append(data[++l] + 0x20);
            else
                currentFrame.append(data[l]);
        }

        // 校验
        if(currentFrame.size()>0 && currentFrame.back() == CheckSumInt8(currentFrame.mid(0, currentFrame.size()-1)))
        {
            currentFrame.chop(1);   // 给下游处理不需要校验位，删掉校验位
            dstDatas.append(currentFrame);
        }
        else
            currentFrame.clear();

        l = r;
    }

    return dstDatas;
}

float Protocol::BytesToFloat(const QByteArray &bytes, bool *ok)
{
    if(ok) *ok = false;
    if(bytes.size() < 4)
        return 0;

    // 大端模式：高位在低数组下标
    uint32_t u32Value = (uint8_t)bytes[0]<<24 | (uint8_t)bytes[1]<<16 | (uint8_t)bytes[2]<<8 | (uint8_t)bytes[3];
    float value = *(float*)&u32Value;

    if(qIsNaN(value))
        return value;

    if(ok) *ok = true;
    return value;
}

void Protocol::InputNewData(QByteArray data)
{
    QByteArrayList dstDatas;
    QByteArray currentFrame;
    bool isLastFrameDecode = false;

    mReceiveBuffer += data;

    for(qsizetype l=0; l<mReceiveBuffer.size(); l++)
    {
        // 寻找一帧的左侧索引
        if(mReceiveBuffer[l] != 0x7D)
            continue;
        l++;

        // 寻找该帧右侧索引
        qsizetype r;
        for(r=l; r<mReceiveBuffer.size(); r++)
            if(mReceiveBuffer[r] == 0x7D)
                break;
        r--;

        // 去除帧内数据转义
        for(; l <= r; l++)
        {
            if((mReceiveBuffer[l] == 0x7E) && (l+1 < mReceiveBuffer.size()))
                currentFrame.append(mReceiveBuffer[++l] + 0x20);
            else
                currentFrame.append(mReceiveBuffer[l]);
        }

        // 校验
        isLastFrameDecode = currentFrame.size()>0 &&
                            currentFrame.back() == CheckSumInt8(currentFrame.mid(0, currentFrame.size()-1));
        if(isLastFrameDecode)
        {
            currentFrame.chop(1);   // 给下游处理不需要校验位，删掉校验位
            dstDatas.append(currentFrame);
        }
        else
            currentFrame.clear();

        l = r;
    }

    if(isLastFrameDecode)   // 如果最后一帧也解析成功，清空缓冲器
        mReceiveBuffer.clear();
    else    // 如果最后一帧没解析成功，将最后一帧前面的数据清除
    {
        // 寻找最后一个0x7D的前一个位置
        qsizetype i=mReceiveBuffer.size()-1;
        for(; i>=0; i--)
            if(mReceiveBuffer[i] == 0x7D)
                break;
        i--;
        if(i>=0)
            mReceiveBuffer.remove(0, i+1);
    }

    foreach (auto data, dstDatas)
        mDecodedQueue.enqueue(data);
}

QByteArrayList Protocol::GetDecodedList()
{
    QByteArrayList dstDataList;
    while(mDecodedQueue.isEmpty() == false)
        dstDataList.append(mDecodedQueue.dequeue());
    return dstDataList;
}

char Protocol::CheckSumInt8(const QByteArray& data)
{
    uint8_t sum = 0;
    foreach (auto byte, data)
        sum += byte;
    return sum;
}
