#include <FrgVisual_RectangleActor.hxx>

#include <FrgBase_Pnt.hxx>

#include <vtkObjectFactory.h>
#include <vtkPolyLine.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkProperty.h>
#include <vtkPolyDataMapper.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_RectangleActor);

ForgVisualLib::FrgVisual_RectangleActor::FrgVisual_RectangleActor()
{

}

void ForgVisualLib::FrgVisual_RectangleActor::SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> P1)
{
	if (P0 == nullptr || P1 == nullptr)
		return;

	theP0_ = P0;
	theP1_ = P1;

	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();

	points->InsertNextPoint(theP0_->X(), theP0_->Y(), 0.0);
	points->InsertNextPoint(theP1_->X(), theP0_->Y(), 0.0);
	points->InsertNextPoint(theP1_->X(), theP1_->Y(), 0.0);
	points->InsertNextPoint(theP0_->X(), theP1_->Y(), 0.0);
	points->InsertNextPoint(theP0_->X(), theP0_->Y(), 0.0);

	vtkSmartPointer<vtkPolyLine> polyLine =
		vtkSmartPointer<vtkPolyLine>::New();
	polyLine->GetPointIds()->SetNumberOfIds(5);
	for (unsigned int i = 0; i < polyLine->GetPointIds()->GetNumberOfIds(); i++)
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

void ForgVisualLib::FrgVisual_RectangleActor::SetRepresentationToPoints()
{
	this->GetProperty()->SetRepresentationToPoints();
}

void ForgVisualLib::FrgVisual_RectangleActor::SetRepresentationToSurface()
{
	this->GetProperty()->SetRepresentationToSurface();
}

void ForgVisualLib::FrgVisual_RectangleActor::SetRepresentationToWireframe()
{
	this->GetProperty()->SetRepresentationToWireframe();
	this->GetProperty()->EdgeVisibilityOn();
}

void ForgVisualLib::FrgVisual_RectangleActor::SetEdgeColor(double red, double green, double blue)
{
	this->GetProperty()->SetInterpolationToFlat();
	this->GetProperty()->SetEdgeColor(red, green, blue);
	this->GetProperty()->SetLineWidth(2.0f);
	this->GetProperty()->SetAmbient(0.0);
	this->GetProperty()->SetSpecular(0.0);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_RectangleActor)
{
	ar& boost::serialization::base_object<FrgVisual_ConicActor<2>>(*this);

	ar& theP0_;
	ar& theP1_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_RectangleActor)
{
	ar& boost::serialization::base_object<FrgVisual_ConicActor<2>>(*this);

	ar& theP0_;
	ar& theP1_;

	SetData(theP0_, theP1_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_RectangleActor)