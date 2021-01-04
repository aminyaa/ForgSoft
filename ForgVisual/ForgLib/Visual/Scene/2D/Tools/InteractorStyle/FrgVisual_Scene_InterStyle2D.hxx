#pragma once
#ifndef _FrgVisual_Scene_InterStyle2D_Header
#define _FrgVisual_Scene_InterStyle2D_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Scene_InterStyle.hxx>

#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSetGet.h>

#include <QtCore/QList>
#include <QtGui/QColor>

class vtkCollection;

BeginForgVisualLib

class FrgVisual_Scene_CameraManip;
//class FrgVisual_BaseActor;
class FrgVisual_BaseActor_Entity;
class FrgVisual_Scene2D;

class FORGVISUAL_EXPORT FrgVisual_Scene_InterStyle2D
	: public FrgVisual_Scene_InterStyle<2, vtkInteractorStyleTrackballCamera>
{
	Q_OBJECT

public:

	typedef FrgVisual_Scene_InterStyle<2, vtkInteractorStyleTrackballCamera> SuperClass;

public:
	static ForgVisualLib::FrgVisual_Scene_InterStyle2D* New();
	vtkTypeMacro(ForgVisualLib::FrgVisual_Scene_InterStyle2D, SuperClass);
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
	 * sense in application.
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

	using SuperClass::Dolly;

	void SelectActor(FrgVisual_BaseActor_Entity* actor, int isControlKeyPressed, bool render = true);
	void UnSelectActor(FrgVisual_BaseActor_Entity* actor, bool render = true);
	void SelectAllActors(bool render = true);
	void UnSelectAllActors(bool render = true);

#ifdef EliminateUnSelectedActors

	void SetUnselectedActorsEliminated(bool render = true);

#endif // EliminateUnSelectedActors

	void HideSelectedActors(bool render = true);
	void UnHideHiddenActors(bool render = true);

	int IsActorSelected(FrgVisual_BaseActor_Entity* actor);
	int IsActorHidden(FrgVisual_BaseActor_Entity* actor);

	std::vector<FrgVisual_BaseActor_Entity*> GetAllActors();

protected:
	FrgVisual_Scene_InterStyle2D();
	~FrgVisual_Scene_InterStyle2D() override;

	void Dolly(double factor) override;

	FrgVisual_Scene_CameraManip* CurrentManipulator;
	double CenterOfRotation[3];
	double RotationFactor;

	// The CameraInteractors also store there button and modifier.
	vtkCollection* CameraManipulators;

	void OnButtonDown(int button, int shift, int control);
	void OnButtonUp(int button);
	void ResetLights();

	FrgVisual_Scene_InterStyle2D(const FrgVisual_Scene_InterStyle2D&) = delete;
	void operator=(const FrgVisual_Scene_InterStyle2D&) = delete;

	int PreviousPosition[2];
	int ResetPixelDistance;

	QList<FrgVisual_BaseActor_Entity*> theSelectedActors_;
	QList<FrgVisual_BaseActor_Entity*> theHiddenActors_;

	QColor theSelectedColor_;

	double theLastPickedPosition_[3];
	bool theLeftButtonPressed_;

public slots:

	void HideActionIsCalledSlot() override;
	void UnHideActionIsCalledSlot() override;
};


/* =================================================================================================== */

EndForgVisualLib

#endif // !_FrgVisual_Scene_InterStyle2D_Header
