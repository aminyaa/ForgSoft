#pragma once
#ifndef _FrgBase_TreeItem_header
#define _FrgBase_TreeItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtWidgets/QTreeWidgetItem>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_Tree;
class FrgBase_MainWindow;
class FrgBase_TItem_Properties;
class FrgBase_Menu;

class FORGBASE_EXPORT FrgBase_TreeItem
	: public QTreeWidgetItem
	, public FrgBase_Object
{

	Q_OBJECT
		
	Q_PROPERTY(QString name READ GetTItemName WRITE SetTItemName NOTIFY TItemChanged)

private:

	FrgBase_Tree* theParentTree_ = FrgNullPtr;
	FrgBase_MainWindow* theParentMainWindow_ = FrgNullPtr;
	FrgBase_TItem_Properties* theProperties_ = FrgNullPtr;
	FrgBase_Menu* theContextMenu_ = FrgNullPtr;

	QString theTItemName_;

signals:

	void TItemChanged(const QString&);

public:

	FrgBase_TreeItem
	(
		const FrgString& itemTitle,
		FrgBase_TreeItem* parentItem,
		FrgBase_Tree* parentTree
	);

	FrgGetMacro(FrgBase_Tree*, ParentTree, theParentTree_);
	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBase_TItem_Properties*, Properties, theProperties_);
	FrgGetMacro(FrgBase_Menu*, ContextMenu, theContextMenu_);

	virtual void DoAfterConstruct() {}

	void UpdateObject() override;

	QString GetTItemName() const { return theTItemName_; }
	void SetTItemName(const QString& name)
	{
		if (theTItemName_ != name)
		{
			theTItemName_ = name;
			emit TItemChanged(theTItemName_);
		}
	}
};

EndForgBaseLib

#endif // !_FrgBase_TreeItem_header
