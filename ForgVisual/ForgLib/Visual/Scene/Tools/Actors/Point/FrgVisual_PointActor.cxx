#include <FrgVisual_PointActor.hxx>

#include <FrgBase_Pnt.hxx>

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
}

template<int Dim>
float ForgVisualLib::FrgVisual_PointActor<Dim>::GetSize()
{
	return GetProperty()->GetPointSize();
}

template<int Dim>
void ForgVisualLib::FrgVisual_PointActor<Dim>::SetRenderPointsAsSpheres(bool condition)
{
	GetProperty()->SetRenderPointsAsSpheres(condition);
}

template<int Dim>
void ForgVisualLib::FrgVisual_PointActor<Dim>::TranslateActor(double dx, double dy)
{
	if constexpr (Dim == 2)
		theP_->Translate(dx, dy);

	FrgVisual_BaseActor<Dim>::TranslateActor(dx, dy);
}

template<int Dim>
void ForgVisualLib::FrgVisual_PointActor<Dim>::TranslateActor(double dx, double dy, double dz)
{
	if constexpr (Dim == 3)
		theP_->Translate(dx, dy, dz);

	FrgVisual_BaseActor<Dim>::TranslateActor(dx, dy, dz);
}

template<int Dim>
bool ForgVisualLib::FrgVisual_PointActor<Dim>::SelectActor(const QColor& color)
{
	if (!FrgVisual_BaseActor<Dim>::SelectActor(color))
		return false;

	SetSize(GetSize() * 2);

	return true;
}

template<int Dim>
void ForgVisualLib::FrgVisual_PointActor<Dim>::SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> pt)
{
	if (pt == nullptr)
		return;

	if (theP_.get() != pt.get())
		theP_ = pt;
	else
		return;

	// Create the geometry of a point (the coordinate)
	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();

	// Create the topology of the point (a vertex)
	vtkSmartPointer<vtkCellArray> vertices =
		vtkSmartPointer<vtkCellArray>::New();
	// We need an an array of point id's for InsertNextCell.
	vtkIdType pid[1];
	if constexpr (Dim == 2)
		pid[0] = points->InsertNextPoint(pt->X(), pt->Y(), 0.0);
	else if constexpr (Dim == 3)
		pid[0] = points->InsertNextPoint(pt->X(), pt->Y(), pt->Z());
	vertices->InsertNextCell(1, pid);

	// Create a polydata object
	vtkSmartPointer<vtkPolyData> point =
		vtkSmartPointer<vtkPolyData>::New();

	// Set the points and vertices we created as the geometry and topology of the polydata
	point->SetPoints(points);
	point->SetVerts(vertices);

	vtkSmartPointer<vtkPolyDataMapper> mapper;
	if (!this->GetMapper())
		mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	else
		mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());

	mapper->SetInputData(point);

	SetMapper(mapper);
}

template<>
template<>
inline void ForgVisualLib::FrgVisual_PointActor<2>::SetData(double x, double y)
{
	SetData(std::make_shared<ForgBaseLib::FrgBase_Pnt<2>>(x, y));
}

template<>
template<>
inline void ForgVisualLib::FrgVisual_PointActor<3>::SetData(double x, double y, double z)
{
	SetData(std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(x, y, z));
}

template<int Dim>
void ForgVisualLib::FrgVisual_PointActor<Dim>::UpdateActor()
{
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkPolyDataMapper::SafeDownCast(this->GetMapper());
	if (mapper)
	{
		vtkSmartPointer<vtkPolyData> polyData = mapper->GetInput();
		if (polyData)
		{
			vtkSmartPointer<vtkPoints> points =
				vtkSmartPointer<vtkPoints>::New();

			vtkIdType pid[1];

			if constexpr (Dim == 2)
				pid[0] = points->InsertNextPoint(theP_->X(), theP_->Y(), 0.0);
			else if constexpr (Dim == 3)
				pid[0] = points->InsertNextPoint(theP_->X(), theP_->Y(), theP_->Z());

			// Create a cell array to store the lines in and add the lines to it
			vtkSmartPointer<vtkCellArray> vertices =
				vtkSmartPointer<vtkCellArray>::New();

			vertices->InsertNextCell(1, pid);

			// Add the lines to the dataset
			polyData->SetPoints(points);
			polyData->SetVerts(vertices);

			mapper->Update();
		}
	}
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_PointActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	ar& theP_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_PointActor<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<Dim>>(*this);

	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> pt;
	ar& pt;

	SetData(pt);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PointActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_PointActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PointActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_PointActor<3>;

template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PointActor<2>::SetData(double x, double y);
template FORGVISUAL_EXPORT void ForgVisualLib::FrgVisual_PointActor<3>::SetData(double x, double y, double z);