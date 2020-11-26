#pragma once
#ifndef _FrgVisual_ConicActor_Header
#define _FrgVisual_ConicActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_SolidActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_ConicActor
	: public FrgVisual_SolidActor<Dim>
{
	typedef FrgVisual_SolidActor<Dim> SuperClass;

public:

	FrgVisual_ConicActor();

	static FrgVisual_ConicActor* New();
	vtkTypeMacro(FrgVisual_ConicActor, FrgVisual_SolidActor<Dim>);

private:

	DECLARE_SAVE_LOAD_HEADER( )
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_ConicActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_ConicActor<3>)

#include <FrgVisual_ConicActorI.hxx>

#endif // !_FrgVisual_ConicActor_Header
