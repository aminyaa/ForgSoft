#include <FrgVisual_Scene_InterStyle2D.hxx>
#include <FrgVisual_Scene_CameraManip.hxx>
#include <FrgVisual_BaseActor.hxx>
#include <FrgVisual_GridActor.hxx>
#include <FrgVisual_Scene2D.hxx>

#include <vtkCamera.h>
#include <vtkCollection.h>
#include <vtkCollectionIterator.h>
#include <vtkCommand.h>
#include <vtkLight.h>
#include <vtkLightCollection.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkMath.h>
#include <vtkTransform.h>
#include <vtkPropPicker.h>
#include <vtkProperty.h>
#include <vtkPointPicker.h>
#include <vtkCellPicker.h>

#include <QtCore\QPoint>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_Scene_InterStyle2D);

//-------------------------------------------------------------------------
ForgVisualLib::FrgVisual_Scene_InterStyle2D::FrgVisual_Scene_InterStyle2D()
	: ResetPixelDistance(5)
{
	this->UseTimers = 0;
	this->CameraManipulators = vtkCollection::New();
	this->CurrentManipulator = NULL;
	this->CenterOfRotation[0] = this->CenterOfRotation[1] = this->CenterOfRotation[2] = 0;
	this->RotationFactor = 1.0;

	this->PreviousPosition[0] = 0;
	this->PreviousPosition[1] = 0;

	theSelectedColor_.setRedF(1.0);
	theSelectedColor_.setGreenF(0.0);
	theSelectedColor_.setBlueF(1.0);

	theLeftButtonPressed_ = false;
}

//-------------------------------------------------------------------------
ForgVisualLib::FrgVisual_Scene_InterStyle2D::~FrgVisual_Scene_InterStyle2D()
{
	this->CameraManipulators->Delete();
	this->CameraManipulators = NULL;
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::RemoveAllManipulators()
{
	this->CameraManipulators->RemoveAllItems();
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::AddManipulator(FrgVisual_Scene_CameraManip* m)
{
	this->CameraManipulators->AddItem(m);
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnLeftButtonDown()
{
	int pickPosition[2];
	this->GetInteractor()->GetEventPosition(pickPosition);

	this->PreviousPosition[0] = pickPosition[0];
	this->PreviousPosition[1] = pickPosition[1];

	theLeftButtonPressed_ = true;

	emit theParentScene_->OnLeftButtonDown(theParentScene_);
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnMiddleButtonDown()
{
	SuperClass::OnMiddleButtonDown();

	emit theParentScene_->OnMiddleButtonDown(theParentScene_);

	//this->OnButtonDown(2, this->Interactor->GetShiftKey(), this->Interactor->GetControlKey());
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnRightButtonDown()
{
	//auto position = this->Interactor->GetEventPosition();

	//vtkCamera* cam = this->CurrentRenderer->GetActiveCamera();

	//double viewFocus[3], originalViewFocus[3], cameraPos[3], newCameraPos[3];
	//double newFocalPoint[4], norm[3];

	//// Move focal point to cursor position
	//cam->GetPosition(cameraPos);
	//cam->GetFocalPoint(viewFocus);
	//cam->GetFocalPoint(originalViewFocus);
	//cam->GetViewPlaneNormal(norm);

	//FrgVisual_Scene_InterStyle3D::ComputeWorldToDisplay(
	//	this->CurrentRenderer, viewFocus[0], viewFocus[1], viewFocus[2], viewFocus);

	//FrgVisual_Scene_InterStyle3D::ComputeDisplayToWorld(
	//	this->CurrentRenderer, double(position[0]), double(position[1]), viewFocus[2], newFocalPoint);

	//cam->SetFocalPoint(newFocalPoint);

	//// Find new focal point
	//cam->GetPosition(newCameraPos);

	//double newPoint[3];
	//newPoint[0] = originalViewFocus[0] + newCameraPos[0] - cameraPos[0];
	//newPoint[1] = originalViewFocus[1] + newCameraPos[1] - cameraPos[1];
	//newPoint[2] = originalViewFocus[2] + newCameraPos[2] - cameraPos[2];

	//cam->SetFocalPoint(newPoint);

	int pickPosition[2];
	this->GetInteractor()->GetEventPosition(pickPosition);

	this->PreviousPosition[0] = pickPosition[0];
	this->PreviousPosition[1] = pickPosition[1];

	//SuperClass::OnLeftButtonDown();

	emit theParentScene_->OnRightButtonDown(theParentScene_);

	//this->OnButtonDown(3, this->Interactor->GetShiftKey(), this->Interactor->GetControlKey());
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnButtonDown(int button, int shift, int control)
{

	// Must not be processing an interaction to start another.
	if (this->CurrentManipulator)
	{
		return;
	}

	// Get the renderer.
	this->FindPokedRenderer(
		this->Interactor->GetEventPosition()[0], this->Interactor->GetEventPosition()[1]);
	if (this->CurrentRenderer == NULL)
	{
		return;
	}

	// Look for a matching camera interactor.
	this->CurrentManipulator = this->FindManipulator(button, shift, control);
	if (this->CurrentManipulator)
	{
		this->CurrentManipulator->Register(this);
		this->InvokeEvent(vtkCommand::StartInteractionEvent);
		this->CurrentManipulator->SetCenter(this->CenterOfRotation);
		this->CurrentManipulator->SetRotationFactor(this->RotationFactor);
		this->CurrentManipulator->StartInteraction();
		this->CurrentManipulator->OnButtonDown(this->Interactor->GetEventPosition()[0],
			this->Interactor->GetEventPosition()[1], this->CurrentRenderer, this->Interactor);
	}
}

//-------------------------------------------------------------------------
ForgVisualLib::FrgVisual_Scene_CameraManip* ForgVisualLib::FrgVisual_Scene_InterStyle2D::FindManipulator(int button, int shift, int control)
{
	// Look for a matching camera interactor.
	this->CameraManipulators->InitTraversal();
	FrgVisual_Scene_CameraManip* manipulator = NULL;
	while ((manipulator = (FrgVisual_Scene_CameraManip*)this->CameraManipulators->GetNextItemAsObject()))
	{
		if (manipulator->GetButton() == button && manipulator->GetShift() == shift &&
			manipulator->GetControl() == control)
		{
			return manipulator;
		}
	}
	return NULL;
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnLeftButtonUp()
{
	if (!this->CurrentRenderer)
		return;

	this->EndTranslation();
	theLeftButtonPressed_ = false;

	int pickPosition[2];
	this->GetInteractor()->GetEventPosition(pickPosition);

	int xdist = pickPosition[0] - this->PreviousPosition[0];
	int ydist = pickPosition[1] - this->PreviousPosition[1];
	int moveDistance = (int)sqrt((double)(xdist * xdist + ydist * ydist));

	if (moveDistance > this->ResetPixelDistance)
	{

	}
	else
	{
		int* clickPos = this->GetInteractor()->GetEventPosition();

		vtkActor* pickedActor = nullptr;
		// Pick from this location.
		auto myPointPicker = vtkSmartPointer<vtkPointPicker>::New();
		myPointPicker->SetTolerance(0.003);
		myPointPicker->Pick(clickPos[0], clickPos[1], 0.0, this->CurrentRenderer);
		pickedActor = myPointPicker->GetActor();
		if (!pickedActor)
		{
			auto myPicker = vtkSmartPointer<vtkCellPicker>::New();
			myPicker->SetTolerance(0.003);
			myPicker->Pick(clickPos[0], clickPos[1], 0.0, this->CurrentRenderer);
			pickedActor = myPicker->GetActor();
		}

		SelectActor(FrgVisual_BaseActor_Entity::SafeDownCast(pickedActor), this->Interactor->GetControlKey(), true);

#ifdef EliminateUnSelectedActors

		SetUnselectedActorsEliminated(true);

#endif // EliminateUnSelectedActors

	}

	/*SuperClass::OnLeftButtonUp();
	return;*/

	//this->OnButtonUp(1);

	emit theParentScene_->OnLeftButtonUp(theParentScene_);
}
//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnMiddleButtonUp()
{
	SuperClass::OnMiddleButtonUp();

	emit theParentScene_->OnMiddleButtonUp(theParentScene_);

	//this->OnButtonUp(2);
}
//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnRightButtonUp()
{
	int pickPosition[2];
	this->GetInteractor()->GetEventPosition(pickPosition);

	int xdist = pickPosition[0] - this->PreviousPosition[0];
	int ydist = pickPosition[1] - this->PreviousPosition[1];
	int moveDistance = (int)sqrt((double)(xdist * xdist + ydist * ydist));

	emit theParentScene_->OnRightButtonUp(theParentScene_);

	if (moveDistance < this->ResetPixelDistance && this->ResetPixelDistanceBool)
	{
		theParentScene_->customContextMenuRequested(QPoint(pickPosition[0], this->CurrentRenderer->GetRenderWindow()->GetSize()[1] - pickPosition[1]));
	}

	SuperClass::OnLeftButtonUp();

	//this->OnButtonUp(3);
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnMouseWheelBackward()
{
	double factor = this->MotionFactor * -0.2 * this->MouseWheelMotionFactor;

	FrgVisual_Scene_InterStyle2D::DollyToPosition(pow(1.1, factor), this->Interactor->GetEventPosition(), this->CurrentRenderer);

	if (this->CurrentRenderer == nullptr)
		return;

	vtkCamera* camera = this->CurrentRenderer->GetActiveCamera();
	if (camera->GetParallelProjection())
		camera->SetParallelScale(camera->GetParallelScale() / std::abs(factor));
	else
		if (this->AutoAdjustCameraClippingRange)
			this->CurrentRenderer->ResetCameraClippingRange();

	if (this->Interactor->GetLightFollowCamera())
		this->CurrentRenderer->UpdateLightsGeometryToFollowCamera();

	this->Interactor->Render();

	emit theParentScene_->OnMouseWheelBackward(theParentScene_);
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnMouseWheelForward()
{
	double factor = -(this->MotionFactor * -0.2 * this->MouseWheelMotionFactor);

	FrgVisual_Scene_InterStyle2D::DollyToPosition(pow(1.1, factor), this->Interactor->GetEventPosition(), this->CurrentRenderer);

	if (this->CurrentRenderer == nullptr)
		return;

	vtkCamera* camera = this->CurrentRenderer->GetActiveCamera();
	if (camera->GetParallelProjection())
		camera->SetParallelScale(camera->GetParallelScale() / std::abs(factor));
	else
		if (this->AutoAdjustCameraClippingRange)
			this->CurrentRenderer->ResetCameraClippingRange();

	if (this->Interactor->GetLightFollowCamera())
		this->CurrentRenderer->UpdateLightsGeometryToFollowCamera();

	this->Interactor->Render();

	emit theParentScene_->OnMouseWheelForward(theParentScene_);
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnButtonUp(int button)
{
	if (this->CurrentManipulator == NULL)
	{
		return;
	}
	if (this->CurrentManipulator->GetButton() == button)
	{
		this->CurrentManipulator->OnButtonUp(this->Interactor->GetEventPosition()[0],
			this->Interactor->GetEventPosition()[1], this->CurrentRenderer, this->Interactor);
		this->CurrentManipulator->EndInteraction();
		this->InvokeEvent(vtkCommand::EndInteractionEvent);
		this->CurrentManipulator->UnRegister(this);
		this->CurrentManipulator = NULL;
	}
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnMouseMove()
{
	if (this->CurrentRenderer && this->CurrentManipulator)
	{
		// When an interaction is active, we should not change the renderer being
		// interacted with.
	}
	else
	{
		this->FindPokedRenderer(
			this->Interactor->GetEventPosition()[0], this->Interactor->GetEventPosition()[1]);
	}

	if (this->CurrentManipulator)
	{
		this->CurrentManipulator->OnMouseMove(this->Interactor->GetEventPosition()[0],
			this->Interactor->GetEventPosition()[1], this->CurrentRenderer, this->Interactor);
		this->InvokeEvent(vtkCommand::InteractionEvent);
	}

	if (theLeftButtonPressed_ || theSelectedActors_.size() > 0)
	{
		vtkNew<vtkCellPicker> myPicker;
			myPicker->SetTolerance(0.003);

		int pick = myPicker->Pick(this->Interactor->GetEventPosition()[0], this->Interactor->GetEventPosition()[1], 0.0, this->CurrentRenderer);

		double position[3];
		myPicker->GetPickPosition(position);

		if (pick > 0 && this->State != VTKIS_Translation && theLeftButtonPressed_)
		{
			auto ac = myPicker->GetActors();
			FrgVisual_BaseActor_Entity* anActor;

			vtkCollectionSimpleIterator ait;
			for (ac->InitTraversal(ait); (anActor = FrgVisual_BaseActor_Entity::SafeDownCast(ac->GetNextActor(ait))); )
			{
				if (anActor)
				{
					if (theSelectedActors_.contains(anActor))
					{
						StartTranslation();

						theLastPickedPosition_[0] = position[0];
						theLastPickedPosition_[1] = position[1];
						theLastPickedPosition_[2] = position[2];

						break;
					}
				}
			}
		}

		if (this->State == VTKIS_Translation)
		{

			double dx = position[0] - theLastPickedPosition_[0];
			double dy = position[1] - theLastPickedPosition_[1];

			for (auto actor : theSelectedActors_)
				dynamic_cast<FrgVisual_BaseActor<2>*>(actor)->TranslateActor(dx, dy);

			if (this->Interactor)
				this->Interactor->Render();
		}

		theLastPickedPosition_[0] = position[0];
		theLastPickedPosition_[1] = position[1];
		theLastPickedPosition_[2] = position[2];
	}

	SuperClass::OnMouseMove();

	emit theParentScene_->OnMouseMove(theParentScene_);
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnChar()
{
	vtkRenderWindowInteractor* rwi = this->Interactor;

	switch (rwi->GetKeyCode())
	{
	case 'Q':
	case 'q':
		// It must be noted that this has no effect in QVTKInteractor and hence
		// we're assured that the Qt application won't exit because the user hit
		// 'q'.
		rwi->ExitCallback();
		break;
	case 'R':
	case 'r':

		if (GetParentScene())
			GetParentScene()->RenderScene(true);

		break;
	}
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::ResetLights()
{
	if (!this->CurrentRenderer)
	{
		return;
	}

	vtkLight* light;

	vtkLightCollection* lights = this->CurrentRenderer->GetLights();
	vtkCamera* camera = this->CurrentRenderer->GetActiveCamera();

	lights->InitTraversal();
	light = lights->GetNextItem();
	if (!light)
	{
		return;
	}
	light->SetPosition(camera->GetPosition());
	light->SetFocalPoint(camera->GetFocalPoint());
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnKeyDown()
{
	// Look for a matching camera interactor.
	this->CameraManipulators->InitTraversal();
	FrgVisual_Scene_CameraManip* manipulator = NULL;
	while ((manipulator = (FrgVisual_Scene_CameraManip*)this->CameraManipulators->GetNextItemAsObject()))
	{
		manipulator->OnKeyDown(this->Interactor);
	}
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnKeyUp()
{
	// Look for a matching camera interactor.
	this->CameraManipulators->InitTraversal();
	FrgVisual_Scene_CameraManip* manipulator = NULL;
	while ((manipulator = (FrgVisual_Scene_CameraManip*)this->CameraManipulators->GetNextItemAsObject()))
	{
		manipulator->OnKeyUp(this->Interactor);
	}
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::Dolly(double fact)
{
	if (this->Interactor->GetControlKey())
	{
		FrgVisual_Scene_InterStyle2D::DollyToPosition(
			fact, this->Interactor->GetEventPosition(), this->CurrentRenderer);
	}
	else
	{
		this->Superclass::Dolly(fact);
	}
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::DollyToPosition(double fact, int* position, vtkRenderer* renderer)
{
	vtkCamera* cam = renderer->GetActiveCamera();
	if (cam->GetParallelProjection())
	{
		int x0 = 0, y0 = 0, x1 = 0, y1 = 0;
		// Zoom relatively to the cursor
		int* aSize = renderer->GetRenderWindow()->GetSize();
		int w = aSize[0];
		int h = aSize[1];
		x0 = w / 2;
		y0 = h / 2;
		x1 = position[0];
		y1 = position[1];
		FrgVisual_Scene_InterStyle2D::TranslateCamera(renderer, x0, y0, x1, y1);
		cam->SetParallelScale(cam->GetParallelScale() / fact);
		FrgVisual_Scene_InterStyle2D::TranslateCamera(renderer, x1, y1, x0, y0);
	}
	else
	{
		// Zoom relatively to the cursor position
		double viewFocus[4], originalViewFocus[3], cameraPos[3], newCameraPos[3];
		double newFocalPoint[4], norm[3];

		// Move focal point to cursor position
		cam->GetPosition(cameraPos);
		cam->GetFocalPoint(viewFocus);
		cam->GetFocalPoint(originalViewFocus);
		cam->GetViewPlaneNormal(norm);

		FrgVisual_Scene_InterStyle2D::ComputeWorldToDisplay(
			renderer, viewFocus[0], viewFocus[1], viewFocus[2], viewFocus);

		FrgVisual_Scene_InterStyle2D::ComputeDisplayToWorld(
			renderer, double(position[0]), double(position[1]), viewFocus[2], newFocalPoint);

		cam->SetFocalPoint(newFocalPoint);

		// Move camera in/out along projection direction
		cam->Dolly(fact);

		// Find new focal point
		cam->GetPosition(newCameraPos);

		double newPoint[3];
		newPoint[0] = originalViewFocus[0] + newCameraPos[0] - cameraPos[0];
		newPoint[1] = originalViewFocus[1] + newCameraPos[1] - cameraPos[1];
		newPoint[2] = originalViewFocus[2] + newCameraPos[2] - cameraPos[2];

		cam->SetFocalPoint(newPoint);
	}
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::TranslateCamera(
	vtkRenderer* renderer, int toX, int toY, int fromX, int fromY)
{
	vtkCamera* cam = renderer->GetActiveCamera();
	double viewFocus[4], focalDepth, viewPoint[3];
	double newPickPoint[4], oldPickPoint[4], motionVector[3];
	cam->GetFocalPoint(viewFocus);

	FrgVisual_Scene_InterStyle2D::ComputeWorldToDisplay(
		renderer, viewFocus[0], viewFocus[1], viewFocus[2], viewFocus);
	focalDepth = viewFocus[2];

	FrgVisual_Scene_InterStyle2D::ComputeDisplayToWorld(
		renderer, double(toX), double(toY), focalDepth, newPickPoint);
	FrgVisual_Scene_InterStyle2D::ComputeDisplayToWorld(
		renderer, double(fromX), double(fromY), focalDepth, oldPickPoint);

	// camera motion is reversed
	motionVector[0] = oldPickPoint[0] - newPickPoint[0];
	motionVector[1] = oldPickPoint[1] - newPickPoint[1];
	motionVector[2] = oldPickPoint[2] - newPickPoint[2];

	cam->GetFocalPoint(viewFocus);
	cam->GetPosition(viewPoint);
	cam->SetFocalPoint(
		motionVector[0] + viewFocus[0], motionVector[1] + viewFocus[1], motionVector[2] + viewFocus[2]);

	cam->SetPosition(
		motionVector[0] + viewPoint[0], motionVector[1] + viewPoint[1], motionVector[2] + viewPoint[2]);
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity*> ForgVisualLib::FrgVisual_Scene_InterStyle2D::GetSelectedActors() const
{
	return theSelectedActors_.toVector().toStdVector();
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity*> ForgVisualLib::FrgVisual_Scene_InterStyle2D::GetHiddenActors() const
{
	return theHiddenActors_.toVector().toStdVector();
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle2D::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os, indent);
	os << indent << "CenterOfRotation: " << this->CenterOfRotation[0] << ", "
		<< this->CenterOfRotation[1] << ", " << this->CenterOfRotation[2] << endl;
	os << indent << "RotationFactor: " << this->RotationFactor << endl;
	os << indent << "CameraManipulators: " << this->CameraManipulators << endl;
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::SelectActor(FrgVisual_BaseActor_Entity* actor, int isControlKeyPressed, bool render)
{
	/*if (actor)
		if (!actor->IsSelectable())
			return;*/

	if (!actor && !isControlKeyPressed)
		UnSelectAllActors(true);
	else if (actor)
	{
		int index = IsActorSelected(actor);
		if (index >= 0)
		{
			if (isControlKeyPressed)
				UnSelectActor(actor, true);
			else
			{
				UnSelectAllActors(false);
				SelectActor(actor, isControlKeyPressed);
			}
		}
		else
		{
			if (!isControlKeyPressed)
				UnSelectAllActors(false);

			if (actor->IsSelectable())
			{
				actor->SelectActor(/*theSelectedColor_*/);
				theSelectedActors_.push_back(actor);
				theParentScene_->ActorSelectedSignal(actor);
			}

			if (render)
				this->Interactor->Render();
		}
	}
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::UnSelectActor(FrgVisual_BaseActor_Entity* actor, bool render)
{
	int index = IsActorSelected(actor);

	if (index >= 0)
	{
		theSelectedActors_[index]->UnSelectActor();
		theSelectedActors_.removeAt(index);

		theParentScene_->ActorUnSelectedSignal(actor);
	}

	if (render)
		this->Interactor->Render();
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::SelectAllActors(bool render)
{
	UnSelectAllActors();

	auto myAllActors = GetAllActors();
	for (int i = 0; i < myAllActors.size(); i++)
	{
		SelectActor(myAllActors[i], 1, false);
	}

	if (render)
		this->Interactor->Render();
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::UnSelectAllActors(bool render)
{
	if (theSelectedActors_.size() == 0)
		return;

	while (!theSelectedActors_.empty())
		UnSelectActor(theSelectedActors_[0], render);

	//FrgVisual_BaseActor_Entity* lastActor = theSelectedActors_[theSelectedActors_.size() - 1];
	/*for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		if (theSelectedActors_[i])
			theSelectedActors_[i]->UnSelectActor();
	}
	theSelectedActors_.clear();

	theParentScene_->ActorUnSelectedSignal(lastActor);

	if (render)
		this->Interactor->Render();*/
}

#ifdef EliminateUnSelectedActors

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::SetUnselectedActorsEliminated(bool render)
{
	auto myAllActors = GetAllActors();
	if (myAllActors.size() == 0)
		return;

	for (int i = 0; i < myAllActors.size(); i++)
	{
		if(dynamic_cast<FrgVisual_GridActor*>(myAllActors[i]))
			continue;

		int index = IsActorSelected(myAllActors[i]);
		if (index < 0)
		{
			if (theSelectedActors_.size() != 0)
				myAllActors[i]->GetProperty()->SetOpacity(0.5);
			else
				myAllActors[i]->GetProperty()->SetOpacity(1.0);
		}
		else
			myAllActors[i]->GetProperty()->SetOpacity(1.0);
	}

	if (render)
		this->Interactor->Render();
}

#endif // EliminateUnSelectedActors

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::HideSelectedActors(bool render)
{
	if (theSelectedActors_.size() == 0)
		return;

	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		theSelectedActors_[i]->HideActor();
		theHiddenActors_.push_back(theSelectedActors_[i]);

		theParentScene_->ActorHideSignal(theSelectedActors_[i]);
	}

	UnSelectAllActors(false);

#ifdef EliminateUnSelectedActors

	auto myAllActors = GetAllActors();
	for (int i = 0; i < myAllActors.size(); i++)
	{
		myAllActors[i]->GetProperty()->SetOpacity(1.0);
	}

#endif // EliminateUnSelectedActors

	if (render)
		this->Interactor->Render();
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::UnHideHiddenActors(bool render)
{
	if (theHiddenActors_.size() == 0)
		return;

	for (int i = 0; i < theHiddenActors_.size(); i++)
	{
		theHiddenActors_[i]->UnHideActor();
		theParentScene_->ActorUnHideSignal(theHiddenActors_[i]);

#ifdef EliminateUnSelectedActors

		if (theSelectedActors_.size() == 0)
			theHiddenActors_[i]->GetProperty()->SetOpacity(1.0);

#endif // EliminateUnSelectedActors
	}
	theHiddenActors_.clear();

	if (render)
		this->Interactor->Render();
}

int ForgVisualLib::FrgVisual_Scene_InterStyle2D::IsActorSelected(FrgVisual_BaseActor_Entity* actor)
{
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		if (theSelectedActors_[i] == actor)
			return i;
	}

	return -1;
}

int ForgVisualLib::FrgVisual_Scene_InterStyle2D::IsActorHidden(FrgVisual_BaseActor_Entity* actor)
{
	for (int i = 0; i < theHiddenActors_.size(); i++)
	{
		if (theHiddenActors_[i] == actor)
			return i;
	}

	return -1;
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity*> ForgVisualLib::FrgVisual_Scene_InterStyle2D::GetAllActors()
{
	std::vector<FrgVisual_BaseActor_Entity*> myActors;

	vtkRenderWindowInteractor* rwi = this->Interactor;
	vtkActorCollection* ac;
	FrgVisual_BaseActor_Entity* anActor;

	if (GetCurrentRenderer() != nullptr)
	{
		ac = GetCurrentRenderer()->GetActors();
		vtkCollectionSimpleIterator ait;
		for (ac->InitTraversal(ait); (anActor = FrgVisual_BaseActor_Entity::SafeDownCast(ac->GetNextActor(ait))); )
		{
			if (anActor)
				myActors.push_back(anActor);
		}
	}
	else
	{
		std::cout << "no current renderer on the interactor style.\n";
	}
	rwi->Render();

	return myActors;
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::HideActionIsCalledSlot()
{
	HideSelectedActors(true);
}

void ForgVisualLib::FrgVisual_Scene_InterStyle2D::UnHideActionIsCalledSlot()
{
	UnHideHiddenActors(true);
}