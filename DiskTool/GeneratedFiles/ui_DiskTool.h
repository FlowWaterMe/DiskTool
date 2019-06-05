/********************************************************************************
** Form generated from reading UI file 'DiskTool.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISKTOOL_H
#define UI_DISKTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "DiskItemView.h"

QT_BEGIN_NAMESPACE

class Ui_DiskToolClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    DiskItemView *widget_Diskview;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget_Sample;
    QWidget *widget_sampleinfo;
    QGridLayout *gridLayout;
    QLabel *label_19;
    QLineEdit *edtSampleNo;
    QLabel *label_2;
    QLineEdit *edtPatientName;
    QLabel *label_3;
    QLineEdit *edtBarcode;
    QLabel *label_5;
    QLineEdit *edtAge;
    QComboBox *cbxAgeUnit;
    QLabel *label_4;
    QComboBox *cbxGender;
    QLabel *label_7;
    QDoubleSpinBox *spinBoxPcv;
    QLabel *label_8;
    QPushButton *btnmodif;
    QPushButton *btnsave;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DiskToolClass)
    {
        if (DiskToolClass->objectName().isEmpty())
            DiskToolClass->setObjectName(QStringLiteral("DiskToolClass"));
        DiskToolClass->resize(1002, 790);
        centralWidget = new QWidget(DiskToolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        widget_Diskview = new DiskItemView(centralWidget);
        widget_Diskview->setObjectName(QStringLiteral("widget_Diskview"));

        gridLayout_4->addWidget(widget_Diskview, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableWidget_Sample = new QTableWidget(groupBox);
        tableWidget_Sample->setObjectName(QStringLiteral("tableWidget_Sample"));

        gridLayout_2->addWidget(tableWidget_Sample, 0, 0, 1, 1);

        widget_sampleinfo = new QWidget(groupBox);
        widget_sampleinfo->setObjectName(QStringLiteral("widget_sampleinfo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_sampleinfo->sizePolicy().hasHeightForWidth());
        widget_sampleinfo->setSizePolicy(sizePolicy);
        widget_sampleinfo->setMinimumSize(QSize(0, 80));
        widget_sampleinfo->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        widget_sampleinfo->setFont(font);
        gridLayout = new QGridLayout(widget_sampleinfo);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_19 = new QLabel(widget_sampleinfo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(60, 0));
        QFont font1;
        font1.setPointSize(12);
        label_19->setFont(font1);
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_19, 0, 0, 1, 1);

        edtSampleNo = new QLineEdit(widget_sampleinfo);
        edtSampleNo->setObjectName(QStringLiteral("edtSampleNo"));
        edtSampleNo->setMinimumSize(QSize(80, 40));
        edtSampleNo->setMaximumSize(QSize(150, 40));
        edtSampleNo->setMaxLength(10);
        edtSampleNo->setEchoMode(QLineEdit::Normal);
        edtSampleNo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(edtSampleNo, 0, 1, 1, 1);

        label_2 = new QLabel(widget_sampleinfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(70, 0));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        edtPatientName = new QLineEdit(widget_sampleinfo);
        edtPatientName->setObjectName(QStringLiteral("edtPatientName"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(edtPatientName->sizePolicy().hasHeightForWidth());
        edtPatientName->setSizePolicy(sizePolicy1);
        edtPatientName->setMinimumSize(QSize(120, 40));
        edtPatientName->setMaximumSize(QSize(120, 40));
        edtPatientName->setMaxLength(20);
        edtPatientName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(edtPatientName, 0, 3, 1, 2);

        label_3 = new QLabel(widget_sampleinfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(75, 0));
        label_3->setMaximumSize(QSize(150, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        edtBarcode = new QLineEdit(widget_sampleinfo);
        edtBarcode->setObjectName(QStringLiteral("edtBarcode"));
        edtBarcode->setMinimumSize(QSize(80, 40));
        edtBarcode->setMaximumSize(QSize(160, 40));
        edtBarcode->setMaxLength(20);
        edtBarcode->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(edtBarcode, 1, 1, 1, 1);

        label_5 = new QLabel(widget_sampleinfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(50, 0));
        label_5->setMaximumSize(QSize(50, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        edtAge = new QLineEdit(widget_sampleinfo);
        edtAge->setObjectName(QStringLiteral("edtAge"));
        edtAge->setMinimumSize(QSize(60, 40));
        edtAge->setMaximumSize(QSize(70, 40));
        edtAge->setMaxLength(3);
        edtAge->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(edtAge, 1, 3, 1, 1);

        cbxAgeUnit = new QComboBox(widget_sampleinfo);
        cbxAgeUnit->setObjectName(QStringLiteral("cbxAgeUnit"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbxAgeUnit->sizePolicy().hasHeightForWidth());
        cbxAgeUnit->setSizePolicy(sizePolicy2);
        cbxAgeUnit->setMinimumSize(QSize(50, 40));
        cbxAgeUnit->setMaximumSize(QSize(50, 40));

        gridLayout->addWidget(cbxAgeUnit, 1, 4, 1, 1);

        label_4 = new QLabel(widget_sampleinfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(50, 0));
        label_4->setMaximumSize(QSize(50, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        cbxGender = new QComboBox(widget_sampleinfo);
        cbxGender->setObjectName(QStringLiteral("cbxGender"));
        cbxGender->setMinimumSize(QSize(80, 40));
        cbxGender->setMaximumSize(QSize(16777215, 40));
        cbxGender->setMaxCount(150);

        gridLayout->addWidget(cbxGender, 2, 1, 1, 1);

        label_7 = new QLabel(widget_sampleinfo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(50, 0));
        label_7->setMaximumSize(QSize(50, 16777215));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        spinBoxPcv = new QDoubleSpinBox(widget_sampleinfo);
        spinBoxPcv->setObjectName(QStringLiteral("spinBoxPcv"));
        spinBoxPcv->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBoxPcv->sizePolicy().hasHeightForWidth());
        spinBoxPcv->setSizePolicy(sizePolicy3);
        spinBoxPcv->setMinimumSize(QSize(0, 40));
        spinBoxPcv->setMaximumSize(QSize(16777215, 40));
        spinBoxPcv->setAlignment(Qt::AlignCenter);
        spinBoxPcv->setAccelerated(false);
        spinBoxPcv->setProperty("showGroupSeparator", QVariant(false));

        gridLayout->addWidget(spinBoxPcv, 2, 3, 1, 1);

        label_8 = new QLabel(widget_sampleinfo);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);
        QFont font2;
        font2.setPointSize(11);
        label_8->setFont(font2);

        gridLayout->addWidget(label_8, 2, 4, 1, 1);

        btnmodif = new QPushButton(widget_sampleinfo);
        btnmodif->setObjectName(QStringLiteral("btnmodif"));

        gridLayout->addWidget(btnmodif, 3, 1, 1, 1);

        btnsave = new QPushButton(widget_sampleinfo);
        btnsave->setObjectName(QStringLiteral("btnsave"));

        gridLayout->addWidget(btnsave, 3, 3, 1, 2);


        gridLayout_2->addWidget(widget_sampleinfo, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 2);
        gridLayout_2->setRowMinimumHeight(0, 1);
        gridLayout_2->setRowMinimumHeight(1, 2);

        gridLayout_4->addWidget(groupBox, 0, 1, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1);
        gridLayout_4->setColumnMinimumWidth(0, 1);
        gridLayout_4->setColumnMinimumWidth(1, 1);
        DiskToolClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DiskToolClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1002, 23));
        DiskToolClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DiskToolClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DiskToolClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DiskToolClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DiskToolClass->setStatusBar(statusBar);

        retranslateUi(DiskToolClass);

        QMetaObject::connectSlotsByName(DiskToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *DiskToolClass)
    {
        DiskToolClass->setWindowTitle(QApplication::translate("DiskToolClass", "DiskTool", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DiskToolClass", "\350\257\225\347\256\241\344\277\241\346\201\257", Q_NULLPTR));
        label_19->setText(QApplication::translate("DiskToolClass", "\350\257\225\347\256\241\347\274\226\345\217\267", Q_NULLPTR));
        edtSampleNo->setText(QString());
        label_2->setText(QApplication::translate("DiskToolClass", "\347\227\205\344\272\272\345\220\215\347\247\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("DiskToolClass", "\346\240\267\346\234\254\346\235\241\347\240\201", Q_NULLPTR));
        edtBarcode->setText(QString());
        label_5->setText(QApplication::translate("DiskToolClass", "\345\271\264 \351\276\204", Q_NULLPTR));
        edtAge->setText(QString());
        label_4->setText(QApplication::translate("DiskToolClass", "\346\200\247 \345\210\253", Q_NULLPTR));
        label_7->setText(QApplication::translate("DiskToolClass", "HCT", Q_NULLPTR));
        label_8->setText(QApplication::translate("DiskToolClass", "%", Q_NULLPTR));
        btnmodif->setText(QApplication::translate("DiskToolClass", "\344\277\256\346\224\271", Q_NULLPTR));
        btnsave->setText(QApplication::translate("DiskToolClass", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DiskToolClass: public Ui_DiskToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISKTOOL_H
