/********************************************************************************
** Form generated from reading UI file 'DiskItemView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISKITEMVIEW_H
#define UI_DISKITEMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiskItemView
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *DiskItemView)
    {
        if (DiskItemView->objectName().isEmpty())
            DiskItemView->setObjectName(QStringLiteral("DiskItemView"));
        DiskItemView->resize(641, 599);
        gridLayout = new QGridLayout(DiskItemView);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(DiskItemView);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(DiskItemView);

        QMetaObject::connectSlotsByName(DiskItemView);
    } // setupUi

    void retranslateUi(QWidget *DiskItemView)
    {
        DiskItemView->setWindowTitle(QApplication::translate("DiskItemView", "DiskItemView", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DiskItemView: public Ui_DiskItemView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISKITEMVIEW_H
