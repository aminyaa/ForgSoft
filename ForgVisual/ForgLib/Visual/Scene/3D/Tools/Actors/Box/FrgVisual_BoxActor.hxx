#pragma once
#ifndef _FrgVisual_BoxActor_Header
#define _FrgVisual_BoxActor_Header

#include <FrgVisual_Global.hxx>
#include <vtkOpenGLActor.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_BoxActor
	: public vtkOpenGLActor
{
	typedef vtkOpenGLActor SuperClass;

public:

	FrgVisual_BoxActor();

	static FrgVisual_BoxActor* New();
	vtkTypeMacro(FrgVisual_BoxActor, vtkOpenGLActor);

	void SetRepresentationToPoints();
	void SetRepresentationToSurface();
	void SetRepresentationToWireframe();

	void SetColor(double red, double green, double blue);
	void SetEdgeColor(double red, double green, double blue);
};

EndForgVisualLib

#endif // !_FrgVisual_BoxActor_Header
