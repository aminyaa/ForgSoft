#pragma once
#ifndef _FrgBaseTree_Header
#define _FrgBaseTree_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QTreeWidget>

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseTreeItem;

struct FrgBaseTreeCache
{
	FrgBaseTreeItem* theLastLeftClicked_;
	FrgBaseTreeItem* theLastRightClicked_;

	~FrgBaseTreeCache()
	{
		FreePointer(theLastLeftClicked_);
		FreePointer(theLastRightClicked_);
	}
};

class FORGBASE_EXPORT FrgBaseTree 
	: public QTreeWidget
	, public FrgBaseTreeCache
{

	Q_OBJECT

private:

	QList<FrgBaseTreeItem*> theItems_;
	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	
	void keyPressEvent(QKeyEvent* event);

public:

	FrgBaseTree(FrgBaseMainWindow* parent = FrgNullPtr);

	~FrgBaseTree();

	FrgGetMacro(QList<FrgBaseTreeItem*>, Items, theItems_);
	FrgGetMacro(FrgBaseMainWindow*, ParentMainWindow, theParentMainWindow_);

	virtual void FormTree();

	void ClearTree();

	FrgBaseTreeItem* GetTreeItem(const FrgString& title);
	FrgBaseTreeItem*& GetTreeItemFromList(FrgBaseTreeItem* item);

	void ScrollToItem(FrgBaseTreeItem* item);
	void ScrollToItems(QList<FrgBaseTreeItem*> items);

protected Q_SLOTS:

	virtual void itemClickedSlot(QTreeWidgetItem* item, int column);

	void itemDoubleClickedSlot(QTreeWidgetItem* item, int column);

public Q_SLOTS:

	void onCustomContextMenuRequested(const QPoint& pos);

	virtual void showContextMenu(FrgBaseTreeItem* item, const QPoint& globalPos);

	void DeleteTreeItemSlot(bool);

	void TreeItemNameChangedSlot(bool);
	void TreeItemNameChangedSlot(QTreeWidgetItem *item, int column);
};

EndFrgBaseLib

#endif // !_FrgBaseTree_Header
