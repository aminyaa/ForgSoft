#include <FrgVisual_PointActor.hxx>

#include <vtkProperty.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_PointActor<Dim>);

template<int Dim>
ForgVisualLib::FrgVisual_PointActor<Dim>::FrgVisual_PointActor()
{

}

template<int Dim>
void ForgVisualLib::FrgVisual_PointActor<Dim>::SetSize(float size)
{
	GetProperty()->SetPointSize(size);
	theSize_ = size;
}

template<int Dim>
float ForgVisualLib::FrgVisual_PointActor<Dim>::GetSelectionSize() const
{
	return theSelectionSize_;
}

template<int Dim>
void ForgVisualLib::FrgVisual_PointActor<Dim>::SetSelectionSize(float size)
{
	theSelectionSize_ = size;
}

template<int Dim>
float ForgVisualLib::FrgVisual_PointActor<Dim>::GetSize() const
{
	return theSize_;
}

template<int Dim>
void ForgVisualLib::FrgVisual_PointActor<Dim>::SetRenderPointsAsSpheres(bool condition)
{
	GetProperty()->SetRenderPointsAsSpheres(condition);
	theRenderPointsAsSpheres_ = condition;
}

//template<int Dim>
//void ForgVisualLib::FrgVisual_PointActor<Dim>::TranslateActor(double dx, double dy)
//{
//	if constexpr (Dim == 2)
//		theP_->Translate(dx, dy);
//
//	FrgVisual_BaseActor<Dim>::TranslateActor(dx, dy);
//}

//template<int Dim>
//void ForgVisualLib::FrgVisual_PointActor<Dim>::TranslateActor(double dx, double dy, double dz)
//{
//	if constexpr (Dim == 3)
//		theP_->Translate(dx, dy, dz);
//
//	FrgVisual_BaseActor<Dim>::TranslateActor(dx, dy, dz);
//}

template<int Dim>
bool ForgVisualLib::FrgVisual_PointActor<Dim>::SelectActor(const QColor& color)
{
	if (!FrgVisual_BaseActor<Dim>::SelectActor(color))
		return false;

	GetProperty()->SetPointSize(theSelectionSize_);

	return true;
}

template<int Dim>
bool ForgVisualLib::FrgVisual_PointActor<Dim>::UnSelectActor()
{
	if (!FrgVisual_BaseActor<Dim>::UnSelectActor())
		return false;

	return true;
}

//template<int Dim>
//void ForgVisualLib::FrgVisual_PointActor<Dim>::SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> pt)
//{
//	if (pt == nullptr)
//		return;
//
//	if (theP_.get() != pt.get())
//		theP_ = pt;
//	else
//		return;
//
//	// Create the geometry of a point (the coordinate)
//	vtkSmartPointer<vtkPoints> points =
//		vtkSmartPointer<vtkPoints>::New();
//
//	// Create the topology of the point (a vertex)
//	vtkSmartPointer<vtkCellArray> vertices =
//		vtkSmartPointer<vtkCellArray>::New();
//	// We need an an array of point id's for InsertNextCell.
//	vtkIdType pid[1];
//	if constexpr (Dim == 2)
//		pid[0] = points->InsertNextPoint(pt->X(), pt->Y(), 0.0);
//	else if constexpr (Dim == 3)
//		pid[0] = points->InsertNextPoint(pt->X(), pt->Y(), pt->Z());
//	vertices->InsertNextCell(1, pid);
//
//	// Create a polydata object
//	vtkSmartPointer<vtkPolyData> point =
//		vtkSmartPointer<vtkPolyData>::New();
//
//	// Set the points and vertices we created as the geometry and topology of the polydata
//	point->SetPoints(points);
//	point->SetVerts(vertices);
//
//	vtkSmartPointer<vtkPolyDataMapper> mapper;
//	if (!this->GetMapper())
//		mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	else
//		mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
//
//	mapper->SetInputData(point);
//
//	SetMapper(mapper);
//}

//template<>
//template<>
//inline void ForgVisualLib::FrgVisual_PointActor<2>::SetData(double x, double y)
//{
//	SetData(std::make_shared<ForgBaseLib::FrgBase_Pnt<2>>(x, y));
//}

template<int Dim>
void ForgVisualLib::FrgVisual_PointActor<Dim>::SetData(ForgBaseLib::FrgBase_Pnt<Dim> pt)
{
	theP_ = pt;

	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		auto polyData = mapper->GetInput();
		if (polyData)
		{
			auto points = polyData->GetPoints();
			if (points)
			{
				if constexpr (Dim == 2)
					points->SetPoint(0, pt.X(), pt.Y(), 0.0);
				else if constexpr (Dim == 3)
					points->SetPoint(0, pt.X(), pt.Y(), pt.Z());

				points->Modified();
			}
		}
		mapper->Update();
	}
	else
	{
		// Create the geometry of a point (the coordinate)
		vtkSmartPointer<vtkPoints> points =
			vtkSmartPointer<vtkPoints>::New();

		// Create the topology of the point (a vertex)
		vtkSmartPointer<vtkCellArray> vertices =
			vtkSmartPointer<vtkCellArray>::New();
		// We need an an array of point id's for InsertNextCell.
		vtkIdType pid[1];
		if constexpr (Dim == 2)
			pid[0] = points->InsertNextPoint(pt.X(), pt.Y(), 0.0);
		else if constexpr (Dim == 3)
			pid[0] = points->InsertNextPoint(pt.X(), pt.Y(), pt.Z());
		vertices->InsertNextCell(1, pid);

		// Create a polydata object
		vtkSmartPointer<vtkPolyData> point =
			vtkSmartPointer<vtkPolyData>::New();

		// Set the points and vertices we created as the geometry and topology of the polydata
		point->SetPoints(points);
		point->SetVerts(vertices);

		vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
		mapper->SetInputData(point);
		SetMapper(mapper);
	}

	//theSize_ = GetProperty()->GetPointSize();
}

//template<int Dim>
//ForgBaseLib::FrgBase_Pnt<Dim> ForgVisualLib::FrgVisual_PointActor<Dim>::GetData()
//{
//	ForgBaseLib::FrgBase_Pnt<Dim> pt;
//	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
//	if (mapper)
//	{
//		auto polyData = mapper->GetInput();
//		if (polyData)
//		{
//			auto points = polyData->GetPoints();
//			if (points)
//			{
//				pt.X() = points->GetPoint(0)[0];
//				pt.Y() = points->GetPoint(0)[1];
//
//				if constexpr(Dim == 3)
//					pt.Z() = points->GetPoint(0)[2];
//			}
//		}
//	}
//	return std::move(pt);
//}

template<>
template<>
void ForgVisualLib::FrgVisual_PointActor<2>::SetData(double x, double y)
{
	SetData(ForgBaseLib::FrgBase_Pnt<2>(x, y));
}

template<>
template<>
inline void ForgVisualLib::FrgVisual_PointActor<3>::SetData(double x, double y, double z)
{
	SetData(ForgBaseLib::FrgBase_Pnt<3>(x, y, z));
}

//template<int Dim>
//void ForgVisualLib::FrgVisual_PointActor<Dim>::UpdateActor()
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
//			vtkIdType pid[1];
//
//			if constexpr (Dim == 2)
//				pid[0] = points->InsertNextPoint(theP_->X(), theP_->Y(), 0.0);
//			else if constexpr (Dim == 3)
//				pid[0] = points->InsertNextPoint(theP_->X(), theP_->Y(), theP_->Z());
//
//			// Create a cell array to store the lines in and add the lines to it
//			vtkSmartPointer<vtkCellArray> vertices =
//				vtkSmartPointer<vtkCellArray>::New();
//
//			vertices->InsertNextCell(1, pid);
//
//			// Add the lines to the dataset
//			polyData->SetPoints(points);
//			polyData->SetVerts(vertices);
//
//			mapper->Update();
//		}
//	}
//}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_PointActor<Dim>::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Point;
}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_PointActor<Dim>::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Point);

	return types;
}

template<int Dim>
ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_PointActor<Dim>::GetActorDimension() const
{
	if constexpr (Dim == 2)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
	if constexpr (Dim == 3)
		return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_PointActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);
	const auto& pt = GetData();

	ar& pt;
	ar& theSize_;
	ar& theSelectionSize_;
	ar& theRenderPointsAsSpheres_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_PointActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ForgBaseLib::FrgBase_Pnt<Dim> pt;
	ar& pt;

	SetData(pt);

	ar& theSize_;
	ar& theSelectionSize_;
	ar& theRenderPointsAsSpheres_;

	SetSize(theSize_);
	SetRenderPointsAsSpheres(theRenderPointsAsSpheres_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PointActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PointActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PointActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PointActor<3>;

template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PointActor<2>::SetData(double x, double y);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PointActor<3>::SetData(double x, double y, double z);