#pragma once
#ifndef _FrgBaseTree_Header
#define _FrgBaseTree_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QTreeWidget>

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseTreeItem;

class FORGBASE_EXPORT FrgBaseTree : public QTreeWidget
{

	Q_OBJECT

private:

	FrgVector<FrgBaseTreeItem*> theItems_;
	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	
	void keyPressEvent(QKeyEvent* event);

public:

	FrgBaseTree(FrgBaseMainWindow* parent = FrgNullPtr);

	FrgGetMacro(FrgVector<FrgBaseTreeItem*>, Items, theItems_);
	FrgGetMacro(FrgBaseMainWindow*, ParentMainWindow, theParentMainWindow_);

	virtual void FormTree();

	void ClearTree();

	FrgBaseTreeItem* GetTreeItem(const FrgString& title);

protected Q_SLOTS:

	void itemClickedSlot(QTreeWidgetItem* item, int column);

public Q_SLOTS:

	void onCustomContextMenuRequested(const QPoint& pos);

	void showContextMenu(FrgBaseTreeItem* item, const QPoint& globalPos);
};

EndFrgBaseLib

#endif // !_FrgBaseTree_Header
