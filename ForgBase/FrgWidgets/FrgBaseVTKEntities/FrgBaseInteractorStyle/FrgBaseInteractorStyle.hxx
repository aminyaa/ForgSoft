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

class FrgBaseSceneTreeItem;

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

	FrgBaseSceneTreeItem* theParent_ = nullptr;

	int PreviousPosition[2];
	int ResetPixelDistance;

	vtkTypeMacro(FrgBaseInteractorStyle, vtkInteractorStyleTrackballCamera);

public:

	FrgBaseInteractorStyle();

	static FrgBaseInteractorStyle* New();

	void SetParent(FrgBaseSceneTreeItem* parent)
	{
		theParent_ = parent;
	}

	void SetSelectedActorColor(QColor color);

	void AddActorToSelectedActors(vtkActor* actor);

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

	FrgGetMacro(QList<FrgBaseActor*>, SelectedActors, theSelectedActors_);

	static QColor GeometryColorRGB;
	static QColor GeometrySelectedColorRGB;
};

EndFrgBaseLib

#endif // !_FrgBaseInteractorStyle_Header
