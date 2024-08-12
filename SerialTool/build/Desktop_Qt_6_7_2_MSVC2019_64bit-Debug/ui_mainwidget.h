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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QPushButton *mOpenConnectionDialogButton;
    QPlainTextEdit *te_Details;
    QFrame *line;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *mReceiveCountLabel;
    QPlainTextEdit *mReceiveTextEdit;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *mReceiveHexCheckBox;
    QCheckBox *cb_AutoClear;
    QLineEdit *le_ClearThreshold;
    QLabel *label;
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
        Widget->resize(990, 615);
        horizontalLayout_10 = new QHBoxLayout(Widget);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        verticalLayout_2->addLayout(verticalLayout);

        mOpenConnectionDialogButton = new QPushButton(Widget);
        mOpenConnectionDialogButton->setObjectName("mOpenConnectionDialogButton");
        mOpenConnectionDialogButton->setMinimumSize(QSize(120, 0));
        mOpenConnectionDialogButton->setMaximumSize(QSize(120, 16777215));

        verticalLayout_2->addWidget(mOpenConnectionDialogButton);

        te_Details = new QPlainTextEdit(Widget);
        te_Details->setObjectName("te_Details");
        te_Details->setMinimumSize(QSize(120, 0));
        te_Details->setMaximumSize(QSize(120, 16777215));

        verticalLayout_2->addWidget(te_Details);

        line = new QFrame(Widget);
        line->setObjectName("line");
        line->setMinimumSize(QSize(120, 0));
        line->setMaximumSize(QSize(120, 16777215));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_2->addWidget(line);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(120, 0));
        pushButton->setMaximumSize(QSize(120, 16777215));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(120, 0));
        pushButton_2->setMaximumSize(QSize(120, 16777215));

        verticalLayout_2->addWidget(pushButton_2);


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

        cb_AutoClear = new QCheckBox(Widget);
        cb_AutoClear->setObjectName("cb_AutoClear");

        horizontalLayout_8->addWidget(cb_AutoClear);

        le_ClearThreshold = new QLineEdit(Widget);
        le_ClearThreshold->setObjectName("le_ClearThreshold");
        le_ClearThreshold->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(le_ClearThreshold);

        label = new QLabel(Widget);
        label->setObjectName("label");

        horizontalLayout_8->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        mReceiveClearButton = new QPushButton(Widget);
        mReceiveClearButton->setObjectName("mReceiveClearButton");
        mReceiveClearButton->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_8->addWidget(mReceiveClearButton);


        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 100);
        verticalLayout_3->setStretch(2, 1);

        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
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
        mSendTextEdit->setMinimumSize(QSize(0, 0));

        verticalLayout_4->addWidget(mSendTextEdit);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
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

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 100);
        verticalLayout_4->setStretch(2, 1);

        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5->setStretch(0, 100);
        verticalLayout_5->setStretch(1, 40);

        horizontalLayout_10->addLayout(verticalLayout_5);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 100);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\351\200\232\350\256\257\345\212\251\346\211\213", nullptr));
        mOpenConnectionDialogButton->setText(QCoreApplication::translate("Widget", "\351\205\215\347\275\256\351\200\232\344\277\241\346\226\271\345\274\217", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\347\272\277\345\233\276", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\350\260\203\345\217\202", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\357\274\232", nullptr));
        mReceiveCountLabel->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\255\227\350\212\202\357\274\2320", nullptr));
        mReceiveHexCheckBox->setText(QCoreApplication::translate("Widget", "16\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        cb_AutoClear->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\346\270\205\351\231\244", nullptr));
        le_ClearThreshold->setText(QCoreApplication::translate("Widget", "100", nullptr));
        label->setText(QCoreApplication::translate("Widget", "KB", nullptr));
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
