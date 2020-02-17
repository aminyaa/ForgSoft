#pragma once
#ifndef _FrgVisual_Scene_Header
#define _FrgVisual_Scene_Header

#include <FrgVisual_Global.hxx>
#include <QVTKOpenGLNativeWidget.h>

class vtkRenderer;
class vtkGenericOpenGLRenderWindow;
class vtkRenderWindowInteractor;
class vtkInteractorStyle;
class vtkCamera;
class vtkTextActor;

template<class T>
class vtkSmartPointer;

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Scene
	: public QVTKOpenGLNativeWidget
{

public:

	FrgVisual_Scene
	(
		ForgBaseLib::FrgBase_MainWindow* parentMainWindow
	);

	~FrgVisual_Scene();

	vtkSmartPointer<vtkRenderer> GetRenderer() { return theRenderer_; }
	void RemoveAllActors();
	virtual void SetLogoText(const char* logoText);
	virtual void RenderScene(bool resetCamera = true) {}

protected:

	vtkSmartPointer<vtkRenderer> theRenderer_;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;
	vtkSmartPointer<vtkRenderWindowInteractor> theRenderWindowInteractor_;
	vtkSmartPointer<vtkInteractorStyle> theInteractorStyle_;
	vtkSmartPointer<vtkCamera> theCamera_;
	vtkSmartPointer<vtkTextActor> theLogoActor_;

	virtual void Init() {}

};

EndForgVisualLib

#endif // !_FrgVisual_Scene_Header
