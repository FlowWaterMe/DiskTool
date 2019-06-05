#include "robot.h"
RobotPart::RobotPart(QGraphicsItem *parent)
	: QGraphicsObject(parent), color(Qt::lightGray), dragOver(false)
{
	setAcceptDrops(true);
}
//! [0]

//! [1]
void RobotPart::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
	//if (event->mimeData()->hasColor()) {
	//	event->setAccepted(true);
	//	dragOver = true;
	//	update();
	//}
	//else {
	//	event->setAccepted(false);
	//}
}
//! [1]

//! [2]
void RobotPart::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
	//Q_UNUSED(event);
	//dragOver = false;
	//update();
}
//! [2]

//! [3]
void RobotPart::dropEvent(QGraphicsSceneDragDropEvent *event)
{
	//dragOver = false;
	//if (event->mimeData()->hasColor())
	//	color = qvariant_cast<QColor>(event->mimeData()->colorData());
	//update();
}
robot::robot(QGraphicsItem *parent): color(Qt::lightGray)
{
	setAcceptDrops(true);
}

robot::~robot()
{

}

QRectF robot::boundingRect() const
{
	return QRectF(-50, -50, 100, 100);
}

void robot::paint(QPainter *painter,
	const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(painter);
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setPen(QPen(Qt::black, 5));
	painter->setBrush(QBrush(color));
	painter->drawEllipse(-50, -50,100, 100);

	painter->setPen(QPen(Qt::black, 15));
	QFont font("Microsoft YaHei", 15, 75);
	painter->setFont(font);
	painter->drawText(0, 0, QString("%1").arg(strText));
}

void robot::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
	if (event->mimeData()->hasColor()) {
		event->setAccepted(true);
		dragOver = true;
		update();
	}
	else {
		event->setAccepted(false);
	}
}
void robot::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
	Q_UNUSED(event);
	dragOver = false;
	update();
}
void robot::dropEvent(QGraphicsSceneDragDropEvent *event)
{
	dragOver = false;
	if (event->mimeData()->hasColor())
		color = qvariant_cast<QColor>(event->mimeData()->colorData());
	if (event->mimeData()->hasText())
		strText = qvariant_cast<QString>(event->mimeData()->text());
	update();
}