#include <QVTKOpenGLNativeWidget.h>
#include <FrgBase_Application.hxx>
#include <MainWindow.hxx>

void SetSurfaceFormat();

int main(int argc, char** argv)
{
	SetSurfaceFormat();

	//vtkObject::GlobalWarningDisplayOff();

	ForgBaseLib::FrgBase_Application app(argc, argv);

	std::shared_ptr<MainWindow> mainWindow = std::make_shared<MainWindow>();
	app.SetParentMainWindow(mainWindow.get());

	mainWindow->SetQApplication(&app);
	mainWindow->Show(false);
	mainWindow->SetGeometry(80);

	return app.exec();
}

void SetSurfaceFormat()
{
	QSurfaceFormat fmt = QSurfaceFormat::defaultFormat();

	fmt.setRenderableType(QSurfaceFormat::OpenGL);
	fmt.setVersion(3, 2);
	fmt.setProfile(QSurfaceFormat::CoreProfile);
	fmt.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
	fmt.setRedBufferSize(1);
	fmt.setGreenBufferSize(1);
	fmt.setBlueBufferSize(1);
	fmt.setDepthBufferSize(1);
	fmt.setStencilBufferSize(1);
	fmt.setAlphaBufferSize(1);
	fmt.setStereo(false);
	fmt.setSamples(8);

	//fmt.setProfile(QSurfaceFormat::CompatibilityProfile);

	QSurfaceFormat::setDefaultFormat(fmt);
}