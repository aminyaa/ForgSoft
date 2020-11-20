#pragma once
#ifndef _FrgVisual_SceneAttBackColor_TItem_Header
#define _FrgVisual_SceneAttBackColor_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgBase_PrptsVrntCombo.hxx>
#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_SceneAttBackColor_TItem_Entity
	: public ForgBaseLib::FrgBase_TreeItem
{

	Q_OBJECT

public:

	FrgVisual_SceneAttBackColor_TItem_Entity
	(
		const QString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

Q_SIGNALS:

	void GradientModeChangedSignal(const QString&);
	void GradientColor1ChangedSignal(const QColor&);
	void GradientColor2ChangedSignal(const QColor&);
	void SolidColorChangedSignal(const QColor&);

protected slots:

	virtual void BackgroundColorModeChangedSlot(const QString& item) {}
};

class FrgVisual_SceneAttBackColorSolid_TItem;
class FrgVisual_SceneAttBackColorGradient_TItem;

template <int Dim>
class FORGVISUAL_EXPORT FrgVisual_SceneAttBackColor_TItem
	: public FrgVisual_SceneAttBackColor_TItem_Entity
{

public:

	FrgVisual_SceneAttBackColor_TItem
	(
		const QString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

	FrgVisual_SceneAttBackColorSolid_TItem* GetSolidBackground() const { return theSolidBackground_; }
	FrgVisual_SceneAttBackColorGradient_TItem* GetGradientBackground() const { return theGradientBackground_; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

public:

	void GradientModeChangedSignal(const QString&);
	void GradientColor1ChangedSignal(const QColor&);
	void GradientColor2ChangedSignal(const QColor&);
	void SolidColorChangedSignal(const QColor&);

protected:

	void BackgroundColorModeChangedSlot(const QString& item) override;

private:

	ForgBaseLib::FrgBase_PrptsVrntCombo* theBackgroundColorMode_ = nullptr;

	FrgVisual_SceneAttBackColorSolid_TItem* theSolidBackground_ = nullptr;
	FrgVisual_SceneAttBackColorGradient_TItem* theGradientBackground_ = nullptr;
};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity, FORGVISUAL_EXPORT)

namespace boost
{
	namespace serialization
	{
		template<class Archive, int Dim>
		void save_construct_data
		(
			Archive& ar,
			const ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>* m,
			const unsigned int version
		);

		template<class Archive, int Dim>
		void load_construct_data
		(
			Archive& ar,
			ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>* m,
			const unsigned int version
		);
	}
}

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<3>)

#endif // !_FrgVisual_SceneAttBackColor_TItem_Header
