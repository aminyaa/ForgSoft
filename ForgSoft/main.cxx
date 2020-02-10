//#include <ForgGlobals.hxx>
//#include <ForgGuiMainWindow.hxx>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDockWidget>
//#include <QtWidgets/QTreeWidgetItem>
//#include <NihadMainWindow.hxx>
//#include <CustomWindow.hxx>
//#include <Console.hxx>
#include <ProgressWidget.hxx>

#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_PrptsWdgInt.hxx>
#include <FrgBase_MainWindow.hxx>

#include <FrgMarine_MainWindow.hxx>


int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	//ForgBaseLib::NihadMainWindow* w = FrgNew ForgBaseLib::NihadMainWindow();

	/*pqProgressWidget* progress = new pqProgressWidget(w);
	progress->setProgress("Warning", 100);
	progress->enableProgress(true);
	progress->enableAbort(true);
	progress->setMinimumSize(QSize(600, 400));
	progress->show();*/

	///*pqConsoleWidget* console = new pqConsoleWidget(w);
	//console->setMinimumSize(QSize(600, 400));
	//console->printCommand("Salam");
	//console->printCommand("Salam2");*/

	//QMainWindow* w = new QMainWindow;

	//QDockWidget* dockWidget = new QDockWidget("sdd", w);

	//ForgBaseLib::FrgBase_PropertiesPanel* panel = new ForgBaseLib::FrgBase_PropertiesPanel(new AA);
	//dockWidget->setWidget(panel);
	////panel->show();
	//w->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dockWidget);

	//QWidget* centralWidget = new QWidget(w);
	////centralWidget->installEventFilter(panel);

	//w->setCentralWidget(centralWidget);
	////w->installEventFilter(centralWidget);
	////dockWidget->installEventFilter(panel);
	////centralWidget->installEventFilter(panel);
	////w->installEventFilter(panel);

	///*for (int i = 0; i < panel->children().size(); i++)
	//	std::cout << panel->children().at(i)->metaObject()->className() << std::endl;*/

	//w->show();

	//ForgBaseLib::FrgBase_MainWindow* mainWindow = new ForgBaseLib::FrgBase_MainWindow;

	ForgMarineLib::FrgMarine_MainWindow* mainWindow = new ForgMarineLib::FrgMarine_MainWindow;

	mainWindow->show();

	//ForgBaseLib::CustomWindow ww;
	//ww.show();

	app.exec();
}

//#include <QtWidgets/QtWidgets>
//#include <QtConcurrent/QtConcurrent>
//
//#include <functional>
//
//using namespace QtConcurrent;
//
//int main(int argc, char **argv)
//{
//	QApplication app(argc, argv);
//
//	const int iterations = 2000;
//
//	// Prepare the vector.
//	QVector<int> vector;
//	for (int i = 0; i < iterations; ++i)
//		vector.append(i);
//
//	// Create a progress dialog.
//	QProgressDialog dialog;
//	dialog.setLabelText(QString("Progressing using %1 thread(s)...").arg(QThread::idealThreadCount()));
//
//	// Create a QFutureWatcher and connect signals and slots.
//	QFutureWatcher<void> futureWatcher;
//	QObject::connect(&futureWatcher, &QFutureWatcher<void>::finished, &dialog, &QProgressDialog::reset);
//	QObject::connect(&dialog, &QProgressDialog::canceled, &futureWatcher, &QFutureWatcher<void>::cancel);
//	QObject::connect(&futureWatcher, &QFutureWatcher<void>::progressRangeChanged, &dialog, &QProgressDialog::setRange);
//	QObject::connect(&futureWatcher, &QFutureWatcher<void>::progressValueChanged, &dialog, &QProgressDialog::setValue);
//
//	// Our function to compute
//	std::function<void(int&)> spin = [](int &iteration) {
//		const int work = 1000 * 1000 * 40;
//		volatile int v = 0;
//		for (int j = 0; j < work; ++j)
//			++v;
//
//		qDebug() << "iteration" << iteration << "in thread" << QThread::currentThreadId();
//	};
//
//	// Start the computation.
//	futureWatcher.setFuture(QtConcurrent::map(vector, spin));
//
//	// Display the dialog and start the event loop.
//	dialog.exec();
//
//	futureWatcher.waitForFinished();
//
//	// Query the future to check if was canceled.
//	qDebug() << "Canceled?" << futureWatcher.future().isCanceled();
//}