#pragma once
#ifndef _FrgVisual_PickingPointActor_Header
#define _FrgVisual_PickingPointActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_PointActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_Pnt2d;
}

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_PickingPointActor
	: public FrgVisual_PointActor<Dim>
{

	typedef FrgVisual_PointActor<Dim> SuperClass;

public:

	static FrgVisual_PickingPointActor* New();
	vtkTypeMacro(FrgVisual_PickingPointActor, FrgVisual_PointActor<Dim>);

	~FrgVisual_PickingPointActor();

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	FrgVisual_PickingPointActor();
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PickingPointActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_PickingPointActor<3>)

#endif // !_FrgVisual_PickingPointActor_Header
