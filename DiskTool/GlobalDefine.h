#pragma once
#define ItemCount 20
#define ColorBlue QColor(11, 157, 200)
#define ColorYellow QColor(204, 183, 63)
#define ColorGreen QColor(0,255,0)
#define ColorRed QColor(255,0,0)
#define ColorGray QColor(120,117,98)
#define ColorWhite QColor(255,255,255)
#define TwoPi 6.28
#include <QObject>
#include <QString>
enum EnumColorStatus
{
	eColorNomal,
	eColorGreen = eColorNomal, //正常 关盖
	eColorBlue,				   //测试
	eColorYellow,			   //开盖
	eColorRed,				   //异常
	eColorabNomal = eColorRed
};
