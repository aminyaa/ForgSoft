#pragma once
#ifndef _FrgBaseInteractorStyle_Header
#define _FrgBaseInteractorStyle_Header

#include <FrgBaseGlobals.hxx>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkObjectFactory.h>

#include <QtCore/QList>

class QColor;
class vtkActor;
class vtkProperty;

BeginFrgBaseLib

class FrgBaseCADScene;

class FORGBASE_EXPORT FrgBaseInteractorStyle : public vtkInteractorStyleTrackballCamera
{
	struct FrgBaseActor
	{
		vtkActor* theActor_ = nullptr;
		vtkProperty* theProperty_ = nullptr;
	};

private:

	QList<FrgBaseActor*> theSelectedActors_;

	QList<FrgBaseActor*> theHiddenActors_;

	FrgBaseCADScene* theParent_ = nullptr;

	int PreviousPosition[2];
	int ResetPixelDistance;

	vtkTypeMacro(FrgBaseInteractorStyle, vtkInteractorStyleTrackballCamera);

private:

	void SetSelectedActorColor(QColor color);

	void AddActorToSelectedActors(vtkActor* actor);

public:

	FrgBaseInteractorStyle();

	static FrgBaseInteractorStyle* New();

	void SetParent(FrgBaseCADScene* parent)
	{
		theParent_ = parent;
	}

	void HideSelectedActors();

	void ShowAllActors();

	void SetGeometriesOpacity(double opacity = 1.0);

	virtual void OnLeftButtonUp() override;

	virtual void OnLeftButtonDown() override;

	virtual void OnMouseWheelForward() override;

	virtual void OnMouseWheelBackward() override;

	virtual void OnMiddleButtonDown() override;

	virtual void OnRightButtonDown() override;

	virtual void OnRightButtonUp() override;

	virtual void OnChar() override;

	void SelectActor(vtkActor* actor, int isControlKeyPressed, FrgBool isFromTree = FrgFalse);

	FrgGetMacro(QList<FrgBaseActor*>, SelectedActors, theSelectedActors_);
	FrgGetMacro(FrgBaseCADScene*, ParentScene, theParent_);

	static QColor GeometryColorRGB;
	static QColor GeometrySelectedColorRGB;
};

EndFrgBaseLib

#endif // !_FrgBaseInteractorStyle_Header
