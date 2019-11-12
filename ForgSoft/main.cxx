//#include <ForgGlobals.hxx>
//#include <ForgGuiMainWindow.hxx>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTreeWidgetItem>
#include <NihadMainWindow.hxx>


int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	ForgBaseLib::NihadMainWindow* w = FrgNew ForgBaseLib::NihadMainWindow();

	w->show();
	app.exec();
}