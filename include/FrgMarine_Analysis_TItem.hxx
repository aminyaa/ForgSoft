#pragma once
#ifndef _FrgMarine_Analysis_TItem_Header
#define _FrgMarine_Analysis_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgMarineLib

class FrgMarine_Analysis_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_Analysis_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;
};

EndForgMarineLib

#endif // !_FrgMarine_Analysis_TItem_Header
