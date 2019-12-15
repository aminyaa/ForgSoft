#include <FrgBaseInteractorStyle.hxx>
//#include <FrgBaseSceneTreeItem.hxx>
#include <FrgBaseCADScene.hxx>
#include <FrgBaseTree.hxx>
#include <FrgBaseCADPartFeatures.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseGlobalsICONS.hxx>

#include <QtGui/QColor>
#include <QApplication>
#include <QtWidgets/QStatusBar>

#include <vtkSetGet.h>
#include <vtkSmartPointer.h>
#include <vtkNew.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkAssemblyPath.h>
#include <vtkPropPicker.h>
#include <vtkCamera.h>
#include <vtkCallbackCommand.h>
#include <vtkCoordinate.h>
#include <vtkRendererCollection.h>

QColor ForgBaseLib::FrgBaseInteractorStyle::GeometryColorRGB = QColor(0.753 * 255, 0.753 * 255, 0.753 * 255);
QColor ForgBaseLib::FrgBaseInteractorStyle::GeometrySelectedColorRGB = QColor(1.0 * 255, 0.0 * 255, 1.0 * 255);

ForgBaseLib::FrgBaseInteractorStyle* ForgBaseLib::FrgBaseInteractorStyle::New()
{
	VTK_STANDARD_NEW_BODY(ForgBaseLib::FrgBaseInteractorStyle)
}

ForgBaseLib::FrgBaseInteractorStyle::FrgBaseInteractorStyle() : ResetPixelDistance(5)
{
	this->PreviousPosition[0] = 0;
	this->PreviousPosition[1] = 0;
}

void ForgBaseLib::FrgBaseInteractorStyle::SetSelectedActorColor(QColor color)
{
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		theSelectedActors_.at(i)->theActor_->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
		vtkSmartPointer<vtkProperty> bprop =
			vtkSmartPointer<vtkProperty>::New();
		bprop->SetColor(color.redF(), color.greenF(), color.blueF());
		theSelectedActors_.at(i)->theActor_->SetBackfaceProperty(bprop);
	}
}

void ForgBaseLib::FrgBaseInteractorStyle::AddActorToSelectedActors(vtkActor* actor)
{
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		if (theSelectedActors_.at(i)->theActor_ == actor)
		{
			if (this->Interactor->GetControlKey())
				theSelectedActors_.removeAt(i);
			return;
		}
	}

	FrgBaseActor* ta = new FrgBaseActor;
	ta->theActor_ = actor;
	ta->theProperty_ = vtkProperty::New();

	theSelectedActors_.push_back(ta);
}

void ForgBaseLib::FrgBaseInteractorStyle::HideSelectedActors()
{
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		theSelectedActors_.at(i)->theActor_->VisibilityOff();

		theSelectedActors_.at(i)->theActor_->GetProperty()->SetColor(GeometryColorRGB.redF(), GeometryColorRGB.greenF(), GeometryColorRGB.blueF());
		
		this->theSelectedActors_[i]->theActor_->GetProperty()->DeepCopy(this->theSelectedActors_[i]->theProperty_);
		theHiddenActors_.push_back(theSelectedActors_.at(i));
	}
	theSelectedActors_.clear();
	//theParent_->UpdateExportContextMenu();
	SetGeometriesOpacity(1.0);
	//TonbPlot tp;
}

void ForgBaseLib::FrgBaseInteractorStyle::ShowAllActors()
{
	for (int i = 0; i < theHiddenActors_.size(); i++)
	{
		theHiddenActors_.at(i)->theActor_->VisibilityOn();
	}
	theHiddenActors_.clear();
	//theParent_->UpdateExportContextMenu();
	if (theSelectedActors_.size() == 0)
		SetGeometriesOpacity(1.0);
}

void ForgBaseLib::FrgBaseInteractorStyle::SetGeometriesOpacity(double opacity)
{
	/*for (int j = 0; j < theParent_->GetGeometry().size(); j++)
		theParent_->GetGeometry().at(j)->GetProperty()->SetOpacity(opacity);*/
}

void ForgBaseLib::FrgBaseInteractorStyle::OnLeftButtonUp()
{
	if (theSelectedIconFromScene_ == Cursor)
	{
		int pickPosition[2];
		this->GetInteractor()->GetEventPosition(pickPosition);

		int xdist = pickPosition[0] - this->PreviousPosition[0];
		int ydist = pickPosition[1] - this->PreviousPosition[1];
		int moveDistance = (int)sqrt((double)(xdist * xdist + ydist * ydist));

		if (moveDistance > this->ResetPixelDistance)
		{
			vtkInteractorStyleTrackballCamera::OnLeftButtonUp();
		}

		else
		{
			int* clickPos = this->GetInteractor()->GetEventPosition();

			// Pick from this location.
			auto picker =
				vtkSmartPointer<vtkPropPicker>::New();
			picker->Pick(clickPos[0], clickPos[1], 0, this->CurrentRenderer);

			SelectActor(picker->GetActor(), this->Interactor->GetControlKey());

			vtkInteractorStyleTrackballCamera::OnLeftButtonUp();

			//theParent_->UpdateExportContextMenu();
		}

		SetCursorShapeToDefault();
	}
	else
	{
		vtkInteractorStyleTrackballCamera::OnLeftButtonUp();
	}
}

void ForgBaseLib::FrgBaseInteractorStyle::OnLeftButtonDown()
{
	if (theSelectedIconFromScene_ == Cursor)
	{
		int pickPosition[2];
		this->GetInteractor()->GetEventPosition(pickPosition);

		this->PreviousPosition[0] = pickPosition[0];
		this->PreviousPosition[1] = pickPosition[1];

		// Forward events
		vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
	}
	else
	{
		this->FindPokedRenderer(this->Interactor->GetEventPosition()[0],
			this->Interactor->GetEventPosition()[1]);
		if (this->CurrentRenderer == nullptr)
		{
			return;
		}

		this->GrabFocus(this->EventCallbackCommand);

		if (theSelectedIconFromScene_ == Move)
			this->StartPan();
		if (theSelectedIconFromScene_ == RotateXYZ)
			this->StartRotate();
	}
}

void ForgBaseLib::FrgBaseInteractorStyle::OnMouseWheelForward()
{
	vtkInteractorStyleTrackballCamera::OnMouseWheelForward();
}

void ForgBaseLib::FrgBaseInteractorStyle::OnMouseWheelBackward()
{
	vtkInteractorStyleTrackballCamera::OnMouseWheelBackward();
}

void ForgBaseLib::FrgBaseInteractorStyle::OnMiddleButtonDown()
{}

void ForgBaseLib::FrgBaseInteractorStyle::OnRightButtonDown()
{
	int pickPosition[2];
	this->GetInteractor()->GetEventPosition(pickPosition);

	this->PreviousPosition[0] = pickPosition[0];
	this->PreviousPosition[1] = pickPosition[1];

	// Forward events
	vtkInteractorStyleTrackballCamera::OnMiddleButtonDown();
}

void ForgBaseLib::FrgBaseInteractorStyle::OnRightButtonUp()
{
	SetCursorShapeToDefault();

	int pickPosition[2];
	this->GetInteractor()->GetEventPosition(pickPosition);

	int xdist = pickPosition[0] - this->PreviousPosition[0];
	int ydist = pickPosition[1] - this->PreviousPosition[1];
	int moveDistance = (int)sqrt((double)(xdist * xdist + ydist * ydist));

	if (moveDistance > this->ResetPixelDistance)
	{
		vtkInteractorStyleTrackballCamera::OnMiddleButtonUp();
	}

	else
	{
		emit theParent_->customContextMenuRequested(QPoint(pickPosition[0], this->CurrentRenderer->GetRenderWindow()->GetSize()[1] - pickPosition[1]));

		vtkInteractorStyleTrackballCamera::OnMiddleButtonUp();
	}
}

void ForgBaseLib::FrgBaseInteractorStyle::OnMouseMove()
{
	if (theRotationEnabled_ == FrgFalse && this->State == VTKIS_ROTATE)
		return;

	if (this->State == VTKIS_ROTATE)
	{
		SetCursorShapeToRotateXYZ();
	}
	else if (this->State == VTKIS_PAN)
	{
		SetCursorShapeToMove();
	}

	if (theRotationEnabled_ == FrgFalse && thePlaneView_ != PlaneXYZ)
	{
		int pickPosition[2];
		this->GetInteractor()->GetEventPosition(pickPosition);

		vtkSmartPointer<vtkCoordinate> coordinate =
			vtkSmartPointer<vtkCoordinate>::New();
		coordinate->SetCoordinateSystemToDisplay();
		coordinate->SetValue(pickPosition[0], pickPosition[1], 0);

		double* world = coordinate->GetComputedWorldValue(theParent_->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
		FrgString axis1 = "", axis2 = "";
		double axis1Value = 0.0, axis2Value = 0.0;

		if (thePlaneView_ == PlaneXY)
		{
			axis1 = "x";
			axis2 = "y";
			axis1Value = world[0];
			axis2Value = world[1];
		}
		else if (thePlaneView_ == PlaneXZ)
		{
			axis1 = "x";
			axis2 = "z";
			axis1Value = world[0];
			axis2Value = world[2];
		}
		else if (thePlaneView_ == PlaneYZ)
		{
			axis1 = "y";
			axis2 = "z";
			axis1Value = world[1];
			axis2Value = world[2];
		}

		theParent_->GetParentTree()->GetParentMainWindow()->statusBar()->showMessage(axis1 + " = " + QString::number(world[0]) + "\t " + axis2 + " = " + QString::number(world[1]));
	}

	vtkInteractorStyleTrackballCamera::OnMouseMove();
}

void ForgBaseLib::FrgBaseInteractorStyle::OnChar()
{
	// Get the keypress
	vtkRenderWindowInteractor* rwi = this->Interactor;
	std::string key = rwi->GetKeySym();

	// Output the key that was pressed
	std::cout << "Pressed " << key << std::endl;

	// Handle an arrow key
	if (key == "Up")
	{
		std::cout << "The up arrow was pressed." << std::endl;
	}

	// Handle w key
	if (key == "m" || key == "M")
	{
		static int iForM = 1;

		if (iForM == 1)
		{
			vtkRenderWindowInteractor* rwi = this->Interactor;
			vtkActorCollection* ac;
			vtkActor* anActor, * aPart;
			vtkAssemblyPath* path;
			this->FindPokedRenderer(rwi->GetEventPosition()[0],
				rwi->GetEventPosition()[1]);
			if (this->CurrentRenderer != nullptr)
			{
				ac = this->CurrentRenderer->GetActors();
				vtkCollectionSimpleIterator ait;
				for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
				{
					for (anActor->InitPathTraversal(); (path = anActor->GetNextPath()); )
					{
						aPart = static_cast<vtkActor*>(path->GetLastNode()->GetViewProp());
						//aPart->GetProperty()->SetEdgeColor(0, 0, 0);
						aPart->GetProperty()->EdgeVisibilityOn();
					}
				}
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			rwi->Render();
		}
		else if (iForM == -1)
		{
			vtkRenderWindowInteractor* rwi = this->Interactor;
			vtkActorCollection* ac;
			vtkActor* anActor, * aPart;
			vtkAssemblyPath* path;
			this->FindPokedRenderer(rwi->GetEventPosition()[0],
				rwi->GetEventPosition()[1]);
			if (this->CurrentRenderer != nullptr)
			{
				ac = this->CurrentRenderer->GetActors();
				vtkCollectionSimpleIterator ait;
				for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
				{
					for (anActor->InitPathTraversal(); (path = anActor->GetNextPath()); )
					{
						aPart = static_cast<vtkActor*>(path->GetLastNode()->GetViewProp());
						//aPart->GetProperty()->SetEdgeColor(0, 0, 0);
						aPart->GetProperty()->EdgeVisibilityOff();
					}
				}
			}
			else
			{
				vtkWarningMacro(<< "no current renderer on the interactor style.");
			}
			rwi->Render();
		}

		iForM *= -1;
	}

	if (theRotationEnabled_ == FrgTrue)
	{
		if (key == "s" || key == "S")
		{
			double* bounds = theParent_->GetRenderer()->ComputeVisiblePropBounds();
			auto camera = GetParentScene()->GetFrgBaseCamera();

			static int iPosForS = 1;

			camera->SetPosition(0, iPosForS, 0);
			//camera->SetFocalPoint((bounds[1] + bounds[0]) / 2.0, 0(bounds[3] + bounds[2]) / 2.0, (bounds[5] + bounds[4]) / 2.0);
			camera->SetFocalPoint(0.0, 0.0, 0.0);
			camera->SetViewUp(0, 0, 1);
			//camera->Azimuth(-180);

			iPosForS *= -1;

			GetParentScene()->GetRenderer()->ResetCamera();
			GetParentScene()->GetRenderWindow()->Render();
		}

		if (key == "f" || key == "F")
		{
			auto camera = GetParentScene()->GetFrgBaseCamera();

			static int iPosForS = 1;

			camera->SetPosition(iPosForS, 0, 0);
			camera->SetFocalPoint(0, 0, 0);
			camera->SetViewUp(0, 0, 1);
			camera->Azimuth(-180);

			iPosForS *= -1;

			GetParentScene()->GetRenderer()->ResetCamera();
			GetParentScene()->GetRenderWindow()->Render();
		}

		if (key == "t" || key == "T")
		{
			auto camera = GetParentScene()->GetFrgBaseCamera();

			static int iPosForT = -1;

			camera->SetPosition(0, 0, iPosForT);
			camera->SetFocalPoint(0, 0, 0);
			camera->SetViewUp(0, -iPosForT, 0);
			camera->Azimuth(-180);

			iPosForT *= -1;

			GetParentScene()->GetRenderer()->ResetCamera();
			GetParentScene()->GetRenderWindow()->Render();
		}

		if (key == "p" || key == "P")
		{
			auto camera = GetParentScene()->GetFrgBaseCamera();

			if (camera->GetParallelProjection())
				camera->ParallelProjectionOff();
			else
				camera->ParallelProjectionOn();

			GetParentScene()->GetRenderer()->ResetCamera();
			GetParentScene()->GetRenderWindow()->Render();
		}

		if (key == "d" || key == "D")
		{
			auto camera = GetParentScene()->GetFrgBaseCamera();

			camera->Yaw(5.0);
			GetParentScene()->GetRenderer()->ResetCamera();
			GetParentScene()->GetRenderWindow()->Render();
		}

		if (key == "a" || key == "A")
		{
			auto camera = GetParentScene()->GetFrgBaseCamera();

			camera->Yaw(-5.0);
			GetParentScene()->GetRenderer()->ResetCamera();
			GetParentScene()->GetRenderWindow()->Render();
		}
	}
}

void ForgBaseLib::FrgBaseInteractorStyle::SelectActor(vtkActor* actor, int isControlKeyPressed, FrgBool isFromTree)
{
	if(!isFromTree)
		theParent_-> GetParentTree()->clearSelection();

	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		// If we picked something before, reset its property
		if (this->theSelectedActors_[i]->theActor_)
		{
			this->theSelectedActors_[i]->theActor_->GetProperty()->DeepCopy(this->theSelectedActors_[i]->theProperty_);
		}
	}

	if (actor == FrgNullPtr && !isControlKeyPressed)
	{
		UnSelectAllActors();

		return;
	}

	if (!isControlKeyPressed)
	{
		theSelectedActors_.clear();
		AddActorToSelectedActors(actor);
	}
	else
	{
		AddActorToSelectedActors(actor);
	}

	for (int i = 0; i < theParent_->GetActors().size(); i++)
	{
		theParent_->GetActors().at(i)->GetProperty()->SetOpacity(0.5);
	}

	QList<FrgBaseTreeItem*> items;
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		if (this->theSelectedActors_[i]->theActor_)
		{
			// Save the property of the picked actor so that we can restore it next time
			this->theSelectedActors_[i]->theProperty_->DeepCopy(this->theSelectedActors_[i]->theActor_->GetProperty());
			// Highlight the picked actor by changing its properties
			this->theSelectedActors_[i]->theActor_->GetProperty()->SetColor
			(GeometrySelectedColorRGB.redF(), GeometrySelectedColorRGB.greenF(), GeometrySelectedColorRGB.blueF());
			this->theSelectedActors_[i]->theActor_->GetProperty()->SetDiffuse(1.0);
			this->theSelectedActors_[i]->theActor_->GetProperty()->SetSpecular(0.0);
			//this->theSelectedActors_[i]->theActor_->GetProperty()->EdgeVisibilityOn();

			theSelectedActors_[i]->theActor_->GetProperty()->SetOpacity(1.0);
		}

		if (!isFromTree)
		{
			auto item = theParent_->GetActorToPartFeature().value(theSelectedActors_[i]->theActor_);
			if (item)
				items.push_back(item);
		}
	}

	if (!isFromTree)
		theParent_->GetParentTree()->ScrollToItems(items);

	this->Interactor->Render();
}

void ForgBaseLib::FrgBaseInteractorStyle::SelectActors(QList<vtkActor*> actors, FrgBool isFromTree)
{
	UnSelectAllActors();

	for (int i = 0; i < actors.size(); i++)
	{
		SelectActor(actors[i], 1, isFromTree);
	}
}

void ForgBaseLib::FrgBaseInteractorStyle::UnSelectAllActors()
{
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		// If we picked something before, reset its property
		if (this->theSelectedActors_[i]->theActor_)
		{
			this->theSelectedActors_[i]->theActor_->GetProperty()->DeepCopy(this->theSelectedActors_[i]->theProperty_);
		}
	}

	for (int i = 0; i < theParent_->GetActors().size(); i++)
	{
		theParent_->GetActors()[i]->GetProperty()->SetOpacity(1.0);
	}
	theSelectedActors_.clear();

	this->Interactor->Render();
}

void ForgBaseLib::FrgBaseInteractorStyle::SetViewToXYPlane()
{
	theRotationEnabled_ = FrgFalse;
	auto camera = GetParentScene()->GetFrgBaseCamera();

	camera->SetPosition(0, 0, 1);
	camera->SetFocalPoint(0, 0, 0);
	camera->SetViewUp(0, 1, 0);
	//camera->Azimuth(-180);
	camera->ParallelProjectionOn();
	thePlaneView_ = PlaneXY;

	GetParentScene()->GetRenderer()->ResetCamera();
	GetParentScene()->GetRenderWindow()->Render();
}

void ForgBaseLib::FrgBaseInteractorStyle::SetViewToXZPlane()
{
	theRotationEnabled_ = FrgFalse;
	auto camera = GetParentScene()->GetFrgBaseCamera();

	camera->SetPosition(0, 1, 0);
	camera->SetFocalPoint(0, 0, 0);
	camera->SetViewUp(0, 0, 1);
	camera->Azimuth(-180);
	camera->ParallelProjectionOn();
	thePlaneView_ = PlaneXZ;

	GetParentScene()->GetRenderer()->ResetCamera();
	GetParentScene()->GetRenderWindow()->Render();
}

void ForgBaseLib::FrgBaseInteractorStyle::SetViewToYZPlane()
{
	theRotationEnabled_ = FrgFalse;
	auto camera = GetParentScene()->GetFrgBaseCamera();

	camera->SetPosition(-1, 0, 0);
	camera->SetFocalPoint(0, 0, 0);
	camera->SetViewUp(0, 0, 1);
	camera->Azimuth(-180);
	camera->ParallelProjectionOn();
	thePlaneView_ = PlaneYZ;

	GetParentScene()->GetRenderer()->ResetCamera();
	GetParentScene()->GetRenderWindow()->Render();
}

void ForgBaseLib::FrgBaseInteractorStyle::SetViewToXYZ()
{
	theRotationEnabled_ = FrgTrue;
	auto camera = GetParentScene()->GetFrgBaseCamera();

	camera->SetPosition(1, 0, 1);
	camera->SetFocalPoint(0, 0, 0);
	camera->SetViewUp(0, 0, 1);
	camera->Azimuth(-50);
	camera->ParallelProjectionOff();
	thePlaneView_ = PlaneXYZ;

	GetParentScene()->GetRenderer()->ResetCamera();
	GetParentScene()->GetRenderWindow()->Render();
}

void ForgBaseLib::FrgBaseInteractorStyle::SetCursorShapeToDefault()
{
	theParent_->setCursor(QCursor());
}

void ForgBaseLib::FrgBaseInteractorStyle::SetCursorShapeToMove()
{
	QPixmap cursor_pixmap = QPixmap(FrgICON_Menu_Scene_Move);
	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
	theParent_->setCursor(cursor_default);
}

void ForgBaseLib::FrgBaseInteractorStyle::SetCursorShapeToRotateXYZ()
{
	QPixmap cursor_pixmap = QPixmap(FrgICON_Menu_Scene_RotateXYZ);
	QCursor cursor_default = QCursor(cursor_pixmap, 0, 0);
	theParent_->setCursor(cursor_default);
}