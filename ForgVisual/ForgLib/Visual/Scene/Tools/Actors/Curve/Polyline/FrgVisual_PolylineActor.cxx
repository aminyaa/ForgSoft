#include <FrgVisual_PolylineActor.hxx>

#include <FrgVisual_PointActor.hxx>
#include <FrgBase_Pnt.hxx>

#include <vtkProperty.h>
#include <vtkPoints.h>
#include <vtkPolyLine.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>

#include <GCE2d_MakeSegment.hxx>
#include <GC_MakeSegment.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_PolylineActor<Dim>);

template<int Dim>
ForgVisualLib::FrgVisual_PolylineActor<Dim>::FrgVisual_PolylineActor()
{

}

//template<int Dim>
//void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> pts)
//{
//	std::vector<FrgVisual_PointActor<Dim>*> ptsActors;
//
//	for (int i = 0; i < pts.size(); i++)
//	{
//		auto ptsActor = FrgVisual_PointActor<Dim>::New();
//		ptsActor->VisibilityOff();
//		ptsActor->SetData(pts[i]);
//		ptsActor->SetIndependent(false);
//
//		ptsActors.push_back(ptsActor);
//	}
//
//	SetData(ptsActors);
//}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetData(std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts)
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				int nbCurrentPoints = points->GetNumberOfPoints();

				if (nbCurrentPoints != pts.size())
				{
					points->SetNumberOfPoints(pts.size());
				}

				for (vtkIdType i = 0; i < pts.size(); i++)
				{
					if constexpr (Dim == 2)
						points->SetPoint(i, pts[i].X(), pts[i].Y(), 0.0);
					else if constexpr (Dim == 3)
						points->SetPoint(i, pts[i].X(), pts[i].Y(), pts[i].Z());
				}

				points->Squeeze();
				points->Modified();

				UpdateIdListUsingPoints(polyData);
			}
		}
		mapper->Update();
	}
	else
	{
		vtkSmartPointer<vtkPoints> points =
			vtkSmartPointer<vtkPoints>::New();

		for (int iPoint = 0; iPoint < pts.size(); iPoint++)
		{
			if constexpr (Dim == 2)
				points->InsertNextPoint(pts[iPoint].X(), pts[iPoint].Y(), 0.0);
			else if constexpr (Dim == 3)
				points->InsertNextPoint(pts[iPoint].X(), pts[iPoint].Y(), pts[iPoint].Z());
		}

		vtkSmartPointer<vtkPolyLine> polyLine =
			vtkSmartPointer<vtkPolyLine>::New();
		polyLine->GetPointIds()->SetNumberOfIds(pts.size());
		for (unsigned int i = 0; i < pts.size(); i++)
			polyLine->GetPointIds()->SetId(i, i);

		// Create a cell array to store the lines in and add the lines to it
		vtkSmartPointer<vtkCellArray> cells =
			vtkSmartPointer<vtkCellArray>::New();
		cells->InsertNextCell(polyLine);

		// Create a polydata to store everything in
		vtkSmartPointer<vtkPolyData> polyData =
			vtkSmartPointer<vtkPolyData>::New();

		// Add the points to the dataset
		polyData->SetPoints(points);

		// Add the lines to the dataset
		polyData->SetLines(cells);

		// Setup actor and mapper
		vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

		mapper->SetInputData(polyData);

		this->SetMapper(mapper);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::AddNextPoint(ForgBaseLib::FrgBase_Pnt<Dim> pt)
{
	if constexpr (Dim == 2)
		AddNextPoint(pt.X(), pt.Y());
	else if constexpr (Dim == 3)
		AddNextPoint(pt.X(), pt.Y(), pt.Z());
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetLastPoint(ForgBaseLib::FrgBase_Pnt<Dim> pt)
{
	if constexpr (Dim == 2)
		SetLastPoint(pt.X(), pt.Y());
	else if constexpr (Dim == 3)
		SetLastPoint(pt.X(), pt.Y(), pt.Z());
}

template<>
template<>
void ForgVisualLib::FrgVisual_PolylineActor<2>::AddNextPoint(double x, double y)
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				points->InsertNextPoint(x, y, 0.0);
				points->Modified();
			}

			AddNextIdIntoCell(polyData);
		}
	}
	else
		SetData({ ForgBaseLib::FrgBase_Pnt<2>(x, y) });
}

template<>
template<>
void ForgVisualLib::FrgVisual_PolylineActor<2>::SetLastPoint(double x, double y)
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				if (points->GetNumberOfPoints() < 1)
					return;

				points->SetPoint(points->GetNumberOfPoints() - 1, x, y, 0.0);
				points->Modified();
			}
		}
	}
}

template<>
template<>
void ForgVisualLib::FrgVisual_PolylineActor<3>::AddNextPoint(double x, double y, double z)
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				points->InsertNextPoint(x, y, z);
				points->Modified();
			}

			AddNextIdIntoCell(polyData);
		}
	}
	else
		SetData({ ForgBaseLib::FrgBase_Pnt<3>(x, y, z) });
}

template<>
template<>
void ForgVisualLib::FrgVisual_PolylineActor<3>::SetLastPoint(double x, double y, double z)
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				if (points->GetNumberOfPoints() < 1)
					return;

				points->SetPoint(points->GetNumberOfPoints() - 1, x, y, z);
				points->Modified();
			}
		}
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::RemoveLastPoint()
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				if (points->GetNumberOfPoints() < 1)
					return;

				points->Resize(points->GetNumberOfPoints() - 1);
				points->Squeeze();
				points->Modified();

				UpdateIdListUsingPoints(polyData);
			}
		}
	}
}

template<int Dim>
long long ForgVisualLib::FrgVisual_PolylineActor<Dim>::GetNumberOfPoints()
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				return points->GetNumberOfPoints();
			}
		}
	}

	return 0;
}

template<int Dim>
std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ForgVisualLib::FrgVisual_PolylineActor<Dim>::GetPoints()
{
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts;

	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				for (int i = 0; i < points->GetNumberOfPoints(); i++)
				{
					auto pt = points->GetPoint(i);

					if constexpr (Dim == 2)
						pts.emplace_back(pt[0], pt[1]);
					if constexpr (Dim == 3)
						pts.emplace_back(pt[0], pt[1], pt[2]);
				}
			}
		}
	}

	return std::move(pts);
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim> ForgVisualLib::FrgVisual_PolylineActor<Dim>::GetPoint(long long i)
{
	ForgBaseLib::FrgBase_Pnt<Dim> pt;
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				pt.X() = points->GetPoint(i)[0];
				pt.Y() = points->GetPoint(i)[1];

				if constexpr (Dim == 3)
					pt.Z() = points->GetPoint(i)[2];
			}
		}
	}

	return pt;
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetPoint(long long i, ForgBaseLib::FrgBase_Pnt<Dim> pt)
{
	if constexpr (Dim == 2)
		SetPoint(i, pt.X(), pt.Y());
	else if constexpr (Dim == 2)
		SetPoint(i, pt.X(), pt.Y(), pt.Z());
}

template<>
template<>
void ForgVisualLib::FrgVisual_PolylineActor<2>::SetPoint(long long i, double x, double y)
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				if (points->GetNumberOfPoints() == 0)
					return;

				points->SetPoint(i, x, y, 0.0);
				points->Modified();
			}
		}
	}
}

template<>
template<>
void ForgVisualLib::FrgVisual_PolylineActor<3>::SetPoint(long long i, double x, double y, double z)
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				if (points->GetNumberOfPoints() == 0)
					return;

				points->SetPoint(i, x, y, z);
				points->Modified();
			}
		}
	}
}

template<int Dim>
bool ForgVisualLib::FrgVisual_PolylineActor<Dim>::SelectActor(const QColor& color)
{
	FrgVisual_CurveActor<Dim>::SelectActor(color);

	ShowPoints(true);

	return true;
}

template<int Dim>
bool ForgVisualLib::FrgVisual_PolylineActor<Dim>::UnSelectActor()
{
	ShowPoints(false);

	return FrgVisual_CurveActor<Dim>::UnSelectActor();
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::ShowPoints(bool condition)
{
	if (theRenderer_)
	{
		for (int i = 0; i < thePts_.size(); i++)
			theRenderer_->RemoveActor(thePts_[i]);
		thePts_.clear();
	}

	if (condition)
	{
		vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
		if (mapper)
		{
			auto polyData = mapper->GetInput();
			if (polyData)
			{
				auto points = polyData->GetPoints();
				if (points)
				{
					int nFor;
					if (this->IsSelected())
						nFor = GetNumberOfPoints();
					else
						nFor = GetNumberOfPoints() - 1;

					for (int i = 0; i < nFor; i++)
					{
						vtkSmartPointer<FrgVisual_PointActor<Dim>> actor =
							vtkSmartPointer<FrgVisual_PointActor<Dim>>::New();
						actor->SetRenderer(theRenderer_);
						actor->SetRenderPointsAsSpheres(true);
						actor->SetColor(0.0, 1.0, 0.0);
						actor->SetSize(8);
						thePts_.push_back(actor);

						double pt[3];
						points->GetPoint(i, pt);

						if constexpr (Dim == 2)
							actor->SetData(pt[0], pt[1]);
						else if constexpr (Dim == 3)
							actor->SetData(pt[0], pt[1], pt[2]);

						if(theRenderer_)
							theRenderer_->AddActor(actor);
					}
				}
			}
		}
	}
}

//template<int Dim>
//void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetData(std::vector<FrgVisual_PointActor<Dim>*> ptsActors)
//{
//	if (thePts_.size() != 0)
//	{
//		if (theRenderer_)
//		{
//			for (auto x : thePts_)
//				theRenderer_->RemoveActor(x);
//		}
//
//		thePts_.clear();
//	}
//
//	vtkSmartPointer<vtkPoints> points =
//		vtkSmartPointer<vtkPoints>::New();
//
//	for (int iPoint = 0; iPoint < ptsActors.size(); iPoint++)
//	{
//		thePts_.push_back(ptsActors[iPoint]);
//
//		if constexpr (Dim == 2)
//			points->InsertNextPoint(ptsActors[iPoint]->GetData()->X(), ptsActors[iPoint]->GetData()->Y(), 0.0);
//		else if constexpr (Dim == 3)
//			points->InsertNextPoint(ptsActors[iPoint]->GetData()->X(), ptsActors[iPoint]->GetData()->Y(), ptsActors[iPoint]->GetData()->Z());
//	}
//
//	vtkSmartPointer<vtkPolyLine> polyLine =
//		vtkSmartPointer<vtkPolyLine>::New();
//	polyLine->GetPointIds()->SetNumberOfIds(ptsActors.size());
//	for (unsigned int i = 0; i < ptsActors.size(); i++)
//		polyLine->GetPointIds()->SetId(i, i);
//
//	// Create a cell array to store the lines in and add the lines to it
//	vtkSmartPointer<vtkCellArray> cells =
//		vtkSmartPointer<vtkCellArray>::New();
//	cells->InsertNextCell(polyLine);
//
//	// Create a polydata to store everything in
//	vtkSmartPointer<vtkPolyData> polyData =
//		vtkSmartPointer<vtkPolyData>::New();
//
//	// Add the points to the dataset
//	polyData->SetPoints(points);
//
//	// Add the lines to the dataset
//	polyData->SetLines(cells);
//
//	// Setup actor and mapper
//	vtkSmartPointer<vtkPolyDataMapper> mapper;
//	if (!this->GetMapper())
//		mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	else
//		mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
//
//	mapper->SetInputData(polyData);
//
//	if (!this->GetMapper())
//		this->SetMapper(mapper);
//
//	for (auto x : ptsActors)
//	{
//		if (!x->IsIndependent())
//		{
//			x->SetParentPolylineActor(this);
//
//			if (theRenderer_)
//				theRenderer_->AddActor(x);
//		}
//	}
//}

//template<int Dim>
//void ForgVisualLib::FrgVisual_PolylineActor<Dim>::UpdateActor()
//{
//	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
//	if (mapper)
//	{
//		vtkSmartPointer<vtkPolyData> polyData = mapper->GetInput();
//		if (polyData)
//		{
//			vtkSmartPointer<vtkPoints> points =
//				vtkSmartPointer<vtkPoints>::New();
//
//			for (int iPoint = 0; iPoint < thePts_.size(); iPoint++)
//			{
//				if constexpr (Dim == 2)
//					points->InsertNextPoint(thePts_[iPoint]->GetData()->X(), thePts_[iPoint]->GetData()->Y(), 0.0);
//				else if constexpr (Dim == 3)
//				{
//					points->InsertNextPoint(thePts_[iPoint]->GetData()->X(), thePts_[iPoint]->GetData()->Y(), thePts_[iPoint]->GetData()->Z());
//				}
//
//				thePts_[iPoint]->UpdateActor();
//			}
//
//			vtkSmartPointer<vtkPolyLine> polyLine =
//				vtkSmartPointer<vtkPolyLine>::New();
//			polyLine->GetPointIds()->SetNumberOfIds(thePts_.size());
//			for (unsigned int i = 0; i < thePts_.size(); i++)
//				polyLine->GetPointIds()->SetId(i, i);
//
//			// Create a cell array to store the lines in and add the lines to it
//			vtkSmartPointer<vtkCellArray> cells =
//				vtkSmartPointer<vtkCellArray>::New();
//			cells->InsertNextCell(polyLine);
//
//			// Add the lines to the dataset
//			polyData->SetPoints(points);
//			polyData->SetLines(cells);
//
//			mapper->Update();
//		}
//	}
//}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetRenderer(vtkRenderer* renderer)
{
	if (!renderer)
		return;

	ForgVisualLib::FrgVisual_BaseActor_Entity::SetRenderer(renderer);

	/*if (thePts_.size() != 0)
	{
		for (auto x : thePts_)
		{
			if (!x->IsIndependent())
				theRenderer_->AddActor(x);
		}
	}*/
}

//template<int Dim>
//void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetParentBSPLineActor(FrgVisual_BSPLineActor<Dim>* parentBSPLineActor)
//{
//	theParentBSPLineActor_ = parentBSPLineActor;
//
//	if (thePts_.size() != 0)
//	{
//		for (auto x : thePts_)
//			x->SetParentPolylineActor(this);
//	}
//}

//template<int Dim>
////template<typename>
//void ForgVisualLib::FrgVisual_PolylineActor<Dim>::TranslateActor(double dx, double dy)
//{
//	for (auto x : thePts_)
//	{
//		x->blockSignals(true);
//		x->TranslateActor(dx, dy);
//		x->blockSignals(false);
//	}
//
//	emit DataChangedSignal();
//
//	UpdateActor();
//	//FrgVisual_CurveActor::TranslateActor(dx, dy);
//}

//template<int Dim>
////template<typename>
//void ForgVisualLib::FrgVisual_PolylineActor<Dim>::TranslateActor(double dx, double dy, double dz)
//{
//	for (auto x : thePts_)
//	{
//		x->blockSignals(true);
//		x->FrgVisual_PointActor<Dim>::TranslateActor(dx, dy, dz);
//		x->blockSignals(false);
//	}
//
//	FrgVisual_CurveActor::TranslateActor(dx, dy, dz);
//}

//template<int Dim>
//void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetSelectable(bool selectable)
//{
//	if(thePts_.size() != 0)
//		for (auto x : thePts_)
//			x->SetSelectable(selectable);
//
//	FrgVisual_CurveActor<Dim>::SetSelectable(selectable);
//}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::RemoveActors(vtkRenderer* renderer)
{
	if (thePts_.size() == 0)
		return;

	if (renderer)
	{
		for (auto pt : thePts_)
		{
			pt->RemoveActors(renderer);
			renderer->RemoveActor(pt);
		}
	}
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_PolylineActor<Dim>::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::PolyLine;
}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_PolylineActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::PolyLine);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Curve);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_PolylineActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
std::vector<opencascade::handle<Standard_Transient>> ForgVisualLib::FrgVisual_PolylineActor<Dim>::GetCurves()
{
	std::vector<opencascade::handle<Standard_Transient>> curves;
	auto pts = GetPoints();
	for (int i = 0; i < pts.size() - 1; i++)
	{
		if constexpr (Dim == 2)
		{
			GCE2d_MakeSegment maker(gp_Pnt2d(pts[i].X(), pts[i].Y()), gp_Pnt2d(pts[i + 1].X(), pts[i + 1].Y()));
			if (maker.IsDone())
				curves.push_back(maker.Value());
		}
		else if constexpr (Dim == 3)
		{
			GC_MakeSegment maker(gp_Pnt(pts[i].X(), pts[i].Y(), pts[i].Z()), gp_Pnt(pts[i + 1].X(), pts[i + 1].Y(), pts[i + 1].Z()));
			if (maker.IsDone())
				curves.push_back(maker.Value());
		}
	}

	return std::move(curves);
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::UpdateActor()
{
	if (theCurve_)
	{
		auto pts = DiscreteCurve(theCurve_, 3.0);
		if (pts.empty())
			return;

		SetData(pts);
	}
}

template <int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::AddNextIdIntoCell(vtkPolyData* polyData)
{
	if (polyData)
	{
		auto cells = polyData->GetLines();
		if (cells)
		{
			auto nb = cells->GetData()->GetNumberOfValues();
			cells->GetData()->SetNumberOfValues(nb + 1);
			
			cells->GetData()->SetValue(0, nb);
			cells->GetData()->SetValue(nb, nb - 1);

			cells->Modified();
		}
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::UpdateIdListUsingPoints(vtkPolyData* polyData)
{
	if (polyData)
	{
		auto cells = polyData->GetLines();
		if (cells)
		{
			auto nb = polyData->GetNumberOfPoints();
			cells->GetData()->SetNumberOfValues(nb + 1);

			cells->GetData()->SetValue(0, nb);
			for (vtkIdType i = 1; i <= nb; i++)
				cells->GetData()->SetValue(i, i - 1);

			/*std::cout << "=========== Nb Points = " << nb << std::endl;
			for (vtkIdType i = 0; i < cells->GetData()->GetNumberOfValues(); i++)
				std::cout << "i = " << cells->GetData()->GetValue(i) << std::endl;
			system("pause");*/

			cells->Squeeze();
			cells->Modified();
		}
	}
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_PolylineActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_CurveActor<Dim>>(*this);

	//ar& thePts_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_PolylineActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_CurveActor<Dim>>(*this);

	//std::vector<FrgVisual_PointActor<Dim>*> pts;

	//ar& pts;

	//SetData(pts);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PolylineActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PolylineActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PolylineActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PolylineActor<3>;

template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PolylineActor<2>::AddNextPoint(double x, double y);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PolylineActor<2>::SetLastPoint(double x, double y);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PolylineActor<3>::AddNextPoint(double x, double y, double z);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PolylineActor<3>::SetLastPoint(double x, double y, double z);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PolylineActor<2>::SetPoint(long long i, double x, double y);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PolylineActor<3>::SetPoint(long long i, double x, double y, double z);