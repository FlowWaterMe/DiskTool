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
	eColorGreen = eColorNomal, //���� �ظ�
	eColorBlue,				   //����
	eColorYellow,			   //����
	eColorRed,				   //�쳣
	eColorabNomal = eColorRed
};
