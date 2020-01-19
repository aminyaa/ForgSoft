//#include <ForgGlobals.hxx>
//#include <ForgGuiMainWindow.hxx>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
//#include <QtWidgets/QTreeWidgetItem>
//#include <NihadMainWindow.hxx>
//#include <CustomWindow.hxx>
//#include <Console.hxx>
#include <ProgressWidget.hxx>

#include <FrgBase_PropertiesPanel.hxx>

class A : public QMainWindow 
{
	//Q_OBJECT
	Q_PROPERTY(int age READ getAge WRITE setAge)

public:

	A(QWidget* parent = nullptr) : QMainWindow(parent) { theAge_ = 26; }

	int getAge() const { return theAge_; }
	void setAge(int age) { theAge_ = age; }

private:

	int theAge_;
};

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

	QMainWindow* w = new QMainWindow;
	AA* aa = new AA;

	ForgBaseLib::FrgBase_PropertiesPanel* panel = new ForgBaseLib::FrgBase_PropertiesPanel(aa);
	panel->show();

	w->setCentralWidget(panel);
	w->show();

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