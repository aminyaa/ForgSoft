#include <ForgGlobals.hxx>
//#include <ForgGuiMainWindow.hxx>
#include <QtWidgets/QApplication>
#include <FrgBaseMainWindow.hxx>


int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	ForgBaseLib::FrgBaseMainWindow w;
	w.show();
	app.exec();
}