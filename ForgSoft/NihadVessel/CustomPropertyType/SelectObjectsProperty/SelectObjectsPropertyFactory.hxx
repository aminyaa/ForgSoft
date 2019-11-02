#pragma once
#ifndef _SelectObjectsPropertyFactory_Header
#define _SelectObjectsPropertyFactory_Header

#include <SelectObjectsPropertyManager.hxx>

class QTreeWidgetItem;

BeginFrgBaseLib


template <typename T>
class SelectObjectsPropertyFactory : public QtAbstractEditorFactory<T>
{
	Q_OBJECT

public:

	SelectObjectsPropertyFactory(QObject* parent = FrgNullPtr, QTreeWidgetItem* treeItemSelection = FrgNullPtr);

	virtual ~SelectObjectsPropertyFactory();

protected:

	virtual void connectPropertyManager(T* manager){}

	virtual QWidget* createEditor(T* manager, QtProperty* property, QWidget* parent){}

	virtual void disconnectPropertyManager(T* manager){}

signals:

	//void ObjectsSelectedUpdate(QList<QTreeWidgetItem*> selectedItems);

private slots:

	//void slotPropertyChanged(QtProperty* property, const QList<QTreeWidgetItem*>& value);

	//void slotSetValue(const QList<QTreeWidgetItem*>& value);

	//void slotWidgetDestroyed(QObject* object);

private:

	//QMap<QtProperty*, QList<SelectObjectsPropertyWidget*> > theCreatedWidgets_;

	//QMap<SelectObjectsPropertyWidget*, QtProperty*> theWidgetToProperty_;

	//QTreeWidgetItem* theTreeItemSelection_;
};

class SelectObjectsPropertyManager;

template <typename T = SelectObjectsPropertyManager>
class SelectObjectsPropertyFactory : public QtAbstractEditorFactory<SelectObjectsPropertyManager>
{

	Q_OBJECT

public:

	SelectObjectsPropertyFactory(QObject* parent = FrgNullPtr, QTreeWidgetItem* treeItemSelection = FrgNullPtr);

	virtual ~SelectObjectsPropertyFactory();

protected:

	virtual void connectPropertyManager(SelectObjectsPropertyManager* manager);

	virtual QWidget* createEditor(SelectObjectsPropertyManager* manager, QtProperty* property, QWidget* parent);

	virtual void disconnectPropertyManager(SelectObjectsPropertyManager* manager);

signals:

	void ObjectsSelectedUpdate(QList<QTreeWidgetItem*> selectedItems);

private slots:

	void slotPropertyChanged(QtProperty* property, const QList<QTreeWidgetItem*>& value);

	void slotSetValue(const QList<QTreeWidgetItem*>& value);

	void slotWidgetDestroyed(QObject* object);

private:

	QMap<QtProperty*, QList<SelectObjectsPropertyWidget*> > theCreatedWidgets_;

	QMap<SelectObjectsPropertyWidget*, QtProperty*> theWidgetToProperty_;

	QTreeWidgetItem* theTreeItemSelection_;
};

EndFrgBaseLib

#endif // !_SelectObjectsPropertyFactory_Header
