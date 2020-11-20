#pragma once
#ifndef _FrgVisual_SceneAttributes_TItem_Header
#define _FrgVisual_SceneAttributes_TItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

#include <FrgVisual_Serialization_Global.hxx>

template <int Dim>
class FrgVisual_SceneAttBackColor_TItem;

template <int Dim>
class FrgVisual_SceneAttAxes_TItem;

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_SceneAttributes_TItem_Entity
	: public ForgBaseLib::FrgBase_TreeItem
{

	Q_OBJECT

public:

	FrgVisual_SceneAttributes_TItem_Entity
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
};

template <int Dim>
class FORGVISUAL_EXPORT FrgVisual_SceneAttributes_TItem
	: public FrgVisual_SceneAttributes_TItem_Entity
{

public:

	FrgVisual_SceneAttributes_TItem
	(
		const FrgString& itemTitle,
		ForgBaseLib::FrgBase_TreeItem* parentItem,
		ForgBaseLib::FrgBase_Tree* parentTree
	);

	void FormTItem() override;

	FrgVisual_SceneAttBackColor_TItem<Dim>* GetBackgroundColor() const { return theBackgroundColor_; }
	FrgVisual_SceneAttAxes_TItem<Dim>* GetAxes() const { return theAxes_; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

private:

	FrgVisual_SceneAttBackColor_TItem<Dim>* theBackgroundColor_ = nullptr;
	FrgVisual_SceneAttAxes_TItem<Dim>* theAxes_ = nullptr;
};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity, FORGVISUAL_EXPORT)

namespace boost
{
	namespace serialization
	{
		template<class Archive, int Dim>
		void save_construct_data
		(
			Archive& ar,
			const ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>* m,
			const unsigned int version
		);

		template<class Archive, int Dim>
		void load_construct_data
		(
			Archive& ar,
			ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>* m,
			const unsigned int version
		);
	}
}

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttributes_TItem<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SceneAttributes_TItem<3>)

#endif // !_FrgVisual_SceneAttributes_TItem_Header
