#include <FrgBaseTreeItemProperties.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseMainWindow.hxx>

ForgBaseLib::FrgBaseTreeItemProperties::FrgBaseTreeItemProperties(FrgBaseTreeItem* parent)
	: theParentTreeItem_(parent)
{
	thePropertyBrowser_ = FrgNew QtTreePropertyBrowser;

	theVariantPropertyManager_ = FrgNew QtVariantPropertyManager;
	theVariantEditorFactory_ = FrgNew QtVariantEditorFactory;

	thePropertyBrowser_->setFactoryForManager(theVariantPropertyManager_, theVariantEditorFactory_);
	//((QtTreePropertyBrowser*)thePropertyBrowser_)->setPropertiesWithoutValueMarked(FrgTrue);
	//((QtTreePropertyBrowser*)thePropertyBrowser_)->setRootIsDecorated(FrgFalse);

	AddTopProperty("Properties");
	AddPropertyString("Properties", "Name", theParentTreeItem_->text(0));
	/*AddTopProperty("Parameters");
	AddPropertyDouble("Parameters", "Length", 100.05);
	AddPropertyDouble("Parameters", "Beam", 25.2);
	AddPropertyDouble("Parameters", "Draft", 8.6);
	AddTopProperty("Color");
	AddPropertyInt("Color", "Red", 255);
	AddPropertyInt("Color", "Green", 0);
	AddPropertyInt("Color", "Blue", 150);
	AddPropertyPointF("Color", "Point 1", QPointF(2.5, 3.5));*/
	GetProperty("Name")->setEnabled(FrgFalse);

	//thePropertyBrowser_->setBackgroundColor(thePropertyBrowser_->items(GetProperty("Properties"))[0], QColor(236, 240, 241));

	thePropertyBrowser_->setStyleSheet(
		"QtTreePropertyBrowser {"
		"background - color: #19232D;"
		"border: 0px solid #32414B;"
		"padding: 0px;"
		"color: #F0F0F0;"
		"selection - background - color: #1464A0;"
		"selection - color: #F0F0F0;"
		"}"
	);
}

ForgBaseLib::FrgBaseTreeItemProperties::~FrgBaseTreeItemProperties()
{
	FreePointer(thePropertyBrowser_);
	FreePointer(theVariantEditorFactory_);
	FreePointer(theVariantPropertyManager_);
	FreePointer(theAbstractEditorFactory_);
	FreePointer(theAbstractPropertyManager_);

	for (int i = 0; i < theTopProperties_.size(); i++)
	{
		if (theTopProperties_[i])
			theTopProperties_.removeAt(i);
	}

	//FreeVectorOfPointers(theTopProperties_);
}

QtProperty* ForgBaseLib::FrgBaseTreeItemProperties::GetTopProperty(const FrgString& name)
{
	for (int i = 0; i < theTopProperties_.size(); i++)
	{
		if (theTopProperties_.at(i)->propertyName() == name)
			return theTopProperties_.at(i);
	}

	return FrgNullPtr;
}

QtProperty* ForgBaseLib::FrgBaseTreeItemProperties::GetTopPropertyById(const FrgString& id)
{
	for (int i = 0; i < theTopProperties_.size(); i++)
	{
		if (theTopProperties_.at(i)->propertyId() == id)
			return theTopProperties_.at(i);
	}

	return FrgNullPtr;
}

QtProperty* ForgBaseLib::FrgBaseTreeItemProperties::GetProperty(const FrgString& name)
{
	for (int i = 0; i < theTopProperties_.size(); i++)
	{
		QtProperty* item = GetTopProperty(name);
		if (item)
			return item;
		for (int j = 0; j < theTopProperties_.at(i)->subProperties().size(); j++)
		{
			QtProperty* subItem = theTopProperties_.at(i)->subProperties().at(j);
			if (subItem->propertyName() == name)
				return subItem;
		}
	}

	return FrgNullPtr;
}

QtProperty* ForgBaseLib::FrgBaseTreeItemProperties::GetPropertyById(const FrgString& id)
{
	for (int i = 0; i < theTopProperties_.size(); i++)
	{
		QtProperty* item = GetTopPropertyById(id);
		if (item)
			return item;
		for (int j = 0; j < theTopProperties_.at(i)->subProperties().size(); j++)
		{
			QtProperty* subItem = theTopProperties_.at(i)->subProperties().at(j);
			if (subItem->propertyId() == id)
				return subItem;
		}
	}

	return FrgNullPtr;
}

void ForgBaseLib::FrgBaseTreeItemProperties::AddTopProperty(const FrgString& name, const FrgString& topProperty)
{
	if (topProperty == "")
	{
		QtProperty* topItem = theVariantPropertyManager_->addProperty(QtVariantPropertyManager::groupTypeId(), QLatin1String(name.toLocal8Bit().data()));
		theTopProperties_.push_back(topItem);
		thePropertyBrowser_->addProperty(topItem);
	}
	else
	{
		QtVariantProperty* item = theVariantPropertyManager_->addProperty(QtVariantPropertyManager::groupTypeId(), QLatin1String(name.toLocal8Bit().data()));
		if (QtProperty* topItem = GetTopProperty(topProperty))
			topItem->addSubProperty(item);

		theTopProperties_.push_back(item);
	}
}

QtVariantProperty* ForgBaseLib::FrgBaseTreeItemProperties::AddProperty(const FrgString& topProperty, FrgInt propertyType, const FrgString& name, const FrgString& propertyId)
{
	QtVariantProperty* item = theVariantPropertyManager_->addProperty(propertyType, QLatin1String(name.toLocal8Bit().data()));
	item->setPropertyId(propertyId);
	//theParentTreeItem_->GetParentMainWindow()->ParseErrorToConsole(name + " =======> " + item->propertyId());
	if (QtProperty* topItem = GetTopProperty(topProperty))
		topItem->addSubProperty(item);

	return item;
}

//void ForgBaseLib::FrgBaseTreeItemProperties::AddPropertyString(const FrgString& topProperty, const FrgString& name, const FrgString& value)
//{
//	QtVariantProperty* item = AddProperty(topProperty, QVariant::String, name);
//
//	item->setValue(value);
//	item->setPropertyId(item->propertyName());
//}
//
//void ForgBaseLib::FrgBaseTreeItemProperties::AddPropertyDouble(const FrgString& topProperty, const FrgString& name, FrgDouble value)
//{
//	QtVariantProperty* item = AddProperty(topProperty, QVariant::Double, name);
//
//	item->setValue(value);
//	item->setPropertyId(item->propertyName());
//}
//
//void ForgBaseLib::FrgBaseTreeItemProperties::AddPropertyInt(const FrgString& topProperty, const FrgString& name, FrgInt value)
//{
//	QtVariantProperty* item = AddProperty(topProperty, QVariant::Int, name);
//
//	item->setValue(value);
//	item->setPropertyId(item->propertyName());
//}

void ForgBaseLib::FrgBaseTreeItemProperties::SetEnabled(const FrgString& name, FrgBool condition)
{
	GetProperty(name)->setEnabled(condition);
}

void ForgBaseLib::FrgBaseTreeItemProperties::SetExpanded(const FrgString& title, FrgBool condition)
{
	//theParentTreeItem_->GetParentMainWindow()->ParseInfoToConsole(QString::number(thePropertyBrowser_->items(GetProperty(title)).size()));
	((QtTreePropertyBrowser*)thePropertyBrowser_)->setExpanded(thePropertyBrowser_->items(GetProperty(title))[0], condition);
}

void ForgBaseLib::FrgBaseTreeItemProperties::AddPropertyFlagType(const FrgString& topProperty, const FrgString& name, QStringList flagNames, const FrgString& propertyId)
{
	QtVariantProperty* item = AddProperty(topProperty, QtVariantPropertyManager::flagTypeId(), name, propertyId);

	item->setAttribute(QLatin1String("flagNames"), flagNames);
}