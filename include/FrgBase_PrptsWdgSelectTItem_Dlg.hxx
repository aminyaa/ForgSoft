#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItem_Dlg_Header
#define _FrgBase_PrptsWdgSelectTItem_Dlg_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgSelectTItem_Dlg_Base.hxx>

BeginForgBaseLib

template <typename Type>
class FrgBase_PrptsWdgSelectTItem_Dlg
	: public FrgBase_PrptsWdgSelectTItem_Dlg_Base
{

public:

	FrgBase_PrptsWdgSelectTItem_Dlg
	(
		const QString& dialogTitle,
		FrgBase_MainWindow* parentMainWindow,
		QTreeWidgetItem* selectedTItem
	);

protected:

	void setupLayout() override;
	void TItemIsClicked(QTreeWidgetItem *item, int column) override;
};

EndForgBaseLib

#include <FrgBase_PrptsWdgSelectTItem_DlgI.hxx>

#endif // !_FrgBase_PrptsWdgSelectTItem_Dlg_Header
