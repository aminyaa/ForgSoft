#include <FrgCAD2D_Scene_InteractorStyle.hxx>

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

vtkStandardNewMacro(ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle);

#define AddLabel(label, title) \
label = new Label; \
label->theTitle_ = new QLabel(title); \
label->theValue_ = new QLabel; \
label->theValue_->setMinimumWidth(60);

ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::FrgCAD2D_Scene_InteractorStyle()
	: ForgVisualLib::FrgVisual_Scene_InterStyle2D()
{
	theIsInOperation_ = false;
	theOperationType_ = Default;
}

ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::~FrgCAD2D_Scene_InteractorStyle()
{

}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::FormInterStyle()
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
}

#include <vtkPropPicker.h>

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::OnMouseMove()
{
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
	//theParentScene_->statusBar()->showMessage("X: " + QString::number(world[0], 'g') + ", Y: " + QString::number(world[1], 'g'));

	if (theIsInOperation_)
	{
		QPixmap myPixmap(":/ForgCAD2D/Resources/Icons/Scene/Aim.png");
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

					if(isHorizontal)
						theCurrentPosition_[0] = pointActorData.X();
					else if(isVertical)
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
	}
	else
	{
		theParentScene_->setCursor(Qt::CursorShape::ArrowCursor);
		theParentScene_->RemoveActor(theTempPointActor_);
		theTempPointActor_ = nullptr;
	}

	theParentScene_->RenderScene(false, false);
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::OnLeftButtonDown()
{
	ForgBaseLib::FrgBase_Pnt<2> addedPt(theCurrentPosition_[0], theCurrentPosition_[1]);
	ForgBaseLib::FrgBase_Pnt<2> lastPt(theLastClickedPosition_[0], theLastClickedPosition_[1]);

	theLastClickedPosition_[0] = theCurrentPosition_[0];
	theLastClickedPosition_[1] = theCurrentPosition_[1];

	if (theIsInOperation_)
	{
		if (theOperationType_ == Default)
		{

		}
		else if (theOperationType_ == AddingPoint)
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
		else if (theOperationType_ == AddingPolyLine)
		{
			if (!theTempActor_)
				theTempActor_ = theParentScene_->AddPolyline({ ForgBaseLib::FrgBase_Pnt<2>(theCurrentPosition_[0], theCurrentPosition_[1]) });
			ForgVisualLib::FrgVisual_PolylineActor<2>::SafeDownCast(theTempActor_)->AddNextPoint(theCurrentPosition_[0], theCurrentPosition_[1]);
		}
		else if (theOperationType_ == AddingBSPLine)
		{
			if (!theTempActor_)
				theTempActor_ = theParentScene_->AddBSPLine({ ForgBaseLib::FrgBase_Pnt<2>(theCurrentPosition_[0], theCurrentPosition_[1]) }, 3);
			if (lastPt != addedPt)
				ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_)->AddNextPoint(theCurrentPosition_[0], theCurrentPosition_[1]);
		}
		else if (theOperationType_ == AddingBSPLineThroughPoints)
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
		else if (theOperationType_ == AddingRectangle)
		{
			if (!theTempActor_)
				theTempActor_ = theParentScene_->AddRectangle(theCurrentPosition_[0], theCurrentPosition_[1], theCurrentPosition_[0], theCurrentPosition_[1], false);
			else
				CompleteCommand();
		}
		else if (theOperationType_ == AddingCircle)
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

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::OnRightButtonDown()
{
	if (theIsInOperation_)
	{
		CompleteCommand();
	}
	else
		ForgVisualLib::FrgVisual_Scene_InterStyle2D::OnRightButtonDown();
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::AddPoint()
{
	theIsInOperation_ = true;
	theOperationType_ = AddingPoint;
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::AddPolyLine()
{
	theIsInOperation_ = true;
	theOperationType_ = AddingPolyLine;
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::AddBSPLine()
{
	theIsInOperation_ = true;
	theOperationType_ = AddingBSPLine;
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::AddBSPLineThroughPoints()
{
	theIsInOperation_ = true;
	theOperationType_ = AddingBSPLineThroughPoints;
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::AddRectangle()
{
	theIsInOperation_ = true;
	theOperationType_ = AddingRectangle;
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::AddCircle()
{
	theIsInOperation_ = true;
	theOperationType_ = AddingCircle;
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::Update(double x, double y)
{
	if (theTempPointActor_)
		theTempPointActor_->SetData(x, y);

	if (theOperationType_ == Default)
	{

	}
	else if (theOperationType_ == AddingPoint)
	{

	}
	else if (theOperationType_ == AddingPolyLine)
	{
		auto actor = ForgVisualLib::FrgVisual_PolylineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->SetLastPoint(x, y);
			actor->ShowPoints(true);
		}
	}
	else if (theOperationType_ == AddingBSPLine)
	{
		auto actor = ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->SetLastPoint(x, y);
			actor->ShowPoints(true);
		}
	}
	else if (theOperationType_ == AddingBSPLineThroughPoints)
	{
		auto actor = ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{

			thePts_[thePts_.size() - 1].X() = x;
			thePts_[thePts_.size() - 1].Y() = y;
			actor->SetDataInterpolate(thePts_, 2);
		}
	}
	else if (theOperationType_ == AddingRectangle)
	{
		auto actor = ForgVisualLib::FrgVisual_RectangleActor::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->SetP1(x, y);
		}
	}
	else if (theOperationType_ == AddingCircle)
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
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::CompleteCommand()
{
	if (!theIsInOperation_)
		return;

	if (theOperationType_ == Default)
	{

	}
	else if (theOperationType_ == AddingPoint)
	{
		theTempActor_ = nullptr;
	}
	else if (theOperationType_ == AddingPolyLine)
	{
		auto actor = ForgVisualLib::FrgVisual_PolylineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->RemoveLastPoint();
			actor->ShowPoints(false);

			if(actor->GetNumberOfPoints() >= 2)
				theTempActor_ = nullptr;
		}
	}
	else if (theOperationType_ == AddingBSPLine)
	{
		auto actor = ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			actor->RemoveLastPoint();
			actor->ShowPoints(false);

			if (actor->GetNumberOfPoints() >= 2)
				theTempActor_ = nullptr;
		}
	}
	else if (theOperationType_ == AddingBSPLineThroughPoints)
	{
		auto actor = ForgVisualLib::FrgVisual_BSPLineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			thePts_.pop_back();
			actor->SetDataInterpolate(thePts_, 2);
			thePts_.clear();

			if (actor->GetNumberOfPoints() >= 2)
				theTempActor_ = nullptr;
		}
	}
	else if (theOperationType_ == AddingRectangle)
	{
		auto actor = ForgVisualLib::FrgVisual_RectangleActor::SafeDownCast(theTempActor_);
		if (actor)
		{
			ForgBaseLib::FrgBase_Pnt<2> pt(theLastClickedPosition_[0], theLastClickedPosition_[1]);
			actor->SetP1(pt);

			if(actor->GetP0() != actor->GetP1())
				theTempActor_ = nullptr;
		}
	}
	else if (theOperationType_ == AddingCircle)
	{
		auto actor = ForgVisualLib::FrgVisual_CircleActor::SafeDownCast(theTempActor_);
		if (actor)
		{
			ForgBaseLib::FrgBase_Pnt<2> pt(theLastClickedPosition_[0], theLastClickedPosition_[1]);
			actor->SetPointOnCurve(pt);
			actor->ShowPoints(false);

			if(actor->GetCenterPoint() != pt)
				theTempActor_ = nullptr;
		}
	}
	else
	{

	}

	CancelCommand();
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::CancelCommand(bool unselectAllActors)
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

	theIsInOperation_ = false;
	theOperationType_ = Default;

	if(unselectAllActors)
		UnSelectAllActors(false);

	OnMouseMove();
}

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::UndoCommand()
{
	if (!theIsInOperation_)
		return;

	if (theOperationType_ == AddingPolyLine)
	{
		auto actor = ForgVisualLib::FrgVisual_PolylineActor<2>::SafeDownCast(theTempActor_);
		if (actor)
		{
			if (actor->GetNumberOfPoints() > 2)
				actor->RemoveLastPoint();
		}
	}
	else if (theOperationType_ == AddingBSPLine)
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

void ForgCAD2DLib::FrgCAD2D_Scene_InteractorStyle::DeleteSelectedActors()
{
	for (int i = 0; i < theSelectedActors_.size(); i++)
	{
		theParentScene_->RemoveActor(theSelectedActors_[i]);
	}
	theSelectedActors_.clear();

	theParentScene_->RenderScene(false, false);
}