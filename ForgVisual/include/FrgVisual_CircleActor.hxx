#pragma once
#ifndef _FrgVisual_CircleActor_Header
#define _FrgVisual_CircleActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_PolylineActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

template<int Dim>
class FrgVisual_PointActor;

template<int Dim>
class FrgVisual_PolylineActor;

class FORGVISUAL_EXPORT FrgVisual_CircleActor
	: public FrgVisual_PolylineActor<2>
{
	typedef FrgVisual_PolylineActor<2> SuperClass;

public:

	FrgVisual_CircleActor();

	static FrgVisual_CircleActor* New();
	vtkTypeMacro(FrgVisual_CircleActor, FrgVisual_PolylineActor<2>);

	void SetData(ForgBaseLib::FrgBase_Pnt<2> center, double radius);
	void SetDataCenterAndPointOnCurve(ForgBaseLib::FrgBase_Pnt<2> P0, ForgBaseLib::FrgBase_Pnt<2> pointOnCurve);
	void SetPointOnCurve(ForgBaseLib::FrgBase_Pnt<2> p);
	void ShowPoints(bool condition = true) override;

	double GetRadius() const;
	ForgBaseLib::FrgBase_Pnt<2> GetCenterPoint() const;

	void RemoveActors(vtkRenderer* renderer) override;

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

protected:

	FrgVisual_PointActor<2>* theCenterPoint_ = nullptr;

private:

	DECLARE_SAVE_LOAD_HEADER()
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_CircleActor)

#endif // !_FrgVisual_CircleActor_Header
