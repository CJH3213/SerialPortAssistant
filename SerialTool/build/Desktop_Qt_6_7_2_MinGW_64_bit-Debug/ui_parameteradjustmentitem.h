/********************************************************************************
** Form generated from reading UI file 'parameteradjustmentitem.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERADJUSTMENTITEM_H
#define UI_PARAMETERADJUSTMENTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParameterAdjustmentItem
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *m_le_PrefixBytes;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *m_le_SuffixBytes;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *m_cb_Format;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *m_le_Scale;

    void setupUi(QWidget *ParameterAdjustmentItem)
    {
        if (ParameterAdjustmentItem->objectName().isEmpty())
            ParameterAdjustmentItem->setObjectName("ParameterAdjustmentItem");
        ParameterAdjustmentItem->resize(595, 342);
        verticalLayout = new QVBoxLayout(ParameterAdjustmentItem);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(ParameterAdjustmentItem);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        m_le_PrefixBytes = new QLineEdit(ParameterAdjustmentItem);
        m_le_PrefixBytes->setObjectName("m_le_PrefixBytes");

        horizontalLayout_2->addWidget(m_le_PrefixBytes);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(ParameterAdjustmentItem);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        m_le_SuffixBytes = new QLineEdit(ParameterAdjustmentItem);
        m_le_SuffixBytes->setObjectName("m_le_SuffixBytes");

        horizontalLayout_3->addWidget(m_le_SuffixBytes);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(ParameterAdjustmentItem);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3, 0, Qt::AlignLeft);

        m_cb_Format = new QComboBox(ParameterAdjustmentItem);
        m_cb_Format->addItem(QString());
        m_cb_Format->addItem(QString());
        m_cb_Format->setObjectName("m_cb_Format");

        horizontalLayout_5->addWidget(m_cb_Format);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        horizontalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_4 = new QLabel(ParameterAdjustmentItem);
        label_4->setObjectName("label_4");

        horizontalLayout_6->addWidget(label_4);

        m_le_Scale = new QLineEdit(ParameterAdjustmentItem);
        m_le_Scale->setObjectName("m_le_Scale");

        horizontalLayout_6->addWidget(m_le_Scale);


        horizontalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(ParameterAdjustmentItem);

        QMetaObject::connectSlotsByName(ParameterAdjustmentItem);
    } // setupUi

    void retranslateUi(QWidget *ParameterAdjustmentItem)
    {
        ParameterAdjustmentItem->setWindowTitle(QCoreApplication::translate("ParameterAdjustmentItem", "Form", nullptr));
        label->setText(QCoreApplication::translate("ParameterAdjustmentItem", "\345\211\215\347\274\200\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("ParameterAdjustmentItem", "\345\220\216\347\274\200\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("ParameterAdjustmentItem", "\346\240\274\345\274\217\357\274\232", nullptr));
        m_cb_Format->setItemText(0, QCoreApplication::translate("ParameterAdjustmentItem", "int16", nullptr));
        m_cb_Format->setItemText(1, QCoreApplication::translate("ParameterAdjustmentItem", "float", nullptr));

        label_4->setText(QCoreApplication::translate("ParameterAdjustmentItem", "\347\274\251\346\224\276\357\274\232", nullptr));
        m_le_Scale->setText(QCoreApplication::translate("ParameterAdjustmentItem", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParameterAdjustmentItem: public Ui_ParameterAdjustmentItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERADJUSTMENTITEM_H
