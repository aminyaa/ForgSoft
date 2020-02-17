#pragma once
#ifndef _FrgBase_Tree_Header
#define _FrgBase_Tree_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtWidgets/QTreeWidget>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_TreeItem;
class FrgBase_MainWindow;

struct FrgBase_TreeCache
{
	FrgBase_TreeItem* theLastLeftClickedTItem_ = NullPtr;
	FrgBase_TreeItem* theLastRightClickedTItem_ = NullPtr;
};

class FORGBASE_EXPORT FrgBase_Tree
	: public QTreeWidget
	, public FrgBase_Object
	, public FrgBase_TreeCache
{

	Q_OBJECT

private:

	FrgBase_MainWindow* theParentMainWindow_ = NullPtr;

	void keyPressEvent(QKeyEvent* event);

public:

	FrgBase_Tree
	(
		FrgBase_MainWindow* parentMainWindow
	);

	~FrgBase_Tree();

	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);

	virtual void FormTree();
	void ScrollToItem(FrgBase_TreeItem* item);
	void ScrollToItems(QList<FrgBase_TreeItem*> items);


protected Q_SLOTS:

	virtual void itemClickedSlot(QTreeWidgetItem* item, int column);
	virtual void itemDoubleClickedSlot(QTreeWidgetItem* item, int column);

public Q_SLOTS:

	void onCustomContextMenuRequested(const QPoint& pos);
	virtual void showContextMenu(FrgBase_TreeItem* item, const QPoint& globalPos);
	void DeleteTreeItemSlot(FrgBase_TreeItem* TItem);
	void DeleteTreeItemSlot();
};

EndForgBaseLib

#endif // !_FrgBase_Tree_Header
