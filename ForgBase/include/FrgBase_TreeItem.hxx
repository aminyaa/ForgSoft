#pragma once
#ifndef _FrgBase_TreeItem_header
#define _FrgBase_TreeItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>
#include <FrgBase_PrptsVrntString.hxx>
#include <FrgBase_PrptsVrntInt.hxx>

#include <FrgBase_Serialization_Global.hxx>
#include <FrgBase_SerialSpec_QString.hxx>
#include <FrgBase_SerialSpec_QTreeWidgetItem.hxx>

#include <QtWidgets/QTreeWidgetItem>

BeginForgBaseLib

class FrgBase_Tree;
class FrgBase_MainWindow;
class FrgBase_PropertiesPanel;
class FrgBase_Menu;
class FrgBase_MenuAction;
class FrgBase_Icon;

class FORGBASE_EXPORT FrgBase_TreeItem
	: public QObject
	, public QTreeWidgetItem
	, public FrgBase_Object
{

	Q_OBJECT

		Q_PROPERTY(FrgBase_PrptsVrntString* TItemName READ GetTItemName WRITE SetTItemName NOTIFY TItemNameChanged)

public:

		enum class LockType
	{
		None,
		Rename,
		Delete,
		PPanel,
		RenameAndDelete,
		RenameAndPPanel,
		DeleteAndPPanel,
		RenameAndDeleteAndPPanel,
		ContextMenu,
		ContextMenuAndRename,
		ContextMenuAndDelete,
		ContextMenuAndRenameAndDelete,
		ContextMenuAndPPanel,
		ContextMenuAndRenameAndPPanel,
		ContextMenuAndDeleteAndPPanel,
		ContextMenuAndRenameAndDeleteAndPPanel,
		Full
	};

protected:

	FrgBase_Tree* theParentTree_ = NullPtr;
	FrgBase_MainWindow* theParentMainWindow_ = NullPtr;
	FrgBase_PropertiesPanel* thePropertiesPanel_ = NullPtr;
	FrgBase_Menu* theContextMenu_ = NullPtr;
	bool theTItemIsClickable_ = true;
	bool theTItemIsSortable_;
	bool theTItemIsDeletable_;
	bool theTItemIsDraggable_;
	bool theTItemIsDroppable_;

	LockType theLockType_ = LockType::None;

	int theLevelInTree_ = -1;

	FrgBase_PrptsVrntString* theTItemName_ = NullPtr;

	FrgBase_Icon* theIcon_ = nullptr;

	virtual void FormPropertiesPanel();

	FrgBase_MenuAction* theRenameAction_ = nullptr;
	FrgBase_MenuAction* theDeleteAction_ = nullptr;

signals:

	void TItemNameChanged(const QString&);
	void DeleteTItemCalled();
	void TItemIsGoingToBeDeleted();

public:

	FrgBase_TreeItem
	(
		const FrgString& itemTitle,
		FrgBase_TreeItem* parentItem,
		FrgBase_Tree* parentTree
	);

	virtual ~FrgBase_TreeItem();

	virtual void SetParentMainWindow(FrgBase_MainWindow* parentMainWindow);
	virtual void SetParentTree(FrgBase_Tree* parentTree);
	virtual void SetParentTItem(FrgBase_TreeItem* parentTItem, bool renameTItem = true);

	virtual bool IsThemeDark() const;
	virtual void SetThemeDark(const bool isDark = false) {}

	virtual int GetLevelInTree() const { return theLevelInTree_; }
	// setting level in tree is not recommended manually
	virtual void SetLevelInTree(int level) { theLevelInTree_ = level; }

	FrgGetMacro(FrgBase_Tree*, ParentTree, theParentTree_);
	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBase_PropertiesPanel*, PropertiesPanel, thePropertiesPanel_);
	FrgGetMacro(FrgBase_Menu*, ContextMenu, theContextMenu_);

	virtual FrgBase_TreeItem* GetParentTItem() const;

	QList<FrgBase_TreeItem*> GetChildren() const;
	FrgBase_TreeItem* GetChild(const QString& name);

	template <class T>
	std::vector<T*> GetChildrenByType() const;

	std::vector<FrgBase_TreeItem*> GetAllChildrenToTheRoot() const;

	template <class T>
	std::vector<T*> GetAllChildrenToTheRootByType() const;

	bool IsSameNameTItem(const QString& name);
	virtual bool IsTItemClickable() const { return theTItemIsClickable_; }
	virtual void SetTItemClickable(bool condition) { theTItemIsClickable_ = condition; }

	virtual void SetTItemSortable(bool condition = true) { theTItemIsSortable_ = condition; }
	virtual bool IsTItemSortable() const { return theTItemIsSortable_; }

	virtual void DoAfterConstruct() {}

	FrgBase_PrptsVrntString* GetTItemName() const { return theTItemName_; }
	void SetTItemName(FrgBase_PrptsVrntString* variant) { theTItemName_ = variant; }

	virtual void AddRenameOptionInContextMenu();
	virtual void RemoveRenameOptionInContextMenu();
	virtual void AddDeleteOptionInContextMenu();
	virtual void RemoveDeleteOptionInContextMenu();

	void ConstructTItem
	(
		const FrgString & itemTitle,
		FrgBase_TreeItem * parentItem,
		FrgBase_Tree * parentTree
	);

	virtual void FormTItem();

	virtual void SortTItem(Qt::SortOrder sortOrder_ = Qt::AscendingOrder);

	virtual bool IsDeletable() const { return theTItemIsDeletable_; }
	virtual void SetDeletable(bool deletable) { theTItemIsDeletable_ = deletable; }

	virtual bool IsDraggable() const { return theTItemIsDraggable_; }
	virtual void SetDraggable(bool drggable) { theTItemIsDraggable_ = drggable; }

	virtual bool IsDroppable() const { return theTItemIsDroppable_; }
	virtual void SetDroppable(bool droppable) { theTItemIsDroppable_ = droppable; }

	virtual LockType GetLockType() const { return theLockType_; }
	virtual void SetLockType(LockType lt) { theLockType_ = lt; }

	virtual bool CanDropTo(FrgBase_TreeItem* draggedTItem) { return true; }

	virtual bool IsMyParent(FrgBase_TreeItem* p, bool recursive = true) const;

	virtual FrgBase_Icon* GetIcon() const { return theIcon_; }
	virtual void SetIcon(int column, const FrgBase_Icon& icon);

	virtual FrgBase_MenuAction* GetRenameAction() const { return theRenameAction_; }
	virtual FrgBase_MenuAction* GetDeleteAction() const { return theDeleteAction_; }

	virtual bool CanRenameUsingLock() const;
	virtual bool CanDeleteUsingLock() const;
	virtual bool CanShowPPanelUsingLock() const;
	virtual bool CanShowContextMenuUsingLock() const;

	virtual bool HasParentTItemNullTree() const;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	void SetTItemName(const QString& name, bool sortParentTItem = true);

	bool operator<(const QTreeWidgetItem& other) const override;

public slots:

	void RenameTItemSlot(bool sortParentTItem = true);
	void RenameTItemSlot(const QString& name, bool sortParentTItem = true);
	virtual void TItemDoubleClickedSlot() {}
	virtual void TItemClickedSlot() {}
	virtual void TItemNotClickedSlot() {}
};

EndForgBaseLib

// override for non-default constructor
DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgBaseLib::FrgBase_TreeItem, FORGBASE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_TreeItem)

#include <FrgBase_TreeItemI.hxx>

#endif // !_FrgBase_TreeItem_header