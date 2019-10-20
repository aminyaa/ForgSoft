#pragma once
#ifndef _FrgBaseSceneTreeItem_Header
#define _FrgBaseSceneTreeItem_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

#include <QVTKOpenGLNativeWidget.h>

class vtkCamera;
class vtkActor;
class vtkGenericOpenGLRenderWindow;
class vtkTextActor;

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseTreeItem;
class FrgBaseTree;
class FrgBaseInteractorStyle;

class FORGBASE_EXPORT FrgBaseSceneTreeItem : public QVTKOpenGLNativeWidget, public FrgBaseTreeItem
{

private:

	vtkSmartPointer<vtkRenderer> theRenderer_;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;

	vtkSmartPointer<vtkRenderWindowInteractor> theRenderWindowInteractor_;

	vtkSmartPointer<FrgBaseInteractorStyle> theInteractorStyle_;

	vtkSmartPointer<vtkCamera> theCamera_;

	vtkSmartPointer<vtkTextActor> theLogoActor_;

	void Init();


public:

	FrgBaseSceneTreeItem
	(
		const FrgString& title,
		FrgBaseTreeItem* parent = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainwindow = FrgNullPtr
	);

	void StartScene();

	FrgGetMacro(vtkSmartPointer<vtkRenderer>, Renderer, theRenderer_);
	FrgGetMacro(vtkSmartPointer<vtkRenderWindowInteractor>, RenderWindowInteractor, theRenderWindowInteractor_);
	FrgGetMacro(vtkSmartPointer<FrgBaseInteractorStyle>, InteractorStyle, theInteractorStyle_);
	FrgGetMacro(vtkSmartPointer<vtkCamera>, Camera, theCamera_);
	FrgGetMacro(vtkSmartPointer<vtkTextActor>, LogoActor, theLogoActor_);

	void Render();
};

EndFrgBaseLib

#endif // !_FrgBaseSceneTreeItem_Header
