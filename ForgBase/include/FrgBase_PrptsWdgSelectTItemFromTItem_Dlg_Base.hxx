#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base_Header
#define _FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QDialog>

class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QTreeWidgetItem;

BeginForgBaseLib

class FrgBase_MainWindow;
class FrgBase_TreeItem;
class FrgBase_PrptsWdgSelectTItemFromTItem_Tree;
class FrgBase_PrptsVrnt;

class FORGBASE_EXPORT FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base
	: public QDialog
{
	Q_OBJECT

protected:

	QVBoxLayout* theMainLayout_ = nullptr;
	QHBoxLayout* theButtonsLayout_ = nullptr;
	QPushButton* theOKButton_ = nullptr;
	QPushButton* theCancelButton_ = nullptr;

	FrgBase_PrptsWdgSelectTItemFromTItem_Tree* theTree_ = nullptr;
	//FrgBase_TreeItem* theParentTItem_ = nullptr;
	QTreeWidgetItem* theSelectedTItem_ = nullptr;
	FrgBase_PrptsVrnt* theVariant_ = nullptr;
	std::map<QTreeWidgetItem*, QTreeWidgetItem*> theMapTreeToSelectionTree_;
	std::map<QTreeWidgetItem*, QTreeWidgetItem*> theMapSelectionTreeToTree_;

	virtual void setupLayout() {}

public:

	FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base
	(
		const QString& dialogTitle,
		FrgBase_MainWindow* parentMainWindow,
		FrgBase_PrptsVrnt* myVariant
	);

	~FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base();

	QTreeWidgetItem* GetSelectedTItem() const { return theSelectedTItem_; }

private slots:

	void onOK();
	virtual void itemClickedSlot(QTreeWidgetItem* item, int column);

protected:

	void keyPressEvent(QKeyEvent* event) override;
	virtual void TItemIsClicked(QTreeWidgetItem* item, int column) {}
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base_Header
