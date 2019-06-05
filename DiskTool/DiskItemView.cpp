#include "DiskItemView.h"

DiskItemView::DiskItemView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitView();
	Init_Connect(true);
}
DiskItemView::~DiskItemView()
{
	Init_Connect(false);
}
void DiskItemView::Init_Connect(bool bisconnect)
{
	qRegisterMetaType<SItemRectInfo>("SItemRectInfo");
	if (bisconnect == true)
	{
		foreach(DiskItem *varitem, m_ListDiskItem)
		{
			connect(varitem, SIGNAL(signalNofityInfo(SItemRectInfo)), this, SLOT(slotActionNotify(SItemRectInfo)));
		}
	}

	else
	{
		foreach(DiskItem *varitem, m_ListDiskItem)
		{
			disconnect(varitem, SIGNAL(signalNofityInfo(SItemRectInfo)), this, SLOT(slotActionNotify(SItemRectInfo)));
		}
	}
}

void DiskItemView::InitView()
{
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

	QGraphicsScene *scene = new QGraphicsScene;
	scene->setSceneRect(-210, -210, 420, 420); //确保原点在中间
	DiskExternItem *item = new DiskExternItem;
	scene->addItem(item);
	m_ListDiskItem.clear();
	for (int i = 0; i < ItemCount; ++i)
	{
		DiskItem *item = new DiskItem;
		item->setPos(::sin((i * TwoPi) / ItemCount) * 150,
			::cos((i * TwoPi) / ItemCount) * 150);
		item->setItemNum(i);
		scene->addItem(item);
		m_ListDiskItem << item;
	}

	robot *m_robot = new robot;
	//m_robot->setTransform(QTransform::fromScale(1.2, 1.2), true);
	scene->addItem(m_robot);
	ui.graphicsView->setScene(scene);
	ui.graphicsView->setRenderHint(QPainter::Antialiasing);
	ui.graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	ui.graphicsView->setBackgroundBrush(ColorWhite);
	ui.graphicsView->setWindowTitle("Drag and Drop Robot");
}




void DiskItemView::slotActionNotify(SItemRectInfo sInfo)
{
	qDebug() << "post some info";
	qDebug() << "idnum is "<<sInfo.m_IdNum << ",status is"<<int(sInfo.m_itemColorStatus);
	emit signalNofityInfoToTable(sInfo);
}