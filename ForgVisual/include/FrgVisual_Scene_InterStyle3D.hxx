#pragma once
#ifndef _FrgVisual_Scene_InterStyle3D_Header
#define _FrgVisual_Scene_InterStyle3D_Header

#include <FrgVisual_Global.hxx>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkObjectFactory.h>

#include <QtCore/QList>

class QColor;
class vtkActor;
class vtkProperty;

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Scene_InterStyle3D
	: public vtkInteractorStyleTrackballCamera
{

public:

	enum SelectedIconFromScene
	{
		Cursor = 0,
		Move = 1,
		RotateX = 2,
		RotateY = 3,
		RotateZ = 4,
		RotateXYZ = 5
	};

	enum PlaneView
	{
		PlaneXY = 0,
		PlaneXZ = 1,
		PlaneYZ = 2,
		PlaneXYZ = 3
	};

private:

	struct FrgVisualActor
	{
		vtkActor* theActor_ = NullPtr;
		vtkProperty* theProperty_ = NullPtr;
	};

private:

	QList<FrgVisualActor*> theSelectedActors_;
	QList<FrgVisualActor*> theHiddenActors_;

	FrgBool theRotationEnabled_ = FrgTrue;

	SelectedIconFromScene theSelectedIconFromScene_ = Cursor;
	PlaneView thePlaneView_ = PlaneXYZ;

	int PreviousPosition[2];
	int ResetPixelDistance;

	vtkTypeMacro(FrgVisual_Scene_InterStyle3D, vtkInteractorStyleTrackballCamera);

private:

	void SetSelectedActorColor(QColor color);
	void AddActorToSelectedActors(vtkActor* actor);
	void SetCursorShapeToDefault();
	void SetCursorShapeToMove();
	void SetCursorShapeToRotateXYZ();
	void SetCursorShapeToZoomIn();
	void SetCursorShapeToZoomOut();

public:

	FrgVisual_Scene_InterStyle3D();

	static FrgVisual_Scene_InterStyle3D* New();

	FrgGetMacro(QList<FrgVisualActor*>, SelectedActors, theSelectedActors_);
	FrgGetMacro(QList<FrgVisualActor*>, HiddenActors, theHiddenActors_);

	void HideSelectedActors();
	void ShowAllActors();

	void OnLeftButtonUp() override;
	void OnLeftButtonDown() override;
	void OnMouseWheelForward() override;
	void OnMouseWheelBackward() override;
	void OnMiddleButtonDown() override;
	void OnRightButtonDown() override;
	void OnRightButtonUp() override;
	void OnMouseMove() override;
	void OnChar() override;

	void SelectActor(vtkActor* actor, int isControlKeyPressed, FrgBool isFromTree = FrgFalse);
	void SelectActors(QList<vtkActor*> actors, FrgBool isFromTree = FrgFalse);
	void UnSelectAllActors();

	static QColor GeometryColorRGB;
	static QColor GeometrySelectedColorRGB;

public:

	void SetViewToXYPlane();
	void SetViewToXZPlane();
	void SetViewToYZPlane();
	void SetViewToXYZ();

	void ShowMesh(FrgBool condition);
};

EndForgVisualLib

#endif // !_FrgVisual_Scene_InterStyle3D_Header
