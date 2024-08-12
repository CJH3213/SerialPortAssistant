#ifndef IDATARECEIVER_H
#define IDATARECEIVER_H

#include <QByteArray>
#include <QList>

class IDataReceiver
{
public:
    virtual void ProcessData(const QByteArray& bytes) = 0;
};

class DataReceiverManager
{
public:
    void RegisterReceiver(IDataReceiver *receiver);
    void UnRegisterReceiver(IDataReceiver *receiver);
    void InvokeAll(const QByteArray& bytes);

private:
    QList<IDataReceiver*> mDataReceivers;

};

#endif // IDATARECEIVER_H
