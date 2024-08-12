#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSerialPort>
#include "connectionsettings.h"
#include "idatareceiver.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void WriteData(const QByteArray &bytes);

protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void sendReceiveBytes(QByteArray bytes);
    void broadcastMainWidgetCloseEvent();

private slots:
    void OnReadData(const QByteArray & bytes);
    void on_mReceiveClearButton_clicked();
    void on_mSendClearButton_clicked();
    void on_mSendButton_clicked();
    void on_mSendHexCheckBox_stateChanged(int arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_mOpenConnectionDialogButton_clicked();
    void on_cb_AutoClear_checkStateChanged(const Qt::CheckState &arg1);
    void on_le_ClearThreshold_editingFinished();

private:
    Ui::Widget *ui;
    QMap<QString, QWidget*> mSubWidgets;
    DataReceiverManager mDataReceiverManager;

    ConnectionSettings *mConnectionSettings = nullptr;
    qsizetype mReceiveCount = 0;
    qsizetype mReceiveAutoClearNum = 0;
    qsizetype mSendCount = 0;

    void OpenSubWindow(const QString &windowType);

    void UpdatePortList();
    void AddItemsForDataBitsComboBox();
    void AddItemsForStopBitsComboBox();
    void AddItemsForParityComboBox();
    QString GB2312StringToHexString(QString str);
    QString HexStringToGB2312String(const QString & str);
    void EnsureCRLF(QByteArray& bytes);

    void SetEnableForSerialConfigWidgets(bool b);


};
#endif // MAINWIDGET_H
