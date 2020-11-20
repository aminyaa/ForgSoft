#pragma once
#ifndef _FrgMarine_Plot2D_TItem_Header
#define _FrgMarine_Plot2D_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>

#include <FrgMarine_Serialization_Global.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_Plot2D_TItem
	: public ForgVisualLib::FrgVisual_Plot2D_TItem
{
	Q_OBJECT

public:

	FrgMarine_Plot2D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGMARINE_EXPORT)
};

EndForgMarineLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgMarineLib::FrgMarine_Plot2D_TItem, FORGMARINE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_Plot2D_TItem)

#endif // !_FrgMarine_Plot2D_TItem_Header
