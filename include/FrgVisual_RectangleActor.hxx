#pragma once
#ifndef _FrgVisual_RectangleActor_Header
#define _FrgVisual_RectangleActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_ConicActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_RectangleActor
	: public FrgVisual_ConicActor<2>
{
	typedef FrgVisual_ConicActor<2> SuperClass;

public:

	FrgVisual_RectangleActor();

	static FrgVisual_RectangleActor* New();
	vtkTypeMacro(FrgVisual_RectangleActor, FrgVisual_ConicActor<2>);

	void SetRepresentationToPoints();
	void SetRepresentationToSurface();
	void SetRepresentationToWireframe();

	void SetEdgeColor(double red, double green, double blue);

	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> P1);

private:

	DECLARE_SAVE_LOAD_HEADER( )

private:

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> theP0_;
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> theP1_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_RectangleActor)

#endif // !_FrgVisual_RectangleActor_Header
