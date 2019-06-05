#pragma once

#include <QWidget>
#include "ui_DiskItemView.h"
#include "DiskItem.h"
#include <QList>
#include "GlobalDefine.h"
#include "robot.h"
class DiskItemView : public QWidget
{
	Q_OBJECT

public:
	DiskItemView(QWidget *parent = Q_NULLPTR);
	~DiskItemView();
	void Init_Connect(bool bisconnect);
	void InitView();
public:
	QList<DiskItem*>m_ListDiskItem;
private slots:
	void slotActionNotify(SItemRectInfo sInfo);

private:
	Ui::DiskItemView ui;

signals:
	void signalNofityInfoToTable(SItemRectInfo qstr);
};
