#include <FrgBase_Dlg.hxx>
#include <FrgBase_MainWindow.hxx>

ForgBaseLib::FrgBase_Dlg::FrgBase_Dlg
(
	FrgBase_MainWindow* parentMainWindow
)
	: QDialog(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{

}