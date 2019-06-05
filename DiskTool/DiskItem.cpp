#include "DiskItem.h"

QString GetColorRefByDef(IN EnumColorStatus emyEumColorStatus)
{
	QString strRet;
	switch (emyEumColorStatus)
	{
	case eColorGreen:
		strRet = QStringLiteral("空闲");
		break;
	case eColorBlue:
		strRet = QStringLiteral("测试中");
		break;
	case eColorYellow:
		strRet = QStringLiteral("开盖中");
		break;
	case eColorRed:
		strRet = QStringLiteral("盘异常");
		break;
	default:
		strRet = QStringLiteral("空闲");
		break;
	}
	return strRet;

}

EnumColorStatus GetColorStatusByColor(IN QColor qColor)
{
	QString strRet;
	if (qColor == ColorBlue)
		return eColorBlue;
	else if (qColor == ColorGreen)
		return eColorGreen;
	else if (qColor == ColorRed)
		return eColorRed;
	else if (qColor == ColorYellow)
		return eColorYellow;
	else
		return eColorBlue;
}
SItemRectInfo::SItemRectInfo()
{
	Init();
}

void SItemRectInfo::Init()
{
	m_itemColorStatus = eColorNomal;
	m_IdNum = 0;
}


DiskExternItem::DiskExternItem()
	: m_color(ColorGreen)
	, m_ItemNum(0)
{
	//setToolTip(QString("QColor(%1, %2, %3)\n%4")
	//	.arg(m_color.red()).arg(m_color.green()).arg(m_color.blue())
	//	.arg(QStringLiteral("大圆环颜色代表圆盘状态")));//建立工具提示文字与指定控制项的关联
	//setCursor(Qt::OpenHandCursor);
	setAcceptedMouseButtons(Qt::LeftButton);
	m_sItemRectInfo.Init();

}

DiskExternItem::~DiskExternItem()
{

}
QRectF DiskExternItem::boundingRect()const
{
	return QRectF(-15.5, -15.5, 454, 454); //计算轮廓的垂直边界最小矩形
}

void DiskExternItem::setItemNum(int itemnum)
{
	m_ItemNum = itemnum;
}

void  DiskExternItem::setItemColor(QColor itemColor)
{
	m_color = itemColor;
}

void DiskExternItem::InitPaint(QPainter &paint)
{
	paint.setRenderHint(QPainter::Antialiasing, true);
}

void DiskExternItem::draw_Big_Ellipse(SItemRectPara &ExternCircle, SItemRectPara &InnerCircle, QPainter &paint)
{
	QPainterPath big;
	big.addEllipse(ExternCircle.m_x, ExternCircle.m_y, ExternCircle.m_width, ExternCircle.m_height);
	QPainterPath sma;
	sma.addEllipse(InnerCircle.m_x, InnerCircle.m_y, InnerCircle.m_width, InnerCircle.m_height);
	QPainterPath path;
	path = big - sma;
	paint.setBrush(QBrush(m_color));
	paint.drawPath(path);
}

void DiskExternItem::draw_Small_Ellipse(SItemRectPara &CircleStr, QPainter &paint,QColor qcolor)
{
	paint.setPen(QPen(Qt::black, 5));
	paint.setBrush(QBrush(qcolor));
	paint.drawEllipse(CircleStr.m_x, CircleStr.m_y, CircleStr.m_width, CircleStr.m_height);
}

void DiskExternItem::draw_RectangleInfo(SItemRectPara &ExternCircle,QPainter &paint)
{
	paint.drawRect(QRectF(ExternCircle.m_x, ExternCircle.m_y, ExternCircle.m_width, ExternCircle.m_height));
}

void DiskExternItem::draw_text_line(SItemRectPara &CircleStr, QString Inputstr, QPainter &paint)
{
	paint.setPen(QPen(Qt::black, 15));
	QFont font("Microsoft YaHei", 15, 75);
	paint.setFont(font);
	paint.drawText(CircleStr.m_x, CircleStr.m_y, QString("%1").arg(Inputstr));
}

void DiskExternItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	InitPaint(*painter);

	SItemRectPara itemExtRect = { -200,-200,400,400 }; //保持x y 与 wight height 成倍数关系
	SItemRectPara itemInnRect = { -180,-180,360,360 };

	draw_Big_Ellipse(itemExtRect, itemInnRect, *painter);

	for (int i = 0;i < 4;i++)
	{
		itemExtRect.m_width = 40;
		itemExtRect.m_height = 40;
		itemExtRect.m_x = -180;
		itemExtRect.m_y = 200 + i*itemExtRect.m_height;

		switch (i)
		{
		case 0:
		{
			draw_Small_Ellipse(itemExtRect, *painter, ColorGreen);
			itemExtRect.m_x = -130;
			itemExtRect.m_y = 230 + i*itemExtRect.m_height;
			itemExtRect.m_width = 50;
			itemExtRect.m_height = 40;

			draw_text_line(itemExtRect, GetColorRefByDef(EnumColorStatus(i)), *painter);
		}
		break;
		case 1:
		{
			draw_Small_Ellipse(itemExtRect, *painter, ColorBlue);
			itemExtRect.m_x = -130;
			itemExtRect.m_y = 230 + i*itemExtRect.m_height;
			itemExtRect.m_width = 50;
			itemExtRect.m_height = 40;

			draw_text_line(itemExtRect, GetColorRefByDef(EnumColorStatus(i)), *painter);
		}
		break;
		case 2:
		{
			draw_Small_Ellipse(itemExtRect, *painter, ColorYellow);
			itemExtRect.m_x = -130;
			itemExtRect.m_y = 230 + i*itemExtRect.m_height;
			itemExtRect.m_width = 50;
			itemExtRect.m_height = 40;

			draw_text_line(itemExtRect, GetColorRefByDef(EnumColorStatus(i)), *painter);
		}
		break;
		case 3:
		{
			draw_Small_Ellipse(itemExtRect, *painter, ColorRed);
			itemExtRect.m_x = -130;
			itemExtRect.m_y = 230 + i*itemExtRect.m_height;
			itemExtRect.m_width = 50;
			itemExtRect.m_height = 40;

			draw_text_line(itemExtRect, GetColorRefByDef(EnumColorStatus(i)), *painter);
		}
		break;
		default:
		{
			draw_Small_Ellipse(itemExtRect, *painter, ColorGreen);
			itemExtRect.m_x = -130;
			itemExtRect.m_y = 230 + i*itemExtRect.m_height;
			itemExtRect.m_width = 50;
			itemExtRect.m_height = 40;

			draw_text_line(itemExtRect, GetColorRefByDef(EnumColorStatus(i)), *painter);
		}
			break;
		}

	}

	update();
}


DiskItem::DiskItem()
	: m_color(ColorGreen)
	, m_ItemNum(0)
{
	setToolTip(QString("QColor(%1, %2, %3)\n%4")
		.arg(m_color.red()).arg(m_color.green()).arg(m_color.blue())
		.arg(QStringLiteral("点击小圆,进行试管信息配置,大圆环颜色代表圆盘状态")));
	setCursor(Qt::OpenHandCursor);
	setAcceptedMouseButtons(Qt::LeftButton);
	m_sItemRectInfo.Init();
}

DiskItem::~DiskItem()
{
}

QRectF DiskItem::boundingRect() const
{
	return QRectF(-15.5, -15.5, 44, 44);
}

void DiskItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	InitPaint(*painter);

	SItemRectPara itemRect = { -20,-20,40,40 };
	
	draw_Small_Ellipse(itemRect,  *painter);
	SItemRectPara itemRectText = { -6,3,40,40 };
	draw_text_line(itemRectText, QString::number(m_ItemNum), *painter);
	update();
}

void DiskItem::InitPaint(QPainter &paint)
{
	paint.setRenderHint(QPainter::Antialiasing, true);
}


void DiskItem::draw_Small_Ellipse(SItemRectPara &CircleStr, QPainter &paint)
{
	paint.setPen(QPen(Qt::black, 5));
	paint.setBrush(QBrush(m_color));
	paint.drawEllipse(CircleStr.m_x,CircleStr.m_y,CircleStr.m_width,CircleStr.m_height);
}

void DiskItem::draw_text_line(SItemRectPara &CircleStr, QString Inputstr, QPainter &paint)
{
	paint.setPen(QPen(Qt::black, 12));
	QFont font("Microsoft YaHei", 12, 75);
	paint.setFont(font);
	paint.drawText(CircleStr.m_x, CircleStr.m_y, Inputstr);
}


void DiskItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	setCursor(Qt::ClosedHandCursor); //tbd 携带信息
	QWidget * w = event->widget();
	qDebug() << m_ItemNum;
	emit signalNofityInfo(m_sItemRectInfo);
}

void DiskItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
		.length() < QApplication::startDragDistance()) {
		return;
	}

	QDrag *drag = new QDrag(event->widget());
	QMimeData *mime = new QMimeData;
	drag->setMimeData(mime);

	static int n = 0;
	if (n++ > 2 && (qrand() % 3) == 0) {
		QImage image(":/images/head.png");
		mime->setImageData(image);

		drag->setPixmap(QPixmap::fromImage(image).scaled(30, 40));
		drag->setHotSpot(QPoint(15, 30));

	}
	else {
		mime->setColorData(m_color);
		//mime->setText(QString("#%1%2%3")
		//	.arg(m_color.red(), 2, 16, QLatin1Char('0'))
		//	.arg(m_color.green(), 2, 16, QLatin1Char('0'))
		//	.arg(m_color.blue(), 2, 16, QLatin1Char('0')));
		mime->setText(QString::number(m_ItemNum));
		QPixmap pixmap(34, 34);
		pixmap.fill(Qt::white);

		QPainter painter(&pixmap);
		painter.translate(15, 15);
		painter.setRenderHint(QPainter::Antialiasing);
		paint(&painter, 0, 0);
		painter.end();

		pixmap.setMask(pixmap.createHeuristicMask());

		drag->setPixmap(pixmap);
		drag->setHotSpot(QPoint(15, 20));
	}

	drag->exec();
	setCursor(Qt::OpenHandCursor);
}

void DiskItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
	setCursor(Qt::OpenHandCursor);
}


void DiskItem::setItemNum(int itemnum)
{
	m_ItemNum = itemnum;
	m_sItemRectInfo.m_IdNum = m_ItemNum;
}

void  DiskItem::setItemColor(QColor itemColor)
{
	m_color = itemColor;

}

void  DiskItem::setItemColorStatus(QColor itemColor)
{
	m_sItemRectInfo.m_itemColorStatus = GetColorStatusByColor(itemColor);
}