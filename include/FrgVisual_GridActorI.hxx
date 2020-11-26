#pragma once
#ifndef _FrgVisual_GridActorI_Header
#define _FrgVisual_GridActorI_Header

#include <vtkProperty.h>
#include <vtkDoubleArray.h>
#include <vtkRectilinearGrid.h>
#include <vtkDataSetMapper.h>

#include <vtkObjectFactory.h>

template<int Dim>
vtkStandardNewMacro(ForgVisualLib::FrgVisual_GridActor<Dim>);

template<int Dim>
inline ForgVisualLib::FrgVisual_GridActor<Dim>::FrgVisual_GridActor()
	: theNumberOfDivisions1_(8)
	, theNumberOfDivisions2_(8)
{

}

template<int Dim>
inline void ForgVisualLib::FrgVisual_GridActor<Dim>::SetData
(
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> P0,
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> P1,
	int numberOfDivisions1,
	int numberOfDivisions2,
	bool principleLines
)
{
	if (P0 == nullptr || P1 == nullptr)
		return;

	if (numberOfDivisions1 == 0 || numberOfDivisions2 == 0)
	{
		std::exception myException("You cannot enter 0 for number of the division to create a grid.");
		throw myException;
	}

	theNumberOfDivisions1_ = numberOfDivisions1;
	theNumberOfDivisions2_ = numberOfDivisions2;

	theP0_ = P0;
	theP1_ = P1;

	theL1_ = L1;
	theL2_ = L2;

	double d1 = 2.0 * L1 / (double)theNumberOfDivisions1_;
	double d2 = 2.0 * L2 / (double)theNumberOfDivisions2_;

	vtkSmartPointer<vtkDoubleArray> xCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	vtkSmartPointer<vtkDoubleArray> yCoords =
		vtkSmartPointer<vtkDoubleArray>::New();
	vtkSmartPointer<vtkDoubleArray> zCoords =
		vtkSmartPointer<vtkDoubleArray>::New();

	for (int i = 0; i <= theNumberOfDivisions1_; i++)
		xCoords->InsertNextValue(i * d1 - L1);

	for (int i = 0; i <= theNumberOfDivisions2_; i++)
		yCoords->InsertNextValue(i * d2 - L2);

	zCoords->InsertNextValue(0.0);

	vtkSmartPointer<vtkRectilinearGrid> rgrid =
		vtkSmartPointer<vtkRectilinearGrid>::New();

	rgrid->SetDimensions(theNumberOfDivisions1_ + 1, theNumberOfDivisions2_ + 1, 1);
	rgrid->SetXCoordinates(xCoords);
	rgrid->SetYCoordinates(yCoords);
	rgrid->SetZCoordinates(zCoords);

	vtkSmartPointer<vtkDataSetMapper> rgridMapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	rgridMapper->SetInputData(rgrid);

	this->SetMapper(rgridMapper);
	this->GetProperty()->SetRepresentationToWireframe();

	double myOpacity = 0.3;

	this->GetProperty()->EdgeVisibilityOn();
	this->GetProperty()->SetAmbient(0.0);
	this->GetProperty()->SetSpecular(0.0);
	this->GetProperty()->SetSpecularPower(20.0);
	this->GetProperty()->SetOpacity(myOpacity);
	this->GetProperty()->ShadingOn();
	this->SetSelectable(false);

	if (XYLines)
	{
		FreePointer(theXLine_);
		FreePointer(theYLine_);

		theXLine_ = new FrgVisual_2DLineActor();
		theYLine_ = new FrgVisual_2DLineActor();

		theXLine_->SetData(theCenter_->X(), theCenter_->Y(), theCenter_->X() + theL1_, theCenter_->Y());
		theXLine_->SetColor(1.0, 0.0, 0.0);

		theYLine_->SetData(theCenter_->X(), theCenter_->Y(), theCenter_->X(), theCenter_->Y() + theL2_);
		theYLine_->SetColor(0.0, 1.0, 0.0);

		theXLine_->GetProperty()->SetLineWidth(3.0f);
		theXLine_->GetProperty()->SetAmbient(0.0);
		theXLine_->GetProperty()->SetSpecular(0.0);
		theXLine_->GetProperty()->SetSpecular(20.0);
		theXLine_->GetProperty()->SetOpacity(myOpacity);
		theXLine_->GetProperty()->ShadingOn();
		theXLine_->SetSelectable(false);
		theXLine_->SetRenderLinesAsTubes(true);

		theYLine_->GetProperty()->SetLineWidth(3.0f);
		theYLine_->GetProperty()->SetAmbient(0.0);
		theYLine_->GetProperty()->SetSpecular(0.0);
		theYLine_->GetProperty()->SetSpecularPower(20.0);
		theYLine_->GetProperty()->SetOpacity(myOpacity);
		theYLine_->GetProperty()->ShadingOn();
		theYLine_->SetSelectable(false);
		theYLine_->SetRenderLinesAsTubes(true);
	}
}

#endif // !_FrgVisual_GridActorI_Header
