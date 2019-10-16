#pragma once
#ifndef _SelectObjectsPropertyManager_Header
#define _SelectObjectsPropertyManager_Header

#include <FrgBaseGlobals.hxx>

#include <qtpropertybrowser.h>

#include <QtCore/QMap>

class QTreeWidgetItem;

BeginFrgBaseLib

class SelectObjectsPropertyManager : public QtAbstractPropertyManager
{

	Q_OBJECT

public:

	SelectObjectsPropertyManager(QObject* parent = FrgNullPtr);

	QList<QTreeWidgetItem*> value(const QtProperty* property) const;

public slots:

	void setValue(QtProperty* property, const QList<QTreeWidgetItem*>& val);

signals:

	void valueChanged(QtProperty* property, const QList<QTreeWidgetItem*>& val);

protected:

	virtual void initializeProperty(QtProperty* property) { theValues[property] = Data(); }

	virtual void uninitializeProperty(QtProperty* property) { theValues.remove(property); }

private:

	struct Data
	{
		QList<QTreeWidgetItem*> theObjects_;
	};

	QMap<const QtProperty*, Data> theValues;
};

EndFrgBaseLib

#endif // !_SelectObjectsPropertyManager_Header
