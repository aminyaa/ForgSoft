#pragma once
#ifndef _FrgVisual_PolylineActor_Header
#define _FrgVisual_PolylineActor_Header

#include <FrgVisual_Global.hxx>
#include <vtkOpenGLActor.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_PolylineActor
	: public vtkOpenGLActor
{
	typedef vtkOpenGLActor SuperClass;

public:

	FrgVisual_PolylineActor();

	~FrgVisual_PolylineActor();

	static FrgVisual_PolylineActor* New();
	vtkTypeMacro(FrgVisual_PolylineActor, vtkOpenGLActor);

};

EndForgVisualLib

#endif // !_FrgVisual_PolylineActor_Header
