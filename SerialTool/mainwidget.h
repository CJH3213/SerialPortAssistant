#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSerialPort>

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


protected:
    void closeEvent(QCloseEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    void sendReceiveBytes(QByteArray bytes);
    void broadcastMainWidgetCloseEvent();

private slots:
    void on_mConnectButton_clicked();
    void ReadSerialData();
    void on_mReceiveClearButton_clicked();
    void on_mSendClearButton_clicked();
    void on_mSendButton_clicked();
    void on_mSendHexCheckBox_stateChanged(int arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

public:
    QSerialPort mSerialPort;

private:
    Ui::Widget *ui;
    QMap<QString, QWidget*> mSubWidgets;
    qsizetype mReceiveCount = 0;
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
