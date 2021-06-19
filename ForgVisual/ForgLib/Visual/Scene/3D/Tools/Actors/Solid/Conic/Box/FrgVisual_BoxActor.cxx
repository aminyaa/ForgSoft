#include <FrgVisual_BoxActor.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>
#include <vtkCubeSource.h>
#include <vtkPolyDataMapper.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_BoxActor);

ForgVisualLib::FrgVisual_BoxActor::FrgVisual_BoxActor()
{

}

void ForgVisualLib::FrgVisual_BoxActor::SetData(ForgBaseLib::FrgBase_Pnt<3> P0, ForgBaseLib::FrgBase_Pnt<3> P1)
{
	SetData(P0.X(), P1.X(), P0.Y(), P1.Y(), P0.Z(), P1.Z());
}

void ForgVisualLib::FrgVisual_BoxActor::SetData(double P0_x, double P0_y, double P0_z, double P1_x, double P1_y, double P1_z)
{
	theP0_.X() = P0_x;
	theP0_.Y() = P0_y;
	theP0_.Z() = P0_z;

	theP1_.X() = P1_x;
	theP1_.Y() = P1_y;
	theP1_.Z() = P1_z;

	// Create a cube.
	auto cube = vtkSmartPointer<vtkCubeSource>::New();
	cube->SetBounds(P0_x, P1_x, P0_y, P1_y, P0_z, P1_z);
	cube->Update();

	// mapper
	auto cubeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
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

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_BoxActor::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Box;
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_BoxActor::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Box);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Conic);

	return types;
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_BoxActor::GetActorDimension() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
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

	SetData(theP0_, theP0_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BoxActor)