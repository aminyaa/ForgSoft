#include <FrgBaseTreeItem.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseTreeItemProperties.hxx>
#include <FrgBaseGlobalsICONS.hxx>
#include <FrgBaseMenu.hxx>
#include <FrgBaseMainWindow.hxx>

#include <QtWidgets/QToolBar>

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
	theContextMenu_ = FrgNew FrgBaseMenu();
	theContextMenu_->GetToolBar()->setHidden(FrgTrue);

	if (parentItem)
	{
		parentItem->addChild(this);
		theContextMenu_->AddItem("Rename");

		QObject::connect(theContextMenu_->GetItem("Rename"), SIGNAL(triggered(bool)), parentTree, SLOT(TreeItemNameChangedSlot(bool)));
	}
	else
		parentTree->addTopLevelItem(this);

	SetTreeItemName(itemName);

	CreateProperties();

	parentTree->GetItems().push_back(this);

	this->setIcon(0, QIcon(FrgICON_Menu_File_Load));
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

void ForgBaseLib::FrgBaseTreeItem::SetTreeItemName(FrgString name)
{
	//name = name.simplified();
	this->setText(0, name);

	FrgString str = name;
	str = str.simplified();
	str.replace(" ", "");

	if (parent())
	{
		for (int i = 0; i < parent()->childCount(); i++)
		{
			//GetParentMainWindow()->ParseErrorToConsole("1 - " + dynamic_cast<FrgBaseTreeItem*>(parent()->child(i))->GetObjectName());
			//GetParentMainWindow()->ParseErrorToConsole("2 - " + dynamic_cast<FrgBaseTreeItem*>(parent())->GetObjectName() + "_" + str);
			if (dynamic_cast<FrgBaseTreeItem*>(parent()->child(i))->GetObjectName() == dynamic_cast<FrgBaseTreeItem*>(parent())->GetObjectName() + "_" + str)
			{
				if (dynamic_cast<FrgBaseTreeItem*>(parent()->child(i)) == this)
					continue;
				str = str + "(Copy)";
				this->setText(0, this->text(0) + " (Copy)");
			}
		}
		this->GetObjectName() = dynamic_cast<FrgBaseTreeItem*>(parent())->GetObjectName() + "_" + str;
		//GetParentMainWindow()->ParseErrorToConsole("1 - " + this->GetObjectName());
	}
	else
		this->GetObjectName() = str;

	emit theParentTree_->itemChanged(this, 0);
}

void ForgBaseLib::FrgBaseTreeItem::RenameTreeItemName(FrgString name)
{
	SetTreeItemName(name);

	if (theProperties_)
	{
		theProperties_->GetPropertyManager()->setProperty("Name", name);
		theProperties_->GetPropertyManager()->setValue(theProperties_->GetProperty("Name"), name);
	}
}