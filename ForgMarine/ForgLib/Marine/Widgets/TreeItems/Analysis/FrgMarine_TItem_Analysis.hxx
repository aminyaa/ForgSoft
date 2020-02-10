#pragma once
#ifndef _FrgMarine_TItem_Analysis_Header
#define _FrgMarine_TItem_Analysis_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_TItem_Analysis
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_TItem_Analysis
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

private slots:

	void NewHydrostaticsClickedSlot();
};

EndForgMarineLib

#endif // !_FrgMarine_TItem_Analysis_Header
