#pragma once
#ifndef _FrgVisual_PointActor_Header
#define _FrgVisual_PointActor_Header

#include <FrgVisual_Global.hxx>
#include <vtkOpenGLActor.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_PointActor
	: public vtkOpenGLActor
{

	typedef vtkOpenGLActor SuperClass;

public:

	static FrgVisual_PointActor* New();
	vtkTypeMacro(FrgVisual_PointActor, vtkOpenGLActor);

	~FrgVisual_PointActor();

protected:

	FrgVisual_PointActor();
};

EndForgVisualLib

#endif // !_FrgVisual_PointActor_Header
