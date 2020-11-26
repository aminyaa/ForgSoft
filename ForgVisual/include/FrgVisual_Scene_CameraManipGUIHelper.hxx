#pragma once
#ifndef _FrgVisual_Scene_CameraManipGUIHelper_header
#define _FrgVisual_Scene_CameraManipGUIHelper_Header

#include <FrgVisual_Global.hxx>

#include <vtkObject.h>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Scene_CameraManipGUIHelper : public vtkObject
{
public:
	vtkTypeMacro(FrgVisual_Scene_CameraManipGUIHelper, vtkObject);
	void PrintSelf(ostream& os, vtkIndent indent) override;

	/**
	 * Called by the manipulator to update the GUI.
	 * This typically involves calling processing pending
	 * events on the GUI.
	 */
	virtual void UpdateGUI() = 0;

	/**
	 * Some interactors use the bounds of the active source.
	 * The method returns 0 is no active source is present or
	 * not supported by GUI, otherwise returns 1 and the bounds
	 * are filled into the passed argument array.
	 */
	virtual int GetActiveSourceBounds(double bounds[6]) = 0;

	//@{
	/**
	 * Called to get/set the translation for the actor for the active
	 * source in the active view. If applicable returns 1, otherwise
	 * returns 0.
	 */
	virtual int GetActiveActorTranslate(double translate[3]) = 0;
	virtual int SetActiveActorTranslate(double translate[3]) = 0;
	//@}

	//@{
	/**
	 * Get the center of rotation. Returns 0 if not applicable.
	 */
	virtual int GetCenterOfRotation(double center[3]) = 0;

protected:
	FrgVisual_Scene_CameraManipGUIHelper();
	~FrgVisual_Scene_CameraManipGUIHelper() override;
	//@}

private:
	FrgVisual_Scene_CameraManipGUIHelper(const FrgVisual_Scene_CameraManipGUIHelper&) = delete;
	void operator=(const FrgVisual_Scene_CameraManipGUIHelper&) = delete;
};

EndForgVisualLib

#endif // !_FrgVisual_Scene_CameraManipGUIHelper_header
