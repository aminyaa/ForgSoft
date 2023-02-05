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

#define EliminateUnSelectedActors

#include <FrgVisual_Scene_InterStyle3D.hxx>
#include <FrgVisual_Scene_CameraManip.hxx>
#include <FrgVisual_BaseActor.hxx>
#include <FrgVisual_Scene3D.hxx>
#include <FrgVisual_PointActor.hxx>
#include <FrgVisual_GridActor.hxx>

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
#include <vtkPicker.h>
#include <vtkCellPicker.h>
#include <vtkAxesActor.h>

#include <QtCore\QPoint>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_Scene_InterStyle3D);

//-------------------------------------------------------------------------
ForgVisualLib::FrgVisual_Scene_InterStyle3D::FrgVisual_Scene_InterStyle3D()
	: ResetPixelDistance(5)
{
	this->UseTimers = 0;
	this->CameraManipulators = vtkCollection::New();
	this->CurrentManipulator = NULL;
	//this->CenterOfRotation[0] = this->CenterOfRotation[1] = this->CenterOfRotation[2] = 0;
	this->RotationFactor = 1.0;

	this->PreviousPosition[0] = 0;
	this->PreviousPosition[1] = 0;

	theSelectedColor_.setRedF(1.0);
	theSelectedColor_.setGreenF(0.0);
	theSelectedColor_.setBlueF(1.0);
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
	int pickPosition[2];
	this->GetInteractor()->GetEventPosition(pickPosition);

	this->PreviousPosition[0] = pickPosition[0];
	this->PreviousPosition[1] = pickPosition[1];

	emit theParentScene_->OnLeftButtonDown(theParentScene_);
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMiddleButtonDown()
{
	SuperClass::OnMiddleButtonDown();

	emit theParentScene_->OnMiddleButtonDown(theParentScene_);

	//this->OnButtonDown(2, this->Interactor->GetShiftKey(), this->Interactor->GetControlKey());
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnRightButtonDown()
{
	int pickPosition[2];
	this->GetInteractor()->GetEventPosition(pickPosition);

	this->PreviousPosition[0] = pickPosition[0];
	this->PreviousPosition[1] = pickPosition[1];

	if (theRotationPoint_)
	{
		this->CurrentRenderer->RemoveActor(theRotationPoint_);
	}

	SuperClass::OnLeftButtonDown();

	Get3DPointOnScreen(pickPosition[0], pickPosition[1], theCenterOfRotaion_);

	theRotationPoint_ = FrgVisual_PointActor<3>::New();
	theRotationPoint_->SetSize(8.0f);
	theRotationPoint_->SetRenderPointsAsSpheres(true);
	theRotationPoint_->SetColor(1.0, 0.0, 1.0);
	theRotationPoint_->SetData(theCenterOfRotaion_[0], theCenterOfRotaion_[1], theCenterOfRotaion_[2]);
	this->CurrentRenderer->AddActor(theRotationPoint_);

	emit theParentScene_->OnRightButtonDown(theParentScene_);
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
		this->CurrentManipulator->SetCenter(this->theCenterOfRotaion_);
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

		// Pick from this location.
		auto myPicker = vtkSmartPointer<vtkCellPicker>::New();
		myPicker->SetTolerance(GetPickingTolerance());
		//myPicker->SetTolerance(0.001);
		int pick = myPicker->Pick(clickPos[0], clickPos[1], 0, this->CurrentRenderer);

		/*auto myPicker = vtkSmartPointer<vtkPropPicker>::New();
		int pick = myPicker->PickProp(clickPos[0], clickPos[1], this->CurrentRenderer);*/


		SelectActor(FrgVisual_BaseActor_Entity::SafeDownCast(myPicker->GetActor()), this->Interactor->GetControlKey(), true);

//#ifdef EliminateUnSelectedActors

		//SetUnselectedActorsEliminated(true);

//#endif // EliminateUnSelectedActors

	}

	/*SuperClass::OnLeftButtonUp();
	return;*/

	//this->OnButtonUp(1);

	emit theParentScene_->OnLeftButtonUp(theParentScene_);
}
//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMiddleButtonUp()
{
	SuperClass::OnMiddleButtonUp();

	emit theParentScene_->OnMiddleButtonUp(theParentScene_);

	//this->OnButtonUp(2);
}
//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnRightButtonUp()
{
	if (theRotationPoint_)
	{
		this->CurrentRenderer->RemoveActor(theRotationPoint_);
	}

	int pickPosition[2];
	this->GetInteractor()->GetEventPosition(pickPosition);

	int xdist = pickPosition[0] - this->PreviousPosition[0];
	int ydist = pickPosition[1] - this->PreviousPosition[1];
	int moveDistance = (int)sqrt((double)(xdist * xdist + ydist * ydist));

	if (moveDistance < this->ResetPixelDistance)
	{
		theParentScene_->customContextMenuRequested(QPoint(pickPosition[0], this->CurrentRenderer->GetRenderWindow()->GetSize()[1] - pickPosition[1]));
	}

	SuperClass::OnLeftButtonUp();

	emit theParentScene_->OnRightButtonUp(theParentScene_);

	//this->OnButtonUp(3);
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMouseWheelBackward()
{
	this->StartDolly();

	double factor = this->MotionFactor * -0.2 * this->MouseWheelMotionFactor;

	vtkCamera* camera = this->CurrentRenderer->GetActiveCamera();
	double distance0 = camera->GetDistance();

	FrgVisual_Scene_InterStyle3D::DollyToPosition(pow(1.1, factor), this->Interactor->GetEventPosition(), this->CurrentRenderer);

	if (this->CurrentRenderer == nullptr)
		return;

	if (camera->GetParallelProjection())
		camera->SetParallelScale(camera->GetParallelScale() / std::abs(factor));
	else
		if (this->AutoAdjustCameraClippingRange)
			this->CurrentRenderer->ResetCameraClippingRange();

	if (this->Interactor->GetLightFollowCamera())
		this->CurrentRenderer->UpdateLightsGeometryToFollowCamera();

	double distance1 = camera->GetDistance();

	//this->MouseWheelMotionFactor *= (distance1 / distance0);

	this->Interactor->Render();

	emit theParentScene_->OnMouseWheelBackward(theParentScene_);

	this->EndDolly();
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMouseWheelForward()
{
	this->StartDolly();

	double factor = -(this->MotionFactor * -0.2 * this->MouseWheelMotionFactor);

	vtkCamera* camera = this->CurrentRenderer->GetActiveCamera();

	FrgVisual_Scene_InterStyle3D::DollyToPosition(pow(1.1, factor), this->Interactor->GetEventPosition(), this->CurrentRenderer);

	if (this->CurrentRenderer == nullptr)
		return;

	if (camera->GetParallelProjection())
		camera->SetParallelScale(camera->GetParallelScale() / (factor));
	else
		if (this->AutoAdjustCameraClippingRange)
			this->CurrentRenderer->ResetCameraClippingRange();

	if (this->Interactor->GetLightFollowCamera())
		this->CurrentRenderer->UpdateLightsGeometryToFollowCamera();

	this->Interactor->Render();

	emit theParentScene_->OnMouseWheelForward(theParentScene_);

	this->EndDolly();
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::Rotate()
{
	if (this->CurrentRenderer == nullptr)
	{
		return;
	}

	vtkRenderWindowInteractor* rwi = this->Interactor;

	int dx = rwi->GetEventPosition()[0] - rwi->GetLastEventPosition()[0];
	int dy = rwi->GetEventPosition()[1] - rwi->GetLastEventPosition()[1];

	int* size = this->CurrentRenderer->GetRenderWindow()->GetSize();

	double delta_elevation = -15.0 / size[1];
	double delta_azimuth = -15.0 / size[0];

	double rxf = dx * delta_azimuth * this->MotionFactor;
	double ryf = dy * delta_elevation * this->MotionFactor;


	int* clickPos = this->GetInteractor()->GetEventPosition();

	/*FrgVisual_3DPointActor* myPointActor = FrgVisual_3DPointActor::New();
	myPointActor->SetData(pt[0], pt[1], pt[2]);
	myPointActor->SetColor(1.0, 0.0, 0.0);
	myPointActor->SetSize(10.0f);
	this->CurrentRenderer->AddActor(myPointActor);*/

	//camera->SetFocalPoint(newFocalPoint);

	// Move camera in/out along projection direction

	vtkCamera* camera = this->CurrentRenderer->GetActiveCamera();

	/*vtkNew<vtkCamera> tmpCamera;
	tmpCamera->SetPosition(camera->GetFocalPoint());
	tmpCamera->SetFocalPoint(theCenterOfRotaion_);
	tmpCamera->SetViewUp(camera->GetViewUp());
	tmpCamera->Azimuth(rxf);
	tmpCamera->Elevation(ryf);*/
	double newFocalPoint[3];

	// For Elevation
	{
		camera->GetFocalPoint(newFocalPoint);

		camera->Roll(-90.0);
		camera->SetFocalPoint(theCenterOfRotaion_);

		vtkNew<vtkCamera> tmpCamera;
		tmpCamera->DeepCopy(camera);
		tmpCamera->SetPosition(newFocalPoint);
		tmpCamera->SetFocalPoint(theCenterOfRotaion_);
		tmpCamera->Azimuth(ryf);
		camera->Azimuth(ryf);
		camera->SetFocalPoint(tmpCamera->GetPosition());
		camera->Roll(90.0);
	}

	// For Azimuth
	{
		camera->GetFocalPoint(newFocalPoint);

		vtkNew<vtkCamera> tmpCamera;
		tmpCamera->DeepCopy(camera);
		tmpCamera->SetPosition(newFocalPoint);
		tmpCamera->SetFocalPoint(theCenterOfRotaion_);
		tmpCamera->Azimuth(rxf);

		camera->SetFocalPoint(theCenterOfRotaion_);
		camera->Azimuth(rxf);
		camera->SetFocalPoint(tmpCamera->GetPosition());

		/*FrgVisual_PointActor<3>* pt = FrgVisual_PointActor<3>::New();
		pt->SetData(tmpCamera->GetPosition()[0], tmpCamera->GetPosition()[1], tmpCamera->GetPosition()[2]);
		pt->SetSize(5.0f);
		pt->SetColor(1.0, 0.0, 0.0);
		pt->SetRenderPointsAsSpheres(true);
		this->CurrentRenderer->AddActor(pt);*/

		//camera->OrthogonalizeViewUp();
	}

	if (this->AutoAdjustCameraClippingRange)
	{
		this->CurrentRenderer->ResetCameraClippingRange();
	}

	if (rwi->GetLightFollowCamera())
	{
		this->CurrentRenderer->UpdateLightsGeometryToFollowCamera();
	}

	rwi->Render();
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

	emit theParentScene_->OnMouseMove(theParentScene_);
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
	case 'R':
	case 'r':

		if (GetParentScene())
			GetParentScene()->RenderScene(true);

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

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::Get3DPointOnScreen(int x, int y, double* point)
{
	double viewFocus[4], cameraPos[3], newCameraPos[3];
	double newFocalPoint[4], norm[3];

	vtkCamera* camera = this->CurrentRenderer->GetActiveCamera();
	/*bool wasParallel = camera->GetParallelProjection();
	if (wasParallel)
		camera->ParallelProjectionOff();*/

	camera->GetPosition(cameraPos);
	camera->GetFocalPoint(viewFocus);
	camera->GetViewPlaneNormal(norm);
	double L = camera->GetDistance();

	FrgVisual_Scene_InterStyle3D::ComputeWorldToDisplay(
		this->CurrentRenderer, viewFocus[0], viewFocus[1], viewFocus[2], viewFocus);

	FrgVisual_Scene_InterStyle3D::ComputeDisplayToWorld(
		this->CurrentRenderer, double(x), double(y), viewFocus[2], newFocalPoint);

	int* clickPos = this->GetInteractor()->GetEventPosition();

	// Pick from this location.
	auto myPicker = vtkSmartPointer<vtkCellPicker>::New();
	myPicker->SetTolerance(GetPickingTolerance());
	//myPicker->SetTolerance(0.001);

	int pick = myPicker->Pick(clickPos[0], clickPos[1], 0.0, this->CurrentRenderer);
	//auto myPicker = vtkSmartPointer<vtkPropPicker>::New();
	//int pick = myPicker->PickProp(clickPos[0], clickPos[1], this->CurrentRenderer);

	double presentFocalPoint[3];
	camera->GetFocalPoint(presentFocalPoint);

	if (pick > 0)
	{
		myPicker->GetPickPosition(point);

		theCenterOfRotaion_[0] = point[0];
		theCenterOfRotaion_[1] = point[1];
		theCenterOfRotaion_[2] = point[2];
	}
	else
	{

		/*auto myActors = GetAllActors();
		std::vector<FrgVisual_GridActor*> myGrids;
		for (auto myActor : myActors)
		{
			auto myGrid = dynamic_cast<FrgVisual_GridActor*>(myActor);
			if (myGrid)
			{
				myGrids.push_back(myGrid);
				myGrid->VisibilityOff();
			}
		}*/

		/*double myBounds[6];
		this->CurrentRenderer->ComputeVisiblePropBounds(myBounds);

		double xDistance = cameraPos[0] - (myBounds[1] + myBounds[0]) / 2.0;
		double yDistance = cameraPos[0] - (myBounds[3] + myBounds[2]) / 2.0;
		double zDistance = cameraPos[2] - (myBounds[5] + myBounds[4]) / 2.0;*/
		//double distance = std::sqrt(std::pow(xDistance, 2.0) + std::pow(yDistance, 2.0) + std::pow(zDistance, 2.0));



		//std::cout << camera->GetClippingRange()[0] << ", " << camera->GetClippingRange()[1] << std::endl;

		//double distance = (camera->GetClippingRange()[0] + camera->GetClippingRange()[1]) / 2.0;
		//double distance = camera->GetClippingRange()[1];
		//double distance = camera->GetClippingRange()[0];

		/*for (auto myGrid : myGrids)
		{
			myGrid->VisibilityOn();
		}*/

		if (1)
		{
			/*auto myActors = GetAllActors();
			std::vector<FrgVisual_GridActor*> myGrids;
			for (auto myActor : myActors)
			{
				auto myGrid = dynamic_cast<FrgVisual_GridActor*>(myActor);
				if (myGrid)
				{
					myGrids.push_back(myGrid);
					myGrid->VisibilityOff();
				}
			}

			double myBounds[6];
			this->CurrentRenderer->ComputeVisiblePropBounds(myBounds);

			for (auto myGrid : myGrids)
			{
				myGrid->VisibilityOn();
			}*/

			/*point[0] = (myBounds[1] + myBounds[0]) / 2.0;
			point[1] = (myBounds[3] + myBounds[2]) / 2.0;
			point[2] = (myBounds[5] + myBounds[4]) / 2.0;
		}
		else
		{*/
		/*point[0] = newFocalPoint[0];
		point[1] = newFocalPoint[1];
		point[2] = newFocalPoint[2];

		double AC[3];
		AC[0] = point[0] - cameraPos[0];
		AC[1] = point[1] - cameraPos[1];
		AC[2] = point[2] - cameraPos[2];

		double mag = std::sqrt(AC[0] * AC[0] + AC[1] * AC[1] + AC[2] * AC[2]);
		double unitAC[3];
		unitAC[0] = AC[0] / mag;
		unitAC[1] = AC[1] / mag;
		unitAC[2] = AC[2] / mag;

		double AP[3];
		AP[0] = unitAC[0] * distance;
		AP[1] = unitAC[1] * distance;
		AP[2] = unitAC[2] * distance;

		point[0] = cameraPos[0] + AP[0];
		point[1] = cameraPos[1] + AP[1];
		point[2] = cameraPos[2] + AP[2];*/

			double BC[3];
			BC[0] = cameraPos[0] - newFocalPoint[0];
			BC[1] = cameraPos[1] - newFocalPoint[1];
			BC[2] = cameraPos[2] - newFocalPoint[2];

			double mag = std::sqrt(std::pow(BC[0], 2.0) + std::pow(BC[1], 2.0) + std::pow(BC[2], 2.0));

			double d[3]; // unit vector of BC
			d[0] = BC[0] / mag;
			d[1] = BC[1] / mag;
			d[2] = BC[2] / mag;

			double v[3]; // vector BA (B = newFocalPoint, A = presentFocalPoint, C = cameraPos)
			v[0] = theCenterOfRotaion_[0] - newFocalPoint[0];
			v[1] = theCenterOfRotaion_[1] - newFocalPoint[1];
			v[2] = theCenterOfRotaion_[2] - newFocalPoint[2];

			double t = v[0] * d[0] + v[1] * d[1] + v[2] * d[2]; // dot product of v and d

			point[0] = newFocalPoint[0] + t * d[0];
			point[1] = newFocalPoint[1] + t * d[1];
			point[2] = newFocalPoint[2] + t * d[2];
		}

		/*std::cout << newFocalPoint[0] << ", " << newFocalPoint[1] << ", " << newFocalPoint[2] << std::endl;
		std::cout << point[0] << ", " << point[1] << ", " << point[2] << std::endl;
		std::cout << camera->GetThickness() << std::endl;*/
	}

	/*if (wasParallel)
		camera->ParallelProjectionOn();*/
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
		double originalViewFocus[3], cameraPos[3], newCameraPos[3];
		double newFocalPoint[3];

		cam->GetPosition(cameraPos);
		cam->GetFocalPoint(originalViewFocus);

		double directionOfProjectionOfCamera[3];
		cam->GetDirectionOfProjection(directionOfProjectionOfCamera);

		Get3DPointOnScreen(position[0], position[1], newFocalPoint);

		cam->SetFocalPoint(newFocalPoint);

		// Move camera in/out along projection direction
		cam->Dolly(fact);
		double distance = cam->GetDistance();

		//		// Find new focal point
		cam->GetPosition(newCameraPos);


		double myFocalPoint[3];

		myFocalPoint[0] = originalViewFocus[0] + newCameraPos[0] - cameraPos[0];
		myFocalPoint[1] = originalViewFocus[1] + newCameraPos[1] - cameraPos[1];
		myFocalPoint[2] = originalViewFocus[2] + newCameraPos[2] - cameraPos[2];

		cam->SetFocalPoint(myFocalPoint);
		cam->SetDistance(distance);
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

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity*> ForgVisualLib::FrgVisual_Scene_InterStyle3D::GetSelectedActors() const
{
	return theSelectedActors_.toVector().toStdVector();
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity*> ForgVisualLib::FrgVisual_Scene_InterStyle3D::GetHiddenActors() const
{
	return theHiddenActors_.toVector().toStdVector();
}

//-------------------------------------------------------------------------
void ForgVisualLib::FrgVisual_Scene_InterStyle3D::PrintSelf(ostream& os, vtkIndent indent)
{

}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SelectActor(FrgVisual_BaseActor_Entity* actor, int isControlKeyPressed, bool render)
{
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

			actor->SelectActor(/*theSelectedColor_*/);
			theSelectedActors_.push_back(actor);
			theParentScene_->ActorSelectedSignal(actor);

			if (render)
				this->Interactor->Render();
		}
	}

	SetUnselectedActorsEliminated(render);
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::UnSelectActor(FrgVisual_BaseActor_Entity* actor, bool render)
{
	int index = IsActorSelected(actor);

	if (index >= 0)
	{
		theSelectedActors_[index]->UnSelectActor();
		theSelectedActors_[index]->GetProperty()->SetOpacity(1.0);
		theParentScene_->ActorUnSelectedSignal(theSelectedActors_[index]);
		theSelectedActors_.removeAt(index);

		theParentScene_->ActorUnSelectedSignal(actor);
	}

	if (render)
		this->Interactor->Render();
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SelectAllActors(bool render)
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

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::UnSelectAllActors(bool render)
{
	if (theSelectedActors_.size() == 0)
		return;

	while (!theSelectedActors_.empty())
		UnSelectActor(theSelectedActors_[0], false);

	if (render)
		this->Interactor->Render();

	/*FrgVisual_BaseActor_Entity* lastActor = theSelectedActors_[theSelectedActors_.size() - 1];
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		if (theSelectedActors_[i])
			theSelectedActors_[i]->UnSelectActor();
	}
	theSelectedActors_.clear();

	theParentScene_->ActorUnSelectedSignal(lastActor);

	if (render)
		this->Interactor->Render();*/
}

//#ifdef EliminateUnSelectedActors

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetUnselectedActorsEliminated(bool render)
{
	auto myAllActors = GetAllActors();

	if (myAllActors.size() == 0)
		return;

	for (int i = 0; i < myAllActors.size(); i++)
	{
		auto axesActor = dynamic_cast<vtkAxesActor*>(myAllActors[i]);
		if(axesActor)
			continue;

		int index = IsActorSelected(myAllActors[i]);

		if (index < 0)
		{
			if (!myAllActors[i]->IsSelectable())
				continue;

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

//#endif // EliminateUnSelectedActors

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::HideSelectedActors(bool render)
{
	if (theSelectedActors_.size() == 0)
		return;

	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		theSelectedActors_[i]->HideActor();
		theParentScene_->ActorHideSignal(theSelectedActors_[i]);
		theHiddenActors_.push_back(theSelectedActors_[i]);

		theParentScene_->ActorHideSignal(theSelectedActors_[i]);
	}

	UnSelectAllActors(false);

//#ifdef EliminateUnSelectedActors

	auto myAllActors = GetAllActors();
	for (int i = 0; i < myAllActors.size(); i++)
	{
		if (myAllActors[i]->IsSelectable())
			myAllActors[i]->GetProperty()->SetOpacity(1.0);
	}

//#endif // EliminateUnSelectedActors

	if (render)
		this->Interactor->Render();
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::UnHideHiddenActors(bool render)
{
	if (theHiddenActors_.size() == 0)
		return;

	for (int i = 0; i < theHiddenActors_.size(); i++)
	{
		theHiddenActors_[i]->UnHideActor();
		theParentScene_->ActorUnHideSignal(theHiddenActors_[i]);

//#ifdef EliminateUnSelectedActors

		if (theSelectedActors_.size() == 0)
			theHiddenActors_[i]->GetProperty()->SetOpacity(1.0);

//#endif // EliminateUnSelectedActors
	}
	theHiddenActors_.clear();

	if (render)
		this->Interactor->Render();
}

int ForgVisualLib::FrgVisual_Scene_InterStyle3D::IsActorSelected(FrgVisual_BaseActor_Entity* actor)
{
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		if (theSelectedActors_[i] == actor)
			return i;
	}

	return -1;
}

int ForgVisualLib::FrgVisual_Scene_InterStyle3D::IsActorHidden(FrgVisual_BaseActor_Entity* actor)
{
	for (int i = 0; i < theHiddenActors_.size(); i++)
	{
		if (theHiddenActors_[i] == actor)
			return i;
	}

	return -1;
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity*> ForgVisualLib::FrgVisual_Scene_InterStyle3D::GetAllActors()
{
	return theParentScene_->GetAllActors(false);

	/*std::vector<FrgVisual_BaseActor_Entity*> myActors;

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

	return myActors;*/
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::HideActionIsCalledSlot()
{
	HideSelectedActors(true);
}

void ForgVisualLib::FrgVisual_Scene_InterStyle3D::UnHideActionIsCalledSlot()
{
	UnHideHiddenActors(true);
}