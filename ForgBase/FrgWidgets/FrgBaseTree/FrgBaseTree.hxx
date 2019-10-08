#pragma once
#ifndef _FrgTree_Header
#define _FrgTree_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QTreeWidget>

BeginFrgBaseLib

class FrgMainWindow;
class FrgTreeItem;

class FORGBASE_EXPORT FrgTree : public QTreeWidget
{

	Q_OBJECT

private:

	FrgVector<FrgTreeItem*> theItems_;
	FrgMainWindow* theParentMainWindow_ = FrgNullPtr;
	
	void keyPressEvent(QKeyEvent* event);

public:

	FrgTree(FrgMainWindow* parent = FrgNullPtr);

	FrgGetMacro(FrgVector<FrgTreeItem*>, Items, theItems_);
	FrgGetMacro(FrgMainWindow*, ParentMainWindow, theParentMainWindow_);

	void FormTree();
	void ClearTree();

protected slots:

	void itemClickedSlot(QTreeWidgetItem* item, FrgInt column);
};

EndFrgBaseLib

#endif // !_FrgTree_Header
