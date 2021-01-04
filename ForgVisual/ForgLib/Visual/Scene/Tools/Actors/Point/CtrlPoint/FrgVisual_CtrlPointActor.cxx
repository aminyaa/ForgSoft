#include <FrgVisual_CtrlPointActor.hxx>
#include <FrgVisual_PolylineActor.hxx>
#include <FrgVisual_BSPLineActor.hxx>

#include <FrgBase_Pnt.hxx>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_CtrlPointActor<Dim>);

template<int Dim>
ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::FrgVisual_CtrlPointActor()
{
	this->SetSize(10.0f);
	this->SetRenderPointsAsSpheres(true);
	this->VisibilityOn();

	SetIndependent(false);
}

template<int Dim>
ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::~FrgVisual_CtrlPointActor()
{

}

//template<int Dim>
//void ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::TranslateActor(double dx, double dy)
//{
//	if constexpr (Dim == 2)
//		theP_->Translate(dx, dy);
//
//	emit DataChangedSignal();
//}

//template<int Dim>
//void ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::TranslateActor(double dx, double dy, double dz)
//{
//	if constexpr (Dim == 3)
//		theP_->Translate(dx, dy, dz);
//
//	emit DataChangedSignal();
//}

//template<int Dim>
//void ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::SetParentPolylineActor(FrgVisual_PolylineActor<Dim>* parentPolyLineActor)
//{
//	theParentPolyLineActor_ = parentPolyLineActor;
//
//	if (theParentPolyLineActor_)
//	{
//		if (theParentPolyLineActor_->GetParentBSPLineActor())
//		{
//			QObject::connect
//			(
//				dynamic_cast<FrgVisual_BaseActor_Entity*>(this),
//				SIGNAL(SelectionHasChangedSignal()),
//				dynamic_cast<FrgVisual_BSPLineActor_Entity*>(theParentPolyLineActor_->GetParentBSPLineActor()),
//				SLOT(CtrlPtsSelectionHasChangedSlot())
//			);
//			QObject::connect
//			(
//				dynamic_cast<FrgVisual_BaseActor_Entity*>(this),
//				SIGNAL(DataChangedSignal()),
//				dynamic_cast<FrgVisual_BSPLineActor_Entity*>(theParentPolyLineActor_->GetParentBSPLineActor()),
//				SLOT(CtrlPtsDataHasChangedSlot())
//			);
//		}
//	}
//}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::CtrlPoint);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Point);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_CtrlPointActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_PointActor<Dim>>(*this);
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_CtrlPointActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_PointActor<Dim>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_CtrlPointActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_CtrlPointActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_CtrlPointActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_CtrlPointActor<3>;