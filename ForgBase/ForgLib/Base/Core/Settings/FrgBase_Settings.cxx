#include <FrgBase_Settings.hxx>

#include <QtCore/QCoreApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDockWidget>
#include <QtCore/QFile>
#include <QtWidgets/QMainWindow>

ForgBaseLib::FrgBase_Settings::FrgBase_Settings
(
	const QString & organization,
	const QString & application,
	QObject * parent
)
	: SuperClass(organization, application, parent)
{

}

ForgBaseLib::FrgBase_Settings::FrgBase_Settings
(
	Scope scope,
	const QString & organization,
	const QString & application,
	QObject * parent
)
	: SuperClass(scope, organization, application, parent)
{

}

ForgBaseLib::FrgBase_Settings::FrgBase_Settings
(
	Format format,
	Scope scope,
	const QString & organization,
	const QString & application,
	QObject * parent
)
	: SuperClass(format, scope, organization, application, parent)
{

}

ForgBaseLib::FrgBase_Settings::FrgBase_Settings
(
	const QString & fileName,
	Format format,
	QObject * parent
)
	: SuperClass(fileName, format, parent)
{

}

ForgBaseLib::FrgBase_Settings::FrgBase_Settings
(
	QObject * parent
)
	: SuperClass(parent)
{

}

ForgBaseLib::FrgBase_Settings::~FrgBase_Settings()
{

}

QString ForgBaseLib::FrgBase_Settings::backup(const QString & argName)
{
	this->sync();

	QString fname = argName.isEmpty() ? (this->fileName() + ".bak") : argName;
	QFile::remove(fname);
	return QFile::copy(this->fileName(), fname) ? fname : QString();
}

void ForgBaseLib::FrgBase_Settings::alertSettingsModified()
{
	emit this->modified();
}

void ForgBaseLib::FrgBase_Settings::saveState
(
	const QDialog & dialog,
	const QString & key
)
{
	this->beginGroup(key);
	this->setValue("Position", dialog.pos());
	this->setValue("Size", dialog.size());
	// let's add a PID to avoid restoring dialog position across different sessions
	this->setValue("PID", QCoreApplication::applicationPid());
	this->endGroup();
}

void ForgBaseLib::FrgBase_Settings::restoreState
(
	const QString & key,
	QDialog & dialog
)
{
	this->beginGroup(key);

	if (this->contains("Size"))
	{
		dialog.resize(this->value("Size").toSize());
	}

	// restore position only if it is the same process.
	if (this->value("PID").value<qint64>() == QCoreApplication::applicationPid() &&
		this->contains("Position"))
	{
		dialog.move(this->value("Position").toPoint());
	}
	this->endGroup();
}

void ForgBaseLib::FrgBase_Settings::saveState
(
	const QMainWindow & window,
	const QString & key
)
{
	this->beginGroup(key);
	this->setValue("Size", window.size());
	this->setValue("Layout", window.saveState());
	this->endGroup();
}

void ForgBaseLib::FrgBase_Settings::restoreState
(
	const QString & key,
	QMainWindow & window
)
{
	this->beginGroup(key);

	if (this->contains("Size"))
	{
		window.resize(this->value("Size").toSize());
	}

	if (this->contains("Layout"))
	{
		window.restoreState(this->value("Layout").toByteArray());

		QList<QDockWidget*> dockWidgets = window.findChildren<QDockWidget*>();
		foreach(QDockWidget* dock_widget, dockWidgets)
		{
			if (dock_widget->isFloating() == true)
			{
				sanityCheckDock(dock_widget);
			}
		}
	}

	this->endGroup();
}

void ForgBaseLib::FrgBase_Settings::sanityCheckDock
(
	QDockWidget * dock_widget
)
{
	QDesktopWidget desktop;
	int screen = -1;
	if (NULL == dock_widget)
	{
		return;
	}

	QPoint dockTopLeft = dock_widget->pos();
	QRect dockRect(dockTopLeft, dock_widget->size());

	QRect geometry = QRect(dockTopLeft, dock_widget->frameSize());
	int titleBarHeight = geometry.height() - dockRect.height();

	screen = desktop.screenNumber(dock_widget);
	if (screen == -1) // Dock is at least partially on a screen
	{
		screen = desktop.screenNumber(dockTopLeft);
	}

	QRect screenRect = desktop.availableGeometry(screen);
	QRect desktopRect = desktop.availableGeometry(); // SHould give us the entire Desktop geometry
	// Ensure the top left corner of the window is on the screen
	if (!screenRect.contains(dockTopLeft))
	{
		// Are we High?
		if (dockTopLeft.y() < screenRect.y())
		{
			dock_widget->move(dockRect.x(), screenRect.y());
			dockTopLeft = dock_widget->pos();
			dockRect = QRect(dockTopLeft, dock_widget->frameSize());
		}
		// Are we low
		if (dockTopLeft.y() > screenRect.y() + screenRect.height())
		{
			dock_widget->move(dockRect.x(), screenRect.y() + screenRect.height() - 20);
			dockTopLeft = dock_widget->pos();
			dockRect = QRect(dockTopLeft, dock_widget->frameSize());
		}
		// Are we left
		if (dockTopLeft.x() < screenRect.x())
		{
			dock_widget->move(screenRect.x(), dockRect.y());
			dockTopLeft = dock_widget->pos();
			dockRect = QRect(dockTopLeft, dock_widget->frameSize());
		}
		// Are we right
		if (dockTopLeft.x() > screenRect.x() + screenRect.width())
		{
			dock_widget->move(screenRect.x() + screenRect.width() - dockRect.width(), dockRect.y());
			dockTopLeft = dock_widget->pos();
			dockRect = QRect(dockTopLeft, dock_widget->frameSize());
		}

		dockTopLeft = dock_widget->pos();
		dockRect = QRect(dockTopLeft, dock_widget->frameSize());
	}

	if (!desktopRect.contains(dockRect))
	{
		// Are we too wide
		if (dockRect.x() + dockRect.width() > screenRect.x() + screenRect.width())
		{
			if (screenRect.x() + screenRect.width() - dockRect.width() > screenRect.x())
			{
				// Move dock side to side
				dockRect.setX(screenRect.x() + screenRect.width() - dockRect.width());
				dock_widget->move(dockRect.x(), dockRect.y());
				dockTopLeft = dock_widget->pos();
				dockRect = QRect(dockTopLeft, dock_widget->frameSize());
			}
			else
			{
				// Move dock side to side + resize to fit
				dockRect.setX(screenRect.x() + screenRect.width() - dockRect.width());
				dockRect.setWidth(screenRect.width());
				dock_widget->resize(dockRect.width(), dockRect.height());
				dock_widget->move(dockRect.x(), dockRect.y());
				dockTopLeft = dock_widget->pos();
				dockRect = QRect(dockTopLeft, dock_widget->frameSize());
			}
		}

		dockTopLeft = dock_widget->pos();
		dockRect = QRect(dockTopLeft, dock_widget->frameSize());
		// Are we too Tall
		if (dockRect.y() + dockRect.height() > screenRect.y() + screenRect.height())
		{
			// See if we can move it more on screen so that the entire dock is on screen
			if (screenRect.y() + screenRect.height() - dockRect.height() > screenRect.y())
			{
				// Move dock up
				dockRect.setY(screenRect.y() + screenRect.height() - dockRect.height());
				dock_widget->move(dockRect.x(), dockRect.y());
				dockTopLeft = dock_widget->pos();
				dockRect = QRect(dockTopLeft, dock_widget->frameSize());
			}
			else
			{
				// Move dock up + resize to fit
				dock_widget->resize(dockRect.width(), screenRect.height() - titleBarHeight);
				dock_widget->move(dockRect.x(), screenRect.y());
				dockTopLeft = dock_widget->pos();
				dockRect = QRect(dockTopLeft, dock_widget->frameSize());
			}
		}
	}
}