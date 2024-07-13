/********************************************************************************
** Form generated from reading UI file 'parameteradjustment.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERADJUSTMENT_H
#define UI_PARAMETERADJUSTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParameterAdjustment
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QComboBox *cb_UprightKP_DataType;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLineEdit *le_UprightKP_Scale;
    QLabel *label_7;
    QLabel *label_28;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_19;
    QComboBox *cb_SpeedKD_DataType;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_20;
    QLineEdit *le_SpeedKD_Scale;
    QLabel *lb_UprightKP_ReceiveValue;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_21;
    QComboBox *cb_SpeedKI_DataType;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_22;
    QLineEdit *le_SpeedKI_Scale;
    QFrame *line_3;
    QLabel *label_23;
    QLabel *lb_SpeedKI_ReceiveValue;
    QLabel *label_6;
    QFrame *line_4;
    QPushButton *bt_UprightKP_Send;
    QPushButton *bt_SpeedKP_Send;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_14;
    QComboBox *cb_UprightKI_DataType;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QLineEdit *le_UprightKI_Scale;
    QLabel *label_3;
    QPushButton *bt_UprightKD_Send;
    QLabel *lb_SpeedKP_ReceiveValue;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QComboBox *cb_UprightKD_DataType;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_17;
    QLineEdit *le_UprightKD_Scale;
    QFrame *line;
    QLabel *lb_SpeedKD_ReceiveValue;
    QLabel *label_4;
    QLabel *label_11;
    QPushButton *bt_SpeedKD_Send;
    QLabel *label_2;
    QPushButton *bt_UprightKI_Send;
    QFrame *line_7;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_26;
    QComboBox *cb_SpeedKP_DataType;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_27;
    QLineEdit *le_SpeedKP_Scale;
    QLabel *lb_UprightKD_ReceiveValue;
    QLabel *label;
    QFrame *line_5;
    QPushButton *bt_SpeedKI_Send;
    QLabel *lb_UprightKI_ReceiveValue;
    QFrame *line_2;
    QLabel *label_29;
    QFrame *line_6;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QLineEdit *le_UprightKP_SendValue;
    QLineEdit *le_UprightKI_SendValue;
    QLineEdit *le_UprightKD_SendValue;
    QLineEdit *le_SpeedKP_SendValue;
    QLineEdit *le_SpeedKI_SendValue;
    QLineEdit *le_SpeedKD_SendValue;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ParameterAdjustment)
    {
        if (ParameterAdjustment->objectName().isEmpty())
            ParameterAdjustment->setObjectName("ParameterAdjustment");
        ParameterAdjustment->resize(636, 577);
        verticalLayout = new QVBoxLayout(ParameterAdjustment);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_9 = new QLabel(ParameterAdjustment);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(label_9, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        cb_UprightKP_DataType = new QComboBox(ParameterAdjustment);
        cb_UprightKP_DataType->addItem(QString());
        cb_UprightKP_DataType->addItem(QString());
        cb_UprightKP_DataType->setObjectName("cb_UprightKP_DataType");
        cb_UprightKP_DataType->setMinimumSize(QSize(80, 30));
        cb_UprightKP_DataType->setMaximumSize(QSize(160, 30));

        horizontalLayout->addWidget(cb_UprightKP_DataType, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_10 = new QLabel(ParameterAdjustment);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(label_10, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        le_UprightKP_Scale = new QLineEdit(ParameterAdjustment);
        le_UprightKP_Scale->setObjectName("le_UprightKP_Scale");
        le_UprightKP_Scale->setMinimumSize(QSize(0, 30));
        le_UprightKP_Scale->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(le_UprightKP_Scale);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 2, 5, 1, 1);

        label_7 = new QLabel(ParameterAdjustment);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(64, 20));

        gridLayout->addWidget(label_7, 0, 5, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_28 = new QLabel(ParameterAdjustment);
        label_28->setObjectName("label_28");

        gridLayout->addWidget(label_28, 11, 0, 2, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_19 = new QLabel(ParameterAdjustment);
        label_19->setObjectName("label_19");

        horizontalLayout_7->addWidget(label_19, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        cb_SpeedKD_DataType = new QComboBox(ParameterAdjustment);
        cb_SpeedKD_DataType->addItem(QString());
        cb_SpeedKD_DataType->addItem(QString());
        cb_SpeedKD_DataType->setObjectName("cb_SpeedKD_DataType");
        cb_SpeedKD_DataType->setMinimumSize(QSize(80, 30));

        horizontalLayout_7->addWidget(cb_SpeedKD_DataType, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_20 = new QLabel(ParameterAdjustment);
        label_20->setObjectName("label_20");

        horizontalLayout_8->addWidget(label_20, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        le_SpeedKD_Scale = new QLineEdit(ParameterAdjustment);
        le_SpeedKD_Scale->setObjectName("le_SpeedKD_Scale");
        le_SpeedKD_Scale->setMinimumSize(QSize(0, 30));
        le_SpeedKD_Scale->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_8->addWidget(le_SpeedKD_Scale);


        verticalLayout_5->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_5, 14, 5, 1, 1);

        lb_UprightKP_ReceiveValue = new QLabel(ParameterAdjustment);
        lb_UprightKP_ReceiveValue->setObjectName("lb_UprightKP_ReceiveValue");
        lb_UprightKP_ReceiveValue->setMinimumSize(QSize(80, 30));
        lb_UprightKP_ReceiveValue->setMaximumSize(QSize(140, 30));

        gridLayout->addWidget(lb_UprightKP_ReceiveValue, 2, 1, 1, 2, Qt::AlignVCenter);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_21 = new QLabel(ParameterAdjustment);
        label_21->setObjectName("label_21");

        horizontalLayout_9->addWidget(label_21, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        cb_SpeedKI_DataType = new QComboBox(ParameterAdjustment);
        cb_SpeedKI_DataType->addItem(QString());
        cb_SpeedKI_DataType->addItem(QString());
        cb_SpeedKI_DataType->setObjectName("cb_SpeedKI_DataType");
        cb_SpeedKI_DataType->setMinimumSize(QSize(80, 30));

        horizontalLayout_9->addWidget(cb_SpeedKI_DataType, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_22 = new QLabel(ParameterAdjustment);
        label_22->setObjectName("label_22");

        horizontalLayout_10->addWidget(label_22, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        le_SpeedKI_Scale = new QLineEdit(ParameterAdjustment);
        le_SpeedKI_Scale->setObjectName("le_SpeedKI_Scale");
        le_SpeedKI_Scale->setMinimumSize(QSize(0, 30));
        le_SpeedKI_Scale->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_10->addWidget(le_SpeedKI_Scale);


        verticalLayout_6->addLayout(horizontalLayout_10);


        gridLayout->addLayout(verticalLayout_6, 11, 5, 2, 1);

        line_3 = new QFrame(ParameterAdjustment);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_3, 6, 0, 1, 7);

        label_23 = new QLabel(ParameterAdjustment);
        label_23->setObjectName("label_23");

        gridLayout->addWidget(label_23, 14, 0, 1, 1);

        lb_SpeedKI_ReceiveValue = new QLabel(ParameterAdjustment);
        lb_SpeedKI_ReceiveValue->setObjectName("lb_SpeedKI_ReceiveValue");
        lb_SpeedKI_ReceiveValue->setMinimumSize(QSize(80, 30));
        lb_SpeedKI_ReceiveValue->setMaximumSize(QSize(140, 30));

        gridLayout->addWidget(lb_SpeedKI_ReceiveValue, 11, 1, 2, 2, Qt::AlignVCenter);

        label_6 = new QLabel(ParameterAdjustment);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        line_4 = new QFrame(ParameterAdjustment);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_4, 8, 0, 1, 7);

        bt_UprightKP_Send = new QPushButton(ParameterAdjustment);
        bt_UprightKP_Send->setObjectName("bt_UprightKP_Send");
        bt_UprightKP_Send->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(bt_UprightKP_Send, 2, 6, 1, 1);

        bt_SpeedKP_Send = new QPushButton(ParameterAdjustment);
        bt_SpeedKP_Send->setObjectName("bt_SpeedKP_Send");
        bt_SpeedKP_Send->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(bt_SpeedKP_Send, 9, 6, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_14 = new QLabel(ParameterAdjustment);
        label_14->setObjectName("label_14");

        horizontalLayout_4->addWidget(label_14, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        cb_UprightKI_DataType = new QComboBox(ParameterAdjustment);
        cb_UprightKI_DataType->addItem(QString());
        cb_UprightKI_DataType->addItem(QString());
        cb_UprightKI_DataType->setObjectName("cb_UprightKI_DataType");
        cb_UprightKI_DataType->setMinimumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(cb_UprightKI_DataType, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_15 = new QLabel(ParameterAdjustment);
        label_15->setObjectName("label_15");

        horizontalLayout_3->addWidget(label_15, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        le_UprightKI_Scale = new QLineEdit(ParameterAdjustment);
        le_UprightKI_Scale->setObjectName("le_UprightKI_Scale");
        le_UprightKI_Scale->setMinimumSize(QSize(0, 30));
        le_UprightKI_Scale->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(le_UprightKI_Scale);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 4, 5, 2, 1);

        label_3 = new QLabel(ParameterAdjustment);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(48, 20));

        gridLayout->addWidget(label_3, 0, 1, 1, 2, Qt::AlignHCenter|Qt::AlignVCenter);

        bt_UprightKD_Send = new QPushButton(ParameterAdjustment);
        bt_UprightKD_Send->setObjectName("bt_UprightKD_Send");
        bt_UprightKD_Send->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(bt_UprightKD_Send, 7, 6, 1, 1);

        lb_SpeedKP_ReceiveValue = new QLabel(ParameterAdjustment);
        lb_SpeedKP_ReceiveValue->setObjectName("lb_SpeedKP_ReceiveValue");
        lb_SpeedKP_ReceiveValue->setMinimumSize(QSize(80, 30));
        lb_SpeedKP_ReceiveValue->setMaximumSize(QSize(140, 30));

        gridLayout->addWidget(lb_SpeedKP_ReceiveValue, 9, 1, 1, 2, Qt::AlignVCenter);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_16 = new QLabel(ParameterAdjustment);
        label_16->setObjectName("label_16");

        horizontalLayout_5->addWidget(label_16, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        cb_UprightKD_DataType = new QComboBox(ParameterAdjustment);
        cb_UprightKD_DataType->addItem(QString());
        cb_UprightKD_DataType->addItem(QString());
        cb_UprightKD_DataType->setObjectName("cb_UprightKD_DataType");
        cb_UprightKD_DataType->setMinimumSize(QSize(80, 30));

        horizontalLayout_5->addWidget(cb_UprightKD_DataType, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_17 = new QLabel(ParameterAdjustment);
        label_17->setObjectName("label_17");

        horizontalLayout_6->addWidget(label_17, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        le_UprightKD_Scale = new QLineEdit(ParameterAdjustment);
        le_UprightKD_Scale->setObjectName("le_UprightKD_Scale");
        le_UprightKD_Scale->setMinimumSize(QSize(0, 30));
        le_UprightKD_Scale->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_6->addWidget(le_UprightKD_Scale);


        verticalLayout_4->addLayout(horizontalLayout_6);


        gridLayout->addLayout(verticalLayout_4, 7, 5, 1, 1);

        line = new QFrame(ParameterAdjustment);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 7);

        lb_SpeedKD_ReceiveValue = new QLabel(ParameterAdjustment);
        lb_SpeedKD_ReceiveValue->setObjectName("lb_SpeedKD_ReceiveValue");
        lb_SpeedKD_ReceiveValue->setMinimumSize(QSize(80, 30));
        lb_SpeedKD_ReceiveValue->setMaximumSize(QSize(140, 30));

        gridLayout->addWidget(lb_SpeedKD_ReceiveValue, 14, 1, 1, 2, Qt::AlignVCenter);

        label_4 = new QLabel(ParameterAdjustment);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(48, 20));

        gridLayout->addWidget(label_4, 0, 3, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_11 = new QLabel(ParameterAdjustment);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(48, 20));

        gridLayout->addWidget(label_11, 0, 6, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        bt_SpeedKD_Send = new QPushButton(ParameterAdjustment);
        bt_SpeedKD_Send->setObjectName("bt_SpeedKD_Send");
        bt_SpeedKD_Send->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(bt_SpeedKD_Send, 14, 6, 1, 1);

        label_2 = new QLabel(ParameterAdjustment);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        bt_UprightKI_Send = new QPushButton(ParameterAdjustment);
        bt_UprightKI_Send->setObjectName("bt_UprightKI_Send");
        bt_UprightKI_Send->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(bt_UprightKI_Send, 4, 6, 2, 1);

        line_7 = new QFrame(ParameterAdjustment);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_7, 15, 0, 1, 7);

        label_5 = new QLabel(ParameterAdjustment);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 2, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_26 = new QLabel(ParameterAdjustment);
        label_26->setObjectName("label_26");
        label_26->setMaximumSize(QSize(80, 30));

        horizontalLayout_11->addWidget(label_26, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        cb_SpeedKP_DataType = new QComboBox(ParameterAdjustment);
        cb_SpeedKP_DataType->addItem(QString());
        cb_SpeedKP_DataType->addItem(QString());
        cb_SpeedKP_DataType->setObjectName("cb_SpeedKP_DataType");
        cb_SpeedKP_DataType->setMinimumSize(QSize(80, 30));
        cb_SpeedKP_DataType->setMaximumSize(QSize(160, 30));

        horizontalLayout_11->addWidget(cb_SpeedKP_DataType, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_27 = new QLabel(ParameterAdjustment);
        label_27->setObjectName("label_27");
        label_27->setMaximumSize(QSize(80, 30));

        horizontalLayout_12->addWidget(label_27, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        le_SpeedKP_Scale = new QLineEdit(ParameterAdjustment);
        le_SpeedKP_Scale->setObjectName("le_SpeedKP_Scale");
        le_SpeedKP_Scale->setMinimumSize(QSize(0, 30));
        le_SpeedKP_Scale->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_12->addWidget(le_SpeedKP_Scale);


        verticalLayout_7->addLayout(horizontalLayout_12);


        gridLayout->addLayout(verticalLayout_7, 9, 5, 1, 1);

        lb_UprightKD_ReceiveValue = new QLabel(ParameterAdjustment);
        lb_UprightKD_ReceiveValue->setObjectName("lb_UprightKD_ReceiveValue");
        lb_UprightKD_ReceiveValue->setMinimumSize(QSize(80, 30));
        lb_UprightKD_ReceiveValue->setMaximumSize(QSize(140, 30));

        gridLayout->addWidget(lb_UprightKD_ReceiveValue, 7, 1, 1, 2, Qt::AlignVCenter);

        label = new QLabel(ParameterAdjustment);
        label->setObjectName("label");
        label->setMaximumSize(QSize(32, 20));

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        line_5 = new QFrame(ParameterAdjustment);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_5, 10, 0, 1, 7);

        bt_SpeedKI_Send = new QPushButton(ParameterAdjustment);
        bt_SpeedKI_Send->setObjectName("bt_SpeedKI_Send");
        bt_SpeedKI_Send->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(bt_SpeedKI_Send, 11, 6, 2, 1);

        lb_UprightKI_ReceiveValue = new QLabel(ParameterAdjustment);
        lb_UprightKI_ReceiveValue->setObjectName("lb_UprightKI_ReceiveValue");
        lb_UprightKI_ReceiveValue->setMinimumSize(QSize(80, 30));
        lb_UprightKI_ReceiveValue->setMaximumSize(QSize(140, 30));

        gridLayout->addWidget(lb_UprightKI_ReceiveValue, 4, 1, 2, 2, Qt::AlignVCenter);

        line_2 = new QFrame(ParameterAdjustment);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 7);

        label_29 = new QLabel(ParameterAdjustment);
        label_29->setObjectName("label_29");
        label_29->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(label_29, 9, 0, 1, 1);

        line_6 = new QFrame(ParameterAdjustment);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_6, 13, 0, 1, 7);

        line_8 = new QFrame(ParameterAdjustment);
        line_8->setObjectName("line_8");
        line_8->setFrameShape(QFrame::Shape::VLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_8, 2, 4, 1, 1);

        line_9 = new QFrame(ParameterAdjustment);
        line_9->setObjectName("line_9");
        line_9->setFrameShape(QFrame::Shape::VLine);
        line_9->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_9, 4, 4, 2, 1);

        line_10 = new QFrame(ParameterAdjustment);
        line_10->setObjectName("line_10");
        line_10->setFrameShape(QFrame::Shape::VLine);
        line_10->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_10, 7, 4, 1, 1);

        line_11 = new QFrame(ParameterAdjustment);
        line_11->setObjectName("line_11");
        line_11->setFrameShape(QFrame::Shape::VLine);
        line_11->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_11, 9, 4, 1, 1);

        line_12 = new QFrame(ParameterAdjustment);
        line_12->setObjectName("line_12");
        line_12->setFrameShape(QFrame::Shape::VLine);
        line_12->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_12, 11, 4, 2, 1);

        line_13 = new QFrame(ParameterAdjustment);
        line_13->setObjectName("line_13");
        line_13->setFrameShape(QFrame::Shape::VLine);
        line_13->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_13, 14, 4, 1, 1);

        le_UprightKP_SendValue = new QLineEdit(ParameterAdjustment);
        le_UprightKP_SendValue->setObjectName("le_UprightKP_SendValue");
        le_UprightKP_SendValue->setMinimumSize(QSize(80, 30));
        le_UprightKP_SendValue->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(le_UprightKP_SendValue, 2, 3, 1, 1);

        le_UprightKI_SendValue = new QLineEdit(ParameterAdjustment);
        le_UprightKI_SendValue->setObjectName("le_UprightKI_SendValue");
        le_UprightKI_SendValue->setMinimumSize(QSize(80, 30));
        le_UprightKI_SendValue->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(le_UprightKI_SendValue, 4, 3, 2, 1);

        le_UprightKD_SendValue = new QLineEdit(ParameterAdjustment);
        le_UprightKD_SendValue->setObjectName("le_UprightKD_SendValue");
        le_UprightKD_SendValue->setMinimumSize(QSize(80, 30));
        le_UprightKD_SendValue->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(le_UprightKD_SendValue, 7, 3, 1, 1);

        le_SpeedKP_SendValue = new QLineEdit(ParameterAdjustment);
        le_SpeedKP_SendValue->setObjectName("le_SpeedKP_SendValue");
        le_SpeedKP_SendValue->setMinimumSize(QSize(80, 30));
        le_SpeedKP_SendValue->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(le_SpeedKP_SendValue, 9, 3, 1, 1);

        le_SpeedKI_SendValue = new QLineEdit(ParameterAdjustment);
        le_SpeedKI_SendValue->setObjectName("le_SpeedKI_SendValue");
        le_SpeedKI_SendValue->setMinimumSize(QSize(80, 30));
        le_SpeedKI_SendValue->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(le_SpeedKI_SendValue, 11, 3, 2, 1);

        le_SpeedKD_SendValue = new QLineEdit(ParameterAdjustment);
        le_SpeedKD_SendValue->setObjectName("le_SpeedKD_SendValue");
        le_SpeedKD_SendValue->setMinimumSize(QSize(80, 30));
        le_SpeedKD_SendValue->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(le_SpeedKD_SendValue, 14, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(ParameterAdjustment);

        QMetaObject::connectSlotsByName(ParameterAdjustment);
    } // setupUi

    void retranslateUi(QWidget *ParameterAdjustment)
    {
        ParameterAdjustment->setWindowTitle(QCoreApplication::translate("ParameterAdjustment", "Form", nullptr));
        label_9->setText(QCoreApplication::translate("ParameterAdjustment", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        cb_UprightKP_DataType->setItemText(0, QCoreApplication::translate("ParameterAdjustment", "int16", nullptr));
        cb_UprightKP_DataType->setItemText(1, QCoreApplication::translate("ParameterAdjustment", "float", nullptr));

        label_10->setText(QCoreApplication::translate("ParameterAdjustment", "\347\274\251\346\224\276\345\200\215\346\225\260\357\274\232", nullptr));
        le_UprightKP_Scale->setText(QCoreApplication::translate("ParameterAdjustment", "1", nullptr));
        label_7->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">\346\240\274\345\274\217\351\205\215\347\275\256</span></p></body></html>", nullptr));
        label_28->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">\351\200\237\345\272\246KI</p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("ParameterAdjustment", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        cb_SpeedKD_DataType->setItemText(0, QCoreApplication::translate("ParameterAdjustment", "int16", nullptr));
        cb_SpeedKD_DataType->setItemText(1, QCoreApplication::translate("ParameterAdjustment", "float", nullptr));

        label_20->setText(QCoreApplication::translate("ParameterAdjustment", "\347\274\251\346\224\276\345\200\215\346\225\260\357\274\232", nullptr));
        le_SpeedKD_Scale->setText(QCoreApplication::translate("ParameterAdjustment", "1", nullptr));
        lb_UprightKP_ReceiveValue->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("ParameterAdjustment", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        cb_SpeedKI_DataType->setItemText(0, QCoreApplication::translate("ParameterAdjustment", "int16", nullptr));
        cb_SpeedKI_DataType->setItemText(1, QCoreApplication::translate("ParameterAdjustment", "float", nullptr));

        label_22->setText(QCoreApplication::translate("ParameterAdjustment", "\347\274\251\346\224\276\345\200\215\346\225\260\357\274\232", nullptr));
        le_SpeedKI_Scale->setText(QCoreApplication::translate("ParameterAdjustment", "1", nullptr));
        label_23->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">\351\200\237\345\272\246KD</p></body></html>", nullptr));
        lb_SpeedKI_ReceiveValue->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">\347\233\264\347\253\213KD</p></body></html>", nullptr));
        bt_UprightKP_Send->setText(QCoreApplication::translate("ParameterAdjustment", "\345\217\221\351\200\201", nullptr));
        bt_SpeedKP_Send->setText(QCoreApplication::translate("ParameterAdjustment", "\345\217\221\351\200\201", nullptr));
        label_14->setText(QCoreApplication::translate("ParameterAdjustment", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        cb_UprightKI_DataType->setItemText(0, QCoreApplication::translate("ParameterAdjustment", "int16", nullptr));
        cb_UprightKI_DataType->setItemText(1, QCoreApplication::translate("ParameterAdjustment", "float", nullptr));

        label_15->setText(QCoreApplication::translate("ParameterAdjustment", "\347\274\251\346\224\276\345\200\215\346\225\260\357\274\232", nullptr));
        le_UprightKI_Scale->setText(QCoreApplication::translate("ParameterAdjustment", "1", nullptr));
        label_3->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">\346\216\245\346\224\266\345\200\274</span></p></body></html>", nullptr));
        bt_UprightKD_Send->setText(QCoreApplication::translate("ParameterAdjustment", "\345\217\221\351\200\201", nullptr));
        lb_SpeedKP_ReceiveValue->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("ParameterAdjustment", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        cb_UprightKD_DataType->setItemText(0, QCoreApplication::translate("ParameterAdjustment", "int16", nullptr));
        cb_UprightKD_DataType->setItemText(1, QCoreApplication::translate("ParameterAdjustment", "float", nullptr));

        label_17->setText(QCoreApplication::translate("ParameterAdjustment", "\347\274\251\346\224\276\345\200\215\346\225\260\357\274\232", nullptr));
        le_UprightKD_Scale->setText(QCoreApplication::translate("ParameterAdjustment", "1", nullptr));
        lb_SpeedKD_ReceiveValue->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">\345\217\221\351\200\201\345\200\274</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">\345\217\221\351\200\201\351\224\256</span></p></body></html>", nullptr));
        bt_SpeedKD_Send->setText(QCoreApplication::translate("ParameterAdjustment", "\345\217\221\351\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">\347\233\264\347\253\213KP</p></body></html>", nullptr));
        bt_UprightKI_Send->setText(QCoreApplication::translate("ParameterAdjustment", "\345\217\221\351\200\201", nullptr));
        label_5->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">\347\233\264\347\253\213KI</p></body></html>", nullptr));
        label_26->setText(QCoreApplication::translate("ParameterAdjustment", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        cb_SpeedKP_DataType->setItemText(0, QCoreApplication::translate("ParameterAdjustment", "int16", nullptr));
        cb_SpeedKP_DataType->setItemText(1, QCoreApplication::translate("ParameterAdjustment", "float", nullptr));

        label_27->setText(QCoreApplication::translate("ParameterAdjustment", "\347\274\251\346\224\276\345\200\215\346\225\260\357\274\232", nullptr));
        le_SpeedKP_Scale->setText(QCoreApplication::translate("ParameterAdjustment", "1", nullptr));
        lb_UprightKD_ReceiveValue->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">\351\241\271\347\233\256</span></p></body></html>", nullptr));
        bt_SpeedKI_Send->setText(QCoreApplication::translate("ParameterAdjustment", "\345\217\221\351\200\201", nullptr));
        lb_UprightKI_ReceiveValue->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label_29->setText(QCoreApplication::translate("ParameterAdjustment", "<html><head/><body><p align=\"center\">\351\200\237\345\272\246KP</p></body></html>", nullptr));
        le_UprightKP_SendValue->setText(QCoreApplication::translate("ParameterAdjustment", "0", nullptr));
        le_UprightKI_SendValue->setText(QCoreApplication::translate("ParameterAdjustment", "0", nullptr));
        le_UprightKD_SendValue->setText(QCoreApplication::translate("ParameterAdjustment", "0", nullptr));
        le_SpeedKP_SendValue->setText(QCoreApplication::translate("ParameterAdjustment", "0", nullptr));
        le_SpeedKI_SendValue->setText(QCoreApplication::translate("ParameterAdjustment", "0", nullptr));
        le_SpeedKD_SendValue->setText(QCoreApplication::translate("ParameterAdjustment", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParameterAdjustment: public Ui_ParameterAdjustment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERADJUSTMENT_H
