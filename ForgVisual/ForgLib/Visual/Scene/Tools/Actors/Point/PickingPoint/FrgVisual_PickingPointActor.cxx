#include <FrgVisual_PickingPointActor.hxx>
#include <FrgBase_Pnt.hxx>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_PickingPointActor<Dim>);

template<int Dim>
ForgVisualLib::FrgVisual_PickingPointActor<Dim>::FrgVisual_PickingPointActor()
{
	this->SetSize(5.0f);
	this->SetRenderPointsAsSpheres(true);
	this->VisibilityOn();
}

template<int Dim>
ForgVisualLib::FrgVisual_PickingPointActor<Dim>::~FrgVisual_PickingPointActor()
{

}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_PickingPointActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::PickingPoint);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Point);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_PickingPointActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_PickingPointActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_PointActor<Dim>>(*this);
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_PickingPointActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_PointActor<Dim>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PickingPointActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PickingPointActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PickingPointActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PickingPointActor<3>;