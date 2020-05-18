#include <FrgBase_ProgressBar.hxx>
#include <FrgBase_MainWindow.hxx>

#include <QtCore/QLocale>

ForgBaseLib::FrgBase_ProgressBar::FrgBase_ProgressBar(FrgBase_MainWindow* parentMainWindow)
	: QProgressBar(parentMainWindow)
{
	QString style = "QProgressBar:horizontal{"
		"background:#bdc1c9;"
		"border: 1px solid #b6b6b6;"
		"text-align: center;"
		"padding: 1px;"
		"border-radius: 4px;}"
		"QProgressBar::Chunk:horizontal{"
		"background-color: qlineargradient(spread:pad, x1:1, y1:0.545, x2:1, y2:0, stop:0 #3874f2, stop:1 #5e90fa);"
		"border-radius: 3px;}";

	this->setStyleSheet(style);
	this->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

	this->setFixedHeight(12);
	this->setRange(0, 1);
}

void ForgBaseLib::FrgBase_ProgressBar::SetProgressBarBusy(bool condition)
{
	if (condition)
		this->setRange(0, 0);
	else
		this->setRange(0, 1);
}