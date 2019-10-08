#include <FrgBaseTreeItem.hxx>
#include <FrgTree.hxx>

#include <qttreepropertybrowser.h>
#include <qtvariantproperty.h>

ForgBaseLib::FrgBaseTreeItem::FrgBaseTreeItem(const FrgString& itemName, FrgBaseTreeItem* parentItem, FrgTree* parentTree, FrgMainWindow* parentMainWindow)
	: QTreeWidgetItem(parentItem)
	, theParentTree_(parentTree)
	, theParentMainWindow_(parentMainWindow)
{
	this->setText(0, itemName);
	this->setIcon(0, QIcon(":/Icons/Menus/File/Load.png"));

	FrgString str = itemName;
	str = str.simplified();
	str.replace(" ", "");

	if (parentItem)
	{
		parentItem->addChild(this);
		this->GetObjectName() = parentItem->GetObjectName() + "_" + str;
	}
	else
	{
		parentTree->addTopLevelItem(this);
		this->GetObjectName() = str;
	}

	CreateProperty();
}

void ForgBaseLib::FrgBaseTreeItem::CreateProperty()
{
	theProperty_ = FrgNew QtTreePropertyBrowser;

	theVariantPropertyManager_ = FrgNew QtVariantPropertyManager;
	theVariantEditorFactory_ = FrgNew QtVariantEditorFactory;

	theProperty_->setFactoryForManager(theVariantPropertyManager_, theVariantEditorFactory_);

	QtProperty* topItem = theVariantPropertyManager_->addProperty(QtVariantPropertyManager::groupTypeId(), QLatin1String("Properties"));

	QtVariantProperty* item = theVariantPropertyManager_->addProperty(QVariant::String, QLatin1String("Name"));
	item->setValue(this->text(0));
	item->setPropertyId(item->propertyName());
	item->setEnabled(FrgFalse);
	topItem->addSubProperty(item);

	theProperty_->addProperty(topItem);
	theProperty_->setPropertiesWithoutValueMarked(FrgTrue);
	theProperty_->setRootIsDecorated(FrgFalse);
}