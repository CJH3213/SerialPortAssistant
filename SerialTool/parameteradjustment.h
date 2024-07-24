#ifndef PARAMETERADJUSTMENT_H
#define PARAMETERADJUSTMENT_H

#include <QWidget>
#include "mainwidget.h"
#include "qpushbutton.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>


namespace Ui {
class ParameterAdjustment;
}

class ParameterAdjustment : public QWidget
{
    Q_OBJECT

public:
    explicit ParameterAdjustment(MainWidget* baseWidget, QWidget *parent = nullptr);
    ~ParameterAdjustment();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void ReadSerialData(QByteArray bytes);
    void on_bt_AddItem_clicked();
    void on_bt_RemoveSelectedItem_clicked();
    // 处理表内按钮事件
    void handleButtonClicked();

    void on_bt_MoveUp_clicked();

    void on_bt_MoveDown_clicked();

private:

    Ui::ParameterAdjustment *ui;
    QSerialPort *mSerialPort;

    // 保存用户设置
    void SaveSettings();
    void RestoreSettings();

    // 传入按钮控件指针，返回按钮所在表行数
    int GetRowForButton(QPushButton *button);
    // 交换表内两行内容
    void SwapRows(int row1, int row2);
};

#endif // PARAMETERADJUSTMENT_H
