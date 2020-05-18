#include <FrgVisual_BoxActor.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_BoxActor);

ForgVisualLib::FrgVisual_BoxActor::FrgVisual_BoxActor()
{

}

void ForgVisualLib::FrgVisual_BoxActor::SetRepresentationToPoints()
{
	this->GetProperty()->SetRepresentationToPoints();
}

void ForgVisualLib::FrgVisual_BoxActor::SetRepresentationToSurface()
{
	this->GetProperty()->SetRepresentationToSurface();
}

void ForgVisualLib::FrgVisual_BoxActor::SetRepresentationToWireframe()
{
	this->GetProperty()->SetRepresentationToWireframe();
	this->GetProperty()->EdgeVisibilityOn();
}

void ForgVisualLib::FrgVisual_BoxActor::SetColor(double red, double green, double blue)
{
	this->GetProperty()->SetColor(red, green, blue);
}

void ForgVisualLib::FrgVisual_BoxActor::SetEdgeColor(double red, double green, double blue)
{
	this->GetProperty()->SetInterpolationToFlat();
	this->GetProperty()->SetEdgeColor(red, green, blue);
	this->GetProperty()->SetLineWidth(2.0f);
	this->GetProperty()->SetAmbient(0.0);
	this->GetProperty()->SetSpecular(0.0);
}