/********************************************************************************
** Form generated from reading UI file 'receivechart.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVECHART_H
#define UI_RECEIVECHART_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
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

class Ui_ReceiveChart
{
public:
    QHBoxLayout *horizontalLayout_2;
    QChartView *mChartWidget;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *mRunOrStopButton;
    QPushButton *mSingleButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *mDirectOrDecodeButton;
    QFrame *line_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QDial *mVerticalPositionDial;
    QLineEdit *mVerticalPositionLineEdit;
    QLabel *label;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_2;
    QDial *mHorizontalScaleDial;
    QLineEdit *mHorizontalScaleLineEdit;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QDial *mVerticalScaleDial;
    QLineEdit *mVerticalScaleLineEdit;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_7;
    QDial *mHorizontalPositionDial;
    QLineEdit *mHorizontalPositionLineEdit;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ReceiveChart)
    {
        if (ReceiveChart->objectName().isEmpty())
            ReceiveChart->setObjectName("ReceiveChart");
        ReceiveChart->resize(746, 518);
        horizontalLayout_2 = new QHBoxLayout(ReceiveChart);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        mChartWidget = new QChartView(ReceiveChart);
        mChartWidget->setObjectName("mChartWidget");
        mChartWidget->setMinimumSize(QSize(200, 500));

        horizontalLayout_2->addWidget(mChartWidget);

        line = new QFrame(ReceiveChart);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_2->addWidget(line);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        mRunOrStopButton = new QPushButton(ReceiveChart);
        mRunOrStopButton->setObjectName("mRunOrStopButton");
        mRunOrStopButton->setMinimumSize(QSize(100, 60));
        mRunOrStopButton->setMaximumSize(QSize(100, 60));
        QFont font;
        font.setPointSize(12);
        mRunOrStopButton->setFont(font);
        mRunOrStopButton->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 255, 205);"));

        gridLayout_2->addWidget(mRunOrStopButton, 0, 1, 1, 1, Qt::AlignHCenter);

        mSingleButton = new QPushButton(ReceiveChart);
        mSingleButton->setObjectName("mSingleButton");
        mSingleButton->setMinimumSize(QSize(100, 60));
        mSingleButton->setMaximumSize(QSize(100, 60));
        mSingleButton->setFont(font);

        gridLayout_2->addWidget(mSingleButton, 1, 1, 1, 1, Qt::AlignHCenter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        mDirectOrDecodeButton = new QPushButton(ReceiveChart);
        mDirectOrDecodeButton->setObjectName("mDirectOrDecodeButton");
        mDirectOrDecodeButton->setMinimumSize(QSize(100, 60));
        mDirectOrDecodeButton->setMaximumSize(QSize(100, 60));
        mDirectOrDecodeButton->setFont(font);

        gridLayout_2->addWidget(mDirectOrDecodeButton, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout->addLayout(gridLayout_2);

        line_2 = new QFrame(ReceiveChart);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(5, 5, 5, 10);
        label_3 = new QLabel(ReceiveChart);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 2, 1, 1, Qt::AlignHCenter);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(ReceiveChart);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(80, 20));
        label_6->setMaximumSize(QSize(80, 20));

        verticalLayout_8->addWidget(label_6, 0, Qt::AlignHCenter);

        mVerticalPositionDial = new QDial(ReceiveChart);
        mVerticalPositionDial->setObjectName("mVerticalPositionDial");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mVerticalPositionDial->sizePolicy().hasHeightForWidth());
        mVerticalPositionDial->setSizePolicy(sizePolicy);
        mVerticalPositionDial->setMinimumSize(QSize(80, 80));
        mVerticalPositionDial->setMaximumSize(QSize(80, 80));
        mVerticalPositionDial->setContextMenuPolicy(Qt::NoContextMenu);
        mVerticalPositionDial->setMinimum(-100);
        mVerticalPositionDial->setMaximum(100);
        mVerticalPositionDial->setWrapping(true);
        mVerticalPositionDial->setNotchTarget(10.000000000000000);
        mVerticalPositionDial->setNotchesVisible(false);

        verticalLayout_8->addWidget(mVerticalPositionDial, 0, Qt::AlignHCenter);

        mVerticalPositionLineEdit = new QLineEdit(ReceiveChart);
        mVerticalPositionLineEdit->setObjectName("mVerticalPositionLineEdit");
        mVerticalPositionLineEdit->setMinimumSize(QSize(100, 25));
        mVerticalPositionLineEdit->setMaximumSize(QSize(100, 25));
        mVerticalPositionLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(mVerticalPositionLineEdit, 0, Qt::AlignHCenter);


        gridLayout->addLayout(verticalLayout_8, 3, 0, 1, 1);

        label = new QLabel(ReceiveChart);
        label->setObjectName("label");
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(ReceiveChart);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(100, 20));
        label_2->setMaximumSize(QSize(100, 20));

        verticalLayout_9->addWidget(label_2, 0, Qt::AlignHCenter);

        mHorizontalScaleDial = new QDial(ReceiveChart);
        mHorizontalScaleDial->setObjectName("mHorizontalScaleDial");
        mHorizontalScaleDial->setMinimumSize(QSize(100, 100));
        mHorizontalScaleDial->setMaximumSize(QSize(100, 100));
        mHorizontalScaleDial->setContextMenuPolicy(Qt::NoContextMenu);
        mHorizontalScaleDial->setMaximum(1000);
        mHorizontalScaleDial->setValue(60);
        mHorizontalScaleDial->setSliderPosition(60);
        mHorizontalScaleDial->setWrapping(true);

        verticalLayout_9->addWidget(mHorizontalScaleDial, 0, Qt::AlignHCenter);

        mHorizontalScaleLineEdit = new QLineEdit(ReceiveChart);
        mHorizontalScaleLineEdit->setObjectName("mHorizontalScaleLineEdit");
        mHorizontalScaleLineEdit->setMinimumSize(QSize(100, 25));
        mHorizontalScaleLineEdit->setMaximumSize(QSize(100, 25));
        mHorizontalScaleLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(mHorizontalScaleLineEdit, 0, Qt::AlignHCenter);


        gridLayout->addLayout(verticalLayout_9, 2, 2, 1, 1);

        line_4 = new QFrame(ReceiveChart);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::VLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_4, 0, 1, 4, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(ReceiveChart);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(100, 20));
        label_5->setMaximumSize(QSize(100, 20));

        verticalLayout_7->addWidget(label_5, 0, Qt::AlignHCenter);

        mVerticalScaleDial = new QDial(ReceiveChart);
        mVerticalScaleDial->setObjectName("mVerticalScaleDial");
        mVerticalScaleDial->setMinimumSize(QSize(100, 100));
        mVerticalScaleDial->setMaximumSize(QSize(100, 100));
        mVerticalScaleDial->setContextMenuPolicy(Qt::NoContextMenu);
        mVerticalScaleDial->setMaximum(500);
        mVerticalScaleDial->setValue(256);
        mVerticalScaleDial->setWrapping(true);
        mVerticalScaleDial->setNotchesVisible(false);

        verticalLayout_7->addWidget(mVerticalScaleDial, 0, Qt::AlignHCenter);

        mVerticalScaleLineEdit = new QLineEdit(ReceiveChart);
        mVerticalScaleLineEdit->setObjectName("mVerticalScaleLineEdit");
        mVerticalScaleLineEdit->setMinimumSize(QSize(100, 25));
        mVerticalScaleLineEdit->setMaximumSize(QSize(100, 25));
        mVerticalScaleLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(mVerticalScaleLineEdit, 0, Qt::AlignHCenter);


        gridLayout->addLayout(verticalLayout_7, 2, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(ReceiveChart);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(80, 20));
        label_7->setMaximumSize(QSize(80, 20));

        verticalLayout_10->addWidget(label_7, 0, Qt::AlignHCenter);

        mHorizontalPositionDial = new QDial(ReceiveChart);
        mHorizontalPositionDial->setObjectName("mHorizontalPositionDial");
        mHorizontalPositionDial->setMinimumSize(QSize(80, 80));
        mHorizontalPositionDial->setMaximumSize(QSize(80, 80));
        mHorizontalPositionDial->setContextMenuPolicy(Qt::NoContextMenu);
        mHorizontalPositionDial->setMinimum(-100);
        mHorizontalPositionDial->setMaximum(100);
        mHorizontalPositionDial->setWrapping(true);

        verticalLayout_10->addWidget(mHorizontalPositionDial, 0, Qt::AlignHCenter);

        mHorizontalPositionLineEdit = new QLineEdit(ReceiveChart);
        mHorizontalPositionLineEdit->setObjectName("mHorizontalPositionLineEdit");
        mHorizontalPositionLineEdit->setMinimumSize(QSize(100, 25));
        mHorizontalPositionLineEdit->setMaximumSize(QSize(100, 25));
        mHorizontalPositionLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(mHorizontalPositionLineEdit, 0, Qt::AlignHCenter);


        gridLayout->addLayout(verticalLayout_10, 3, 2, 1, 1);

        line_5 = new QFrame(ReceiveChart);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_5, 1, 0, 1, 1);

        line_6 = new QFrame(ReceiveChart);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_6, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line_3 = new QFrame(ReceiveChart);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_3);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 1);

        retranslateUi(ReceiveChart);

        QMetaObject::connectSlotsByName(ReceiveChart);
    } // setupUi

    void retranslateUi(QWidget *ReceiveChart)
    {
        ReceiveChart->setWindowTitle(QCoreApplication::translate("ReceiveChart", "Dialog", nullptr));
        mRunOrStopButton->setText(QCoreApplication::translate("ReceiveChart", "Run/Stop", nullptr));
        mSingleButton->setText(QCoreApplication::translate("ReceiveChart", "Single", nullptr));
        mDirectOrDecodeButton->setText(QCoreApplication::translate("ReceiveChart", "Direct/\n"
"Decode", nullptr));
        label_3->setText(QCoreApplication::translate("ReceiveChart", "\346\260\264\345\271\263", nullptr));
        label_6->setText(QCoreApplication::translate("ReceiveChart", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\236\202\347\233\264\345\271\263\347\247\273</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("ReceiveChart", "\345\236\202\347\233\264", nullptr));
        label_2->setText(QCoreApplication::translate("ReceiveChart", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\227\266\351\227\264</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("ReceiveChart", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\271\205\345\272\246</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("ReceiveChart", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\260\264\345\271\263\345\271\263\347\247\273</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReceiveChart: public Ui_ReceiveChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVECHART_H
