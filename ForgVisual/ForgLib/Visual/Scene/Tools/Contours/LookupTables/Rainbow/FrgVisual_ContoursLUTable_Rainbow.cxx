#include <FrgVisual_ContoursLUTable_Rainbow.hxx>

#include <vtkObjectFactory.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_ContoursLUTable_Rainbow);

ForgVisualLib::FrgVisual_ContoursLUTable_Rainbow::FrgVisual_ContoursLUTable_Rainbow()
{
	this->SetHueRange(0.6667, 0.0);
	this->SetSaturationRange(1.0, 1.0);
	this->SetValueRange(1.0, 1.0);
	this->SetAlphaRange(1.0, 1.0);
	this->SetNumberOfColors(256);

	this->Build();
}