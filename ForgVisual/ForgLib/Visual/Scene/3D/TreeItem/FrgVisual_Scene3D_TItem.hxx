#pragma once
#ifndef _FrgVisual_Scene3D_TItem_Header
#define _FrgVisual_Scene3D_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Scene_TItem.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FrgVisual_Scene3D;

class FORGVISUAL_EXPORT FrgVisual_Scene3D_TItem
	: public FrgVisual_Scene_TItem<3>
{
	Q_OBJECT

public:

	FrgVisual_Scene3D_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Scene3D_TItem, FORGVISUAL_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene3D_TItem)

#endif // !_FrgVisual_Scene3D_TItem_Header
