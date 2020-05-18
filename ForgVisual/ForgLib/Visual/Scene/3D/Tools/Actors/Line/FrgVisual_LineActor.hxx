#ifndef _FrgVisual_LineActor_Header
#define _FrgVisual_LineActor_Header

#include <FrgVisual_Global.hxx>
#include <vtkOpenGLActor.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_LineActor
	: public vtkOpenGLActor
{

	typedef vtkOpenGLActor SuperClass;

public:

	FrgVisual_LineActor();

	~FrgVisual_LineActor();

	static FrgVisual_LineActor* New();
	vtkTypeMacro(FrgVisual_LineActor, vtkOpenGLActor);
};

EndForgVisualLib

#endif // !_FrgVisual_LineActor_Header
#pragma once
