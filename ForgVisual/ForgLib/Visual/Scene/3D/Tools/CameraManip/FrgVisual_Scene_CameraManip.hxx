#pragma once
#ifndef _FrgVisual_Scene_CameraManip_Header
#define _FrgVisual_Scene_CameraManip_Header

#include <FrgVisual_Global.hxx>

#include <vtkObject.h>

class vtkCollection;
class vtkRenderer;
class vtkRenderWindowInteractor;

BeginForgVisualLib

class FrgVisual_Scene_CameraManipGUIHelper;

class FORGVISUAL_EXPORT FrgVisual_Scene_CameraManip : public vtkObject
{
public:
	static FrgVisual_Scene_CameraManip* New();
	vtkTypeMacro(FrgVisual_Scene_CameraManip, vtkObject);
	void PrintSelf(ostream& os, vtkIndent indent) override;

	//@{
	/**
	 * Event bindings controlling the effects of pressing mouse buttons
	 * or moving the mouse.
	 */
	virtual void StartInteraction();
	virtual void EndInteraction();
	//@}

	virtual void OnMouseMove(int x, int y, vtkRenderer* ren, vtkRenderWindowInteractor* iren);
	virtual void OnButtonDown(int x, int y, vtkRenderer* ren, vtkRenderWindowInteractor* iren);
	virtual void OnButtonUp(int x, int y, vtkRenderer* ren, vtkRenderWindowInteractor* iren);

	//@{
	/**
	 * These methods are called on all registered manipulators, not just the
	 * active one. Hence, these should just be used to record state and not
	 * perform any interactions.
	 */
	virtual void OnKeyUp(vtkRenderWindowInteractor* iren);
	virtual void OnKeyDown(vtkRenderWindowInteractor* iren);
	//@}

	//@{
	/**
	 * These settings determine which button and modifiers the
	 * manipulator responds to. Button can be either 1 (left), 2
	 * (middle), and 3 right.
	 */
	vtkSetMacro(Button, int);
	vtkGetMacro(Button, int);
	vtkSetMacro(Shift, int);
	vtkGetMacro(Shift, int);
	vtkBooleanMacro(Shift, int);
	vtkSetMacro(Control, int);
	vtkGetMacro(Control, int);
	vtkBooleanMacro(Control, int);
	//@}

	//@{
	/**
	 * For setting the center of rotation.
	 */
	vtkSetVector3Macro(Center, double);
	vtkGetVector3Macro(Center, double);
	//@}

	//@{
	/**
	 * Set and get the rotation factor.
	 */
	vtkSetMacro(RotationFactor, double);
	vtkGetMacro(RotationFactor, double);
	//@}

	//@{
	/**
	 * Set and get the manipulator name.
	 */
	vtkSetStringMacro(ManipulatorName);
	vtkGetStringMacro(ManipulatorName);
	//@}

	//@{
	/**
	 * Get/Set the GUI helper.
	 */
	void SetGUIHelper(FrgVisual_Scene_CameraManipGUIHelper*);
	vtkGetObjectMacro(GUIHelper, FrgVisual_Scene_CameraManipGUIHelper);

protected:
	FrgVisual_Scene_CameraManip();
	~FrgVisual_Scene_CameraManip() override;
	//@}

	char* ManipulatorName;

	int Button;
	int Shift;
	int Control;

	double Center[3];
	double RotationFactor;
	double DisplayCenter[2];
	void ComputeDisplayCenter(vtkRenderer* ren);

	FrgVisual_Scene_CameraManipGUIHelper* GUIHelper;

private:
	FrgVisual_Scene_CameraManip(const FrgVisual_Scene_CameraManip&) = delete;
	void operator=(const FrgVisual_Scene_CameraManip&) = delete;
};

EndForgVisualLib

#endif // !_FrgVisual_Scene_CameraManip_Header
