#include <FrgVisual_LineActor.hxx>

#include <FrgBase_Pnt.hxx>

#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkLine.h>
#include <vtkCellArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_LineActor<Dim>);

template<int Dim>
ForgVisualLib::FrgVisual_LineActor<Dim>::FrgVisual_LineActor()
{

}

//template<int Dim>
//void ForgVisualLib::FrgVisual_LineActor<Dim>::SetData
//(
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> P0,
//	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> P1
//)
//{
//	if (P0 == nullptr || P1 == nullptr)
//		return;
//
//	bool isNewCreated = false;
//
//	if (theP0_ == nullptr || theP1_ == nullptr)
//		isNewCreated = true;
//
//	if (!isNewCreated)
//		if (theP0_.get() != P0.get() || theP1_.get() != P1.get())
//			isNewCreated = true;
//
//	if (!isNewCreated)
//		return;
//
//	theP0_ = P0;
//	theP1_ = P1;
//	
//	vtkSmartPointer<vtkPolyData> linesPolyData =
//		vtkSmartPointer<vtkPolyData>::New();
//
//	vtkSmartPointer<vtkPoints> pts =
//		vtkSmartPointer<vtkPoints>::New();
//	
//	if constexpr (Dim == 2)
//	{
//		pts->InsertNextPoint(P0->X(), P0->Y(), 0.0);
//		pts->InsertNextPoint(P1->X(), P1->Y(), 0.0);
//	}
//	else if constexpr (Dim == 3)
//	{
//		pts->InsertNextPoint(P0->X(), P0->Y(), P0->Z());
//		pts->InsertNextPoint(P1->X(), P1->Y(), P1->Z());
//	}
//
//	linesPolyData->SetPoints(pts);
//
//
//	vtkSmartPointer<vtkLine> line =
//		vtkSmartPointer<vtkLine>::New();
//
//	line->GetPointIds()->SetId(0, 0);
//	line->GetPointIds()->SetId(1, 1);
//
//	vtkSmartPointer<vtkCellArray> lines =
//		vtkSmartPointer<vtkCellArray>::New();
//
//	lines->InsertNextCell(line);
//
//	linesPolyData->SetLines(lines);
//
//	vtkSmartPointer<vtkPolyDataMapper> mapper;
//	if (!this->GetMapper())
//		mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	else
//		mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
//
//	mapper->SetInputData(linesPolyData);
//
//	SetMapper(mapper);
//}

template<int Dim>
void ForgVisualLib::FrgVisual_LineActor<Dim>::SetData(ForgBaseLib::FrgBase_Pnt<Dim> P0, ForgBaseLib::FrgBase_Pnt<Dim> P1)
{
	FrgVisual_PolylineActor::SetData({ P0, P1 });
	/*vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				if constexpr (Dim == 2)
				{
					points->SetPoint(0, P0.X(), P0.Y(), 0.0);
					points->SetPoint(1, P1.X(), P1.Y(), 0.0);
				}
				else if constexpr (Dim == 3)
				{
					points->SetPoint(0, P0.X(), P0.Y(), P0.Z());
					points->SetPoint(1, P1.X(), P1.Y(), P1.Z());
				}

				points->Modified();
			}
		}
		mapper->Update();
	}
	else
	{
		vtkSmartPointer<vtkPolyData> linesPolyData =
			vtkSmartPointer<vtkPolyData>::New();

		vtkSmartPointer<vtkPoints> pts =
			vtkSmartPointer<vtkPoints>::New();

		if constexpr (Dim == 2)
		{
			pts->InsertNextPoint(P0.X(), P0.Y(), 0.0);
			pts->InsertNextPoint(P1.X(), P1.Y(), 0.0);
		}
		else if constexpr (Dim == 3)
		{
			pts->InsertNextPoint(P0.X(), P0.Y(), P0.Z());
			pts->InsertNextPoint(P1.X(), P1.Y(), P1.Z());
		}

		linesPolyData->SetPoints(pts);

		vtkSmartPointer<vtkLine> line =
			vtkSmartPointer<vtkLine>::New();

		line->GetPointIds()->SetId(0, 0);
		line->GetPointIds()->SetId(1, 1);

		vtkSmartPointer<vtkCellArray> lines =
			vtkSmartPointer<vtkCellArray>::New();

		lines->InsertNextCell(line);

		linesPolyData->SetLines(lines);

		vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

		mapper->SetInputData(linesPolyData);

		SetMapper(mapper);
	}*/
}

template<>
template<>
inline void ForgVisualLib::FrgVisual_LineActor<2>::SetData
(
	double P0_X,
	double P0_Y,
	double P1_X,
	double P1_Y
)
{
	FrgVisual_PolylineActor::SetData({ ForgBaseLib::FrgBase_Pnt<2>(P0_X, P0_Y), ForgBaseLib::FrgBase_Pnt<2>(P1_X, P1_Y) });
}

template<>
template<>
inline void ForgVisualLib::FrgVisual_LineActor<3>::SetData
(
	double P0_X,
	double P0_Y,
	double P0_Z,
	double P1_X,
	double P1_Y,
	double P1_Z
)
{
	FrgVisual_PolylineActor::SetData({ ForgBaseLib::FrgBase_Pnt<3>(P0_X, P0_Y, P0_Z), ForgBaseLib::FrgBase_Pnt<3>(P1_X, P1_Y, P1_Z) });
}

//template <int Dim>
//void ForgVisualLib::FrgVisual_LineActor<Dim>::UpdateActor()
//{
//	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
//	if (mapper)
//	{
//		vtkSmartPointer<vtkPolyData> linesPolyData = mapper->GetInput();
//		if (linesPolyData)
//		{
//			vtkSmartPointer<vtkPoints> pts =
//				vtkSmartPointer<vtkPoints>::New();
//
//			if constexpr (Dim == 2)
//			{
//				pts->InsertNextPoint(theP0_->X(), theP0_->Y(), 0.0);
//				pts->InsertNextPoint(theP1_->X(), theP1_->Y(), 0.0);
//			}
//			else if constexpr (Dim == 3)
//			{
//				pts->InsertNextPoint(theP0_->X(), theP0_->Y(), theP0_->Z());
//				pts->InsertNextPoint(theP1_->X(), theP1_->Y(), theP1_->Z());
//			}
//
//			vtkSmartPointer<vtkLine> line =
//				vtkSmartPointer<vtkLine>::New();
//
//			line->GetPointIds()->SetId(0, 0);
//			line->GetPointIds()->SetId(1, 1);
//
//			vtkSmartPointer<vtkCellArray> lines =
//				vtkSmartPointer<vtkCellArray>::New();
//
//			lines->InsertNextCell(line);
//			linesPolyData->SetLines(lines);
//
//			mapper->Update();
//		}
//	}
//}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_LineActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Line);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Curve);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_LineActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_LineActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_PolylineActor<Dim>>(*this);
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_LineActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_PolylineActor<Dim>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_LineActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_LineActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_LineActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_LineActor<3>;

template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_LineActor<2>::SetData(double P0_X, double P0_Y, double P1_X, double P1_Y);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_LineActor<3>::SetData(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z);