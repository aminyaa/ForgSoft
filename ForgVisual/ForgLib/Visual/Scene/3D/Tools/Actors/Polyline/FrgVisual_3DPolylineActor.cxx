#include <FrgVisual_3DPolylineActor.hxx>

#include <FrgBase_Pnt3d.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>
#include <vtkPoints.h>
#include <vtkPolyLine.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_3DPolylineActor);

ForgVisualLib::FrgVisual_3DPolylineActor::FrgVisual_3DPolylineActor()
{

}

ForgVisualLib::FrgVisual_3DPolylineActor::~FrgVisual_3DPolylineActor()
{

}

void ForgVisualLib::FrgVisual_3DPolylineActor::SetData(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> pts)
{
	thePts_.clear();
	thePts_ = pts;

	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();

	for (int iPoint = 0; iPoint < pts.size(); iPoint++)
		points->InsertNextPoint(pts[iPoint]->X(), pts[iPoint]->Y(), pts[iPoint]->Z());

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
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(polyData);

	this->SetMapper(mapper);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_3DPolylineActor)
{
	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_3DPolylineActor, ForgVisualLib::FrgVisual_3DBaseActor);

	ar & thePts_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_3DPolylineActor)
{
	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_3DPolylineActor, ForgVisualLib::FrgVisual_3DBaseActor);

	ar & thePts_;

	SetData(thePts_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_3DPolylineActor)