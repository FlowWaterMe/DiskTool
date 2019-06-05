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
	EnumColorStatus m_itemColorStatus;//����״̬
	int m_IdNum; //���Ӻ�

	SItemRectInfo();
	void Init();
};


QString GetColorRefByDef(IN EnumColorStatus emyEumColorStatus);       //��ȡ״̬
EnumColorStatus GetColorStatusByColor(IN QColor qColor);       //��ȡ����״̬
class DiskExternItem : public QObject ,public QGraphicsItem          //������Բ
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

class DiskItem : public QObject, public QGraphicsItem            //����СԲ
{
	Q_OBJECT

public:
	DiskItem();
	~DiskItem();
	QRectF boundingRect() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	void setItemNum(int itemnum);//����ID
	void setItemColor(QColor itemColor);//�����Թ���ɫ
	void InitPaint(QPainter &paint);//��ʼ�� �����
	void setItemColorStatus(QColor itemColor);
	void draw_Small_Ellipse(SItemRectPara &CircleStr, QPainter &paint); //����Բ
	void draw_text_line(SItemRectPara &CircleStr, QString Inputstr, QPainter &paint); //�������
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
