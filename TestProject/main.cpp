#include "testproject.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestProject w;
	w.show();
	return a.exec();
}
