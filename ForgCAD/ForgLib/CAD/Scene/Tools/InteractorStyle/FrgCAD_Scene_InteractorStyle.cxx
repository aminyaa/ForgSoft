#include <FrgCAD_Scene_InteractorStyle.hxx>
#include <FrgCAD_DlgPoint.hxx>
#include <FrgCAD_DlgOneValue.hxx>
#include <FrgCAD_Scene.hxx>
#include <FrgCAD_CmdLineEdit.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgVisual_Scene_CameraManip.hxx>
#include <FrgVisual_Scene.hxx>
#include <FrgVisual_PointActor.hxx>
#include <FrgVisual_PickingPointActor.hxx>
#include <FrgVisual_LineActor.hxx>
#include <FrgVisual_PolylineActor.hxx>
#include <FrgVisual_BSPLineActor.hxx>
#include <FrgVisual_RectangleActor.hxx>
#include <FrgVisual_CircleActor.hxx>

#include <QHBoxLayout>
#include <QStatusBar>
#include <QLabel>

#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkCoordinate.h>
#include <vtkRenderWindow.h>
#include <vtkRendererCollection.h>
#include <vtkPointPicker.h>
#include <vtkCellPicker.h>

#include <vtkAutoInit.h>

vtkStandardNewMacro(ForgCADLib::FrgCAD_Scene_InteractorStyle);

#define AddLabel(label, title) \
label = new Label; \
label->theTitle_ = new QLabel(title); \
label->theValue_ = new QLabel; \
label->theValue_->setMinimumWidth(60);

ForgCADLib::FrgCAD_Scene_InteractorStyle::FrgCAD_Scene_InteractorStyle()
	: ForgVisualLib::FrgVisual_Scene_InterStyle2D()
{
	SetInOperation(false);
	theOperationType_ = OperationType::Default;
}

ForgCADLib::FrgCAD_Scene_InteractorStyle::~FrgCAD_Scene_InteractorStyle()
{

}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::FormInterStyle()
{
	AddLabel(theXLabel_, "X:");
	AddLabel(theYLabel_, "Y:");

	class VLine : public QFrame
	{
	public:

		VLine()
		{
			setFrameShape(Shape::VLine);
		}
	};

	theParentScene_->statusBar()->addWidget(theXLabel_->theTitle_);
	theParentScene_->statusBar()->addWidget(theXLabel_->theValue_);
	theParentScene_->statusBar()->addWidget(new VLine);
	theParentScene_->statusBar()->addWidget(theYLabel_->theTitle_);
	theParentScene_->statusBar()->addWidget(theYLabel_->theValue_);
	theParentScene_->statusBar()->addWidget(new VLine);

	auto scene = dynamic_cast<FrgCAD_Scene*>(theParentScene_);
	if (scene)
	{
		connect(this, &FrgCAD_Scene_InteractorStyle::ActorAddedToCADSignal, scene, &FrgCAD_Scene::ActorAddedToCADSignal);
		connect(this, &FrgCAD_Scene_InteractorStyle::ActorIsGoingToBeDeletedFromCADSignal, scene, &FrgCAD_Scene::ActorIsGoingToBeDeletedFromCADSignal);
	}
}

#include <vtkPropPicker.h>

void ForgCADLib::FrgCAD_Scene_InteractorStyle::OnMouseMove()
{
	if (theDlg_)
	{
		if (theDlg_->IsInEditing())
		{
			theParentScene_->RenderScene(false, false);
			return;
		}
	}

	vtkRenderWindowInteractor* rwi = this->Interactor;

	if (this->CurrentRenderer && this->CurrentManipulator)
	{

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

	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];

	CustomOnMouseMove(x, y);
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::CustomOnMouseMove(int x, int y)
{
	vtkRenderWindowInteractor* rwi = this->Interactor;

	vtkSmartPointer<vtkCoordinate> coordinate =
		vtkSmartPointer<vtkCoordinate>::New();
	coordinate->SetCoordinateSystemToDisplay();
	coordinate->SetValue(x, y, 0);

	double* world = coordinate->GetComputedWorldValue(this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
	bool isVertical = false, isHorizontal = false;
	if (rwi->GetShiftKey())
	{
		double x1 = std::abs(world[0] - theLastClickedPosition_[0]);
		double y1 = std::abs(world[1] - theLastClickedPosition_[1]);
		if (x1 > y1)
		{
			world[1] = theLastClickedPosition_[1];
			isHorizontal = true;
		}
		else
		{
			world[0] = theLastClickedPosition_[0];
			isVertical = true;
		}
	}

	theCurrentPosition_[0] = world[0];
	theCurrentPosition_[1] = world[1];

	theXLabel_->theValue_->setText(QString::number(world[0], 'f').rightJustified(6, '0'));
	theXLabel_->theValue_->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	theYLabel_->theValue_->setText(QString::number(world[1], 'f').rightJustified(6, '0'));
	theYLabel_->theValue_->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	if (theIsInOperation_)
	{
		QPixmap myPixmap(":/ForgCAD/Resources/Icons/Scene/Aim.png");
		myPixmap = myPixmap.scaled(myPixmap.width() / 2, myPixmap.height() / 2);
		QCursor myCursor(myPixmap);
		theParentScene_->setCursor(myCursor);

		if (!theTempPointActor_)
		{
			theTempPointActor_ = theParentScene_->AddPickingPoint(ForgBaseLib::FrgBase_Pnt<2>(world[0], world[1]), false);
			//theTempPointActor_ = theParentScene_->AddPoint(world[0], world[1], false);
			theTempPointActor_->SetRenderPointsAsSpheres(true);
			theTempPointActor_->SetSize(8);
		}

		int* clickPos = this->GetInteractor()->GetEventPosition();

		vtkActorCollection* pickedActors = nullptr;
		auto myPicker = vtkSmartPointer<vtkPointPicker>::New();
		myPicker->SetTolerance(0.01);
		int picked = myPicker->Pick(clickPos[0], clickPos[1], 0.0, this->CurrentRenderer);


		if (picked)
		{
			pickedActors = myPicker->GetActors();
			vtkCollectionSimpleIterator ait;
			vtkActor* anActor = nullptr;
			for (pickedActors->InitTraversal(ait); (anActor = pickedActors->GetNextActor(ait)); )
			{
				auto pointActor = dynamic_cast<ForgVisualLib::FrgVisual_PointActor<2>*>(anActor);
				if (pointActor && pointActor != theTempPointActor_)
				{
					auto pointActorData = pointActor->GetData();

					if (isHorizontal)
						theCurrentPosition_[0] = pointActorData.X();
					else if (isVertical)
						theCurrentPosition_[1] = pointActorData.Y();
					else
					{
						theCurrentPosition_[0] = pointActorData.X();
						theCurrentPosition_[1] = pointActorData.Y();
					}

					break;
				}
			}
		}

		Update(theCurrentPosition_[0], theCurrentPosition_[1]);

		if (theDlg_)
		{
			auto oneValueDlg = dynamic_cast<FrgCAD_DlgOneValue*>(theDlg_);
			if (oneValueDlg)
			{

			}
			else
			{
				theDlg_->SetValue({ theCurrentPosition_[0], theCurrentPosition_[1] });
			}

			if (!rwi->GetShiftKey() && !rwi->GetControlKey())
				theDlg_->SetFocused(true);
			else
				theDlg_->SetFocused(false);
		}
	}
	else
	{
		theParentScene_->setCursor(Qt::CursorShape::ArrowCursor);
		theParentScene_->RemoveActor(theTempPointActor_);
		theTempPointActor_ = nullptr;
	}

	theParentScene_->RenderScene(false, false);
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::OnLeftButtonDown()
{
	ForgBaseLib::FrgBase_Pnt<2> addedPt(theCurrentPosition_[0], theCurrentPosition_[1]);
	ForgBaseLib::FrgBase_Pnt<2> lastPt(theLastClickedPosition_[0], theLastClickedPosition_[1]);

	theLastClickedPosition_[0] = theCurrentPosition_[0];
	theLastClickedPosition_[1] = theCurrentPosition_[1];

	if (theIsInOperation_)
	{
		if (theOperationType_ == OperationType::Default)
		{

		}
		else if (theOperationType_ == OperationType::AddingPoint)
		{
			if (!theTempActor_)
				theTempActor_ = theParentScene_->AddPoint(theCurrentPosition_[0], theCurrentPosition_[1], true);
			auto actor = ForgVisualLib::FrgVisual_PointActor<2>::SafeDownCast(theTempActor_);
			if (actor)
			{
				actor->SetRenderPointsAsSpheres(true);
				actor->SetSize(8);
			}
			theTempActor_ = nullptr;
		}
		else if (theOperationType_ == OperationType::AddingPolyLine)
		{
			if (!theTempActor_)
				theTempActor_ = theParentScene_->AddPolyline({ ForgBaseLib::FrgBase_Pnt<2>(theCurrentPosition_[0], theCurrentPosition_[1]) });
			ForgVisualLib::FrgVisual_PolylineActor<2>::SafeDownCast(theTempActor_)->AddNextPoint(theCurrentPosition_[0], theCurrentPosition_[1]);
		}
		else if (theOperationType_ == OperationType::AddingBSPLine)
		{
			if (!theTempActor_)
				theTempActor_ = theParentScene_->AddBSPLine({ ForgBaseLib::FrgBase_Pnt<2>(theCurrentPosition_[0], theCurrentPosition_[1]) }, 3);
			if (lastPt != addedPt)
				ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_)->AddNextPoint(theCurrentPosition_[0], theCurrentPosition_[1]);
		}
		else if (theOperationType_ == OperationType::AddingBSPLineThroughPoints)
		{
			if (!theTempActor_)
			{
				thePts_.push_back(addedPt);
				thePts_.push_back(addedPt);
				theTempActor_ = theParentScene_->AddBSPLineThroughPoints(thePts_, 2, false);
			}
			else
			{
				if (lastPt != addedPt)
					thePts_.push_back(addedPt);
				ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_)->SetDataInterpolate(thePts_, 2);
			}
		}
		else if (theOperationType_ == OperationType::AddingRectangle)
		{
			if (!theTempActor_)
				theTempActor_ = theParentScene_->AddRectangle(theCurrentPosition_[0], theCurrentPosition_[1], theCurrentPosition_[0], theCurrentPosition_[1], false);
			else
				CompleteCommand();
		}
		else if (theOperationType_ == OperationType::AddingCircle)
		{
			if (!theTempActor_)
			{
				ForgBaseLib::FrgBase_Pnt<2> p(theCurrentPosition_[0], theCurrentPosition_[1]);
				theTempActor_ = theParentScene_->AddCircleUsingCenterAndPointOnCurve(p, p, false);
			}
			else
				CompleteCommand();
		}
		else
		{

		}
	}
	else
		ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnLeftButtonDown();

	OnMouseMove();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::OnRightButtonDown()
{
	if (theIsInOperation_)
	{
		CompleteCommand();
	}
	else
		ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnRightButtonDown();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::AddCommand(const QString& command)
{
	if (command == "Point")
		AddPoint();
	else if (command == "PolyLine")
		AddPolyLine();
	else if (command == "SPLine")
		AddBSPLine();
	else if (command == "SPLineThroughPoints")
		AddBSPLineThroughPoints();
	else if (command == "Circle")
		AddCircle();
	else if (command == "Rectangle")
		AddRectangle();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::AddPoint()
{
	SetInOperation(true);
	theOperationType_ = OperationType::AddingPoint;

	AddPointDialog();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::AddPolyLine()
{
	SetInOperation(true);
	theOperationType_ = OperationType::AddingPolyLine;

	AddPointDialog();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::AddBSPLine()
{
	SetInOperation(true);
	theOperationType_ = OperationType::AddingBSPLine;

	AddPointDialog();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::AddBSPLineThroughPoints()
{
	SetInOperation(true);
	theOperationType_ = OperationType::AddingBSPLineThroughPoints;

	AddPointDialog();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::AddRectangle()
{
	SetInOperation(true);
	theOperationType_ = OperationType::AddingRectangle;

	AddPointDialog();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::AddCircle()
{
	SetInOperation(true);
	theOperationType_ = OperationType::AddingCircle;

	AddPointDialog();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::Update(double x, double y, bool render)
{
	if (theTempPointActor_)
		theTempPointActor_->SetData(x, y);

	if (theOperationType_ == OperationType::Default)
	{

	}
	else if (theOperationType_ == OperationType::AddingPoint)
	{

	}
	else if (theOperationType_ == OperationType::AddingPolyLine)
	{
		auto actor = ForgVisualLib::FrgVisual_PolylineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->SetLastPoint(x, y);
			actor->ShowPoints(true);
		}
	}
	else if (theOperationType_ == OperationType::AddingBSPLine)
	{
		auto actor = ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->SetLastPoint(x, y);
			actor->ShowPoints(true);
		}
	}
	else if (theOperationType_ == OperationType::AddingBSPLineThroughPoints)
	{
		auto actor = ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{

			thePts_[thePts_.size() - 1].X() = x;
			thePts_[thePts_.size() - 1].Y() = y;
			actor->SetDataInterpolate(thePts_, 2);
		}
	}
	else if (theOperationType_ == OperationType::AddingRectangle)
	{
		auto actor = ForgVisualLib::FrgVisual_RectangleActor::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->SetP1(x, y);
		}
	}
	else if (theOperationType_ == OperationType::AddingCircle)
	{
		auto actor = ForgVisualLib::FrgVisual_CircleActor::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->SetPointOnCurve(ForgBaseLib::FrgBase_Pnt<2>(x, y));
			actor->ShowPoints(true);
		}
	}
	else
	{

	}

	if (render)
		theParentScene_->RenderScene(false, false);
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::CompleteCommand()
{
	if (!theIsInOperation_)
		return;

	if (theOperationType_ == OperationType::Default)
	{
		emit ActorAddedToCADSignal(theTempActor_);
	}
	else if (theOperationType_ == OperationType::AddingPoint)
	{
		emit ActorAddedToCADSignal(theTempActor_);

		theTempActor_ = nullptr;
	}
	else if (theOperationType_ == OperationType::AddingPolyLine)
	{
		auto actor = ForgVisualLib::FrgVisual_PolylineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->RemoveLastPoint();
			actor->ShowPoints(false);

			emit ActorAddedToCADSignal(theTempActor_);

			if (actor->GetNumberOfPoints() >= 2)
				theTempActor_ = nullptr;
		}
	}
	else if (theOperationType_ == OperationType::AddingBSPLine)
	{
		auto actor = ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->RemoveLastPoint();
			actor->ShowPoints(false);

			emit ActorAddedToCADSignal(theTempActor_);

			if (actor->GetNumberOfPoints() >= 2)
				theTempActor_ = nullptr;
		}
	}
	else if (theOperationType_ == OperationType::AddingBSPLineThroughPoints)
	{
		auto actor = ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			thePts_.pop_back();
			actor->SetDataInterpolate(thePts_, 2);
			thePts_.clear();

			emit ActorAddedToCADSignal(theTempActor_);

			if (actor->GetNumberOfPoints() >= 2)
				theTempActor_ = nullptr;
		}
	}
	else if (theOperationType_ == OperationType::AddingRectangle)
	{
		auto actor = ForgVisualLib::FrgVisual_RectangleActor::SafeDownCast(theTempActor_);
		if (actor)
		{
			ForgBaseLib::FrgBase_Pnt<2> pt(theLastClickedPosition_[0], theLastClickedPosition_[1]);
			actor->SetP1(pt);

			emit ActorAddedToCADSignal(theTempActor_);

			if (actor->GetP0() != actor->GetP1())
				theTempActor_ = nullptr;
		}
	}
	else if (theOperationType_ == OperationType::AddingCircle)
	{
		auto actor = ForgVisualLib::FrgVisual_CircleActor::SafeDownCast(theTempActor_);
		if (actor)
		{
			ForgBaseLib::FrgBase_Pnt<2> pt(theLastClickedPosition_[0], theLastClickedPosition_[1]);
			actor->SetPointOnCurve(pt);
			actor->ShowPoints(false);

			emit ActorAddedToCADSignal(theTempActor_);

			if (actor->GetCenterPoint() != pt)
				theTempActor_ = nullptr;
		}
	}
	else
	{

	}

	CancelCommand();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::CancelCommand(bool unselectAllActors)
{
	if (theTempActor_)
	{
		theParentScene_->RemoveActor(theTempActor_);
		theTempActor_ = nullptr;
	}
	if (theTempPointActor_)
	{
		theParentScene_->RemoveActor(theTempPointActor_);
		theTempPointActor_ = nullptr;
	}
	
	if (theDlg_)
	{
		theDlg_->deleteLater();
		theDlg_ = nullptr;
	}

	SetInOperation(false);
	theOperationType_ = OperationType::Default;

	if (unselectAllActors)
		UnSelectAllActors(false);

	OnMouseMove();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::UndoCommand()
{
	if (!theIsInOperation_)
		return;

	if (theOperationType_ == OperationType::AddingPolyLine)
	{
		auto actor = ForgVisualLib::FrgVisual_PolylineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			if (actor->GetNumberOfPoints() > 2)
				actor->RemoveLastPoint();
		}
	}
	else if (theOperationType_ == OperationType::AddingBSPLine)
	{
		auto actor = ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			if (actor->GetNumberOfCtrlPts() > 2)
				actor->RemoveLastPoint();
		}
	}

	OnMouseMove();
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::DeleteSelectedActors()
{
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		emit ActorIsGoingToBeDeletedFromCADSignal(theSelectedActors_[i]);

		theParentScene_->RemoveActor(theSelectedActors_[i]);
	}
	theSelectedActors_.clear();

	theParentScene_->RenderScene(false, false);
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::AddPointDialog()
{
	theDlg_ = new FrgCAD_DlgPoint(theParentScene_);

	QObject::connect
	(
		theDlg_,
		&FrgCAD_DlgEntity::IsInEditingSignal,
		[this](bool condition)
		{
			if (condition)
			{
				auto dlgPoint = dynamic_cast<FrgCAD_DlgPoint*>(theDlg_);
				const double x = dlgPoint->GetXValue();
				const double y = dlgPoint->GetYValue();

				Update(x, y, true);
				theCurrentPosition_[0] = x;
				theCurrentPosition_[1] = y;
			}
			else
				OnMouseMove();
		}
	);

	QObject::connect(theDlg_, &FrgCAD_DlgEntity::OKClickedSignal, [this]() {OnLeftButtonDown(); });
	QObject::connect(theDlg_, &FrgCAD_DlgEntity::CancelClickedSignal, [this]() {CancelCommand(); });
}

void ForgCADLib::FrgCAD_Scene_InteractorStyle::SetInOperation(bool inOperation)
{
	theIsInOperation_ = inOperation;
	auto scene = dynamic_cast<FrgCAD_Scene*>(theParentScene_);
	if (scene)
		scene->GetCmdLineEdit()->DisableCommandLine(inOperation);
}