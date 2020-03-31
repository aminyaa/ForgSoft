#include <FrgVisual_Scene_CameraManip.hxx>
#include <FrgVisual_Scene_CameraManipGUIHelper.hxx>

#include <vtkObjectFactory.h>
#include <vtkSetGet.h>
#include <vtkRenderer.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_Scene_CameraManip);
vtkCxxSetObjectMacro(ForgVisualLib::FrgVisual_Scene_CameraManip, GUIHelper, ForgVisualLib::FrgVisual_Scene_CameraManipGUIHelper);

//-------------------------------------------------------------------------
ForgVisualLib::FrgVisual_Scene_CameraManip::FrgVisual_Scene_CameraManip()
{
	this->Button = 1;
	this->Shift = 0;
	this->Control = 0;

	this->Center[0] = this->Center[1] = this->Center[2] = 0.0;
	this->RotationFactor = 1.0;
	this->DisplayCenter[0] = this->DisplayCenter[1] = 0.0;

	this->ManipulatorName = 0;
	this->GUIHelper = 0;
}

//-------------------------------------------------------------------------
ForgVisualLib::FrgVisual_Scene_CameraManip::~FrgVisual_Scene_CameraManip()
{
	this->SetManipulatorName(0);
	this->SetGUIHelper(0);
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_CameraManip::StartInteraction()
{
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_CameraManip::EndInteraction()
{
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_CameraManip::OnButtonDown(int, int, vtkRenderer*, vtkRenderWindowInteractor*)
{
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_CameraManip::OnButtonUp(int, int, vtkRenderer*, vtkRenderWindowInteractor*)
{
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_CameraManip::OnMouseMove(int, int, vtkRenderer*, vtkRenderWindowInteractor*)
{
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_CameraManip::OnKeyUp(vtkRenderWindowInteractor*)
{
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_CameraManip::OnKeyDown(vtkRenderWindowInteractor*)
{
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_CameraManip::ComputeDisplayCenter(vtkRenderer* ren)
{
	double* pt;

	// save the center of rotation in screen coordinates
	ren->SetWorldPoint(this->Center[0], this->Center[1], this->Center[2], 1.0);
	ren->WorldToDisplay();
	pt = ren->GetDisplayPoint();
	this->DisplayCenter[0] = pt[0];
	this->DisplayCenter[1] = pt[1];
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_CameraManip::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os, indent);

	os << indent << "ManipulatorName: " << (this->ManipulatorName ? this->ManipulatorName : "none")
		<< endl;
	os << indent << "Button: " << this->Button << endl;
	os << indent << "Shift: " << this->Shift << endl;
	os << indent << "Control: " << this->Control << endl;
	os << indent << "Center: " << this->Center[0] << ", " << this->Center[1] << ", "
		<< this->Center[2] << endl;
	os << indent << "RotationFactor: " << this->RotationFactor << endl;
	os << indent << "GUIHelper: " << this->GUIHelper << endl;
}