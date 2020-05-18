//#include <FrgVisual_Scene_InterStyle3D.hxx>
//#include <FrgBase_Global_Icons.hxx>
//#include <FrgBase_TreeItem.hxx>
//
//#include <vtkActor.h>
//#include <vtkProperty.h>
//#include <vtkSmartPointer.h>
//#include <vtkRenderWindowInteractor.h>
//#include <vtkPropPicker.h>
//#include <vtkCallbackCommand.h>
//#include <vtkCoordinate.h>
//#include <vtkActorCollection.h>
//#include <vtkAssemblyPath.h>
//#include <vtkRenderer.h>
//
//#include <QtGui/QColor>
//#include <QtGui/QCursor>
//#include <QtGui/QPixmap>
//
//QColor ForgVisualLib::FrgVisual_Scene_InterStyle3D::GeometryColorRGB = QColor(200, 200, 200, 200);
//QColor ForgVisualLib::FrgVisual_Scene_InterStyle3D::GeometrySelectedColorRGB = QColor(200, 200, 200, 200);
//
//
//ForgVisualLib::FrgVisual_Scene_InterStyle3D* ForgVisualLib::FrgVisual_Scene_InterStyle3D::New()
//{
//	VTK_STANDARD_NEW_BODY(ForgVisualLib::FrgVisual_Scene_InterStyle3D)
//}
//
//ForgVisualLib::FrgVisual_Scene_InterStyle3D::FrgVisual_Scene_InterStyle3D()
//	: ResetPixelDistance(5)
//{
//	this->PreviousPosition[0] = 0;
//	this->PreviousPosition[1] = 0;
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetSelectedActorColor(QColor color)
//{
//	for (int i = 0; i < theSelectedActors_.size(); i++)
//	{
//		theSelectedActors_.at(i)->theActor_->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
//		vtkSmartPointer<vtkProperty> bprop =
//			vtkSmartPointer<vtkProperty>::New();
//		bprop->SetColor(color.redF(), color.greenF(), color.blueF());
//		theSelectedActors_.at(i)->theActor_->SetBackfaceProperty(bprop);
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::AddActorToSelectedActors(vtkActor* actor)
//{
//	for (int i = 0; i < theSelectedActors_.size(); i++)
//	{
//		if (theSelectedActors_.at(i)->theActor_ == actor)
//		{
//			if (this->Interactor->GetControlKey())
//				theSelectedActors_.removeAt(i);
//			return;
//		}
//	}
//
//	FrgVisualActor* ta = new FrgVisualActor;
//	ta->theActor_ = actor;
//	ta->theProperty_ = vtkProperty::New();
//
//	theSelectedActors_.push_back(ta);
//
//	//emit theParent_->ActorSelectedSignal(true);
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToDefault()
//{
//	//theParent_->setCursor(QCursor());
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToMove()
//{
//	/*QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_Move);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	theParent_->setCursor(cursor_default);*/
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToRotateXYZ()
//{
//	/*QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_RotateXYZ);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	theParent_->setCursor(cursor_default);*/
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToZoomIn()
//{
//	/*QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_RotateXYZ);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	theParent_->setCursor(cursor_default);*/
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToZoomOut()
//{
//	/*QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_RotateXYZ);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	theParent_->setCursor(cursor_default);*/
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::HideSelectedActors()
//{
//	for (int i = 0; i < theSelectedActors_.size(); i++)
//	{
//		theSelectedActors_.at(i)->theActor_->VisibilityOff();
//
//		theSelectedActors_.at(i)->theActor_->GetProperty()->SetColor(GeometryColorRGB.redF(), GeometryColorRGB.greenF(), GeometryColorRGB.blueF());
//
//		this->theSelectedActors_[i]->theActor_->GetProperty()->DeepCopy(this->theSelectedActors_[i]->theProperty_);
//		theHiddenActors_.push_back(theSelectedActors_.at(i));
//	}
//	theSelectedActors_.clear();
//	UnSelectAllActors();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::ShowAllActors()
//{
//	for (int i = 0; i < theHiddenActors_.size(); i++)
//	{
//		theHiddenActors_.at(i)->theActor_->VisibilityOn();
//	}
//	theHiddenActors_.clear();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnLeftButtonUp()
//{
//	if (theSelectedIconFromScene_ == Cursor)
//	{
//		int pickPosition[2];
//		this->GetInteractor()->GetEventPosition(pickPosition);
//
//		int xdist = pickPosition[0] - this->PreviousPosition[0];
//		int ydist = pickPosition[1] - this->PreviousPosition[1];
//		int moveDistance = (int)sqrt((double)(xdist * xdist + ydist * ydist));
//
//		if (moveDistance > this->ResetPixelDistance)
//		{
//			SuperClass::OnLeftButtonUp();
//		}
//
//		else
//		{
//			int* clickPos = this->GetInteractor()->GetEventPosition();
//
//			// Pick from this location.
//			auto picker =
//				vtkSmartPointer<vtkPropPicker>::New();
//			picker->Pick(clickPos[0], clickPos[1], 0, this->CurrentRenderer);
//
//			SelectActor(picker->GetActor(), this->Interactor->GetControlKey());
//
//			SuperClass::OnLeftButtonUp();
//		}
//
//		SetCursorShapeToDefault();
//	}
//	else
//	{
//		SuperClass::OnLeftButtonUp();
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnLeftButtonDown()
//{
//	if (theSelectedIconFromScene_ == Cursor)
//	{
//		int pickPosition[2];
//		this->GetInteractor()->GetEventPosition(pickPosition);
//
//		this->PreviousPosition[0] = pickPosition[0];
//		this->PreviousPosition[1] = pickPosition[1];
//
//		// Forward events
//		SuperClass::OnLeftButtonDown();
//	}
//	else
//	{
//		this->FindPokedRenderer(this->Interactor->GetEventPosition()[0],
//			this->Interactor->GetEventPosition()[1]);
//		if (this->CurrentRenderer == nullptr)
//		{
//			return;
//		}
//
//		this->GrabFocus(this->EventCallbackCommand);
//
//		if (theSelectedIconFromScene_ == Move)
//			this->StartPan();
//		if (theSelectedIconFromScene_ == RotateXYZ)
//			this->StartRotate();
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMouseWheelForward()
//{
//	SuperClass::OnMouseWheelForward();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMouseWheelBackward()
//{
//	SuperClass::OnMouseWheelBackward();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMiddleButtonDown()
//{
//
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnRightButtonDown()
//{
//	int pickPosition[2];
//	this->GetInteractor()->GetEventPosition(pickPosition);
//
//	this->PreviousPosition[0] = pickPosition[0];
//	this->PreviousPosition[1] = pickPosition[1];
//
//	// Forward events
//	SuperClass::OnMiddleButtonDown();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnRightButtonUp()
//{
//	SetCursorShapeToDefault();
//
//	int pickPosition[2];
//	this->GetInteractor()->GetEventPosition(pickPosition);
//
//	int xdist = pickPosition[0] - this->PreviousPosition[0];
//	int ydist = pickPosition[1] - this->PreviousPosition[1];
//	int moveDistance = (int)sqrt((double)(xdist * xdist + ydist * ydist));
//
//	if (moveDistance > this->ResetPixelDistance)
//	{
//		SuperClass::OnMiddleButtonUp();
//	}
//
//	else
//	{
//		//emit theParent_->customContextMenuRequested(QPoint(pickPosition[0], this->CurrentRenderer->GetRenderWindow()->GetSize()[1] - pickPosition[1]));
//
//		SuperClass::OnMiddleButtonUp();
//	}
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMouseMove()
//{
//	if (theRotationEnabled_ == FrgFalse && this->State == VTKIS_ROTATE)
//		return;
//
//	if (this->State == VTKIS_ROTATE)
//	{
//		SetCursorShapeToRotateXYZ();
//	}
//	else if (this->State == VTKIS_PAN)
//	{
//		SetCursorShapeToMove();
//	}
//
//	/*if (theRotationEnabled_ == FrgFalse && thePlaneView_ != PlaneXYZ)
//	{
//		int pickPosition[2];
//		this->GetInteractor()->GetEventPosition(pickPosition);
//
//		vtkSmartPointer<vtkCoordinate> coordinate =
//			vtkSmartPointer<vtkCoordinate>::New();
//		coordinate->SetCoordinateSystemToDisplay();
//		coordinate->SetValue(pickPosition[0], pickPosition[1], 0);
//
//		double* world = coordinate->GetComputedWorldValue(theParent_->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
//		FrgString axis1 = "", axis2 = "";
//		double axis1Value = 0.0, axis2Value = 0.0;
//
//		if (thePlaneView_ == PlaneXY)
//		{
//			axis1 = "x";
//			axis2 = "y";
//			axis1Value = world[0];
//			axis2Value = world[1];
//		}
//		else if (thePlaneView_ == PlaneXZ)
//		{
//			axis1 = "x";
//			axis2 = "z";
//			axis1Value = world[0];
//			axis2Value = world[2];
//		}
//		else if (thePlaneView_ == PlaneYZ)
//		{
//			axis1 = "y";
//			axis2 = "z";
//			axis1Value = world[1];
//			axis2Value = world[2];
//		}
//
//		theParent_->GetParentTree()->GetParentMainWindow()->statusBar()->showMessage(axis1 + " = " + QString::number(world[0]) + "\t " + axis2 + " = " + QString::number(world[1]));
//	}*/
//
//	SuperClass::OnMouseMove();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnChar()
//{
//	// Get the keypress
//	vtkRenderWindowInteractor* rwi = this->Interactor;
//	std::string key = rwi->GetKeySym();
//
//	// Output the key that was pressed
//	std::cout << "Pressed " << key << std::endl;
//
//	// Handle an arrow key
//	if (key == "Up")
//	{
//		std::cout << "The up arrow was pressed." << std::endl;
//	}
//
//	if (key == "m" || key == "M")
//	{
//		static bool condition = true;
//		ShowMesh(condition);
//
//		condition = !condition;
//	}
//	/*
//	if (theRotationEnabled_ == FrgTrue)
//	{
//		if (key == "s" || key == "S")
//		{
//			double* bounds = theParent_->GetRenderer()->ComputeVisiblePropBounds();
//			auto camera = GetParentScene()->GetFrgBaseCamera();
//
//			static int iPosForS = 1;
//
//			camera->SetPosition(0, iPosForS, 0);
//			//camera->SetFocalPoint((bounds[1] + bounds[0]) / 2.0, 0(bounds[3] + bounds[2]) / 2.0, (bounds[5] + bounds[4]) / 2.0);
//			camera->SetFocalPoint(0.0, 0.0, 0.0);
//			camera->SetViewUp(0, 0, 1);
//			//camera->Azimuth(-180);
//
//			iPosForS *= -1;
//
//			GetParentScene()->GetRenderer()->ResetCamera();
//			GetParentScene()->GetRenderWindow()->Render();
//		}
//
//		if (key == "f" || key == "F")
//		{
//			auto camera = GetParentScene()->GetFrgBaseCamera();
//
//			static int iPosForS = 1;
//
//			camera->SetPosition(iPosForS, 0, 0);
//			camera->SetFocalPoint(0, 0, 0);
//			camera->SetViewUp(0, 0, 1);
//			camera->Azimuth(-180);
//
//			iPosForS *= -1;
//
//			GetParentScene()->GetRenderer()->ResetCamera();
//			GetParentScene()->GetRenderWindow()->Render();
//		}
//
//		if (key == "t" || key == "T")
//		{
//			auto camera = GetParentScene()->GetFrgBaseCamera();
//
//			static int iPosForT = -1;
//
//			camera->SetPosition(0, 0, iPosForT);
//			camera->SetFocalPoint(0, 0, 0);
//			camera->SetViewUp(0, -iPosForT, 0);
//			camera->Azimuth(-180);
//
//			iPosForT *= -1;
//
//			GetParentScene()->GetRenderer()->ResetCamera();
//			GetParentScene()->GetRenderWindow()->Render();
//		}
//
//		if (key == "p" || key == "P")
//		{
//			auto camera = GetParentScene()->GetFrgBaseCamera();
//
//			if (camera->GetParallelProjection())
//				camera->ParallelProjectionOff();
//			else
//				camera->ParallelProjectionOn();
//
//			GetParentScene()->GetRenderer()->ResetCamera();
//			GetParentScene()->GetRenderWindow()->Render();
//		}
//
//		if (key == "d" || key == "D")
//		{
//			auto camera = GetParentScene()->GetFrgBaseCamera();
//
//			camera->Yaw(5.0);
//			GetParentScene()->GetRenderer()->ResetCamera();
//			GetParentScene()->GetRenderWindow()->Render();
//		}
//
//		if (key == "a" || key == "A")
//		{
//			auto camera = GetParentScene()->GetFrgBaseCamera();
//
//			camera->Yaw(-5.0);
//			GetParentScene()->GetRenderer()->ResetCamera();
//			GetParentScene()->GetRenderWindow()->Render();
//		}
//	}
//	*/
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SelectActor
//(
//	vtkActor* actor,
//	int isControlKeyPressed,
//	FrgBool isFromTree
//)
//{
//	/*
//	if (!isFromTree)
//		theParent_->GetParentTree()->clearSelection();
//
//	for (int i = 0; i < theSelectedActors_.size(); i++)
//	{
//		// If we picked something before, reset its property
//		if (this->theSelectedActors_[i]->theActor_)
//		{
//			this->theSelectedActors_[i]->theActor_->GetProperty()->DeepCopy(this->theSelectedActors_[i]->theProperty_);
//		}
//	}
//
//	if (actor == FrgNullPtr && !isControlKeyPressed)
//	{
//		UnSelectAllActors();
//
//		return;
//	}
//
//	if (!isControlKeyPressed)
//	{
//		theSelectedActors_.clear();
//		AddActorToSelectedActors(actor);
//	}
//	else
//	{
//		AddActorToSelectedActors(actor);
//	}
//
//	for (int i = 0; i < theParent_->GetActors().size(); i++)
//	{
//		theParent_->GetActors().at(i)->GetProperty()->SetOpacity(0.5);
//	}
//
//	QList<FrgBase_TreeItem*> items;
//	for (int i = 0; i < theSelectedActors_.size(); i++)
//	{
//		if (this->theSelectedActors_[i]->theActor_)
//		{
//			// Save the property of the picked actor so that we can restore it next time
//			this->theSelectedActors_[i]->theProperty_->DeepCopy(this->theSelectedActors_[i]->theActor_->GetProperty());
//			// Highlight the picked actor by changing its properties
//			this->theSelectedActors_[i]->theActor_->GetProperty()->SetColor
//			(GeometrySelectedColorRGB.redF(), GeometrySelectedColorRGB.greenF(), GeometrySelectedColorRGB.blueF());
//			this->theSelectedActors_[i]->theActor_->GetProperty()->SetDiffuse(1.0);
//			this->theSelectedActors_[i]->theActor_->GetProperty()->SetSpecular(0.0);
//			//this->theSelectedActors_[i]->theActor_->GetProperty()->EdgeVisibilityOn();
//
//			theSelectedActors_[i]->theActor_->GetProperty()->SetOpacity(1.0);
//		}
//
//		if (!isFromTree)
//		{
//			auto item = theParent_->GetActorToPartFeature().value(theSelectedActors_[i]->theActor_);
//			if (item)
//				items.push_back(item);
//		}
//	}
//
//	if (!isFromTree)
//		theParent_->GetParentTree()->ScrollToItems(items);
//
//	this->Interactor->Render();
//	*/
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SelectActors
//(
//	QList<vtkActor*> actors,
//	FrgBool isFromTree
//)
//{
//	UnSelectAllActors();
//
//	for (int i = 0; i < actors.size(); i++)
//	{
//		SelectActor(actors[i], 1, isFromTree);
//	}
//
//	//emit theParent_->ActorSelectedSignal(true);
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::UnSelectAllActors()
//{
//	//for (int i = 0; i < theSelectedActors_.size(); i++)
//	//{
//	//	// If we picked something before, reset its property
//	//	if (this->theSelectedActors_[i]->theActor_)
//	//	{
//	//		this->theSelectedActors_[i]->theActor_->GetProperty()->DeepCopy(this->theSelectedActors_[i]->theProperty_);
//	//	}
//	//}
//
//	//for (int i = 0; i < theParent_->GetActors().size(); i++)
//	//{
//	//	theParent_->GetActors()[i]->GetProperty()->SetOpacity(1.0);
//	//}
//	//theSelectedActors_.clear();
//
//	//this->Interactor->Render();
//
//	//emit theParent_->ActorSelectedSignal(false);
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetViewToXYPlane()
//{
//	//theRotationEnabled_ = FrgFalse;
//	//auto camera = GetParentScene()->GetFrgBaseCamera();
//
//	//camera->SetPosition(0, 0, 1);
//	//camera->SetFocalPoint(0, 0, 0);
//	//camera->SetViewUp(0, 1, 0);
//	////camera->Azimuth(-180);
//	//camera->ParallelProjectionOn();
//	//thePlaneView_ = PlaneXY;
//
//	//GetParentScene()->GetRenderer()->ResetCamera();
//	//GetParentScene()->GetRenderWindow()->Render();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetViewToXZPlane()
//{
//	/*theRotationEnabled_ = FrgFalse;
//	auto camera = GetParentScene()->GetFrgBaseCamera();
//
//	camera->SetPosition(0, 1, 0);
//	camera->SetFocalPoint(0, 0, 0);
//	camera->SetViewUp(0, 0, 1);
//	camera->Azimuth(-180);
//	camera->ParallelProjectionOn();
//	thePlaneView_ = PlaneXZ;
//
//	GetParentScene()->GetRenderer()->ResetCamera();
//	GetParentScene()->GetRenderWindow()->Render();*/
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetViewToYZPlane()
//{
//	/*theRotationEnabled_ = FrgFalse;
//	auto camera = GetParentScene()->GetFrgBaseCamera();
//
//	camera->SetPosition(-1, 0, 0);
//	camera->SetFocalPoint(0, 0, 0);
//	camera->SetViewUp(0, 0, 1);
//	camera->Azimuth(-180);
//	camera->ParallelProjectionOn();
//	thePlaneView_ = PlaneYZ;
//
//	GetParentScene()->GetRenderer()->ResetCamera();
//	GetParentScene()->GetRenderWindow()->Render();*/
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetViewToXYZ()
//{
//	/*theRotationEnabled_ = FrgTrue;
//	auto camera = GetParentScene()->GetFrgBaseCamera();
//
//	camera->SetPosition(1, 0, 1);
//	camera->SetFocalPoint(0, 0, 0);
//	camera->SetViewUp(0, 0, 1);
//	camera->Azimuth(-50);
//	camera->ParallelProjectionOff();
//	thePlaneView_ = PlaneXYZ;
//
//	GetParentScene()->GetRenderer()->ResetCamera();
//	GetParentScene()->GetRenderWindow()->Render();*/
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::ShowMesh(FrgBool condition)
//{
//	vtkRenderWindowInteractor* rwi = this->Interactor;
//	vtkActorCollection* ac;
//	vtkActor* anActor, * aPart;
//	vtkAssemblyPath* path;
//	this->FindPokedRenderer(rwi->GetEventPosition()[0],
//		rwi->GetEventPosition()[1]);
//	if (this->CurrentRenderer != nullptr)
//	{
//		ac = this->CurrentRenderer->GetActors();
//		vtkCollectionSimpleIterator ait;
//		for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
//		{
//			for (anActor->InitPathTraversal(); (path = anActor->GetNextPath()); )
//			{
//				aPart = static_cast<vtkActor*>(path->GetLastNode()->GetViewProp());
//				//aPart->GetProperty()->SetEdgeColor(0, 0, 0);
//				aPart->GetProperty()->SetEdgeVisibility(condition);
//			}
//		}
//	}
//	else
//	{
//		vtkWarningMacro(<< "no current renderer on the interactor style.");
//	}
//	rwi->Render();
//}


#include <FrgVisual_Scene_InterStyle3D.hxx>
#include <FrgVisual_Scene_CameraManip.hxx>

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

vtkStandardNewMacro(ForgVisualLib::FrgVisual_Scene_InterStyle3D);

//-------------------------------------------------------------------------
ForgVisualLib::FrgVisual_Scene_InterStyle3D::FrgVisual_Scene_InterStyle3D()
{
	this->UseTimers = 0;
	this->CameraManipulators = vtkCollection::New();
	this->CurrentManipulator = NULL;
	this->CenterOfRotation[0] = this->CenterOfRotation[1] = this->CenterOfRotation[2] = 0;
	this->RotationFactor = 1.0;

	this->PreviousPosition[0] = 0;
	this->PreviousPosition[1] = 0;
}

//-------------------------------------------------------------------------
ForgVisualLib::FrgVisual_Scene_InterStyle3D::~FrgVisual_Scene_InterStyle3D()
{
	this->CameraManipulators->Delete();
	this->CameraManipulators = NULL;
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::RemoveAllManipulators()
{
	this->CameraManipulators->RemoveAllItems();
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::AddManipulator(FrgVisual_Scene_CameraManip* m)
{
	this->CameraManipulators->AddItem(m);
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnLeftButtonDown()
{
	//// Zoom relatively to the cursor position
	//double viewFocus[4], originalViewFocus[3], cameraPos[3], newCameraPos[3];
	//double newFocalPoint[4], norm[3];

	//vtkCamera* cam = this->CurrentRenderer->GetActiveCamera();
	//// Move focal point to cursor position
	//cam->GetPosition(cameraPos);
	//cam->GetFocalPoint(viewFocus);
	//cam->GetFocalPoint(originalViewFocus);
	//cam->GetViewPlaneNormal(norm);

	//auto position = this->Interactor->GetEventPosition();
	//FrgVisual_Scene_InterStyle3D::ComputeWorldToDisplay(this->CurrentRenderer, viewFocus[0], viewFocus[1], viewFocus[2], viewFocus);

	//FrgVisual_Scene_InterStyle3D::ComputeDisplayToWorld(this->CurrentRenderer, double(position[0]), double(position[1]), viewFocus[2], newFocalPoint);

	//cam->SetFocalPoint(newFocalPoint);

	//// Find new focal point
	//cam->GetPosition(newCameraPos);

	//double newPoint[3];
	//newPoint[0] = originalViewFocus[0] + newCameraPos[0] - cameraPos[0];
	//newPoint[1] = originalViewFocus[1] + newCameraPos[1] - cameraPos[1];
	//newPoint[2] = originalViewFocus[2] + newCameraPos[2] - cameraPos[2];

	//cam->SetFocalPoint(newPoint);

	//SuperClass::OnLeftButtonDown();
	//return;

	//this->OnButtonDown(1, this->Interactor->GetShiftKey(), this->Interactor->GetControlKey());
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMiddleButtonDown()
{
	SuperClass::OnMiddleButtonDown();
	return;

	//this->OnButtonDown(2, this->Interactor->GetShiftKey(), this->Interactor->GetControlKey());
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnRightButtonDown()
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



	SuperClass::OnLeftButtonDown();
	return;

	//this->OnButtonDown(3, this->Interactor->GetShiftKey(), this->Interactor->GetControlKey());
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnButtonDown(int button, int shift, int control)
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
ForgVisualLib::FrgVisual_Scene_CameraManip* ForgVisualLib::FrgVisual_Scene_InterStyle3D::FindManipulator(int button, int shift, int control)
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
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnLeftButtonUp()
{
	/*SuperClass::OnLeftButtonUp();
	return;*/

	//this->OnButtonUp(1);
}
//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMiddleButtonUp()
{
	SuperClass::OnMiddleButtonUp();
	return;

	//this->OnButtonUp(2);
}
//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnRightButtonUp()
{
	SuperClass::OnLeftButtonUp();
	return;

	//this->OnButtonUp(3);
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMouseWheelBackward()
{
	double factor = this->MotionFactor * -0.2 * this->MouseWheelMotionFactor;

	FrgVisual_Scene_InterStyle3D::DollyToPosition(pow(1.1, factor), this->Interactor->GetEventPosition(), this->CurrentRenderer);

	if (this->CurrentRenderer == nullptr)
		return;

	vtkCamera *camera = this->CurrentRenderer->GetActiveCamera();
	if (camera->GetParallelProjection())
		camera->SetParallelScale(camera->GetParallelScale() / (factor));
	else
		if (this->AutoAdjustCameraClippingRange)
			this->CurrentRenderer->ResetCameraClippingRange();

	if (this->Interactor->GetLightFollowCamera())
		this->CurrentRenderer->UpdateLightsGeometryToFollowCamera();

	this->Interactor->Render();
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMouseWheelForward()
{
	double factor = -(this->MotionFactor * -0.2 * this->MouseWheelMotionFactor);

	FrgVisual_Scene_InterStyle3D::DollyToPosition(pow(1.1, factor), this->Interactor->GetEventPosition(), this->CurrentRenderer);

	if (this->CurrentRenderer == nullptr)
		return;

	vtkCamera *camera = this->CurrentRenderer->GetActiveCamera();
	if (camera->GetParallelProjection())
		camera->SetParallelScale(camera->GetParallelScale() / (factor));
	else
		if (this->AutoAdjustCameraClippingRange)
			this->CurrentRenderer->ResetCameraClippingRange();

	if (this->Interactor->GetLightFollowCamera())
		this->CurrentRenderer->UpdateLightsGeometryToFollowCamera();

	this->Interactor->Render();
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnButtonUp(int button)
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
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMouseMove()
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

	SuperClass::OnMouseMove();
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnChar()
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
	}
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::ResetLights()
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
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnKeyDown()
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
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnKeyUp()
{
	// Look for a matching camera interactor.
	this->CameraManipulators->InitTraversal();
	FrgVisual_Scene_CameraManip* manipulator = NULL;
	while ((manipulator = (FrgVisual_Scene_CameraManip*)this->CameraManipulators->GetNextItemAsObject()))
	{
		manipulator->OnKeyUp(this->Interactor);
	}
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::Dolly(double fact)
{
	if (this->Interactor->GetControlKey())
	{
		FrgVisual_Scene_InterStyle3D::DollyToPosition(
			fact, this->Interactor->GetEventPosition(), this->CurrentRenderer);
	}
	else
	{
		this->Superclass::Dolly(fact);
	}
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::DollyToPosition(double fact, int* position, vtkRenderer* renderer)
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
		FrgVisual_Scene_InterStyle3D::TranslateCamera(renderer, x0, y0, x1, y1);
		cam->SetParallelScale(cam->GetParallelScale() / fact);
		FrgVisual_Scene_InterStyle3D::TranslateCamera(renderer, x1, y1, x0, y0);
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

		FrgVisual_Scene_InterStyle3D::ComputeWorldToDisplay(
			renderer, viewFocus[0], viewFocus[1], viewFocus[2], viewFocus);

		FrgVisual_Scene_InterStyle3D::ComputeDisplayToWorld(
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
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::TranslateCamera(
	vtkRenderer* renderer, int toX, int toY, int fromX, int fromY)
{
	vtkCamera* cam = renderer->GetActiveCamera();
	double viewFocus[4], focalDepth, viewPoint[3];
	double newPickPoint[4], oldPickPoint[4], motionVector[3];
	cam->GetFocalPoint(viewFocus);

	FrgVisual_Scene_InterStyle3D::ComputeWorldToDisplay(
		renderer, viewFocus[0], viewFocus[1], viewFocus[2], viewFocus);
	focalDepth = viewFocus[2];

	FrgVisual_Scene_InterStyle3D::ComputeDisplayToWorld(
		renderer, double(toX), double(toY), focalDepth, newPickPoint);
	FrgVisual_Scene_InterStyle3D::ComputeDisplayToWorld(
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

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os, indent);
	os << indent << "CenterOfRotation: " << this->CenterOfRotation[0] << ", "
		<< this->CenterOfRotation[1] << ", " << this->CenterOfRotation[2] << endl;
	os << indent << "RotationFactor: " << this->RotationFactor << endl;
	os << indent << "CameraManipulators: " << this->CameraManipulators << endl;
}
