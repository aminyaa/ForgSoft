#pragma once
#ifndef _SelectObjectsPropertyFactory_Header
#define _SelectObjectsPropertyFactory_Header

#include <SelectObjectsPropertyManager.hxx>
#include <SelectObjectsPropertyWidget.hxx>

class QTreeWidgetItem;

BeginFrgBaseLib

template <class T>
class SelectObjectsPropertyFactory : public QObject, public QtAbstractEditorFactory<T>
{
	//Q_OBJECT

public:

	SelectObjectsPropertyFactory() {}

	//SelectObjectsPropertyFactory(QObject* parent = FrgNullPtr, QTreeWidgetItem* treeItemSelection = FrgNullPtr);

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

template <>
class SelectObjectsPropertyFactory<SelectObjectsPropertyManager> : public QObject, public QtAbstractEditorFactory<SelectObjectsPropertyManager>
{

	//Q_OBJECT

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

inline SelectObjectsPropertyFactory<SelectObjectsPropertyManager>::SelectObjectsPropertyFactory
(
	QObject* parent,
	QTreeWidgetItem* treeItemSelection
)
	: QtAbstractEditorFactory<SelectObjectsPropertyManager>(parent)
	, theTreeItemSelection_(treeItemSelection)
{

}

inline SelectObjectsPropertyFactory<SelectObjectsPropertyManager>::~SelectObjectsPropertyFactory()
{

}

inline void SelectObjectsPropertyFactory<SelectObjectsPropertyManager>::connectPropertyManager(SelectObjectsPropertyManager* manager)
{
	QObject::connect(manager, SIGNAL(valueChanged(QtProperty*, const QList<QTreeWidgetItem*>&)),
		this, SLOT(slotPropertyChanged(QtProperty*, const QList<QTreeWidgetItem*>&)));
}

QWidget* SelectObjectsPropertyFactory<SelectObjectsPropertyManager>::createEditor(SelectObjectsPropertyManager* manager, QtProperty* property, QWidget* parent)
{
	SelectObjectsPropertyWidget* widget = FrgNew SelectObjectsPropertyWidget(parent, theTreeItemSelection_);
	widget->SetObjectsLabel(manager->value(property));

	theCreatedWidgets_[property].append(widget);
	theWidgetToProperty_[widget] = property;

	QObject::connect(widget, SIGNAL(LabelChanged(const QList<QTreeWidgetItem*>&)),
		this, SLOT(slotSetValue(const QList<QTreeWidgetItem*>&)));
	QObject::connect(widget, SIGNAL(destroyed(QObject*)),
		this, SLOT(slotWidgetDestroyed(QObject*)));
	QObject::connect(widget, SIGNAL(ObjectsSelectedUpdate(QList<QTreeWidgetItem*>)),
		this, SIGNAL(ObjectsSelectedUpdate(QList<QTreeWidgetItem*>)));
	return widget;
}

inline void SelectObjectsPropertyFactory<SelectObjectsPropertyManager>::disconnectPropertyManager(SelectObjectsPropertyManager* manager)
{
	QObject::disconnect(manager, SIGNAL(valueChanged(QtProperty*, const QList<QTreeWidgetItem*>&)),
		this, SLOT(slotPropertyChanged(QtProperty*, const QList<QTreeWidgetItem*>&)));
}

inline void SelectObjectsPropertyFactory<SelectObjectsPropertyManager>::slotPropertyChanged(QtProperty* property, const QList<QTreeWidgetItem*>& value)
{
	if (!theCreatedWidgets_.contains(property))
		return;

	QList<SelectObjectsPropertyWidget*> widgets = theCreatedWidgets_[property];
	QListIterator<SelectObjectsPropertyWidget*> itWidget(widgets);
	while (itWidget.hasNext())
		itWidget.next()->SetObjectsLabel(value);
}

inline void SelectObjectsPropertyFactory<SelectObjectsPropertyManager>::slotSetValue(const QList<QTreeWidgetItem*>& value)
{
	QObject* object = QObject::sender();
	QMap<SelectObjectsPropertyWidget*, QtProperty*>::ConstIterator itWidget =
		theWidgetToProperty_.constBegin();
	while (itWidget != theWidgetToProperty_.constEnd()) {
		if (itWidget.key() == object) {
			QtProperty* property = itWidget.value();
			SelectObjectsPropertyManager* manager = propertyManager(property);
			if (!manager)
				return;
			manager->setValue(property, value);
			return;
		}
		itWidget++;
	}
}

inline void SelectObjectsPropertyFactory<SelectObjectsPropertyManager>::slotWidgetDestroyed(QObject* object)
{
	QMap<SelectObjectsPropertyWidget*, QtProperty*>::ConstIterator itWidget =
		theWidgetToProperty_.constBegin();
	while (itWidget != theWidgetToProperty_.constEnd()) {
		if (itWidget.key() == object) {
			SelectObjectsPropertyWidget* editor = itWidget.key();
			QtProperty* property = itWidget.value();
			theWidgetToProperty_.remove(editor);
			theCreatedWidgets_[property].removeAll(editor);
			if (theCreatedWidgets_[property].isEmpty())
				theCreatedWidgets_.remove(property);
			return;
		}
		itWidget++;
	}
}

EndFrgBaseLib

#endif // !_SelectObjectsPropertyFactory_Header
