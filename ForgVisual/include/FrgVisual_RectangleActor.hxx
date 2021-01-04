#pragma once
#ifndef _FrgVisual_RectangleActor_Header
#define _FrgVisual_RectangleActor_Header

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
class FrgVisual_PolylineActor;

class FORGVISUAL_EXPORT FrgVisual_RectangleActor
	: public FrgVisual_PolylineActor<2>
{
	typedef FrgVisual_PolylineActor<2> SuperClass;

public:

	FrgVisual_RectangleActor();

	static FrgVisual_RectangleActor* New();
	vtkTypeMacro(FrgVisual_RectangleActor, FrgVisual_PolylineActor<2>);

	void SetRepresentationToPoints();
	void SetRepresentationToSurface();
	void SetRepresentationToWireframe();

	void SetEdgeColor(double red, double green, double blue);
	void SetColor(double red, double green, double blue) override;

	void SetData(ForgBaseLib::FrgBase_Pnt<2> P0, ForgBaseLib::FrgBase_Pnt<2> P1);
	void SetData(double P0_X, double P0_Y, double P1_X, double P1_Y);

	void SetP0(ForgBaseLib::FrgBase_Pnt<2> p0);
	void SetP0(double x, double y);
	void SetP1(ForgBaseLib::FrgBase_Pnt<2> p1);
	void SetP1(double x, double y);

	void RemoveActors(vtkRenderer* renderer) override;

	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

private:

	DECLARE_SAVE_LOAD_HEADER( )
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_RectangleActor)

#endif // !_FrgVisual_RectangleActor_Header
