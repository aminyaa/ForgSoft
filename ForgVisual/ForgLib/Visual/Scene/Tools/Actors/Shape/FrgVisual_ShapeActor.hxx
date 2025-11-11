#pragma once
#ifndef _FrgVisual_ShapeActor_Header
#define _FrgVisual_ShapeActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_BaseActor.hxx>
#include <TopoDS_Shape.hxx>

#include <FrgVisual_Serialization_Global.hxx>

class vtkSphereSource;

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_ShapeActor
	: public FrgVisual_BaseActor<3>
{
	typedef FrgVisual_BaseActor<3> SuperClass;

public:

	FrgVisual_ShapeActor();

	static FrgVisual_ShapeActor* New();
	vtkTypeMacro(FrgVisual_ShapeActor, FrgVisual_BaseActor<3>);

	void SetData(const ForgBaseLib::FrgBase_Pnt<3>& center, const double radius);

	void SetRepresentationToPoints();
	void SetRepresentationToSurface();
	void SetRepresentationToWireframe();

	void SetEdgeColor(double red, double green, double blue);

	void SetData(const TopoDS_Shape& shape);

	ActorType GetActorType() const override;
	std::vector<ActorType> GetActorTypes() const override;
	ActorDimension GetActorDimension() const override;

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	TopoDS_Shape theShape_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_ShapeActor)

#endif // !_FrgVisual_ShapeActor_Header
