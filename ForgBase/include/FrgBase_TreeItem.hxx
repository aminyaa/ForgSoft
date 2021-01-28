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
	bool theTItemIsClickable_ = true;
	bool theTItemIsSortable_;
	bool theTItemIsDeletable_;
	bool theTItemIsDraggable_;
	bool theTItemIsDroppable_;

	FrgBase_PrptsVrntString* theTItemName_ = NullPtr;

	virtual void FormPropertiesPanel();

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

	virtual void SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow) { theParentMainWindow_ = parentMainWindow; }

	FrgGetMacro(FrgBase_Tree*, ParentTree, theParentTree_);
	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBase_PropertiesPanel*, PropertiesPanel, thePropertiesPanel_);
	FrgGetMacro(FrgBase_Menu*, ContextMenu, theContextMenu_);

	QList<FrgBase_TreeItem*> GetChildren() const;
	FrgBase_TreeItem* GetChild(const QString& name);

	std::vector<FrgBase_TreeItem*> GetAllChildrenToTheRoot() const;

	bool IsSameNameTItem(const QString& name);
	bool IsTItemClickable() const { return theTItemIsClickable_; }
	void SetTItemClickable(bool condition) { theTItemIsClickable_ = condition; }

	void SetTItemSortable(bool condition = true) { theTItemIsSortable_ = condition; }
	bool IsTItemSortable() const { return theTItemIsSortable_; }

	virtual void DoAfterConstruct() {}

	FrgBase_PrptsVrntString* GetTItemName() const { return theTItemName_; }
	void SetTItemName(FrgBase_PrptsVrntString* variant) { theTItemName_ = variant; }

	void AddRenameOptionInContextMenu();
	void RemoveRenameOptionInContextMenu();
	void AddDeleteOptionInContextMenu();
	void RemoveDeleteOptionInContextMenu();

	void ConstructTItem
	(
		const FrgString & itemTitle,
		FrgBase_TreeItem * parentItem,
		FrgBase_Tree * parentTree
	);

	virtual void FormTItem();

	virtual void SortTItem(Qt::SortOrder sortOrder_ = Qt::AscendingOrder);

	virtual bool IsDeletable() const { return theTItemIsDeletable_; }
	void SetDeletable(bool deletable) { theTItemIsDeletable_ = deletable; }

	bool IsDraggable() const { return theTItemIsDraggable_; }
	void SetDraggable(bool drggable) { theTItemIsDraggable_ = drggable; }

	bool IsDroppable() const { return theTItemIsDroppable_; }
	void SetDroppable(bool droppable) { theTItemIsDroppable_ = droppable; }

	virtual bool CanDropTo(FrgBase_TreeItem* draggedTItem) { return true; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

private:

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

#endif // !_FrgBase_TreeItem_header