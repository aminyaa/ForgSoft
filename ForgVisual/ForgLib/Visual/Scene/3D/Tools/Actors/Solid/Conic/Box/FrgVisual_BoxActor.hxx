#pragma once
#ifndef _FrgVisual_BoxActor_Header
#define _FrgVisual_BoxActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_ConicActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_BoxActor
	: public FrgVisual_ConicActor<3>
{
	typedef FrgVisual_ConicActor<3> SuperClass;

public:

	FrgVisual_BoxActor();

	static FrgVisual_BoxActor* New();
	vtkTypeMacro(FrgVisual_BoxActor, FrgVisual_ConicActor<3>);

	void SetRepresentationToPoints();
	void SetRepresentationToSurface();
	void SetRepresentationToWireframe();

	void SetEdgeColor(double red, double green, double blue);

	void SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> P1);

private:

	DECLARE_SAVE_LOAD_HEADER( )

private:

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> theP0_;
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> theP1_;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BoxActor)

#endif // !_FrgVisual_BoxActor_Header
