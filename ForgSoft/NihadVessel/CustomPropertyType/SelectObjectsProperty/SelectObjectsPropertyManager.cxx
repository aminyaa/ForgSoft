#include <SelectObjectsPropertyManager.hxx>

ForgBaseLib::SelectObjectsPropertyManager::SelectObjectsPropertyManager(QObject* parent)
	: QtAbstractPropertyManager(parent)
{

}

QList<QTreeWidgetItem*> ForgBaseLib::SelectObjectsPropertyManager::value(const QtProperty* property) const
{
	if (!theValues.contains(property))
	{
		QList<QTreeWidgetItem*> output;
		return output;
	}
	return theValues[property].theObjects_;
}

void ForgBaseLib::SelectObjectsPropertyManager::setValue(QtProperty* property, const QList<QTreeWidgetItem*>& val)
{
	if (!theValues.contains(property))
		return;

	Data data = theValues[property];

	if (data.theObjects_ == val)
		return;

	data.theObjects_ = val;

	theValues[property] = data;

	emit propertyChanged(property);
	emit valueChanged(property, data.theObjects_);
}