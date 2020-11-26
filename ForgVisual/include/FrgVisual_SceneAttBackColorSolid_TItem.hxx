#pragma once
#ifndef _FrgVisual_SceneAttBackColorSolid_TItem_Header
#define _FrgVisual_SceneAttBackColorSolid_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgBase_PrptsVrntColor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_SceneAttBackColorSolid_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{

	Q_OBJECT

public:

	FrgVisual_SceneAttBackColorSolid_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

	const QColor& GetColor() const;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

Q_SIGNALS:

	void ColorChangedSignal(const QColor&);

private:

	ForgBaseLib::FrgBase_PrptsVrntColor* theColor_ = nullptr;
};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem, FORGVISUAL_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem)

#endif // !_FrgVisual_SceneAttBackColorSolid_TItem_Header
