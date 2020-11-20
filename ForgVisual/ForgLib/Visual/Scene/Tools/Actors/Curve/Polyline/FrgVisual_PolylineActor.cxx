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

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_PolylineActor<Dim>);

template<int Dim>
ForgVisualLib::FrgVisual_PolylineActor<Dim>::FrgVisual_PolylineActor()
{

}

template<int Dim>
ForgVisualLib::FrgVisual_PolylineActor<Dim>::~FrgVisual_PolylineActor()
{

}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> pts)
{
	std::vector<FrgVisual_PointActor<Dim>*> ptsActors;

	for (int i = 0; i < pts.size(); i++)
	{
		auto ptsActor = FrgVisual_PointActor<Dim>::New();
		ptsActor->VisibilityOff();
		ptsActor->SetData(pts[i]);
		ptsActor->SetIndependent(false);

		ptsActors.push_back(ptsActor);
	}

	SetData(ptsActors);
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetData(std::vector<FrgVisual_PointActor<Dim>*> ptsActors)
{
	if (thePts_.size() != 0)
	{
		if (theRenderer_)
		{
			for (auto x : thePts_)
				theRenderer_->RemoveActor(x);
		}

		thePts_.clear();
	}

	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();

	for (int iPoint = 0; iPoint < ptsActors.size(); iPoint++)
	{
		thePts_.push_back(ptsActors[iPoint]);

		if constexpr (Dim == 2)
			points->InsertNextPoint(ptsActors[iPoint]->GetData()->X(), ptsActors[iPoint]->GetData()->Y(), 0.0);
		else if constexpr (Dim == 3)
			points->InsertNextPoint(ptsActors[iPoint]->GetData()->X(), ptsActors[iPoint]->GetData()->Y(), ptsActors[iPoint]->GetData()->Z());
	}

	vtkSmartPointer<vtkPolyLine> polyLine =
		vtkSmartPointer<vtkPolyLine>::New();
	polyLine->GetPointIds()->SetNumberOfIds(ptsActors.size());
	for (unsigned int i = 0; i < ptsActors.size(); i++)
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
	vtkSmartPointer<vtkPolyDataMapper> mapper;
	if (!this->GetMapper())
		mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	else
		mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());

	mapper->SetInputData(polyData);

	if (!this->GetMapper())
		this->SetMapper(mapper);

	for (auto x : ptsActors)
	{
		if (!x->IsIndependent())
		{
			x->SetParentPolylineActor(this);

			if (theRenderer_)
				theRenderer_->AddActor(x);
		}
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::UpdateActor()
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		vtkSmartPointer<vtkPolyData> polyData = mapper->GetInput();
		if (polyData)
		{
			vtkSmartPointer<vtkPoints> points =
				vtkSmartPointer<vtkPoints>::New();

			for (int iPoint = 0; iPoint < thePts_.size(); iPoint++)
			{
				if constexpr (Dim == 2)
					points->InsertNextPoint(thePts_[iPoint]->GetData()->X(), thePts_[iPoint]->GetData()->Y(), 0.0);
				else if constexpr (Dim == 3)
				{
					points->InsertNextPoint(thePts_[iPoint]->GetData()->X(), thePts_[iPoint]->GetData()->Y(), thePts_[iPoint]->GetData()->Z());
				}

				thePts_[iPoint]->UpdateActor();
			}

			vtkSmartPointer<vtkPolyLine> polyLine =
				vtkSmartPointer<vtkPolyLine>::New();
			polyLine->GetPointIds()->SetNumberOfIds(thePts_.size());
			for (unsigned int i = 0; i < thePts_.size(); i++)
				polyLine->GetPointIds()->SetId(i, i);

			// Create a cell array to store the lines in and add the lines to it
			vtkSmartPointer<vtkCellArray> cells =
				vtkSmartPointer<vtkCellArray>::New();
			cells->InsertNextCell(polyLine);

			// Add the lines to the dataset
			polyData->SetPoints(points);
			polyData->SetLines(cells);

			mapper->Update();
		}
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetRenderer(vtkRenderer* renderer)
{
	if (!renderer)
		return;

	ForgVisualLib::FrgVisual_BaseActor_Entity::SetRenderer(renderer);

	if (thePts_.size() != 0)
	{
		for (auto x : thePts_)
		{
			if (!x->IsIndependent())
				theRenderer_->AddActor(x);
		}
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetParentBSPLineActor(FrgVisual_BSPLineActor<Dim>* parentBSPLineActor)
{
	theParentBSPLineActor_ = parentBSPLineActor;

	if (thePts_.size() != 0)
	{
		for (auto x : thePts_)
			x->SetParentPolylineActor(this);
	}
}

template<int Dim>
//template<typename>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::TranslateActor(double dx, double dy)
{
	for (auto x : thePts_)
	{
		x->blockSignals(true);
		x->TranslateActor(dx, dy);
		x->blockSignals(false);
	}

	emit DataChangedSignal();

	UpdateActor();
	//FrgVisual_CurveActor::TranslateActor(dx, dy);
}

template<int Dim>
//template<typename>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::TranslateActor(double dx, double dy, double dz)
{
	for (auto x : thePts_)
	{
		x->blockSignals(true);
		x->FrgVisual_PointActor<Dim>::TranslateActor(dx, dy, dz);
		x->blockSignals(false);
	}

	FrgVisual_CurveActor::TranslateActor(dx, dy, dz);
}

template<int Dim>
void ForgVisualLib::FrgVisual_PolylineActor<Dim>::SetSelectable(bool selectable)
{
	if(thePts_.size() != 0)
		for (auto x : thePts_)
			x->SetSelectable(selectable);

	FrgVisual_CurveActor<Dim>::SetSelectable(selectable);
}

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
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_PolylineActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_CurveActor<Dim>>(*this);

	ar& thePts_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_PolylineActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_CurveActor<Dim>>(*this);

	std::vector<FrgVisual_PointActor<Dim>*> pts;

	ar& pts;

	SetData(pts);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PolylineActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PolylineActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PolylineActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PolylineActor<3>;