#pragma once
#ifndef _FrgMarine_Plots_TItem_Header
#define _FrgMarine_Plots_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgMarineLib

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

public slots:

	void AddPlot2DSlot();
};

EndForgMarineLib

#endif // !_FrgMarine_Plots_TItem_Header
