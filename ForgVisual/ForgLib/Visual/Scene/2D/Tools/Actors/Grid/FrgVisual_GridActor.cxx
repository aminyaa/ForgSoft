#include <FrgVisual_GridActor.hxx>
#include <FrgVisual_LineActor.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>
#include <vtkDoubleArray.h>
#include <vtkRectilinearGrid.h>
#include <vtkDataSetMapper.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_GridActor);

ForgVisualLib::FrgVisual_GridActor::FrgVisual_GridActor()
{

}

ForgVisualLib::FrgVisual_GridActor::~FrgVisual_GridActor()
{

}

void ForgVisualLib::FrgVisual_GridActor::SetData
(
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> center,
	double L1,
	double L2,
	int numberOfDivisions1,
	int numberOfDivisions2,
	bool XYLines
)
{
	if (center == nullptr)
		return;

	theNumberOfDivisions1_ = numberOfDivisions1;
	theNumberOfDivisions2_ = numberOfDivisions2;

	theCenter_ = center;

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
	this->GetProperty()->SetAmbient(0.1);
	this->GetProperty()->SetDiffuse(0.95);
	this->GetProperty()->SetSpecular(1.0);
	this->GetProperty()->SetSpecularPower(128.0);
	this->GetProperty()->SetOpacity(myOpacity);
	this->GetProperty()->ShadingOn();
	this->SetSelectable(false);

	if (XYLines)
	{
		if (!theXLine_)
		{
			theXLine_ = FrgVisual_LineActor<2>::New();
			theXLine_->SetColor(1.0, 0.0, 0.0);
			theXLine_->GetProperty()->SetLineWidth(3.0f);
			theXLine_->GetProperty()->SetAmbient(0.1);
			theXLine_->GetProperty()->SetDiffuse(0.95);
			theXLine_->GetProperty()->SetSpecular(1.0);
			theXLine_->GetProperty()->SetSpecularPower(128.0);
			theXLine_->GetProperty()->SetOpacity(myOpacity);
			theXLine_->GetProperty()->ShadingOn();
			theXLine_->SetSelectable(false);
			theXLine_->SetRenderLinesAsTubes(true);
		}
		if (!theYLine_)
		{
			theYLine_ = FrgVisual_LineActor<2>::New();
			theYLine_->SetColor(0.0, 1.0, 0.0);
			theYLine_->GetProperty()->SetLineWidth(3.0f);
			theYLine_->GetProperty()->SetAmbient(0.1);
			theYLine_->GetProperty()->SetDiffuse(0.95);
			theYLine_->GetProperty()->SetSpecular(1.0);
			theYLine_->GetProperty()->SetSpecularPower(128.0);
			theYLine_->GetProperty()->SetOpacity(myOpacity);
			theYLine_->GetProperty()->ShadingOn();
			theYLine_->SetSelectable(false);
			theYLine_->SetRenderLinesAsTubes(true);
		}

		theXLine_->SetData(theCenter_->X(), theCenter_->Y(), theCenter_->X() + theL1_, theCenter_->Y());
		theYLine_->SetData(theCenter_->X(), theCenter_->Y(), theCenter_->X(), theCenter_->Y() + theL2_);
	}
}

void ForgVisualLib::FrgVisual_GridActor::SetData
(
	double xCenter,
	double yCenter,
	double L1,
	double L2,
	int numberOfDivisions1,
	int numberOfDivisions2,
	bool XYLines
)
{
	SetData(std::make_shared<ForgBaseLib::FrgBase_Pnt<2>>(xCenter, yCenter), L1, L2, numberOfDivisions1, numberOfDivisions2);
}

void ForgVisualLib::FrgVisual_GridActor::SetVisibility(vtkTypeBool _arg)
{
	if (theXLine_)
		theXLine_->SetVisibility(_arg);
	if (theYLine_)
		theYLine_->SetVisibility(_arg);

	FrgVisual_CurveActor<2>::SetVisibility(_arg);
}

void ForgVisualLib::FrgVisual_GridActor::VisibilityOn()
{
	if (theXLine_)
		theXLine_->VisibilityOn();
	if (theYLine_)
		theYLine_->VisibilityOn();

	FrgVisual_CurveActor<2>::VisibilityOn();
}

void ForgVisualLib::FrgVisual_GridActor::VisibilityOff()
{
	if (theXLine_)
		theXLine_->VisibilityOff();
	if (theYLine_)
		theYLine_->VisibilityOff();

	FrgVisual_CurveActor<2>::VisibilityOff();
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_GridActor::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Grid;
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_GridActor::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Grid);

	return std::move(types);
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_GridActor::GetActorDimension() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_GridActor)
{
	ar& boost::serialization::base_object<FrgVisual_CurveActor<2>>(*this);

	ar& theCenter_;

	ar& theXLine_;
	ar& theYLine_;

	ar& theL1_;
	ar& theL2_;

	ar& theNumberOfDivisions1_;
	ar& theNumberOfDivisions2_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_GridActor)
{
	ar& boost::serialization::base_object<FrgVisual_CurveActor<2>>(*this);

	ar& theCenter_;

	ar& theXLine_;
	ar& theYLine_;

	ar& theL1_;
	ar& theL2_;

	ar& theNumberOfDivisions1_;
	ar& theNumberOfDivisions2_;

	SetData(theCenter_, theL1_, theL2_, theNumberOfDivisions1_, theNumberOfDivisions2_, false);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_GridActor)