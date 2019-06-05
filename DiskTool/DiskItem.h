#pragma once

#include <QGraphicsItem>
#include <QtWidgets>
#include <QObject>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QRectF>
#include <QColor>
#include "GlobalDefine.h"
#include <QDebug>

struct  SItemRectPara
{
	float m_x;
	float m_y;
	float m_width;
	float m_height;
};

struct  SItemRectInfo  //tds
{
	EnumColorStatus m_itemColorStatus;//盘子状态
	int m_IdNum; //盘子号

	SItemRectInfo();
	void Init();
};


QString GetColorRefByDef(IN EnumColorStatus emyEumColorStatus);       //获取状态
EnumColorStatus GetColorStatusByColor(IN QColor qColor);       //获取盘子状态
class DiskExternItem : public QObject ,public QGraphicsItem          //绘制外圆
{
	Q_OBJECT

public:
	DiskExternItem();
	~DiskExternItem();
	QRectF boundingRect() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	void setItemNum(int itemnum);
	void setItemColor(QColor itemColor);
	void InitPaint(QPainter &paint);
	void draw_Small_Ellipse(SItemRectPara &CircleStr, QPainter &paint, QColor qcolor);
	void draw_Big_Ellipse(SItemRectPara &ExternCircle, SItemRectPara &InnerCircle, QPainter &paint);
	void draw_RectangleInfo(SItemRectPara &ExternCircle, QPainter &paint);
	void draw_text_line(SItemRectPara &CircleStr, QString Inputstr, QPainter &paint);
public:
	SItemRectInfo m_sItemRectInfo;
private:
	QColor m_color;
	int m_ItemNum;
};

class DiskItem : public QObject, public QGraphicsItem            //绘制小圆
{
	Q_OBJECT

public:
	DiskItem();
	~DiskItem();
	QRectF boundingRect() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	void setItemNum(int itemnum);//设置ID
	void setItemColor(QColor itemColor);//设置试管颜色
	void InitPaint(QPainter &paint);//初始化 防锯齿
	void setItemColorStatus(QColor itemColor);
	void draw_Small_Ellipse(SItemRectPara &CircleStr, QPainter &paint); //绘制圆
	void draw_text_line(SItemRectPara &CircleStr, QString Inputstr, QPainter &paint); //添加文字
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
public:
	SItemRectInfo m_sItemRectInfo;
private:
	QColor m_color;
	int m_ItemNum;
signals:
	void signalNofityInfo(SItemRectInfo qstr);
};
