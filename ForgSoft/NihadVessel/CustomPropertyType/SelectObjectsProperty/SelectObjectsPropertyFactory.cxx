#include <SelectObjectsPropertyFactory.hxx>
#include <SelectObjectsPropertyWidget.hxx>

ForgBaseLib::SelectObjectsPropertyFactory::SelectObjectsPropertyFactory(QObject* parent, QTreeWidgetItem* treeItemSelection)
	: QtAbstractEditorFactory<SelectObjectsPropertyManager>(parent)
	, theTreeItemSelection_(treeItemSelection)
{

}

ForgBaseLib::SelectObjectsPropertyFactory::~SelectObjectsPropertyFactory()
{

}

void ForgBaseLib::SelectObjectsPropertyFactory::connectPropertyManager(SelectObjectsPropertyManager* manager)
{
	connect(manager, SIGNAL(valueChanged(QtProperty*, const QList<QTreeWidgetItem*>&)),
		this, SLOT(slotPropertyChanged(QtProperty*, const QList<QTreeWidgetItem*>&)));
}

QWidget* ForgBaseLib::SelectObjectsPropertyFactory::createEditor(SelectObjectsPropertyManager* manager, QtProperty* property, QWidget* parent)
{
	SelectObjectsPropertyWidget* widget = FrgNew SelectObjectsPropertyWidget(parent, theTreeItemSelection_);
	widget->SetObjectsLabel(manager->value(property));

	theCreatedWidgets_[property].append(widget);
	theWidgetToProperty_[widget] = property;

	connect(widget, SIGNAL(LabelChanged(const QList<QTreeWidgetItem*>&)),
		this, SLOT(slotSetValue(const QList<QTreeWidgetItem*>&)));
	connect(widget, SIGNAL(destroyed(QObject*)),
		this, SLOT(slotWidgetDestroyed(QObject*)));
	return widget;
}

void ForgBaseLib::SelectObjectsPropertyFactory::disconnectPropertyManager(SelectObjectsPropertyManager* manager)
{
	disconnect(manager, SIGNAL(valueChanged(QtProperty*, const QList<QTreeWidgetItem*>&)),
		this, SLOT(slotPropertyChanged(QtProperty*, const QList<QTreeWidgetItem*>&)));
}

void ForgBaseLib::SelectObjectsPropertyFactory::slotPropertyChanged(QtProperty* property, const QList<QTreeWidgetItem*>& value)
{
	if (!theCreatedWidgets_.contains(property))
		return;

	QList<SelectObjectsPropertyWidget*> widgets = theCreatedWidgets_[property];
	QListIterator<SelectObjectsPropertyWidget*> itWidget(widgets);
	while (itWidget.hasNext())
		itWidget.next()->SetObjectsLabel(value);
}

void ForgBaseLib::SelectObjectsPropertyFactory::slotSetValue(const QList<QTreeWidgetItem*>& value)
{
	QObject* object = sender();
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

void ForgBaseLib::SelectObjectsPropertyFactory::slotWidgetDestroyed(QObject* object)
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