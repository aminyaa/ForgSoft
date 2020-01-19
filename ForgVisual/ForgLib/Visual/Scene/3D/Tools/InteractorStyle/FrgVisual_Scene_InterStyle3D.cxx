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
//	emit theParent_->ActorSelectedSignal(true);
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToDefault()
//{
//	theParent_->setCursor(QCursor());
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToMove()
//{
//	QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_Move);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	theParent_->setCursor(cursor_default);
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToRotateXYZ()
//{
//	QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_RotateXYZ);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	theParent_->setCursor(cursor_default);
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToZoomIn()
//{
//	QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_RotateXYZ);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	theParent_->setCursor(cursor_default);
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetCursorShapeToZoomOut()
//{
//	QPixmap cursor_pixmap = QPixmap(ICON_Menu_Scene_RotateXYZ);
//	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
//	theParent_->setCursor(cursor_default);
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
//			vtkInteractorStyleTrackballCamera::OnLeftButtonUp();
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
//			vtkInteractorStyleTrackballCamera::OnLeftButtonUp();
//		}
//
//		SetCursorShapeToDefault();
//	}
//	else
//	{
//		vtkInteractorStyleTrackballCamera::OnLeftButtonUp();
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
//		vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
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
//	vtkInteractorStyleTrackballCamera::OnMouseWheelForward();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::OnMouseWheelBackward()
//{
//	vtkInteractorStyleTrackballCamera::OnMouseWheelBackward();
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
//	vtkInteractorStyleTrackballCamera::OnMiddleButtonDown();
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
//		vtkInteractorStyleTrackballCamera::OnMiddleButtonUp();
//	}
//
//	else
//	{
//		emit theParent_->customContextMenuRequested(QPoint(pickPosition[0], this->CurrentRenderer->GetRenderWindow()->GetSize()[1] - pickPosition[1]));
//
//		vtkInteractorStyleTrackballCamera::OnMiddleButtonUp();
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
//	if (theRotationEnabled_ == FrgFalse && thePlaneView_ != PlaneXYZ)
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
//	}
//
//	vtkInteractorStyleTrackballCamera::OnMouseMove();
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
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SelectActor
//(
//	vtkActor* actor,
//	int isControlKeyPressed,
//	FrgBool isFromTree
//)
//{
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
//	emit theParent_->ActorSelectedSignal(true);
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::UnSelectAllActors()
//{
//	for (int i = 0; i < theSelectedActors_.size(); i++)
//	{
//		// If we picked something before, reset its property
//		if (this->theSelectedActors_[i]->theActor_)
//		{
//			this->theSelectedActors_[i]->theActor_->GetProperty()->DeepCopy(this->theSelectedActors_[i]->theProperty_);
//		}
//	}
//
//	for (int i = 0; i < theParent_->GetActors().size(); i++)
//	{
//		theParent_->GetActors()[i]->GetProperty()->SetOpacity(1.0);
//	}
//	theSelectedActors_.clear();
//
//	this->Interactor->Render();
//
//	emit theParent_->ActorSelectedSignal(false);
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetViewToXYPlane()
//{
//	theRotationEnabled_ = FrgFalse;
//	auto camera = GetParentScene()->GetFrgBaseCamera();
//
//	camera->SetPosition(0, 0, 1);
//	camera->SetFocalPoint(0, 0, 0);
//	camera->SetViewUp(0, 1, 0);
//	//camera->Azimuth(-180);
//	camera->ParallelProjectionOn();
//	thePlaneView_ = PlaneXY;
//
//	GetParentScene()->GetRenderer()->ResetCamera();
//	GetParentScene()->GetRenderWindow()->Render();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetViewToXZPlane()
//{
//	theRotationEnabled_ = FrgFalse;
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
//	GetParentScene()->GetRenderWindow()->Render();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetViewToYZPlane()
//{
//	theRotationEnabled_ = FrgFalse;
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
//	GetParentScene()->GetRenderWindow()->Render();
//}
//
//void ForgVisualLib::FrgVisual_Scene_InterStyle3D::SetViewToXYZ()
//{
//	theRotationEnabled_ = FrgTrue;
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
//	GetParentScene()->GetRenderWindow()->Render();
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