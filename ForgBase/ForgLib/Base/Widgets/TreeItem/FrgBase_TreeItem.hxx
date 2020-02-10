#pragma once
#ifndef _FrgBase_TreeItem_header
#define _FrgBase_TreeItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>
#include <FrgBase_PrptsVrntString.hxx>
#include <FrgBase_PrptsVrntInt.hxx>

#include <QtWidgets/QTreeWidgetItem>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_Tree;
class FrgBase_MainWindow;
class FrgBase_PropertiesPanel;
class FrgBase_Menu;

class FORGBASE_EXPORT FrgBase_TreeItem
	: public QObject
	, public QTreeWidgetItem
	, public FrgBase_Object
{

	Q_OBJECT
		
	Q_PROPERTY(FrgBase_PrptsVrntString* TItemName READ GetTItemName WRITE SetTItemName NOTIFY TItemNameChanged)

protected:

	FrgBase_Tree* theParentTree_ = NullPtr;
	FrgBase_MainWindow* theParentMainWindow_ = NullPtr;
	FrgBase_PropertiesPanel* thePropertiesPanel_ = NullPtr;
	FrgBase_Menu* theContextMenu_ = NullPtr;

	FrgBase_PrptsVrntString* theTItemName_ = NullPtr;

signals:

	void TItemNameChanged(const QString&);

public:

	FrgBase_TreeItem
	(
		const FrgString& itemTitle,
		FrgBase_TreeItem* parentItem,
		FrgBase_Tree* parentTree
	);

	FrgGetMacro(FrgBase_Tree*, ParentTree, theParentTree_);
	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBase_PropertiesPanel*, PropertiesPanel, thePropertiesPanel_);
	FrgGetMacro(FrgBase_Menu*, ContextMenu, theContextMenu_);

	QList<FrgBase_TreeItem*> GetChildren();
	FrgBase_TreeItem* GetChild(const QString& name);
	bool IsSameNameTItem(const QString& name);

	virtual void DoAfterConstruct() {}

	FrgBase_PrptsVrntString* GetTItemName() const { return theTItemName_; }
	void SetTItemName(FrgBase_PrptsVrntString* variant) { theTItemName_ = variant; }

	void AddRenameOptionInContextMenu();

private:

	void SetTItemName(const QString& name);

public slots:

	void RenameTItemSlot();
	void RenameTItemSlot(const QString& name);
	virtual void TItemDoubleClickedSlot() {}
};

EndForgBaseLib

#endif // !_FrgBase_TreeItem_header
