#pragma once
#ifndef _FrgVisual_CtrlPointActor_Header
#define _FrgVisual_CtrlPointActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_PointActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_Pnt2d;
}

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_CtrlPointActor
	: public FrgVisual_PointActor<Dim>
{

	typedef FrgVisual_PointActor<Dim> SuperClass;

public:

	static FrgVisual_CtrlPointActor* New();
	vtkTypeMacro(FrgVisual_CtrlPointActor, FrgVisual_PointActor<Dim>);

	~FrgVisual_CtrlPointActor();

	//void TranslateActor(double dx, double dy) override;
	//void TranslateActor(double dx, double dy, double dz) override;

	//void SetParentPolylineActor(FrgVisual_PolylineActor<Dim>* parentPolyLineActor) override;

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

private:

	DECLARE_SAVE_LOAD_HEADER( )

protected:

	FrgVisual_CtrlPointActor();
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_CtrlPointActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_CtrlPointActor<3>)

#include <FrgVisual_CtrlPointActorI.hxx>

#endif // !_FrgVisual_CtrlPointActor_Header
