#include <FrgBase_TreeItem.hxx>
#include <FrgBase_Menu.hxx>

#include <QtWidgets/QToolBar>
#include <QtCore/QMetaProperty>

ForgBaseLib::FrgBase_TreeItem::FrgBase_TreeItem
(
	const FrgString & itemTitle, FrgBase_TreeItem * parentItem, FrgBase_Tree * parentTree
)
	: QTreeWidgetItem(parentItem)
{

	const QMetaObject *metaobject = this->metaObject();
	int count = metaobject->propertyCount();
	for (int i = 0; i < count; ++i) {
		QMetaProperty metaproperty = metaobject->property(i);
		const char *name = metaproperty.name();
		QVariant value = this->property(name);
	}

	theContextMenu_ = FrgBase_Menu;
	theContextMenu_->GetToolBar()->setHidden(FrgTrue);

	if (parentItem)
	{
		parentItem->addChild(this);
		theContextMenu_->AddItem("Rename");

		QObject::connect(theContextMenu_->GetItem("Rename"), SIGNAL(triggered(bool)), parentTree, SLOT(TreeItemNameChangedSlot(bool)));
	}
	else
		parentTree->addTopLevelItem(this);
}

void ForgBaseLib::FrgBase_TreeItem::UpdateObject()
{

}