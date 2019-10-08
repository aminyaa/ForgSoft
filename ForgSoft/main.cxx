#include <ForgGlobals.hxx>
//#include <ForgGuiMainWindow.hxx>
#include <QtWidgets/QApplication>
#include <FrgMainWindow.hxx>


int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	ForgBaseLib::FrgMainWindow w;
	w.show();
	app.exec();
}