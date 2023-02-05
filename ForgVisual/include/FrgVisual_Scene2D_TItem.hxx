#pragma once
#ifndef _FrgVisual_Scene2D_TItem_Header
#define _FrgVisual_Scene2D_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Scene_TItem.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FrgVisual_Scene2D;

class FORGVISUAL_EXPORT FrgVisual_Scene2D_TItem
	: public FrgVisual_Scene_TItem<2>
{
	Q_OBJECT

public:

	FrgVisual_Scene2D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

	bool Is2D() const override { return true; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Scene2D_TItem, FORGVISUAL_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene2D_TItem)

#endif // !_FrgVisual_Scene2D_TItem_Header
