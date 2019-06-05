#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsObject>
#include <QtWidgets>
#include <QObject>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QRectF>
#include <QColor>
#include "GlobalDefine.h"
#include <QDebug>
#include <QDrag>
#include <QGraphicsSceneDragDropEvent>
#include <QEvent>
class RobotPart : public QGraphicsObject
{
	Q_OBJECT
		Q_INTERFACES(QGraphicsItem)
public:
	RobotPart(QGraphicsItem *parent = 0);

protected:
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
	void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
	void dropEvent(QGraphicsSceneDragDropEvent *event) override;

	QColor color;
	bool dragOver;
};


class robot : public QObject,public QGraphicsItem
{
	Q_OBJECT
		Q_INTERFACES(QGraphicsItem)
public:
	robot(QGraphicsItem *parent = 0);
	~robot();
	QRectF boundingRect() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
	void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
	void dropEvent(QGraphicsSceneDragDropEvent *event) override;
private:
	QColor color;
	QString strText;
	bool dragOver;
};

#endif // ROBOT_H
