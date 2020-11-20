#pragma once
#ifndef _FrgVisual_SceneAttAxes_TItem_Header
#define _FrgVisual_SceneAttAxes_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgBase_PrptsVrntColor.hxx>
#include <FrgBase_PrptsVrntBool.hxx>
#include <FrgBase_PrptsVrntString.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_SceneAttAxes_TItem_Entity
	: public ForgBaseLib::FrgBase_TreeItem
{

	Q_OBJECT

public:

	FrgVisual_SceneAttAxes_TItem_Entity
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

Q_SIGNALS:

	void TextColorChangedSignal(const QColor&);
	void VisibleChangedSignal(const bool&);

	void XLabelChangedSignal(const QString&);
	void YLabelChangedSignal(const QString&);
	void ZLabelChangedSignal(const QString&);
};

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_SceneAttAxes_TItem
	: public FrgVisual_SceneAttAxes_TItem_Entity
{

public:

	FrgVisual_SceneAttAxes_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

private:

	ForgBaseLib::FrgBase_PrptsVrntColor* theTextColor_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntBool* theVisible_ = nullptr;

	ForgBaseLib::FrgBase_PrptsVrntString* theXLabel_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntString* theYLabel_ = nullptr;
	ForgBaseLib::FrgBase_PrptsVrntString* theZLabel_ = nullptr;
};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity, FORGVISUAL_EXPORT)

namespace boost
{
	namespace serialization
	{
		template<class Archive, int Dim>
		void save_construct_data
		(
			Archive& ar,
			const ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>* m,
			const unsigned int version
		);

		template<class Archive, int Dim>
		void load_construct_data
		(
			Archive& ar,
			ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>* m,
			const unsigned int version
		);
	}
}

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttAxes_TItem<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttAxes_TItem<3>)

#endif // !_FrgVisual_SceneAttAxes_TItem_Header
