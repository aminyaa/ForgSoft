#pragma once
#ifndef _FrgVisual_SurfaceActor_Header
#define _FrgVisual_SurfaceActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_BaseActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_SurfaceActor
	: public FrgVisual_BaseActor<Dim>
{
	typedef FrgVisual_BaseActor<Dim> SuperClass;

public:

	FrgVisual_SurfaceActor();

	//static FrgVisual_SurfaceActor* New();
	vtkTypeMacro(FrgVisual_SurfaceActor, FrgVisual_BaseActor<Dim>);

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SurfaceActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SurfaceActor<3>)

#endif // !_FrgVisual_SurfaceActor_Header
