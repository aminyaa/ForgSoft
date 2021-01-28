#pragma once
#ifndef _FrgBase_Tree_Header
#define _FrgBase_Tree_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>

#include <FrgBase_Serialization_Global.hxx>

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

protected:

	FrgBase_MainWindow* theParentMainWindow_ = NullPtr;

	void keyPressEvent(QKeyEvent* event);

public:

	FrgBase_Tree
	(
		FrgBase_MainWindow* parentMainWindow = nullptr
	);

	~FrgBase_Tree();

	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);

	void SetParentMainWindow(FrgBase_MainWindow* parentMainWindow);

	virtual void FormTree();
	void ScrollToItem(FrgBase_TreeItem* item);
	void ScrollToItems(QList<FrgBase_TreeItem*> items);

	FrgBase_TreeItem* FindTItemByObjectName(const QString& objectName);

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)
// 	friend class boost::serialization::access;
// 	template<class Archive>
// 	void save(Archive & ar, const unsigned int version) const;
// 	template<class Archive>
// 	void load(Archive & ar, const unsigned int version);
// 	BOOST_SERIALIZATION_SPLIT_MEMBER()

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

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Tree)

#endif // !_FrgBase_Tree_Header