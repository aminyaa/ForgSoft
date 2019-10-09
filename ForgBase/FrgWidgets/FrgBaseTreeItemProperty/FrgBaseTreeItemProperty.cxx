#include <FrgBaseTreeItemProperty.hxx>
#include <FrgBaseTreeItem.hxx>

ForgBaseLib::FrgBaseTreeItemProperty::FrgBaseTreeItemProperty(FrgBaseTreeItem* parent)
	: theParentTreeItem_(parent)
{
	thePropertyBrowser_ = FrgNew QtTreePropertyBrowser;

	theVariantPropertyManager_ = FrgNew QtVariantPropertyManager;
	theVariantEditorFactory_ = FrgNew QtVariantEditorFactory;

	thePropertyBrowser_->setFactoryForManager(theVariantPropertyManager_, theVariantEditorFactory_);

	AddTopProperty("Properties");
	AddPropertyString("Properties", "Name", theParentTreeItem_->text(0));
	AddTopProperty("Parameters");
	AddPropertyDouble("Parameters", "Length", 100.05);
	AddPropertyDouble("Parameters", "Beam", 25.2);
	AddPropertyDouble("Parameters", "Draft", 8.6);
	AddTopProperty("Color");
	AddPropertyInt("Color", "Red", 255);
	AddPropertyInt("Color", "Green", 0);
	AddPropertyInt("Color", "Blue", 150);
	AddPropertyPointF("Color", "Point 1", QPointF(2.5, 3.5));

	GetProperty("Name")->setEnabled(FrgFalse);
}

QtProperty* ForgBaseLib::FrgBaseTreeItemProperty::GetTopProperty(const FrgString& name)
{
	for (int i = 0; i < theTopProperties_.size(); i++)
	{
		if (theTopProperties_.at(i)->propertyName() == name)
			return theTopProperties_.at(i);
	}

	return FrgNullPtr;
}

QtProperty* ForgBaseLib::FrgBaseTreeItemProperty::GetProperty(const FrgString& name)
{
	for (int i = 0; i < theTopProperties_.size(); i++)
	{
		for (int j = 0; j < theTopProperties_.at(i)->subProperties().size(); j++)
		{
			if (theTopProperties_.at(i)->subProperties().at(j)->propertyName() == name)
				return theTopProperties_.at(i)->subProperties().at(j);
		}
	}

	return FrgNullPtr;
}

void ForgBaseLib::FrgBaseTreeItemProperty::AddTopProperty(const FrgString& name)
{
	QtProperty* topItem = theVariantPropertyManager_->addProperty(QtVariantPropertyManager::groupTypeId(), QLatin1String(name.toLocal8Bit().data()));
	theTopProperties_.push_back(topItem);

	thePropertyBrowser_->addProperty(topItem);
	thePropertyBrowser_->setPropertiesWithoutValueMarked(FrgTrue);
	thePropertyBrowser_->setRootIsDecorated(FrgFalse);
}

QtVariantProperty* ForgBaseLib::FrgBaseTreeItemProperty::AddProperty(const FrgString& topProperty, FrgInt propertyType, const FrgString& name)
{
	QtVariantProperty * item = theVariantPropertyManager_->addProperty(propertyType, QLatin1String(name.toLocal8Bit().data()));
	if(QtProperty* topItem = GetTopProperty(topProperty))
		topItem->addSubProperty(item);

	return item;
}

//void ForgBaseLib::FrgBaseTreeItemProperty::AddPropertyString(const FrgString& topProperty, const FrgString& name, const FrgString& value)
//{
//	QtVariantProperty* item = AddProperty(topProperty, QVariant::String, name);
//
//	item->setValue(value);
//	item->setPropertyId(item->propertyName());
//}
//
//void ForgBaseLib::FrgBaseTreeItemProperty::AddPropertyDouble(const FrgString& topProperty, const FrgString& name, FrgDouble value)
//{
//	QtVariantProperty* item = AddProperty(topProperty, QVariant::Double, name);
//
//	item->setValue(value);
//	item->setPropertyId(item->propertyName());
//}
//
//void ForgBaseLib::FrgBaseTreeItemProperty::AddPropertyInt(const FrgString& topProperty, const FrgString& name, FrgInt value)
//{
//	QtVariantProperty* item = AddProperty(topProperty, QVariant::Int, name);
//
//	item->setValue(value);
//	item->setPropertyId(item->propertyName());
//}

void ForgBaseLib::FrgBaseTreeItemProperty::SetEnabled(const FrgString& name, FrgBool condition)
{
	GetProperty(name)->setEnabled(condition);
}