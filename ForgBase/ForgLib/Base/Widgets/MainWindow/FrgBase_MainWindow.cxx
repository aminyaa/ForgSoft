#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_MenuFile.hxx>
#include <FrgBase_MenuEdit.hxx>
#include <FrgBase_MenuTools.hxx>
#include <FrgBase_MenuWindow.hxx>
#include <FrgBase_MenuHelp.hxx>

ForgBaseLib::FrgBase_MainWindow::FrgBase_MainWindow
(
	QWidget* parent
)
	: QMainWindow(parent)
{
	this->window()->setWindowIcon(QIcon(ICONLogo));

	FormMenus();

	this->setCentralWidget(FrgNew QWidget);
	SetMainWindowStyleSheet();
}

void ForgBaseLib::FrgBase_MainWindow::FormMenus()
{
	theMainWindowMenus_ = new MainWindowMenus_Struct;

	/*theMainWindowMenus_->theFileMenu_ = new FrgBase_MenuFile(this);
	theMainWindowMenus_->theEditMenu_ = new FrgBase_MenuEdit(this);
	theMainWindowMenus_->theToolsMenu_ = new FrgBase_MenuTools;
	theMainWindowMenus_->theWindowMenu_ = new FrgBase_MenuWindow;
	theMainWindowMenus_->theHelpMenu_ = new FrgBase_MenuHelp;*/
}

void ForgBaseLib::FrgBase_MainWindow::SetMainWindowStyleSheet()
{
	FrgString seperatorStyle = "QMainWindow::separator {"
		"  height: 5px;"
		"  width:  5px;"
		"}"
		"QMainWindow::separator:hover{"
		"  background : #c2c2c2;"
		"}"
		"QMainWindow::separator:horizontal{"
		"  border-top: 1px solid #6b9cb8;"
		"  border-bottom: 1px solid #6b9cb8;"
		"}"
		"QMainWindow::separator:vertical{"
		"  border-left: 1px solid #6b9cb8;"
		"  border-right: 1px solid #6b9cb8;"
		"}";
	AddMainWindowStyleSheet(seperatorStyle);

	FrgString statusBarStyle = "QStatusBar {"
		"		border-top: 1px solid #6b9cb8;"
		"}";
	AddMainWindowStyleSheet(statusBarStyle);
}

void ForgBaseLib::FrgBase_MainWindow::AddMainWindowStyleSheet(const QString& styleSheet)
{
	QString str = this->styleSheet();
	str += styleSheet;
	this->setStyleSheet(str);
}