#pragma once
#ifndef _FrgVisual_SolidActor_Header
#define _FrgVisual_SolidActor_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_BaseActor.hxx>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_SolidActor
	: public FrgVisual_BaseActor<Dim>
{
	typedef FrgVisual_BaseActor<Dim> SuperClass;

public:

	FrgVisual_SolidActor();

	static FrgVisual_SolidActor* New();
	vtkTypeMacro(FrgVisual_SolidActor, FrgVisual_BaseActor<Dim>);

private:

	DECLARE_SAVE_LOAD_HEADER( )
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SolidActor<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_SolidActor<3>)

#include <FrgVisual_SolidActorI.hxx>

#endif // !_FrgVisual_SolidActor_Header
