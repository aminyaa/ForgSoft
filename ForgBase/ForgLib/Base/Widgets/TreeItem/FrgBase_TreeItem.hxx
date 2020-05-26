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

	FrgBase_PrptsVrntString* theTItemName_ = NullPtr;

	void FormPropertiesPanel();

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

	~FrgBase_TreeItem();

	void SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow) { theParentMainWindow_ = parentMainWindow; }

	FrgGetMacro(FrgBase_Tree*, ParentTree, theParentTree_);
	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBase_PropertiesPanel*, PropertiesPanel, thePropertiesPanel_);
	FrgGetMacro(FrgBase_Menu*, ContextMenu, theContextMenu_);

	QList<FrgBase_TreeItem*> GetChildren();
	FrgBase_TreeItem* GetChild(const QString& name);
	bool IsSameNameTItem(const QString& name);
	bool IsTItemClickable() const { return theTItemIsClickable_; }
	void SetTItemClickable(bool condition) { theTItemIsClickable_ = condition; }

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

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	void SetTItemName(const QString& name);

public slots:

	void RenameTItemSlot();
	void RenameTItemSlot(const QString& name);
	virtual void TItemDoubleClickedSlot() {}
	virtual void TItemClickedSlot() {}
	virtual void TItemNotClickedSlot() {}
};

EndForgBaseLib

// override for non-default constructor
DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgBaseLib::FrgBase_TreeItem)

//namespace boost {
//	namespace serialization {
//		template<class Archive>
//		inline void save_construct_data
//		(
//			Archive & ar, const ForgBaseLib::FrgBase_TreeItem * t, const unsigned int file_version
//		)
//		{
//			// ============================================
//			// store FrgBase_TreeItem title
//			// ============================================
//			QString myTItemTitle = t->text(0);
//			ar << myTItemTitle;
//
//			// ============================================
//			// store FrgBase_TreeItem parentTItem
//			// ============================================
//			QString parentTItemIsNull;
//			ForgBaseLib::FrgBase_TreeItem* parentTItem = dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(((QTreeWidgetItem*)t)->parent());
//
//			if (!parentTItem)
//			{
//				parentTItemIsNull = "PARENT_TITEM_IS_NULL";
//
//				ar << parentTItemIsNull;
//			}
//			else
//			{
//				parentTItemIsNull = "PARENT_TITEM_IS_NOT_NULL";
//
//				ar << parentTItemIsNull;
//				ar << parentTItem;
//			}
//
//			// ============================================
//			// store FrgBase_TreeItem parentTree
//			// ============================================
//			QString parentTreeIsNull;
//			ForgBaseLib::FrgBase_Tree* parentTree = (t->GetParentTree());
//
//			if (!parentTree)
//			{
//				parentTreeIsNull = "PARENT_TREE_IS_NULL";
//
//				ar << parentTreeIsNull;
//			}
//			else
//			{
//				parentTreeIsNull = "PARENT_TREE_IS_NOT_NULL";
//
//				ar << parentTreeIsNull;
//				ar << parentTree;
//			}
//
//		}
//
//		template<class Archive>
//		inline void load_construct_data
//		(
//			Archive & ar, ForgBaseLib::FrgBase_TreeItem * t, const unsigned int file_version
//		)
//		{
//			// ============================================
//			// load FrgBase_TreeItem title
//			// ============================================
//			QString myTItemTitle;;
//			ar >> myTItemTitle;
//
//			// ============================================
//			// load FrgBase_TreeItem parentTItem
//			// ============================================
//			QString parentTItemIsNull;
//			ForgBaseLib::FrgBase_TreeItem* parentTItem;
//
//			ar >> parentTItemIsNull;
//
//			if (parentTItemIsNull == "PARENT_TITEM_IS_NULL")
//				parentTItem = nullptr;
//			else if (parentTItemIsNull == "PARENT_TITEM_IS_NOT_NULL")
//				ar >> parentTItem;
//
//			// ============================================
//			// load FrgBase_TreeItem parentTree
//			// ============================================
//			QString parentTreeIsNull;
//			ForgBaseLib::FrgBase_Tree* parentTree;
//
//			ar >> parentTreeIsNull;
//
//			if (parentTreeIsNull == "PARENT_TREE_IS_NULL")
//				parentTree = nullptr;
//			else if (parentTreeIsNull == "PARENT_TREE_IS_NOT_NULL")
//				ar >> parentTree;
//
//			// =============================================================
//			// invoke inplace constructor to initialize instance of my_class
//			// =============================================================
//			::new(t)ForgBaseLib::FrgBase_TreeItem(myTItemTitle, parentTItem, parentTree);
//		}
//	}
//}

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_TreeItem)

#endif // !_FrgBase_TreeItem_header