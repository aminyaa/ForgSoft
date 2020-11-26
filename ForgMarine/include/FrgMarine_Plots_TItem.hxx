#pragma once
#ifndef _FrgMarine_Plots_TItem_Header
#define _FrgMarine_Plots_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgMarine_Serialization_Global.hxx>

BeginForgMarineLib

class FrgMarine_Plot2D_TItem;

class FORGMARINE_EXPORT FrgMarine_Plots_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_Plots_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

	FrgMarine_Plot2D_TItem* AddPlot2D();

private:

	DECLARE_SAVE_LOAD_HEADER(FORGMARINE_EXPORT)

private slots:

	void AddPlot2DSlot();
};

EndForgMarineLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgMarineLib::FrgMarine_Plots_TItem, FORGMARINE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_Plots_TItem)

#endif // !_FrgMarine_Plots_TItem_Header
