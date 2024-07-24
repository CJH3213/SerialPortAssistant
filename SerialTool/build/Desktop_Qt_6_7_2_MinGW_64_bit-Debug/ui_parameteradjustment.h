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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParameterAdjustment
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *bt_AddItem;
    QPushButton *bt_RemoveSelectedItem;
    QSpacerItem *horizontalSpacer;
    QPushButton *bt_MoveUp;
    QPushButton *bt_MoveDown;

    void setupUi(QWidget *ParameterAdjustment)
    {
        if (ParameterAdjustment->objectName().isEmpty())
            ParameterAdjustment->setObjectName("ParameterAdjustment");
        ParameterAdjustment->resize(693, 460);
        verticalLayout = new QVBoxLayout(ParameterAdjustment);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(ParameterAdjustment);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget->horizontalHeader()->setDefaultSectionSize(130);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(110);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);

        line_6 = new QFrame(ParameterAdjustment);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        bt_AddItem = new QPushButton(ParameterAdjustment);
        bt_AddItem->setObjectName("bt_AddItem");

        horizontalLayout->addWidget(bt_AddItem);

        bt_RemoveSelectedItem = new QPushButton(ParameterAdjustment);
        bt_RemoveSelectedItem->setObjectName("bt_RemoveSelectedItem");

        horizontalLayout->addWidget(bt_RemoveSelectedItem);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bt_MoveUp = new QPushButton(ParameterAdjustment);
        bt_MoveUp->setObjectName("bt_MoveUp");

        horizontalLayout->addWidget(bt_MoveUp);

        bt_MoveDown = new QPushButton(ParameterAdjustment);
        bt_MoveDown->setObjectName("bt_MoveDown");

        horizontalLayout->addWidget(bt_MoveDown);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ParameterAdjustment);

        QMetaObject::connectSlotsByName(ParameterAdjustment);
    } // setupUi

    void retranslateUi(QWidget *ParameterAdjustment)
    {
        ParameterAdjustment->setWindowTitle(QCoreApplication::translate("ParameterAdjustment", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ParameterAdjustment", "\351\241\271\347\233\256\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ParameterAdjustment", "\346\216\245\346\224\266\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ParameterAdjustment", "\345\217\221\351\200\201\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ParameterAdjustment", "\345\217\221\351\200\201\345\217\202\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ParameterAdjustment", "\345\217\221\351\200\201\346\214\211\351\222\256", nullptr));
        bt_AddItem->setText(QCoreApplication::translate("ParameterAdjustment", "\345\242\236\345\212\240", nullptr));
        bt_RemoveSelectedItem->setText(QCoreApplication::translate("ParameterAdjustment", "\345\210\240\351\231\244", nullptr));
        bt_MoveUp->setText(QCoreApplication::translate("ParameterAdjustment", "\344\270\212\347\247\273", nullptr));
        bt_MoveDown->setText(QCoreApplication::translate("ParameterAdjustment", "\344\270\213\347\247\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParameterAdjustment: public Ui_ParameterAdjustment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERADJUSTMENT_H
