//#include <ForgGlobals.hxx>
//#include <ForgGuiMainWindow.hxx>
#include <QtWidgets/QApplication>
#include <NihadMainWindow.hxx>

#include <NihadVesselSceneTreeItem.hxx>


int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	ForgBaseLib::NihadMainWindow w;

	w.show();
	app.exec();
}