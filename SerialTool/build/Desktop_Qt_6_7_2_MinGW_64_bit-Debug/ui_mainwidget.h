/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *mPortNamesComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QComboBox *mBaudrateComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QComboBox *mDataBitsComboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QComboBox *mStopBitsComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QComboBox *mParityComboBox;
    QPushButton *mConnectButton;
    QFrame *line;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *mReceiveCountLabel;
    QPlainTextEdit *mReceiveTextEdit;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *mReceiveHexCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *mReceiveClearButton;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *mSendCountLabel;
    QPlainTextEdit *mSendTextEdit;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *mSendHexCheckBox;
    QCheckBox *mSendLineFeedCheckBox;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *mSendButton;
    QPushButton *mSendClearButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(723, 494);
        horizontalLayout_10 = new QHBoxLayout(Widget);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(label);

        mPortNamesComboBox = new QComboBox(Widget);
        mPortNamesComboBox->setObjectName("mPortNamesComboBox");
        mPortNamesComboBox->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(mPortNamesComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_6 = new QLabel(Widget);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(label_6);

        mBaudrateComboBox = new QComboBox(Widget);
        mBaudrateComboBox->setObjectName("mBaudrateComboBox");
        mBaudrateComboBox->setMinimumSize(QSize(90, 0));

        horizontalLayout_2->addWidget(mBaudrateComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_7 = new QLabel(Widget);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_3->addWidget(label_7);

        mDataBitsComboBox = new QComboBox(Widget);
        mDataBitsComboBox->setObjectName("mDataBitsComboBox");

        horizontalLayout_3->addWidget(mDataBitsComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_8 = new QLabel(Widget);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_4->addWidget(label_8);

        mStopBitsComboBox = new QComboBox(Widget);
        mStopBitsComboBox->setObjectName("mStopBitsComboBox");

        horizontalLayout_4->addWidget(mStopBitsComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_9 = new QLabel(Widget);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_5->addWidget(label_9);

        mParityComboBox = new QComboBox(Widget);
        mParityComboBox->setObjectName("mParityComboBox");

        horizontalLayout_5->addWidget(mParityComboBox);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        mConnectButton = new QPushButton(Widget);
        mConnectButton->setObjectName("mConnectButton");

        verticalLayout_2->addWidget(mConnectButton);

        line = new QFrame(Widget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_2->addWidget(line);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_10->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");

        horizontalLayout_6->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        mReceiveCountLabel = new QLabel(Widget);
        mReceiveCountLabel->setObjectName("mReceiveCountLabel");

        horizontalLayout_6->addWidget(mReceiveCountLabel);


        verticalLayout_3->addLayout(horizontalLayout_6);

        mReceiveTextEdit = new QPlainTextEdit(Widget);
        mReceiveTextEdit->setObjectName("mReceiveTextEdit");
        mReceiveTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(mReceiveTextEdit);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        mReceiveHexCheckBox = new QCheckBox(Widget);
        mReceiveHexCheckBox->setObjectName("mReceiveHexCheckBox");

        horizontalLayout_8->addWidget(mReceiveHexCheckBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        mReceiveClearButton = new QPushButton(Widget);
        mReceiveClearButton->setObjectName("mReceiveClearButton");
        mReceiveClearButton->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_8->addWidget(mReceiveClearButton);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setSizeConstraint(QLayout::SetMinimumSize);
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(36, 20));

        horizontalLayout_7->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(36, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        mSendCountLabel = new QLabel(Widget);
        mSendCountLabel->setObjectName("mSendCountLabel");
        mSendCountLabel->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_7->addWidget(mSendCountLabel);


        verticalLayout_4->addLayout(horizontalLayout_7);

        mSendTextEdit = new QPlainTextEdit(Widget);
        mSendTextEdit->setObjectName("mSendTextEdit");
        mSendTextEdit->setMaximumSize(QSize(16777215, 100));

        verticalLayout_4->addWidget(mSendTextEdit);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setSizeConstraint(QLayout::SetMinimumSize);
        mSendHexCheckBox = new QCheckBox(Widget);
        mSendHexCheckBox->setObjectName("mSendHexCheckBox");
        mSendHexCheckBox->setMaximumSize(QSize(85, 19));

        horizontalLayout_9->addWidget(mSendHexCheckBox);

        mSendLineFeedCheckBox = new QCheckBox(Widget);
        mSendLineFeedCheckBox->setObjectName("mSendLineFeedCheckBox");
        mSendLineFeedCheckBox->setMaximumSize(QSize(85, 19));

        horizontalLayout_9->addWidget(mSendLineFeedCheckBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        mSendButton = new QPushButton(Widget);
        mSendButton->setObjectName("mSendButton");
        mSendButton->setMaximumSize(QSize(75, 23));

        horizontalLayout_9->addWidget(mSendButton);

        mSendClearButton = new QPushButton(Widget);
        mSendClearButton->setObjectName("mSendClearButton");
        mSendClearButton->setMaximumSize(QSize(75, 23));

        horizontalLayout_9->addWidget(mSendClearButton);


        verticalLayout_4->addLayout(horizontalLayout_9);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_10->addLayout(verticalLayout_5);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        mConnectButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\347\272\277\345\233\276", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\350\260\203\345\217\202", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\357\274\232", nullptr));
        mReceiveCountLabel->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\255\227\350\212\202\357\274\2320", nullptr));
        mReceiveHexCheckBox->setText(QCoreApplication::translate("Widget", "16\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        mReceiveClearButton->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\357\274\232", nullptr));
        mSendCountLabel->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\345\255\227\350\212\202\357\274\2320", nullptr));
        mSendHexCheckBox->setText(QCoreApplication::translate("Widget", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        mSendLineFeedCheckBox->setText(QCoreApplication::translate("Widget", "\351\231\204\345\212\240\346\215\242\350\241\214\347\254\246", nullptr));
        mSendButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        mSendClearButton->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
