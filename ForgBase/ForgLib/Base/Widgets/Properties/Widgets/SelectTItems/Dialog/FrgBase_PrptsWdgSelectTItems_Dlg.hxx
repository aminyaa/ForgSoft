#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItems_Dlg_Header
#define _FrgBase_PrptsWdgSelectTItems_Dlg_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Dlg.hxx>

class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QTreeWidget;
class QTreeWidgetItem;

BeginForgBaseLib

class FrgBase_MainWindow;
class FrgBase_TreeItem;

class FORGBASE_EXPORT FrgBase_PrptsWdgSelectTItems_Dlg
	: public FrgBase_Dlg
{
	Q_OBJECT

private:

	QVBoxLayout* theMainLayout_ = NullPtr;
	QHBoxLayout* theButtonsLayout_ = NullPtr;
	QPushButton* theOKButton_ = NullPtr;
	QPushButton* theCancelButton_ = NullPtr;

	QTreeWidget* theTree_ = NullPtr;
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
		FrgBase_TreeItem* parentTItem
	);

	~FrgBase_PrptsWdgSelectTItems_Dlg();

	std::vector<QTreeWidgetItem*> GetListOfSelectedTItems() const { return theListOfSelectedTItems_; }

private slots:

	void onOK();

protected:

	void keyPressEvent(QKeyEvent* event) override;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgSelectTItems_Dlg_Header
