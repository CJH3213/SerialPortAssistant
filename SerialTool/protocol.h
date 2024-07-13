#ifndef PROTOCOL_H
#define PROTOCOL_H

// #include <cstdint>
#include <QByteArray>
#include <QQueue>


class Protocol
{
public:
    // Protocol();

    // 存入新接收的数据，并解析
    void InputNewData(QByteArray data);
    // 获取未读的已解析数据集
    QByteArrayList GetDecodedList();

    // 数据编码
    static QByteArray ProtocolEncode(const QByteArray& data);
    static QByteArray ProtocolEncode(const QByteArrayList& datas);
    // 数据解码
    static QByteArrayList ProtocolDecode(const QByteArray& data);
    // 字节数组转浮点数（大端模式）
    static float BytesToFloat(const QByteArray& data, bool* ok=nullptr);

private:
    QByteArray mReceiveBuffer;
    QQueue<QByteArray> mDecodedQueue;

    // 大小端翻转，16位
    template <typename T>
    static T ReverseEndianForInt16(T src);
    // 校验和，8位输出
    static char CheckSumInt8(const QByteArray& data);
};

template <typename T>
static T ReverseEndianForU16(T src)
{
    return ((src & 0xFF00) >> 8) | ((src & 0xFF) << 8);
}

#endif // PROTOCOL_H
