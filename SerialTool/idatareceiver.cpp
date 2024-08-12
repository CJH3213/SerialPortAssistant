#include "idatareceiver.h"
#include <QDebug>

void DataReceiverManager::RegisterReceiver(IDataReceiver *receiver)
{
    if(receiver != nullptr && mDataReceivers.contains(receiver) == false)
        mDataReceivers.append(receiver);
}

void DataReceiverManager::UnRegisterReceiver(IDataReceiver *receiver)
{
    if(receiver != nullptr)
        mDataReceivers.removeOne(receiver);
}

void DataReceiverManager::InvokeAll(const QByteArray &bytes)
{
    foreach (auto *receiver, mDataReceivers)
    {
        receiver->ProcessData(bytes);
    }
}
