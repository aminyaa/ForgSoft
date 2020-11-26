#pragma once
#ifndef _FrgVisual_SceneAttBackColorGradient_TItem_Header
#define _FrgVisual_SceneAttBackColorGradient_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgBase_PrptsVrntCombo.hxx>
#include <FrgBase_PrptsVrntColor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_SceneAttBackColorGradient_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{

	Q_OBJECT

public:

	FrgVisual_SceneAttBackColorGradient_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

	const QString& GetMode() const;
	const QColor& GetColor1() const;
	const QColor& GetColor2() const;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

Q_SIGNALS:

	void ModeChangedSignal(const QString&);
	void Color1ChangedSignal(const QColor&);
	void Color2ChangedSignal(const QColor&);

private:

	ForgBaseLib::FrgBase_PrptsVrntCombo* theMode_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntColor* theColor1_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntColor* theColor2_ = nullptr;
};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem, FORGVISUAL_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem)

#endif // !_FrgVisual_SceneAttBackColorGradient_TItem_Header
