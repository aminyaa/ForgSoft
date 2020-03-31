//#pragma once
//#ifndef _FrgVisual_Scene_InterStyle3D_Header
//#define _FrgVisual_Scene_InterStyle3D_Header
//
//#include <FrgVisual_Global.hxx>
//#include <vtkInteractorStyleTrackballCamera.h>
//#include <vtkObjectFactory.h>
//
//#include <QtCore/QList>
//
//class QColor;
//class vtkActor;
//class vtkProperty;
//
//BeginForgVisualLib
//
//class FORGVISUAL_EXPORT FrgVisual_Scene_InterStyle3D
//	: public vtkInteractorStyleTrackballCamera
//{
//
//public:
//
//	enum SelectedIconFromScene
//	{
//		Cursor = 0,
//		Move = 1,
//		RotateX = 2,
//		RotateY = 3,
//		RotateZ = 4,
//		RotateXYZ = 5
//	};
//
//	enum PlaneView
//	{
//		PlaneXY = 0,
//		PlaneXZ = 1,
//		PlaneYZ = 2,
//		PlaneXYZ = 3
//	};
//
//private:
//
//	struct FrgVisualActor
//	{
//		vtkActor* theActor_ = NullPtr;
//		vtkProperty* theProperty_ = NullPtr;
//	};
//
//private:
//
//	QList<FrgVisualActor*> theSelectedActors_;
//	QList<FrgVisualActor*> theHiddenActors_;
//
//	FrgBool theRotationEnabled_ = FrgTrue;
//
//	SelectedIconFromScene theSelectedIconFromScene_ = Cursor;
//	PlaneView thePlaneView_ = PlaneXYZ;
//
//	int PreviousPosition[2];
//	int ResetPixelDistance;
//
//	vtkTypeMacro(FrgVisual_Scene_InterStyle3D, vtkInteractorStyleTrackballCamera);
//
//private:
//
//	void SetSelectedActorColor(QColor color);
//	void AddActorToSelectedActors(vtkActor* actor);
//	void SetCursorShapeToDefault();
//	void SetCursorShapeToMove();
//	void SetCursorShapeToRotateXYZ();
//	void SetCursorShapeToZoomIn();
//	void SetCursorShapeToZoomOut();
//
//public:
//
//	FrgVisual_Scene_InterStyle3D();
//
//	static FrgVisual_Scene_InterStyle3D* New();
//
//	FrgGetMacro(QList<FrgVisualActor*>, SelectedActors, theSelectedActors_);
//	FrgGetMacro(QList<FrgVisualActor*>, HiddenActors, theHiddenActors_);
//
//	void HideSelectedActors();
//	void ShowAllActors();
//
//	void OnLeftButtonUp() override;
//	void OnLeftButtonDown() override;
//	void OnMouseWheelForward() override;
//	void OnMouseWheelBackward() override;
//	void OnMiddleButtonDown() override;
//	void OnRightButtonDown() override;
//	void OnRightButtonUp() override;
//	void OnMouseMove() override;
//	void OnChar() override;
//
//	void SelectActor(vtkActor* actor, int isControlKeyPressed, FrgBool isFromTree = FrgFalse);
//	void SelectActors(QList<vtkActor*> actors, FrgBool isFromTree = FrgFalse);
//	void UnSelectAllActors();
//
//	static QColor GeometryColorRGB;
//	static QColor GeometrySelectedColorRGB;
//
//public:
//
//	void SetViewToXYPlane();
//	void SetViewToXZPlane();
//	void SetViewToYZPlane();
//	void SetViewToXYZ();
//
//	void ShowMesh(FrgBool condition);
//};
//
//EndForgVisualLib
//
//#endif // !_FrgVisual_Scene_InterStyle3D_Header

#pragma once
#ifndef _FrgVisual_Scene_InterStyle3D_Header
#define  _FrgVisual_Scene_InterStyle3D_Header

#include <FrgVisual_Global.hxx>

#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSetGet.h>

class vtkCollection;

BeginForgVisualLib

class FrgVisual_Scene_CameraManip;

class FORGVISUAL_EXPORT FrgVisual_Scene_InterStyle3D
	: public vtkInteractorStyleTrackballCamera
{
public:
	static ForgVisualLib::FrgVisual_Scene_InterStyle3D* New();
	vtkTypeMacro(ForgVisualLib::FrgVisual_Scene_InterStyle3D, vtkInteractorStyleTrackballCamera);
	void PrintSelf(ostream& os, vtkIndent indent) override;

	//@{
	/**
	 * Event bindings controlling the effects of pressing mouse buttons
	 * or moving the mouse.
	 */
	void OnMouseMove() override;
	void OnLeftButtonDown() override;
	void OnLeftButtonUp() override;
	void OnMiddleButtonDown() override;
	void OnMiddleButtonUp() override;
	void OnRightButtonDown() override;
	void OnRightButtonUp() override;
	void OnMouseWheelBackward() override;
	void OnMouseWheelForward() override;
	//@}

	//@{
	/**
	 * Unlike mouse events, these are forwarded to all camera manipulators
	 * since we don't have a mechanism to activate a manipulator by key presses
	 * currently.
	 */
	void OnKeyDown() override;
	void OnKeyUp() override;
	//@}

	/**
	 * Overrides superclass behaviors to only support the key codes that make
	 * sense in a ParaView application.
	 */
	void OnChar() override;

	/**
	 * Access to adding or removing manipulators.
	 */
	void AddManipulator(FrgVisual_Scene_CameraManip* m);

	/**
	 * Removes all manipulators.
	 */
	void RemoveAllManipulators();

	//@{
	/**
	 * Accessor for the collection of camera manipulators.
	 */
	vtkGetObjectMacro(CameraManipulators, vtkCollection);
	//@}

	//@{
	/**
	 * Propagates the center to the manipulators.
	 * This simply sets an internal ivar.
	 * It is propagated to a manipulator before the event
	 * is sent to it.
	 * Also changing the CenterOfRotation during interaction
	 * i.e. after a button press but before a button up
	 * has no effect until the next button press.
	 */
	vtkSetVector3Macro(CenterOfRotation, double);
	vtkGetVector3Macro(CenterOfRotation, double);
	//@}

	//@{
	/**
	 * Propagates the rotation factor to the manipulators.
	 * This simply sets an internal ivar.
	 * It is propagated to a manipulator before the event
	 * is sent to it.
	 * Also changing the RotationFactor during interaction
	 * i.e. after a button press but before a button up
	 * has no effect until the next button press.
	 */
	vtkSetMacro(RotationFactor, double);
	vtkGetMacro(RotationFactor, double);
	//@}

	/**
	 * Returns the chosen manipulator based on the modifiers.
	 */
	virtual FrgVisual_Scene_CameraManip* FindManipulator(int button, int shift, int control);

	/**
	 * Dolly the renderer's camera to a specific point
	 */
	static void DollyToPosition(double fact, int* position, vtkRenderer* renderer);

	/**
	 * Translate the renderer's camera
	 */
	static void TranslateCamera(vtkRenderer* renderer, int toX, int toY, int fromX, int fromY);

	using vtkInteractorStyleTrackballCamera::Dolly;

protected:
	FrgVisual_Scene_InterStyle3D();
	~FrgVisual_Scene_InterStyle3D() override;

	void Dolly(double factor) override;

	FrgVisual_Scene_CameraManip* CurrentManipulator;
	double CenterOfRotation[3];
	double RotationFactor;

	// The CameraInteractors also store there button and modifier.
	vtkCollection* CameraManipulators;

	void OnButtonDown(int button, int shift, int control);
	void OnButtonUp(int button);
	void ResetLights();

	FrgVisual_Scene_InterStyle3D(const FrgVisual_Scene_InterStyle3D&) = delete;
	void operator=(const FrgVisual_Scene_InterStyle3D&) = delete;

	int PreviousPosition[2];
};


/* =================================================================================================== */

EndForgVisualLib

#endif // !_FrgVisual_Scene_InterStyle3D_Header
