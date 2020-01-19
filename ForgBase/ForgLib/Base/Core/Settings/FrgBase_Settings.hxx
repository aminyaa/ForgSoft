#pragma once
#ifndef _FrgBase_Settings_Header
#define _FrgBase_Settings_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>
#include <QtCore/QSettings>

class QDialog;
class QMainWindow;
class QDockWidget;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Settings
	: public QSettings
	, public FrgBase_Object
{
	Q_OBJECT
	typedef QSettings SuperClass;

public:

	FrgBase_Settings
	(
		const QString& organization,
		const QString& application = QString(),
		QObject* parent = nullptr
	);

	FrgBase_Settings
	(
		Scope scope,
		const QString& organization,
		const QString& application = QString(),
		QObject* parent = nullptr
	);

	FrgBase_Settings
	(
		Format format,
		Scope scope,
		const QString& organization,
		const QString& application = QString(),
		QObject* parent = nullptr
	);

	FrgBase_Settings
	(
		const QString& fileName,
		Format format,
		QObject* parent = nullptr
	);

	FrgBase_Settings
	(
		QObject* parent = nullptr
	);

	~FrgBase_Settings() override;

	void saveState(const QMainWindow& window, const QString& key);
	void saveState(const QDialog& dialog, const QString& key);

	void restoreState(const QString& key, QMainWindow& window);
	void restoreState(const QString& key, QDialog& dialog);

	/**
  * Calling this method will cause the modified signal to be emitted.
  */
	void alertSettingsModified();

	/**
  * Creates a new backup file for the current settings.
  * If `filename` is empty, then a backup file name will automatically be
  * picked. On success returns the backup file name, on failure an empty string
  * is returned.
  */
	QString backup(const QString& filename = QString());

private:
	/**
	* ensure that when window state is being loaded, if dock windows are
	* beyond the viewport, we correct them.
	*/
	void sanityCheckDock(QDockWidget* dock_widget);
signals:
	void modified();
};

EndForgBaseLib

#endif // !_FrgBase_Settings_Header
