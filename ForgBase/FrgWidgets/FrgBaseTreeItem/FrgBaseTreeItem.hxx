#pragma once
#ifndef _FrgTreeItem_Header
#define _FrgTreeItem_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QTreeWidgetItem>

class QtTreePropertyBrowser;
class QtVariantPropertyManager;
class QtVariantEditorFactory;
class QtBrowserItem;
class QtProperty;
class QVariant;

BeginFrgBaseLib

class FrgMainWindow;
class FrgTree;

class FORGBASE_EXPORT FrgBaseTreeItem : public QTreeWidgetItem
{

private:

	FrgMainWindow* theParentMainWindow_ = FrgNullPtr;
	FrgTree* theParentTree_ = FrgNullPtr;
	FrgString theObjectName_;

	QtTreePropertyBrowser* theProperty_;
	QtVariantPropertyManager* theVariantPropertyManager_;
	QtVariantEditorFactory* theVariantEditorFactory_;

public:

	FrgBaseTreeItem(const FrgString& itemName, FrgBaseTreeItem* parentItem = FrgNullPtr, FrgTree* parentTree = FrgNullPtr, FrgMainWindow* parentMainWindow = FrgNullPtr);

	void CreateProperty();

	FrgGetMacro(FrgMainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgTree*, ParentTree, theParentTree_);
	FrgGetMacro(FrgString, ObjectName, theObjectName_);
	FrgGetMacro(QtTreePropertyBrowser*, Property, theProperty_);
};

EndFrgBaseLib

#endif // !_FrgTreeItem_Header
