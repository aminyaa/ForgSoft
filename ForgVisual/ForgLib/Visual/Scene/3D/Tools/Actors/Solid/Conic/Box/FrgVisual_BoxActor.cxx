#include <FrgVisual_BoxActor.hxx>

#include <FrgBase_Pnt.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>
#include <vtkCubeSource.h>
#include <vtkPolyDataMapper.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_BoxActor);

ForgVisualLib::FrgVisual_BoxActor::FrgVisual_BoxActor()
{

}

void ForgVisualLib::FrgVisual_BoxActor::SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> P1)
{
	if (P0 == nullptr || P1 == nullptr)
		return;
	
	theP0_ = P0;
	theP1_ = P1;

	// Create a cube.
	vtkNew<vtkCubeSource> cube;
	cube->SetBounds(P0->X(), P1->X(), P0->Y(), P1->Y(), P0->Z(), P1->Z());
	cube->Update();

	// mapper
	vtkNew<vtkPolyDataMapper> cubeMapper;
	cubeMapper->SetInputData(cube->GetOutput());

	this->SetMapper(cubeMapper);
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

void ForgVisualLib::FrgVisual_BoxActor::SetEdgeColor(double red, double green, double blue)
{
	this->GetProperty()->SetInterpolationToFlat();
	this->GetProperty()->SetEdgeColor(red, green, blue);
	this->GetProperty()->SetLineWidth(2.0f);
	this->GetProperty()->SetAmbient(0.0);
	this->GetProperty()->SetSpecular(0.0);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_BoxActor)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_ConicActor<3>>(*this);

	ar & theP0_;
	ar & theP1_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_BoxActor)
{
	ar & boost::serialization::base_object<ForgVisualLib::FrgVisual_ConicActor<3>>(*this);

	ar & theP0_;
	ar & theP1_;

	SetData(theP0_, theP1_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BoxActor)