#include <FrgBaseTreeItem.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseTreeItemProperties.hxx>
#include <FrgBaseGlobalsICONS.hxx>

#include <FrgBaseMenu.hxx>

#include <qttreepropertybrowser.h>
#include <qtvariantproperty.h>

ForgBaseLib::FrgBaseTreeItem::FrgBaseTreeItem
(
	const FrgString& itemName,
	FrgBaseTreeItem* parentItem,
	FrgBaseTree* parentTree,
	FrgBaseMainWindow* parentMainWindow
)
	: QTreeWidgetItem(parentItem)
	, theParentTree_(parentTree)
	, theParentMainWindow_(parentMainWindow)
{

	this->setText(0, itemName);
	this->setIcon(0, QIcon(FrgICON_Menu_File_Load));

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

	CreateProperties();

	theContextMenu_ = FrgNew FrgBaseMenu();

	parentTree->GetItems().push_back(this);
}

ForgBaseLib::FrgBaseTreeItem::~FrgBaseTreeItem()
{
	if (theProperties_)
	{
		delete theProperties_;
		theProperties_ = FrgNullPtr;
	}

	/*if (theContextMenu_)
	{
		delete theContextMenu_;
		theContextMenu_ = FrgNullPtr;
	}*/
}

void ForgBaseLib::FrgBaseTreeItem::CreateProperties()
{
	theProperties_ = FrgNew FrgBaseTreeItemProperties(this);
}