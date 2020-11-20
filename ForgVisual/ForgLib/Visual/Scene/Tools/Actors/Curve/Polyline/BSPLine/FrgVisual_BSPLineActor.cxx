#include <FrgVisual_BSPLineActor.hxx>

#include <FrgVisual_CtrlPointActor.hxx>
#include <FrgBase_Pnt.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

#include <Geom2d_BSplineCurve.hxx>
#include <Geom_BSplineCurve.hxx>

#include <vtkProperty.h>
#include <vtkMapper.h>
#include <vtkRenderer.h>
#include <vtkObjectFactory.h>

#define CTRLPTS_POLYLINE_IS_NULL "CTRLPTS_POLYLINE_IS_NULL"
#define CTRLPTS_POLYLINE_IS_NOT_NULL "CTRLPTS_POLYLINE_IS_NOT_NULL"

ForgVisualLib::FrgVisual_BSPLineActor_Entity::FrgVisual_BSPLineActor_Entity()
{

}

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_BSPLineActor<Dim>);

template<int Dim>
ForgVisualLib::FrgVisual_BSPLineActor<Dim>::FrgVisual_BSPLineActor()
{
	GetProperty()->SetRepresentationToWireframe();

	theDegree_ = 2;
	theNumberOfDiscretization_ = 200;
}

template<int Dim>
ForgVisualLib::FrgVisual_BSPLineActor<Dim>::~FrgVisual_BSPLineActor()
{
}

#include <BSplCLib.hxx>

template<int Dim>
 void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SetData
(
	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts,
	int degree,
	bool drawCtrlPts
)
{
	if (ctrlPts.size() < 3)
	{
		ctrlPts.push_back(ctrlPts[ctrlPts.size() - 1]);
		/*std::exception myException("The size of control points cannot be smaller than 3");
		throw myException;*/
	}
	if (degree >= ctrlPts.size() || degree <= 1)
	{
		std::exception myException("The degree should be bigger than 1 and smaller than the number of control points.");
		throw myException;
	}

	theDegree_ = degree;

	CalculateKnotsAndMultiplicities(ctrlPts);

	CreateBSPLineCurve(ctrlPts, theKnots_, theMultiplicities_);

	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> curvePts = CalculatePointsOnCurve();

	FrgVisual_PolylineActor<Dim>::SetData(curvePts);

	FrgVisual_PolylineActor<Dim>::SetParentBSPLineActor(this);

	DrawCtrlPts(drawCtrlPts);
}

template<int Dim>
 void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::UpdateActor()
{
	const auto& ctrlPts = GetCtrlPts();

	if constexpr (Dim == 2)
	{
		auto my2dCurve = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_);
		for (int i = 0; i < ctrlPts.size(); i++)
		{
			if (my2dCurve->Pole(i + 1).X() != ctrlPts[i]->GetData()->X() || my2dCurve->Pole(i + 1).Y() != ctrlPts[i]->GetData()->Y())
				my2dCurve->SetPole(i + 1, gp_Pnt2d(ctrlPts[i]->GetData()->X(), ctrlPts[i]->GetData()->Y()));
		}
	}
	else if constexpr (Dim == 3)
	{
		auto my3dCurve = dynamic_cast<Geom_BSplineCurve*>(theBSPLineCurve_);
		for (int i = 0; i < ctrlPts.size(); i++)
		{

			if (my3dCurve->Pole(i + 1).X() != ctrlPts[i]->GetData()->X() || my3dCurve->Pole(i + 1).Y() != ctrlPts[i]->GetData()->Y() || my3dCurve->Pole(i + 1).Z() != ctrlPts[i]->GetData()->Z())
				my3dCurve->SetPole(i + 1, gp_Pnt(ctrlPts[i]->GetData()->X(), ctrlPts[i]->GetData()->Y(), ctrlPts[i]->GetData()->Z()));
		}
	}

	const auto& calculatedPointsOnCurve = CalculatePointsOnCurve();

	auto pointsOnCurve = this->GetPts();
	int i = 0;
	for (auto x : pointsOnCurve)
	{
		x->GetData()->X() = calculatedPointsOnCurve[i]->X();
		x->GetData()->Y() = calculatedPointsOnCurve[i]->Y();
		if constexpr (Dim == 3)
			x->GetData()->Z() = calculatedPointsOnCurve[i]->Z();

		i++;
	}

	this->FrgVisual_PolylineActor::UpdateActor();

	if (theCtrlPtsPolyLine_)
		theCtrlPtsPolyLine_->UpdateActor();

	if (this->GetMapper())
		this->GetMapper()->Update();
}

template<int Dim>
 void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::DrawCtrlPts(bool drawCtrlPts)
{
	if (theRenderer_)
	{
		if (!drawCtrlPts)
		{
			if (theCtrlPtsPolyLine_)
			{
				auto ctrlPts = theCtrlPtsPolyLine_->GetPts();
				for (auto x : ctrlPts)
					theRenderer_->RemoveActor(x);

				theRenderer_->RemoveActor(theCtrlPtsPolyLine_);
				theCtrlPtsPolyLine_ = nullptr;
			}
		}
		else
		{
			auto ctrlPts = GetCtrlPts();

			if (!theCtrlPtsPolyLine_)
			{
				theCtrlPtsPolyLine_ = FrgVisual_PolylineActor<Dim>::New();
				theCtrlPtsPolyLine_->SetIndependent(false);
				theCtrlPtsPolyLine_->SetRenderer(theRenderer_);
				theCtrlPtsPolyLine_->SetData(ctrlPts);
				theCtrlPtsPolyLine_->SetColor(0.0, 0.0, 0.0);
				theCtrlPtsPolyLine_->SetLineWidth(1.0);
				theCtrlPtsPolyLine_->SetRenderLinesAsTubes(false);
				theCtrlPtsPolyLine_->SetStippledLine(50);
				theCtrlPtsPolyLine_->SetSelectable(false);
			}

			//for (int i = 0; i < ctrlPts.size(); i++)
			//{
			//	//ctrlPts[i]->SetSize(10.0f);
			//	//ctrlPts[i]->SetRenderPointsAsSpheres(true);
			//	////ctrlPts[i]->SetColor(0.0, 0.0, 0.0);
			//	//ctrlPts[i]->VisibilityOn();
			//	
			//	dynamic_cast<ForgVisualLib::FrgVisual_CtrlPointActor<Dim>*>(ctrlPts[i])->SetParentBSPLineActor(this);

			//}

			theCtrlPtsPolyLine_->SetParentBSPLineActor(this);

			theRenderer_->AddActor(theCtrlPtsPolyLine_);
		}
	}
}

template<int Dim>
 void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::TranslateActor(double dx, double dy)
{
	 if (theCtrlPtsPolyLine_)
	 {
		 theCtrlPtsPolyLine_->blockSignals(true);
		 theCtrlPtsPolyLine_->TranslateActor(dx, dy);
		 theCtrlPtsPolyLine_->blockSignals(false);
	 }

	FrgVisual_PolylineActor<Dim>::TranslateActor(dx, dy);
}

template<int Dim>
 void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::TranslateActor(double dx, double dy, double dz)
{
	if (theCtrlPtsPolyLine_)
	{
		theCtrlPtsPolyLine_->blockSignals(true);
		theCtrlPtsPolyLine_->TranslateActor(dx, dy, dz);
		theCtrlPtsPolyLine_->blockSignals(false);
	}

	FrgVisual_PolylineActor<Dim>::TranslateActor(dx, dy, dz);
}

template<int Dim>
 bool ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SelectActor(const QColor& color)
{
	if (theCtrlPtsPolyLine_)
	{
		auto ctrlPts = theCtrlPtsPolyLine_->GetPts();
		for (auto x : ctrlPts)
			x->SetSelectable(false);
	}

	return FrgVisual_PolylineActor<Dim>::SelectActor(color);
}

template<int Dim>
 bool ForgVisualLib::FrgVisual_BSPLineActor<Dim>::UnSelectActor()
{
	if (theCtrlPtsPolyLine_)
	{
		auto ctrlPts = theCtrlPtsPolyLine_->GetPts();
		for (auto x : ctrlPts)
			x->SetSelectable(true);
	}

	return FrgVisual_PolylineActor<Dim>::UnSelectActor();
}

template<int Dim>
 void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CtrlPtsSelectionHasChangedSlot()
{
	if (theCtrlPtsPolyLine_)
	{
		auto ctrlPts = theCtrlPtsPolyLine_->GetPts();
		bool isSelected = false;
		for (auto x : ctrlPts)
		{
			if (x->IsSelected())
			{
				isSelected = true;
				break;
			}
		}

		this->SetSelectable(!isSelected);
	}
}

template<int Dim>
 void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CtrlPtsDataHasChangedSlot()
{
	UpdateActor();
}

template<int Dim>
 void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalculateKnotsAndMultiplicities(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts)
{
	 theMultiplicities_.clear();
	 int sizeOfOther = ctrlPts.size() - theDegree_ - 1;

	 theMultiplicities_.resize(2 + sizeOfOther);

	 theMultiplicities_[0] = theDegree_ + 1;
	 theMultiplicities_[theMultiplicities_.size() - 1] = theDegree_ + 1;

	 for (int i = 1; i < theMultiplicities_.size() - 1; i++)
		 theMultiplicities_[i] = 1;

	theKnots_.clear();
	theKnots_.resize(theMultiplicities_.size());

	theKnots_[0] = 0.0;
	theKnots_[theKnots_.size() - 1] = 1.0;

	double dK = 1.0 / ((double)theKnots_.size() - 1.0);

	for (int i = 1; i < theKnots_.size() - 1; i++)
		theKnots_[i] = i * dK;
}

 template<int Dim>
 void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CreateBSPLineCurve
 (
	 std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts,
	 std::vector<double> theKnots,
	 std::vector<int> theMultiplicities
 )
 {
	 FreePointer(theBSPLineCurve_);

	 TColStd_Array1OfReal knots;
	 TColStd_Array1OfInteger mult;

	 knots.Resize(1, theKnots.size(), false);
	 mult.Resize(1, theMultiplicities.size(), false);

	 for (int i = 0; i < theKnots.size(); i++)
	 {
		 knots.SetValue(i + 1, theKnots[i]);
		 mult.SetValue(i + 1, theMultiplicities[i]);
	 }

	 if constexpr (Dim == 2)
	 {
		 TColgp_Array1OfPnt2d Pts(1, ctrlPts.size());
		 for (int i = 0; i < ctrlPts.size(); i++)
			 Pts.SetValue(i + 1, gp_Pnt2d(ctrlPts[i]->X(), ctrlPts[i]->Y()));

		 theBSPLineCurve_ = new Geom2d_BSplineCurve(Pts, knots, mult, theDegree_);
	 }
	 else if constexpr (Dim == 3)
	 {
		 TColgp_Array1OfPnt Pts(1, ctrlPts.size());
		 for (int i = 0; i < ctrlPts.size(); i++)
			 Pts.SetValue(i + 1, gp_Pnt(ctrlPts[i]->X(), ctrlPts[i]->Y(), ctrlPts[i]->Z()));

		 theBSPLineCurve_ = new Geom_BSplineCurve(Pts, knots, mult, theDegree_);
	 }
 }

template<int Dim>
 std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalculatePointsOnCurve() const
{
	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> curvePoints;
	double dU = 1.0 / (double)theNumberOfDiscretization_;
	if constexpr (Dim == 2)
	{
		auto my2dCurve = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_);
		for (int i = 0; i <= theNumberOfDiscretization_; i++)
		{
			double u = i * dU;
			auto pt = my2dCurve->Value(u);

			curvePoints.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(pt.X(), pt.Y()));
		}
	}
	else if constexpr (Dim == 3)
	{
		auto my3dCurve = dynamic_cast<Geom_BSplineCurve*>(theBSPLineCurve_);
		for (int i = 0; i <= theNumberOfDiscretization_; i++)
		{
			double u = i * dU;
			auto pt = my3dCurve->Value(u);

			curvePoints.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(pt.X(), pt.Y(), pt.Z()));
		}
	}

	return std::move(curvePoints);
}

template<int Dim>
 std::vector<ForgVisualLib::FrgVisual_PointActor<Dim>*> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::GetCtrlPts() const
{
	if (theCtrlPtsPolyLine_)
	{
		return theCtrlPtsPolyLine_->GetPts();
	}
	else if (theBSPLineCurve_)
	{
		std::vector<ForgVisualLib::FrgVisual_PointActor<Dim>*> ctrlPts;

		if constexpr (Dim == 2)
		{
			auto curvePoles = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_)->Poles();
			for (int i = 0; i < curvePoles.Size(); i++)
			{
				auto myPoint = std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(curvePoles(i + 1).X(), curvePoles(i + 1).Y());
				ForgVisualLib::FrgVisual_PointActor<Dim>* myCtrlPoint = ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::New();
				myCtrlPoint->SetData(myPoint);
				ctrlPts.push_back(myCtrlPoint);
			}
		}
		else if constexpr (Dim == 3)
		{
			auto curvePoles = dynamic_cast<Geom_BSplineCurve*>(theBSPLineCurve_)->Poles();
			for (int i = 0; i < curvePoles.Size(); i++)
			{
				auto myPoint = std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(curvePoles(i + 1).X(), curvePoles(i + 1).Y(), curvePoles(i + 1).Z());
				ForgVisualLib::FrgVisual_PointActor<Dim>* myCtrlPoint = ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::New();
				myCtrlPoint->SetData(myPoint);
				ctrlPts.push_back(myCtrlPoint);
			}
		}

		return std::move(ctrlPts);
	}
	else
		return std::move(std::vector<ForgVisualLib::FrgVisual_PointActor<Dim>*>());
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SetRenderer(vtkRenderer* renderer)
{
	if (!renderer)
		return;

	ForgVisualLib::FrgVisual_BaseActor_Entity::SetRenderer(renderer);

	if (theCtrlPtsPolyLine_)
	{
		theCtrlPtsPolyLine_->SetRenderer(renderer);

		if (!theCtrlPtsPolyLine_->IsIndependent())
			theRenderer_->AddActor(theCtrlPtsPolyLine_);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SetSelectable(bool selectable)
{
	if (theCtrlPtsPolyLine_)
		theCtrlPtsPolyLine_->SetSelectable(selectable);

	ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetSelectable(selectable);
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::RemoveActors(vtkRenderer* renderer)
{
	if (!theCtrlPtsPolyLine_)
		return;

	if (renderer)
	{
		ForgVisualLib::FrgVisual_PolylineActor<Dim>::RemoveActors(renderer);

		theCtrlPtsPolyLine_->RemoveActors(renderer);
		renderer->RemoveActor(theCtrlPtsPolyLine_);
	}
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_BSPLineActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_PolylineActor<Dim>>(*this);

	ar& theDegree_;
	ar& theNumberOfDiscretization_;
	ar& theKnots_;
	ar& theMultiplicities_;

	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts;

	if constexpr (Dim == 2)
	{
		auto geomPoles = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_)->Poles();
		for (int i = 0; i < geomPoles.Size(); i++)
			ctrlPts.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(geomPoles.Value(i + 1).X(), geomPoles.Value(i + 1).Y()));
	}
	else if constexpr (Dim == 3)
	{
		auto geomPoles = dynamic_cast<Geom_BSplineCurve*>(theBSPLineCurve_)->Poles();
		for (int i = 0; i < geomPoles.Size(); i++)
			ctrlPts.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(geomPoles.Value(i + 1).X(), geomPoles.Value(i + 1).Y(), geomPoles.Value(i + 1).Z()));
	}

	ar& ctrlPts;

	QString ctrlPtsPolyLineIsNull;
	if (theCtrlPtsPolyLine_)
	{
		ctrlPtsPolyLineIsNull = CTRLPTS_POLYLINE_IS_NOT_NULL;
		ar& ctrlPtsPolyLineIsNull;

		ar& theCtrlPtsPolyLine_;
	}
	else
	{
		ctrlPtsPolyLineIsNull = CTRLPTS_POLYLINE_IS_NULL;
		ar& ctrlPtsPolyLineIsNull;
	}
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_BSPLineActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_PolylineActor<Dim>>(*this);

	ar& theDegree_;
	ar& theNumberOfDiscretization_;
	ar& theKnots_;
	ar& theMultiplicities_;

	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts;
	ar& ctrlPts;

	QString ctrlPtsPolyLineIsNull;
	ar& ctrlPtsPolyLineIsNull;

	if (ctrlPtsPolyLineIsNull == CTRLPTS_POLYLINE_IS_NOT_NULL)
		ar& theCtrlPtsPolyLine_;

	CreateBSPLineCurve(ctrlPts, theKnots_, theMultiplicities_);

	ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetParentBSPLineActor(this);

	if (theCtrlPtsPolyLine_)
	{
		theCtrlPtsPolyLine_->SetParentBSPLineActor(this);
		theCtrlPtsPolyLine_->SetStippledLine(theCtrlPtsPolyLine_->GetLineStipplePattern(), theCtrlPtsPolyLine_->IsStippled());
	}
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BSPLineActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BSPLineActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_BSPLineActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_BSPLineActor<3>;