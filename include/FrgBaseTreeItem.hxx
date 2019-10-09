#pragma once
#ifndef _FrgBaseTreeItem_Header
#define _FrgBaseTreeItem_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QTreeWidgetItem>

class QtTreePropertyBrowser;
class QtVariantPropertyManager;
class QtVariantEditorFactory;
class QtBrowserItem;
class QtProperty;
class QVariant;

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseTree;
class FrgBaseTreeItemProperty;

class FORGBASE_EXPORT FrgBaseTreeItem : public QTreeWidgetItem
{

private:

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	FrgBaseTree* theParentTree_ = FrgNullPtr;
	FrgString theObjectName_;

	FrgBaseTreeItemProperty* theProperty_;

	/*QtTreePropertyBrowser* theProperty_;
	QtVariantPropertyManager* theVariantPropertyManager_;
	QtVariantEditorFactory* theVariantEditorFactory_;*/

public:

	FrgBaseTreeItem(const FrgString& itemName, FrgBaseTreeItem* parentItem = FrgNullPtr, FrgBaseTree* parentTree = FrgNullPtr, FrgBaseMainWindow* parentMainWindow = FrgNullPtr);

	void CreateProperty();

	FrgGetMacro(FrgBaseMainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBaseTree*, ParentTree, theParentTree_);
	FrgGetMacro(FrgString, ObjectName, theObjectName_);
	//FrgGetMacro(QtTreePropertyBrowser*, Property, theProperty_);

	FrgGetMacro(FrgBaseTreeItemProperty*, Property, theProperty_);
};

EndFrgBaseLib

#endif // !_FrgBaseTreeItem_Header
