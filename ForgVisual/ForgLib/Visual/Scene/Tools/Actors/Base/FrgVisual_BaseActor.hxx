#pragma once
#ifndef _FrgVisual_BaseActor_Header
#define _FrgVisual_BaseActor_Header

#include <FrgVisual_Global.hxx>
#include <vtkOpenGLActor.h>

#include <FrgVisual_Serialization_Global.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_BaseActor
	: public vtkOpenGLActor
{
	typedef vtkOpenGLActor SuperClass;

public:

	FrgVisual_BaseActor();

	static FrgVisual_BaseActor* New();
	vtkTypeMacro(FrgVisual_BaseActor, vtkOpenGLActor);

	~FrgVisual_BaseActor();

	void SetColor(double red, double green, double blue);

private:

	DECLARE_SAVE_LOAD_HEADER
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_BaseActor)

#endif // !_FrgVisual_BaseActor_Header
