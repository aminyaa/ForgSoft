#include <ForgGlobals.hxx>
#include <ForgGuiMainWindow.hxx>
#include <QtWidgets/QApplication>


int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	ForgGuiLib::ForgGuiMainWindow w;
	w.show();
	app.exec();
}