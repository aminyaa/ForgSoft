#include <QtWidgets/QApplication>
#include <FrgMarine_MainWindow.hxx>
#include <QVTKOpenGLNativeWidget.h>
#include <FrgBase_ProgressBar.hxx>

int main(int argc, char** argv)
{
	// needed to ensure appropriate OpenGL context is created for VTK rendering.
	QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

	QApplication app(argc, argv);

	std::shared_ptr<ForgMarineLib::FrgMarine_MainWindow> mainWindow = std::make_shared<ForgMarineLib::FrgMarine_MainWindow>();

	mainWindow->SetQApplication(&app);
	mainWindow->Show(true);
	mainWindow->SetGeometry(80);
	//mainWindow->GetProgressBar()->SetProgressBarBusy();

	return app.exec();
}