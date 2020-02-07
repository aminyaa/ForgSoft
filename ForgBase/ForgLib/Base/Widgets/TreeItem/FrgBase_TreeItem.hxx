#pragma once
#ifndef _FrgBase_TreeItem_header
#define _FrgBase_TreeItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <QtWidgets/QTreeWidgetItem>
#include <QtCore/QObject>

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
		
	//Q_PROPERTY(QString name READ GetTItemName WRITE SetTItemName NOTIFY TItemNameChanged)

private:

	FrgBase_Tree* theParentTree_ = NullPtr;
	FrgBase_MainWindow* theParentMainWindow_ = NullPtr;
	FrgBase_PropertiesPanel* thePropertiesPanel_ = NullPtr;
	FrgBase_Menu* theContextMenu_ = NullPtr;

	//QString theTItemName_;

signals:

	void TItemNameChanged(const QString&);

public:

	FrgBase_TreeItem
	(
		const FrgString& itemTitle,
		FrgBase_TreeItem* parentItem,
		FrgBase_Tree* parentTree
	);

	FrgGetMacro(FrgBase_Tree*, ParentTree, theParentTree_);
	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBase_PropertiesPanel*, PropertiesPanel, thePropertiesPanel_);
	FrgGetMacro(FrgBase_Menu*, ContextMenu, theContextMenu_);

	QList<FrgBase_TreeItem*> GetChildren();
	FrgBase_TreeItem* GetChild(const QString& name);

	virtual void DoAfterConstruct() {}

	QString GetTItemName() const;
	void SetTItemName(const QString& name);

public slots:

	void RenameTItemSlot();
};

EndForgBaseLib

#endif // !_FrgBase_TreeItem_header
