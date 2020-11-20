#include <FrgVisual_ContoursLUTable_InverseRainbow.hxx>

#include <vtkObjectFactory.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_ContoursLUTable_InverseRainbow);

ForgVisualLib::FrgVisual_ContoursLUTable_InverseRainbow::FrgVisual_ContoursLUTable_InverseRainbow()
{
	this->SetHueRange(0.0, 0.6667);
	this->SetSaturationRange(1.0, 1.0);
	this->SetValueRange(1.0, 1.0);
	this->SetAlphaRange(1.0, 1.0);
	this->SetNumberOfColors(256);

	this->Build();
}