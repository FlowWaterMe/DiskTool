#include "DiskTool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DiskTool w;
	w.show();
	return a.exec();
}
