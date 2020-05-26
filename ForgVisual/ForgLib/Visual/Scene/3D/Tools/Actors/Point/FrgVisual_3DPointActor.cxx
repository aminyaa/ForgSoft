#include <FrgVisual_3DPointActor.hxx>

#include <FrgBase_Pnt3d.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_3DPointActor);

ForgVisualLib::FrgVisual_3DPointActor::FrgVisual_3DPointActor()
{
	GetProperty()->SetRepresentationToPoints();
	SetRenderPointsAsSpheres(true);
}

ForgVisualLib::FrgVisual_3DPointActor::~FrgVisual_3DPointActor()
{

}

double* ForgVisualLib::FrgVisual_3DPointActor::GetColor()
{
	return GetProperty()->GetColor();
}

void ForgVisualLib::FrgVisual_3DPointActor::SetSize(float size)
{
	GetProperty()->SetPointSize(size);
}

float ForgVisualLib::FrgVisual_3DPointActor::GetSize()
{
	return GetProperty()->GetPointSize();
}

void ForgVisualLib::FrgVisual_3DPointActor::SetRenderPointsAsSpheres(bool condition)
{
	GetProperty()->SetRenderPointsAsSpheres(condition);
}

void ForgVisualLib::FrgVisual_3DPointActor::SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> pt)
{
	if (pt == nullptr)
		return;

	theP_ = pt;

	// Create the geometry of a point (the coordinate)
	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();

	// Create the topology of the point (a vertex)
	vtkSmartPointer<vtkCellArray> vertices =
		vtkSmartPointer<vtkCellArray>::New();
	// We need an an array of point id's for InsertNextCell.
	vtkIdType pid[1];
	pid[0] = points->InsertNextPoint(pt->X(), pt->Y(), pt->Z());
	vertices->InsertNextCell(1, pid);

	// Create a polydata object
	vtkSmartPointer<vtkPolyData> point =
		vtkSmartPointer<vtkPolyData>::New();

	// Set the points and vertices we created as the geometry and topology of the polydata
	point->SetPoints(points);
	point->SetVerts(vertices);

	// Visualize
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(point);

	SetMapper(mapper);

}

void ForgVisualLib::FrgVisual_3DPointActor::SetData(double x, double y, double z)
{
	SetData(std::make_shared<ForgBaseLib::FrgBase_Pnt3d>(x, y, z));
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_3DPointActor)
{
	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_3DPointActor, ForgVisualLib::FrgVisual_3DBaseActor);

	ar & theP_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_3DPointActor)
{
	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_3DPointActor, ForgVisualLib::FrgVisual_3DBaseActor);

	ar & theP_;

	SetData(theP_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_3DPointActor)