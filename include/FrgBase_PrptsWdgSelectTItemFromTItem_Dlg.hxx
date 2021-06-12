#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Header
#define _FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base.hxx>

BeginForgBaseLib

template <typename Type>
class FrgBase_PrptsWdgSelectTItemFromTItem_Dlg
	: public FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Base
{

public:

	FrgBase_PrptsWdgSelectTItemFromTItem_Dlg
	(
		const QString& dialogTitle,
		FrgBase_MainWindow* parentMainWindow,
		FrgBase_PrptsVrnt* myVariant
	);

protected:

	void setupLayout() override;
	void TItemIsClicked(QTreeWidgetItem* item, int column) override;
};

EndForgBaseLib

#include <FrgBase_PrptsWdgSelectTItemFromTItem_DlgI.hxx>

#endif // !_FrgBase_PrptsWdgSelectTItemFromTItem_Dlg_Header
