#pragma once
#ifndef _FrgMaine_Scenes_TItem_Header
#define _FrgMaine_Scenes_TItem_Header

#include <FrgMarine_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgMarine_Serialization_Global.hxx>

BeginForgMarineLib

class FORGMARINE_EXPORT FrgMarine_Scenes_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{
	Q_OBJECT

public:

	FrgMarine_Scenes_TItem
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

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgMarineLib::FrgMarine_Scenes_TItem, FORGMARINE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgMarineLib::FrgMarine_Scenes_TItem)

#endif // !_FrgMaine_Scenes_TItem_Header
