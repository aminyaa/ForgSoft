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

	void FormTree();
	void ClearTree();

protected slots:

	void itemClickedSlot(QTreeWidgetItem* item, FrgInt column);
};

EndFrgBaseLib

#endif // !_FrgBaseTree_Header
