#include <FrgVisual_3DBoxActor.hxx>

#include <FrgBase_Pnt3d.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>
#include <vtkCubeSource.h>
#include <vtkPolyDataMapper.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_3DBoxActor);

ForgVisualLib::FrgVisual_3DBoxActor::FrgVisual_3DBoxActor()
{

}

void ForgVisualLib::FrgVisual_3DBoxActor::SetData(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P1)
{
	if (P0 == nullptr || P1 == nullptr)
		return;

	theP0_ = P0;
	theP1_ = P1;

	// Create a cube.
	vtkNew<vtkCubeSource> cube;
	cube->SetBounds(P0->X(), P1->X(),P0->Y(), P1->Y(), P0->Z(), P1->Z());
	cube->Update();

	// mapper
	vtkNew<vtkPolyDataMapper> cubeMapper;
	cubeMapper->SetInputData(cube->GetOutput());

	this->SetMapper(cubeMapper);
}

void ForgVisualLib::FrgVisual_3DBoxActor::SetRepresentationToPoints()
{
	this->GetProperty()->SetRepresentationToPoints();
}

void ForgVisualLib::FrgVisual_3DBoxActor::SetRepresentationToSurface()
{
	this->GetProperty()->SetRepresentationToSurface();
}

void ForgVisualLib::FrgVisual_3DBoxActor::SetRepresentationToWireframe()
{
	this->GetProperty()->SetRepresentationToWireframe();
	this->GetProperty()->EdgeVisibilityOn();
}

void ForgVisualLib::FrgVisual_3DBoxActor::SetEdgeColor(double red, double green, double blue)
{
	this->GetProperty()->SetInterpolationToFlat();
	this->GetProperty()->SetEdgeColor(red, green, blue);
	this->GetProperty()->SetLineWidth(2.0f);
	this->GetProperty()->SetAmbient(0.0);
	this->GetProperty()->SetSpecular(0.0);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_3DBoxActor)
{
	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_3DBoxActor, ForgVisualLib::FrgVisual_3DBaseActor);

	ar & theP0_;
	ar & theP1_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_3DBoxActor)
{
	VOID_CAST_REGISTER(ForgVisualLib::FrgVisual_3DBoxActor, ForgVisualLib::FrgVisual_3DBaseActor);

	ar & theP0_;
	ar & theP1_;

	SetData(theP0_, theP1_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_3DBoxActor)