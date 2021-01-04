#include <FrgVisual_BSPLineActor.hxx>
#include <FrgVisual_CtrlPointActor.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgBase_SerialSpec_QString.hxx>
#include <FrgBase_FullMtx.hxx>

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

	theDegree_ = -1;
}

template<int Dim>
ForgVisualLib::FrgVisual_BSPLineActor<Dim>::~FrgVisual_BSPLineActor()
{
}

#include <BSplCLib.hxx>

//template<int Dim>
// void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SetData
//(
//	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts,
//	int degree,
//	bool drawCtrlPts
//)
//{
//	//if (ctrlPts.size() < 3)
//	//{
//	//	ctrlPts.push_back(ctrlPts[ctrlPts.size() - 1]);
//	//	/*std::exception myException("The size of control points cannot be smaller than 3");
//	//	throw myException;*/
//	//}
//	//if (degree >= ctrlPts.size() || degree <= 1)
//	//{
//	//	std::exception myException("The degree should be bigger than 1 and smaller than the number of control points.");
//	//	throw myException;
//	//}
//
//	//theDegree_ = degree;
//
//	//CalculateKnotsAndMultiplicities(ctrlPts);
//
//	//CreateBSPLineCurve(ctrlPts, theKnots_, theMultiplicities_);
//
//	//std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> curvePts = CalculatePointsOnCurve();
//
//	//FrgVisual_PolylineActor<Dim>::SetData(curvePts);
//
//	//FrgVisual_PolylineActor<Dim>::SetParentBSPLineActor(this);
//
//	//DrawCtrlPts(drawCtrlPts);
//}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SetData(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts, int degree)
{
	if (theDegree_ == -1)
		theDegree_ = degree;

	if (ctrlPts.empty())
		return;

	if (ctrlPts.size() == 1 || ctrlPts.size() == 2)
	{
		FrgVisual_PolylineActor<Dim>::SetData(ctrlPts);
		return;
	}

	int newDegree = degree;
	if (degree >= ctrlPts.size())
		newDegree = ctrlPts.size() - 1;

	bool isPeriodic = false;
	if (ctrlPts[0] == ctrlPts[ctrlPts.size() - 1])
		isPeriodic = true;

	CreateBSPLineCurve(ctrlPts, CalculateKnots(ctrlPts, newDegree, isPeriodic), CalculateMultiplicities(ctrlPts, newDegree, isPeriodic), newDegree, isPeriodic);

	UpdateActor();
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SetDataInterpolate(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts, int degree)
{
	if (theDegree_ == -1)
		theDegree_ = degree;

	if (pts.empty())
		return;

	if (pts.size() == 1 || pts.size() == 2)
	{
		FrgVisual_PolylineActor<Dim>::SetData(pts);
		return;
	}

	bool canBeDrawn = true;
	auto ptStart = pts[0];
	auto ptEnd = pts[pts.size() - 1];
	for (int i = 1; i < pts.size() - 1; i++)
	{
		if (pts[i] == ptStart || pts[i] == ptEnd)
		{
			canBeDrawn = false;
			break;
		}
	}

	if (!canBeDrawn)
		return;

	/*if (pts[pts.size() - 1] == pts[pts.size() - 2])
	{
		std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ptsEdited = pts;
		ptsEdited.pop_back();
		SetDataInterpolate(ptsEdited, degree);
		return;
	}*/

	int newDegree = degree;
	if (degree >= pts.size())
		newDegree = pts.size() - 1;

	auto ctrlPts = Interpolate(pts, newDegree);
	auto myKnots = CalcKnotVector(pts, CalcKnotBarCentripetal(pts), newDegree);
	std::vector<double> myKnotsEdited(myKnots.size() - 2 * newDegree);
	for (int i = newDegree, k = 0; k < myKnotsEdited.size(); i++, k++)
		myKnotsEdited[k] = myKnots[i];
	CreateBSPLineCurve(ctrlPts, myKnotsEdited, CalculateMultiplicities(ctrlPts, newDegree, false), newDegree, false);

	UpdateActor();
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::AddNextPoint(ForgBaseLib::FrgBase_Pnt<Dim> pt)
{
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts = GetCtrlPts();
	ctrlPts.push_back(pt);
	SetData(ctrlPts, theDegree_);
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SetLastPoint(ForgBaseLib::FrgBase_Pnt<Dim> pt)
{
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts = GetCtrlPts();
	ctrlPts[ctrlPts.size() - 1] = pt;
	SetData(ctrlPts, theDegree_);
}

template<>
template<>
inline void ForgVisualLib::FrgVisual_BSPLineActor<2>::AddNextPoint(double x, double y)
{
	AddNextPoint(ForgBaseLib::FrgBase_Pnt<2>(x, y));
}

template<>
template<>
void ForgVisualLib::FrgVisual_BSPLineActor<2>::SetLastPoint(double x, double y)
{
	SetLastPoint(ForgBaseLib::FrgBase_Pnt<2>(x, y));
}

template<>
template<>
inline void ForgVisualLib::FrgVisual_BSPLineActor<3>::AddNextPoint(double x, double y, double z)
{
	AddNextPoint(ForgBaseLib::FrgBase_Pnt<3>(x, y, z));
}

template<>
template<>
void ForgVisualLib::FrgVisual_BSPLineActor<3>::SetLastPoint(double x, double y, double z)
{
	SetLastPoint(ForgBaseLib::FrgBase_Pnt<3>(x, y, z));
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::RemoveLastPoint()
{
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts = GetCtrlPts();
	ctrlPts.pop_back();
	SetData(ctrlPts, theDegree_);
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::ShowPoints(bool condition)
{
	if (theRenderer_)
	{
		for (auto x : theCtrlPts_)
			theRenderer_->RemoveActor(x);
		theCtrlPts_.clear();

		theRenderer_->RemoveActor(theCtrlPtsPolyLine_);
		theCtrlPtsPolyLine_ = nullptr;
	}

	if (condition)
	{
		std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts = GetCtrlPts();
		int nFor;
		if (this->IsSelected())
			nFor = ctrlPts.size();
		else
			nFor = ctrlPts.size() - 1;

		for (int i = 0; i < nFor; i++)
		{
			vtkSmartPointer<FrgVisual_PointActor<Dim>> actor =
				vtkSmartPointer<FrgVisual_PointActor<Dim>>::New();
			actor->SetRenderer(theRenderer_);
			actor->SetRenderPointsAsSpheres(true);
			actor->SetColor(0.0, 1.0, 0.0);
			actor->SetSize(8);

			actor->SetData(ctrlPts[i]);

			if (theRenderer_)
				theRenderer_->AddActor(actor);

			theCtrlPts_.push_back(actor);
		}

		theCtrlPtsPolyLine_ = FrgVisual_PolylineActor<Dim>::New();
		theCtrlPtsPolyLine_->SetRenderer(theRenderer_);
		theCtrlPtsPolyLine_->SetData(ctrlPts);
		theCtrlPtsPolyLine_->SetStippledLine(50, true);

		if (theRenderer_)
			theRenderer_->AddActor(theCtrlPtsPolyLine_);
	}
}

template<int Dim>
long long ForgVisualLib::FrgVisual_BSPLineActor<Dim>::GetNumberOfCtrlPts()
{
	return GetCtrlPts().size();
}

//template<int Dim>
// void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::UpdateActor()
//{
//	/*const auto& ctrlPts = GetCtrlPts();
//
//	if constexpr (Dim == 2)
//	{
//		auto my2dCurve = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_);
//		for (int i = 0; i < ctrlPts.size(); i++)
//		{
//			if (my2dCurve->Pole(i + 1).X() != ctrlPts[i]->GetData()->X() || my2dCurve->Pole(i + 1).Y() != ctrlPts[i]->GetData()->Y())
//				my2dCurve->SetPole(i + 1, gp_Pnt2d(ctrlPts[i]->GetData()->X(), ctrlPts[i]->GetData()->Y()));
//		}
//	}
//	else if constexpr (Dim == 3)
//	{
//		auto my3dCurve = dynamic_cast<Geom_BSplineCurve*>(theBSPLineCurve_);
//		for (int i = 0; i < ctrlPts.size(); i++)
//		{
//
//			if (my3dCurve->Pole(i + 1).X() != ctrlPts[i]->GetData()->X() || my3dCurve->Pole(i + 1).Y() != ctrlPts[i]->GetData()->Y() || my3dCurve->Pole(i + 1).Z() != ctrlPts[i]->GetData()->Z())
//				my3dCurve->SetPole(i + 1, gp_Pnt(ctrlPts[i]->GetData()->X(), ctrlPts[i]->GetData()->Y(), ctrlPts[i]->GetData()->Z()));
//		}
//	}
//
//	const auto& calculatedPointsOnCurve = CalculatePointsOnCurve();
//
//	auto pointsOnCurve = this->GetPts();
//	int i = 0;
//	for (auto x : pointsOnCurve)
//	{
//		x->GetData()->X() = calculatedPointsOnCurve[i]->X();
//		x->GetData()->Y() = calculatedPointsOnCurve[i]->Y();
//		if constexpr (Dim == 3)
//			x->GetData()->Z() = calculatedPointsOnCurve[i]->Z();
//
//		i++;
//	}
//
//	this->FrgVisual_PolylineActor::UpdateActor();
//
//	if (theCtrlPtsPolyLine_)
//		theCtrlPtsPolyLine_->UpdateActor();
//
//	if (this->GetMapper())
//		this->GetMapper()->Update();*/
//}

//template<int Dim>
// void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::DrawCtrlPts(bool drawCtrlPts)
//{
//	//if (theRenderer_)
//	//{
//	//	if (!drawCtrlPts)
//	//	{
//	//		if (theCtrlPtsPolyLine_)
//	//		{
//	//			auto ctrlPts = theCtrlPtsPolyLine_->GetPts();
//	//			for (auto x : ctrlPts)
//	//				theRenderer_->RemoveActor(x);
//
//	//			theRenderer_->RemoveActor(theCtrlPtsPolyLine_);
//	//			theCtrlPtsPolyLine_ = nullptr;
//	//		}
//	//	}
//	//	else
//	//	{
//	//		auto ctrlPts = GetCtrlPts();
//
//	//		if (!theCtrlPtsPolyLine_)
//	//		{
//	//			theCtrlPtsPolyLine_ = FrgVisual_PolylineActor<Dim>::New();
//	//			theCtrlPtsPolyLine_->SetIndependent(false);
//	//			theCtrlPtsPolyLine_->SetRenderer(theRenderer_);
//	//			theCtrlPtsPolyLine_->SetData(ctrlPts);
//	//			theCtrlPtsPolyLine_->SetColor(0.0, 0.0, 0.0);
//	//			theCtrlPtsPolyLine_->SetLineWidth(1.0);
//	//			theCtrlPtsPolyLine_->SetRenderLinesAsTubes(false);
//	//			theCtrlPtsPolyLine_->SetStippledLine(50);
//	//			theCtrlPtsPolyLine_->SetSelectable(false);
//	//		}
//
//	//		//for (int i = 0; i < ctrlPts.size(); i++)
//	//		//{
//	//		//	//ctrlPts[i]->SetSize(10.0f);
//	//		//	//ctrlPts[i]->SetRenderPointsAsSpheres(true);
//	//		//	////ctrlPts[i]->SetColor(0.0, 0.0, 0.0);
//	//		//	//ctrlPts[i]->VisibilityOn();
//	//		//	
//	//		//	dynamic_cast<ForgVisualLib::FrgVisual_CtrlPointActor<Dim>*>(ctrlPts[i])->SetParentBSPLineActor(this);
//
//	//		//}
//
//	//		theCtrlPtsPolyLine_->SetParentBSPLineActor(this);
//
//	//		theRenderer_->AddActor(theCtrlPtsPolyLine_);
//	//	}
//	//}
//}

//template<int Dim>
// void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::TranslateActor(double dx, double dy)
//{
//	/* if (theCtrlPtsPolyLine_)
//	 {
//		 theCtrlPtsPolyLine_->blockSignals(true);
//		 theCtrlPtsPolyLine_->TranslateActor(dx, dy);
//		 theCtrlPtsPolyLine_->blockSignals(false);
//	 }
//
//	FrgVisual_PolylineActor<Dim>::TranslateActor(dx, dy);*/
//}

//template<int Dim>
// void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::TranslateActor(double dx, double dy, double dz)
//{
//	/*if (theCtrlPtsPolyLine_)
//	{
//		theCtrlPtsPolyLine_->blockSignals(true);
//		theCtrlPtsPolyLine_->TranslateActor(dx, dy, dz);
//		theCtrlPtsPolyLine_->blockSignals(false);
//	}
//
//	FrgVisual_PolylineActor<Dim>::TranslateActor(dx, dy, dz);*/
//}

//template<int Dim>
// bool ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SelectActor(const QColor& color)
//{
//	/*if (theCtrlPtsPolyLine_)
//	{
//		auto ctrlPts = theCtrlPtsPolyLine_->GetPts();
//		for (auto x : ctrlPts)
//			x->SetSelectable(false);
//	}*/
//
//	return FrgVisual_PolylineActor<Dim>::SelectActor(color);
//}

//template<int Dim>
// bool ForgVisualLib::FrgVisual_BSPLineActor<Dim>::UnSelectActor()
//{
//	/*if (theCtrlPtsPolyLine_)
//	{
//		auto ctrlPts = theCtrlPtsPolyLine_->GetPts();
//		for (auto x : ctrlPts)
//			x->SetSelectable(true);
//	}*/
//
//	return FrgVisual_PolylineActor<Dim>::UnSelectActor();
//}

//template<int Dim>
// void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CtrlPtsSelectionHasChangedSlot()
//{
//	/*if (theCtrlPtsPolyLine_)
//	{
//		auto ctrlPts = theCtrlPtsPolyLine_->GetPts();
//		bool isSelected = false;
//		for (auto x : ctrlPts)
//		{
//			if (x->IsSelected())
//			{
//				isSelected = true;
//				break;
//			}
//		}
//
//		this->SetSelectable(!isSelected);
//	}*/
//}

//template<int Dim>
// void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CtrlPtsDataHasChangedSlot()
//{
//	UpdateActor();
//}

template<int Dim>
std::vector<double> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalculateKnots(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts, int degree, bool isPeriodic)
{
	std::vector<double> knots;

	if (!isPeriodic)
	{
		knots.resize(2 + (ctrlPts.size() - degree - 1));
		knots[0] = 0.0;
		knots[knots.size() - 1] = 1.0;

		double dK = 1.0 / ((double)knots.size() - 1.0);

		for (int i = 1; i < knots.size() - 1; i++)
			knots[i] = i * dK;
	}
	else
	{
		knots.push_back(0.0);
		int sizeOfOther = ctrlPts.size() - degree;
		double dK = 1.0 / ((double)sizeOfOther + 1.0);
		for (int i = 0; i < sizeOfOther; i++)
			knots.push_back((i + 1.0) * dK);
		knots.push_back(1.0);
	}

	return std::move(knots);
}

template<int Dim>
std::vector<int> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalculateMultiplicities(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts, int degree, bool isPeriodic)
{
	std::vector<int> mult;

	if (!isPeriodic)
	{
		int sizeOfOther = ctrlPts.size() - degree - 1;
		mult.resize(2 + sizeOfOther);

		for (int i = 1; i < mult.size() - 1; i++)
			mult[i] = 1;

		mult[0] = degree + 1;
		mult[mult.size() - 1] = degree + 1;
	}
	else
	{
		mult.push_back(degree);
		int sizeOfOther = ctrlPts.size() - mult[0];
		for (int i = 0; i < sizeOfOther; i++)
			mult.push_back(1);
		mult.push_back(degree);
	}

	return std::move(mult);
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CreateBSPLineCurve
(
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts,
	std::vector<double> theKnots,
	std::vector<int> theMultiplicities,
	int degree,
	bool isPerodic
)
{
	FreePointer(theCurve_);

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
			Pts.SetValue(i + 1, gp_Pnt2d(ctrlPts[i].X(), ctrlPts[i].Y()));

		theCurve_ = new Geom2d_BSplineCurve(Pts, knots, mult, degree, isPerodic);
	}
	else if constexpr (Dim == 3)
	{
		TColgp_Array1OfPnt Pts(1, ctrlPts.size());
		for (int i = 0; i < ctrlPts.size(); i++)
			Pts.SetValue(i + 1, gp_Pnt(ctrlPts[i].X(), ctrlPts[i].Y(), ctrlPts[i].Z()));

		theCurve_ = new Geom_BSplineCurve(Pts, knots, mult, degree, isPerodic);
	}
}

//template<int Dim>
// std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalculatePointsOnCurve() const
//{
//	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> curvePoints;
//	double dU = 1.0 / (double)theNumberOfDiscretization_;
//	if constexpr (Dim == 2)
//	{
//		auto my2dCurve = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_);
//		for (int i = 0; i <= theNumberOfDiscretization_; i++)
//		{
//			double u = i * dU;
//			auto pt = my2dCurve->Value(u);
//
//			curvePoints.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(pt.X(), pt.Y()));
//		}
//	}
//	else if constexpr (Dim == 3)
//	{
//		auto my3dCurve = dynamic_cast<Geom_BSplineCurve*>(theBSPLineCurve_);
//		for (int i = 0; i <= theNumberOfDiscretization_; i++)
//		{
//			double u = i * dU;
//			auto pt = my3dCurve->Value(u);
//
//			curvePoints.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(pt.X(), pt.Y(), pt.Z()));
//		}
//	}
//
//	return std::move(curvePoints);
//}

#include <BRepMesh_IncrementalMesh.hxx>
#include <Precision.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeEdge2d.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBndLib.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Wire.hxx>
#include <BRep_Tool.hxx>

Handle(Poly_Triangulation)
RetrieveTriangulation
(
	const TopoDS_Face& theFace
)
{
	TopLoc_Location Loc;
	auto Triangulation = BRep_Tool::Triangulation(theFace, Loc);
	return std::move(Triangulation);
}

template<int Dim>
std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalculatePointsOnCurve()
{
	//auto pts = std::move(CalculatePointsOnCurve(3.0));
	auto pts = std::move(DiscreteCurve(theCurve_, 3.0));

	//for (auto x : thePts_)
	//{
	//	theRenderer_->RemoveActor(x);
	//	//x->Delete();
	//}
	//thePts_.clear();

	//for (const auto& pt : pts)
	//{
	//	auto actor = vtkSmartPointer<FrgVisual_PointActor<Dim>>::New();
	//	actor->SetData(pt);
	//	actor->SetSize(4.0);
	//	actor->SetRenderPointsAsSpheres(true);
	//	theRenderer_->AddActor(actor);
	//	thePts_.push_back(actor);
	//}

	return std::move(pts);

	/*std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> curvePoints;
	double dU = 1.0 / (double)theNumberOfDiscretization_;
	if constexpr (Dim == 2)
	{
		auto my2dCurve = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_);
		for (int i = 0; i <= theNumberOfDiscretization_; i++)
		{
			double u = i * dU;
			auto pt = my2dCurve->Value(u);

			curvePoints.push_back(ForgBaseLib::FrgBase_Pnt<Dim>(pt.X(), pt.Y()));
		}
	}
	else if constexpr (Dim == 3)
	{
		auto my3dCurve = dynamic_cast<Geom_BSplineCurve*>(theBSPLineCurve_);
		for (int i = 0; i <= theNumberOfDiscretization_; i++)
		{
			double u = i * dU;
			auto pt = my3dCurve->Value(u);

			curvePoints.push_back(ForgBaseLib::FrgBase_Pnt<Dim>(pt.X(), pt.Y(), pt.Z()));
		}
	}*/

	//BRepMesh_FastDiscret::Parameters params;
	//params.Deflection = 0.01;
	//params.Angle = 0.5;
	//params.Relative = Standard_False;
	//params.InParallel = Standard_True;
	//params.MinSize = Precision::Confusion();
	//params.InternalVerticesMode = Standard_True;
	//params.ControlSurfaceDeflection = Standard_True;

	//auto my2dCurve = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_);
	//Handle(Geom2d_BSplineCurve) my2dCurveHandle = new Geom2d_BSplineCurve(*my2dCurve);
	//TopoDS_Edge E = BRepBuilderAPI_MakeEdge2d(my2dCurveHandle);
	//TopoDS_Wire W = BRepBuilderAPI_MakeWire(E);

	//Bnd_Box BoundingBox;
	//BRepBndLib::Add(W, BoundingBox);

	////TopoDS_Wire W = BRepBuilderAPI_MakeWire(E);
	////BRepMesh_IncrementalMesh aMesher(E, params);
	//BRepMesh_FastDiscret Mesh(BoundingBox, params);
	//Mesh.Perform(W);

	//std::vector<Handle(Poly_Triangulation)> tris;
	//for
	//	(
	//		TopExp_Explorer Explorer(W, TopAbs_WIRE);
	//		Explorer.More();
	//		Explorer.Next()
	//		)
	//{
	//	auto tri = RetrieveTriangulation(TopoDS::Wire(Explorer.Current()));
	//	std::cout << tri.IsNull() << std::endl;
	//	if (tri)
	//		tris.push_back(tri);
	//}

	//std::cout << tris[0]->Node(1).X() << ", " << tris[0]->Node(1).Y() << std::endl;
	//std::cout << "========================\n";

	//return std::move(curvePoints);
}

//template<int Dim>
//std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalculatePointsOnCurve(double epsilon)
//{
//	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts;
//
//	auto my2dCurve = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_);
//	auto my3dCurve = dynamic_cast<Geom_BSplineCurve*>(theBSPLineCurve_);
//
//	double du = 0.1;
//	double u0 = 0.0;
//	double u1 = u0 + du;
//	
//	if constexpr (Dim == 2)
//	{
//		auto p0Curve = my2dCurve->Value(0.0);
//		pts.emplace_back(p0Curve.X(), p0Curve.Y());
//	}
//	else if constexpr (Dim == 3)
//	{
//		auto p0Curve = my3dCurve->Value(0.0);
//		pts.emplace_back(p0Curve.X(), p0Curve.Y(), p0Curve.Z());
//	}
//
//	int ii = 0;
//	while (u0 < 1.0)
//	{
//		if (u1 >= 1.0)
//			break;
//
//		if constexpr (Dim == 2)
//		{
//			if (my2dCurve)
//			{
//				gp_Pnt2d p0, p1;
//				gp_Vec2d v0, v1;
//				my2dCurve->D1(u0, p0, v0);
//				my2dCurve->D1(u1, p1, v1);
//
//				double myError = std::abs(v0.Angle(v1) * 180.0 / 3.1415927);
//				if (myError > epsilon)
//				{
//					u1 = (u0 + u1) / 2.0;
//					du = u1 - u0;
//
//					continue;
//				}
//				else
//				{
//					pts.emplace_back(p1.X(), p1.Y());
//					ii++;
//
//					u0 = u1;
//					du *= 2.0;
//					u1 = u0 + du;
//				}
//			}
//		}
//		else if constexpr (Dim == 3)
//		{
//			if (my3dCurve)
//			{
//				gp_Pnt p0, p1;
//				gp_Vec v0, v1;
//				my3dCurve->D1(u0, p0, v0);
//				my3dCurve->D1(u1, p1, v1);
//
//				double myError = std::abs(v0.Angle(v1) * 180.0 / 3.1415927);
//				if (myError > epsilon)
//				{
//					u1 = (u0 + u1) / 2.0;
//					du = u1 - u0;
//
//					continue;
//				}
//				else
//				{
//					pts.emplace_back(p1.X(), p1.Y(), p1.Z());
//					ii++;
//
//					u0 = u1;
//					du *= 2.0;
//					u1 = u0 + du;
//				}
//			}
//		}
//	}
//
//	if constexpr (Dim == 2)
//	{
//		auto p0Curve = my2dCurve->Value(1.0);
//		pts.emplace_back(p0Curve.X(), p0Curve.Y());
//	}
//	else if constexpr (Dim == 3)
//	{
//		auto p0Curve = my3dCurve->Value(1.0);
//		pts.emplace_back(p0Curve.X(), p0Curve.Y(), p0Curve.Z());
//	}
//
//	return std::move(pts);
//}

//template<int Dim>
//std::vector<ForgVisualLib::FrgVisual_PointActor<Dim>*> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::GetCtrlPts() const
//{
//	/*if (theCtrlPtsPolyLine_)
//	{
//		return theCtrlPtsPolyLine_->GetPts();
//	}
//	else if (theBSPLineCurve_)
//	{
//		std::vector<ForgVisualLib::FrgVisual_PointActor<Dim>*> ctrlPts;
//
//		if constexpr (Dim == 2)
//		{
//			auto curvePoles = dynamic_cast<Geom2d_BSplineCurve*>(theBSPLineCurve_)->Poles();
//			for (int i = 0; i < curvePoles.Size(); i++)
//			{
//				auto myPoint = std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(curvePoles(i + 1).X(), curvePoles(i + 1).Y());
//				ForgVisualLib::FrgVisual_PointActor<Dim>* myCtrlPoint = ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::New();
//				myCtrlPoint->SetData(myPoint);
//				ctrlPts.push_back(myCtrlPoint);
//			}
//		}
//		else if constexpr (Dim == 3)
//		{
//			auto curvePoles = dynamic_cast<Geom_BSplineCurve*>(theBSPLineCurve_)->Poles();
//			for (int i = 0; i < curvePoles.Size(); i++)
//			{
//				auto myPoint = std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(curvePoles(i + 1).X(), curvePoles(i + 1).Y(), curvePoles(i + 1).Z());
//				ForgVisualLib::FrgVisual_PointActor<Dim>* myCtrlPoint = ForgVisualLib::FrgVisual_CtrlPointActor<Dim>::New();
//				myCtrlPoint->SetData(myPoint);
//				ctrlPts.push_back(myCtrlPoint);
//			}
//		}
//
//		return std::move(ctrlPts);
//	}
//	else*/
//	return std::move(std::vector<ForgVisualLib::FrgVisual_PointActor<Dim>*>());
//}

template<int Dim>
std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::GetCtrlPts()
{
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts;
	if (!theCurve_)
		ctrlPts = FrgVisual_PolylineActor<Dim>::GetPoints();
	else
	{
		if constexpr (Dim == 2)
		{
			auto curvePoles = dynamic_cast<Geom2d_BSplineCurve*>(theCurve_)->Poles();
			for (int i = 0; i < curvePoles.Size(); i++)
				ctrlPts.push_back(ForgBaseLib::FrgBase_Pnt<Dim>(curvePoles(i + 1).X(), curvePoles(i + 1).Y()));
		}
		else if constexpr (Dim == 3)
		{
			auto curvePoles = dynamic_cast<Geom_BSplineCurve*>(theCurve_)->Poles();
			for (int i = 0; i < curvePoles.Size(); i++)
				ctrlPts.push_back(ForgBaseLib::FrgBase_Pnt<Dim>(curvePoles(i + 1).X(), curvePoles(i + 1).Y(), curvePoles(i + 1).Z()));
		}
	}

	return std::move(ctrlPts);
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

		/*if (!theCtrlPtsPolyLine_->IsIndependent())
			theRenderer_->AddActor(theCtrlPtsPolyLine_);*/
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_BSPLineActor<Dim>::SetSelectable(bool selectable)
{
	/*if (theCtrlPtsPolyLine_)
		theCtrlPtsPolyLine_->SetSelectable(selectable);*/

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

		for (int i = 0; i < theCtrlPts_.size(); i++)
			renderer->RemoveActor(theCtrlPts_[i]);
		theCtrlPts_.clear();
	}
}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::BSPLine);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Curve);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_BSPLineActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
std::vector<double> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalcBasisFunctionVector(std::vector<double> U, int i, int p, double u) const
{
	std::vector<double> N(p + 1);
	std::vector<double> left(p + 1);
	std::vector<double> right(p + 1);

	N[0] = 1.0;
	for (int j = 1; j <= p; j++)
	{
		left[j] = u - U[i + 1 - j];
		right[j] = U[i + j] - u;
		double saved = 0.0;
		for (int r = 0; r < j; r++)
		{
			double temp = N[r] / (right[r + 1] + left[j - r]);
			N[r] = saved + right[r + 1] * temp;
			saved = left[j - r] * temp;
		}
		N[j] = saved;
	}

	return N;
}

template<int Dim>
double ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalcBasisFunction(std::vector<double> U, int i, int p, double u) const
{
	int m = U.size() - 1;

	if ((i == 0 && u == U[0]) || (i == m - p - 1 && u == U[m]))
	{
		return 1;
	}

	if (u < U[i] || u >= U[i + p + 1])
	{
		return 0;
	}

	std::vector<double> N(p + 1);

	for (int j = 0; j <= p; j++)
		if (u >= U[i + j] && u < U[i + j + 1]) N[j] = 1;
		else
			N[j] = 0;

	double saved, temp;
	double Uleft, Uright;

	for (int k = 1; k <= p; k++)
	{
		if (N[0] == 0.) saved = 0;
		else
		{
			saved = ((u - U[i]) * N[0]) / (U[i + k] - U[i]);
		}

		for (int j = 0; j < p - k + 1; j++)
		{
			Uleft = U[i + j + 1];
			Uright = U[i + j + k + 1];

			if (N[j + 1] == 0)
			{
				N[j] = saved;
				saved = 0;
			}
			else
			{
				temp = N[j + 1] / (Uright - Uleft);
				N[j] = saved + (Uright - u) * temp;
				saved = (u - Uleft) * temp;
			}
		}
	}
	return N[0];

	/*int m = knots.size() - 1;

	if (p == 0)
	{
		if (u >= knots[i] && u < knots[i + 1])
			return 1.0;
		else
			return 0.0;
	}

	double A = (u - knots[i]) / (knots[i + p] - knots[i]);
	double B = (knots[i + p + 1] - u) / (knots[i + p + 1] - knots[i + 1]);

	std::cout <<"u = " << u << ", A = " << A << ", B = " << B << std::endl;
	system("pause");

	return A * CalcBasisFunction(knots, i, p - 1, u) + B * CalcBasisFunction(knots, i + 1, p - 1, u);*/
}

template<int Dim>
int ForgVisualLib::FrgVisual_BSPLineActor<Dim>::FindSpan(int n, int p, double u, std::vector<double> knots)
{
	if (u >= knots[n + 1])
		return n;

	int low = p;
	int high = n + 1;
	int mid = (low + high) / 2;
	while (u < knots[mid] || u >= knots[mid + 1])
	{
		if (u < knots[mid])
			high = mid;
		else
			low = mid;

		mid = (low + high) / 2.0;
	}
	return mid;
}

template<int Dim>
std::vector<double> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalcKnotBarEquallySpaced(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q)
{
	std::vector<double> knots;
	knots.push_back(0.0);

	int n = Q.size() - 1;

	for (int k = 1; k <= n - 1; k++)
		knots.push_back(static_cast<double>(k) / static_cast<double>(n));

	knots.push_back(1.0);

	return std::move(knots);
}

template<int Dim>
std::vector<double> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalcKnotBarChordLength(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q)
{
	std::vector<double> knots;
	knots.push_back(0.0);

	int n = Q.size() - 1;
	double d = 0.0;
	for (int k = 1; k <= n; k++)
		d += (Q[k] - (Q[k - 1])).TwoNorm();

	for (int k = 1; k <= n - 1; k++)
		knots.push_back(knots[k - 1] + ((Q[k] - (Q[k - 1])).TwoNorm() / d));

	knots.push_back(1.0);

	return std::move(knots);
}

template<int Dim>
std::vector<double> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalcKnotBarCentripetal(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q)
{
	std::vector<double> knots;
	knots.push_back(0.0);

	int n = Q.size() - 1;
	double d = 0.0;
	for (int k = 1; k <= n; k++)
		d += std::sqrt((Q[k] - (Q[k - 1])).TwoNorm());

	for (int k = 1; k <= n - 1; k++)
		knots.push_back(knots[k - 1] + (std::sqrt((Q[k] - (Q[k - 1])).TwoNorm()) / d));

	knots.push_back(1.0);

	return std::move(knots);
}

template<int Dim>
std::vector<double> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::CalcKnotVector(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q, std::vector<double> knotsBar, int degree)
{
	std::vector<double> knots;

	for (int i = 0; i <= degree; i++)
		knots.push_back(0.0);

	int n = Q.size() - 1;
	for (int j = 1; j <= n - degree; j++)
	{
		double A = 0.0;
		for (int i = j; i <= j + degree - 1; i++)
			A += knotsBar[i];
		knots.push_back(1.0 / (static_cast<double>(degree)) * A);
	}

	for (int i = 0; i <= degree; i++)
		knots.push_back(1.0);

	return std::move(knots);
}

template<int Dim>
std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ForgVisualLib::FrgVisual_BSPLineActor<Dim>::Interpolate(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> Q, int degree)
{
	auto knotsBar = CalcKnotBarCentripetal(Q);

	int n = Q.size() - 1;
	ForgBaseLib::FrgBase_FullMtx<double> A(n + 1, n + 1);
	ForgBaseLib::FrgBase_Vcr<double> rhsX(n + 1);
	ForgBaseLib::FrgBase_Vcr<double> rhsY(n + 1);
	ForgBaseLib::FrgBase_Vcr<double> rhsZ(n + 1);

	for (int i = 0; i < Q.size(); i++)
	{
		rhsX[i] = Q[i].X();
		rhsY[i] = Q[i].Y();

		if constexpr (Dim == 3)
			rhsZ[i] = Q[i].Z();
	}

	auto knots = CalcKnotVector(Q, knotsBar, degree);

	for (int i = 0; i <= n; i++)
	{
		int span = FindSpan(n, degree, knotsBar[i], knots);
		auto N = CalcBasisFunctionVector(knots, span, degree, knotsBar[i]);
		for (int j = 0; j <= degree; j++)
			A[i][j + span - degree] = N[j];
	}

	A[0][0] = 1.0;
	A[n][n] = 1.0;

	A.GaussElim(rhsX);
	A.GaussElim(rhsY);

	if constexpr (Dim == 3)
		A.GaussElim(rhsZ);

	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts;
	for (int i = 0; i < rhsX.size(); i++)
	{
		if constexpr (Dim == 2)
			ctrlPts.emplace_back(rhsX[i], rhsY[i]);
		else if constexpr (Dim == 3)
			ctrlPts.emplace_back(rhsX[i], rhsY[i], rhsZ[i]);
	}

	return std::move(ctrlPts);
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_BSPLineActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_PolylineActor<Dim>>(*this);

	/*ar& theDegree_;
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
	}*/
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_BSPLineActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_PolylineActor<Dim>>(*this);

	/*ar& theDegree_;
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
	}*/
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BSPLineActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BSPLineActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_BSPLineActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_BSPLineActor<3>;

template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_BSPLineActor<2>::AddNextPoint(double x, double y);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_BSPLineActor<2>::SetLastPoint(double x, double y);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_BSPLineActor<3>::AddNextPoint(double x, double y, double z);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_BSPLineActor<3>::SetLastPoint(double x, double y, double z);