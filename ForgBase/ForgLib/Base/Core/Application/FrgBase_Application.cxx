//#include <FrgBase_Application.hxx>
//#include <FrgBase_ApplicationCore.hxx>
//#include <FrgBase_MainWindow.hxx>
//
//#include <QtWidgets/QMainWindow>
//#include <QtWidgets/QSplashScreen>
//#include <QtWidgets/QApplication>
//
//ForgBaseLib::FrgBase_Application::FrgBase_Application()
//{
//
//}
//
//ForgBaseLib::FrgBase_Application::~FrgBase_Application()
//{
//	delete theSplashScreen_;
//	theSplashScreen_ = nullptr;
//
//	delete theMainWindow_;
//	theMainWindow_ = nullptr;
//
//	delete theAppCore_;
//	theAppCore_ = nullptr;
//}
//
//ForgBaseLib::FrgBase_Application::Status ForgBaseLib::FrgBase_Application::Initialize(int argc, char * argv[])
//{
//	theAppCore_ = new FrgBase_ApplicationCore(argc, argv);
//
//	QApplication::instance()->installEventFilter(theAppCore_);
//
//#if 0
//	pqSettings *settings = this->PVApp->settings();
//	if (this->PVApp->getOptions()->GetDisableRegistry() == false &&
//		settings->value("GeneralSettings.ShowSplashScreen", true).toBool())
//	{
//		// Create and show the splash screen as the main window is being created.
//		QPixmap pixmap("");
//		this->Splash = new QSplashScreen(pixmap, Qt::WindowStaysOnTopHint);
//		this->Splash->setMask(pixmap.createMaskFromColor(QColor(Qt::transparent)));
//		this->Splash->show();
//	}
//#endif
//
//	// Create main window.
//	theMainWindow_ = new FrgBase_MainWindow;
//
//	theMainWindow_->show();
//	if (this->theSplashScreen_)
//	{
//		this->theSplashScreen_->finish(this->theMainWindow_);
//	}
//	return RunApplication;
//}