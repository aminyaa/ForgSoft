#include <FrgVisual_ContoursLUTable_BlackAndWhite.hxx>

#include <vtkObjectFactory.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_ContoursLUTable_BlackAndWhite);

ForgVisualLib::FrgVisual_ContoursLUTable_BlackAndWhite::FrgVisual_ContoursLUTable_BlackAndWhite()
{
	this->SetHueRange(0, 0);
	this->SetSaturationRange(0, 0);
	this->SetValueRange(0.2, 1.0);
	this->SetAlphaRange(1.0, 1.0);
	this->SetNumberOfColors(256);
	this->SetHueRange(0.0, 0.667);

	this->Build();
}