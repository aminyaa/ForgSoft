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
	FrgBase_TreeItem* theLastLeftClickedTItem_ = nullptr;
	FrgBase_TreeItem* theLastRightClickedTItem_ = nullptr;
};

class FORGBASE_EXPORT FrgBase_Tree
	: public QTreeWidget
	, public FrgBase_Object
	, public FrgBase_TreeCache
{

	Q_OBJECT

protected:

	FrgBase_MainWindow* theParentMainWindow_ = nullptr;

	std::vector<ForgBaseLib::FrgBase_TreeItem*> theDraggedTItems_;

public:

	FrgBase_Tree
	(
		FrgBase_MainWindow* parentMainWindow = nullptr
	);

	~FrgBase_Tree();

	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);

	virtual void SetParentMainWindow(FrgBase_MainWindow* parentMainWindow);

	virtual void FormTree();
	virtual void ScrollToItem(FrgBase_TreeItem* item);
	virtual void ScrollToItems(QList<FrgBase_TreeItem*> items);

	FrgBase_TreeItem* FindTItemByObjectName(const QString& objectName);

	std::vector<FrgBase_TreeItem*> GetAllItems() const;
	std::vector<FrgBase_TreeItem*> GetItemsUsingLevel(int level) const;

	virtual void SetThemeDark(const bool isDark = false);

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	void keyPressEvent(QKeyEvent* event) override;

	void dropEvent(QDropEvent* event) override;
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;

Q_SIGNALS:

	void ChildTItemDeletedSignal(FrgBase_TreeItem* TItem);

protected Q_SLOTS:

	virtual void itemClickedSlot(QTreeWidgetItem* item, int column);
	virtual void itemDoubleClickedSlot(QTreeWidgetItem* item, int column);

public Q_SLOTS:

	virtual void onCustomContextMenuRequested(const QPoint& pos);
	virtual void showContextMenu(FrgBase_TreeItem* item, const QPoint& globalPos);
	virtual void DeleteTreeItemSlot(FrgBase_TreeItem* TItem);
	virtual void DeleteTreeItemSlot();
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Tree)

#endif // !_FrgBase_Tree_Header