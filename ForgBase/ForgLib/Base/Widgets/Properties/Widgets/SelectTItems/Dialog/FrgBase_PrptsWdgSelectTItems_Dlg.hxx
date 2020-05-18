#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItems_Dlg_Header
#define _FrgBase_PrptsWdgSelectTItems_Dlg_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Dlg.hxx>

class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QTreeWidgetItem;

BeginForgBaseLib

class FrgBase_MainWindow;
class FrgBase_TreeItem;
class FrgBase_PrptsWdgSelectTItems_Tree;

class FORGBASE_EXPORT FrgBase_PrptsWdgSelectTItems_Dlg
	: public FrgBase_Dlg
{
	Q_OBJECT

protected:

	QVBoxLayout* theMainLayout_ = NullPtr;
	QHBoxLayout* theButtonsLayout_ = NullPtr;
	QPushButton* theOKButton_ = NullPtr;
	QPushButton* theCancelButton_ = NullPtr;

	FrgBase_PrptsWdgSelectTItems_Tree* theTree_ = NullPtr;
	FrgBase_TreeItem* theParentTItem_ = NullPtr;
	std::vector<QTreeWidgetItem*> theListOfSelectedTItems_;
	std::map<QTreeWidgetItem*, QTreeWidgetItem*> theMapTreeToSelectionTree_;
	std::map<QTreeWidgetItem*, QTreeWidgetItem*> theMapSelectionTreeToTree_;

	void setupLayout();

public:

	FrgBase_PrptsWdgSelectTItems_Dlg
	(
		const QString& dialogTitle,
		FrgBase_MainWindow* parentMainWindow,
		FrgBase_TreeItem* parentTItem,
		std::vector<QTreeWidgetItem*> selectedTItems
	);

	~FrgBase_PrptsWdgSelectTItems_Dlg();

	std::vector<QTreeWidgetItem*> GetListOfSelectedTItems() const { return theListOfSelectedTItems_; }

private slots:

	void onOK();
	void ItemSelectionChangedSlot();

protected:

	void keyPressEvent(QKeyEvent* event) override;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgSelectTItems_Dlg_Header
