#include <FrgVisual_SceneAttributes_TItem.hxx>

#include <FrgVisual_SceneAttBackColor_TItem.hxx>
#include <FrgVisual_SceneAttAxes_TItem.hxx>

#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity::FrgVisual_SceneAttributes_TItem_Entity
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	this->setHidden(true);
}

void ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();
}

template <int Dim>
ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>::FrgVisual_SceneAttributes_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_SceneAttributes_TItem_Entity(itemTitle, parentItem, parentTree)
{

}

template <int Dim>
void ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>::FormTItem()
{
	FrgVisual_SceneAttributes_TItem_Entity::FormTItem();

	theBackgroundColor_ = new FrgVisual_SceneAttBackColor_TItem<Dim>("Background Color", this, GetParentTree());
	theBackgroundColor_->FormTItem();

	theAxes_ = new FrgVisual_SceneAttAxes_TItem<Dim>("Axes", this, GetParentTree());
	theAxes_->FormTItem();
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity);
}

template <int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theBackgroundColor_;
	ar& theAxes_;
}

template <int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theBackgroundColor_;
	ar& theAxes_;
}

template<class Archive, int Dim>
void boost::serialization::save_construct_data
(
	Archive& ar,
	const ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>* t,
	const unsigned int version
)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>);
}

template<class Archive, int Dim>
void boost::serialization::load_construct_data
(
	Archive& ar,
	ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>* t,
	const unsigned int version
)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttributes_TItem<Dim>);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttributes_TItem_Entity)

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttributes_TItem<2>)
BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttributes_TItem<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SceneAttributes_TItem<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SceneAttributes_TItem<3>;