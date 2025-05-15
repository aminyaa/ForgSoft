#include <FrgVisual_SphereActor.hxx>

#include <vtkObjectFactory.h>
#include <vtkProperty.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_SphereActor);

ForgVisualLib::FrgVisual_SphereActor::FrgVisual_SphereActor()
{

}

void ForgVisualLib::FrgVisual_SphereActor::SetData(const ForgBaseLib::FrgBase_Pnt<3>& center, const double radius)
{
	// Create a sphere
	theSource_ = vtkSmartPointer<vtkSphereSource>::New();
	SetCenter(center);
	SetRadius(radius);

	// Make the surface smooth.
	theSource_->SetPhiResolution(100);
	theSource_->SetThetaResolution(100);

	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(theSource_->GetOutputPort());
	
	this->SetMapper(mapper);	
}

void ForgVisualLib::FrgVisual_SphereActor::SetRepresentationToPoints()
{
	this->GetProperty()->SetRepresentationToPoints();
}

void ForgVisualLib::FrgVisual_SphereActor::SetRepresentationToSurface()
{
	this->GetProperty()->SetRepresentationToSurface();
}

void ForgVisualLib::FrgVisual_SphereActor::SetRepresentationToWireframe()
{
	this->GetProperty()->SetRepresentationToWireframe();
	this->GetProperty()->EdgeVisibilityOn();
}

void ForgVisualLib::FrgVisual_SphereActor::SetEdgeColor(double red, double green, double blue)
{
	this->GetProperty()->SetInterpolationToFlat();
	this->GetProperty()->SetEdgeColor(red, green, blue);
	this->GetProperty()->SetLineWidth(2.0f);
	/*this->GetProperty()->SetAmbient(0.0);
	this->GetProperty()->SetSpecular(0.0);*/
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_SphereActor::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Sphere;
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_SphereActor::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Sphere);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Conic);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Solid);

	return types;
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_SphereActor::GetActorDimension() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

void ForgVisualLib::FrgVisual_SphereActor::SetCenter(const ForgBaseLib::FrgBase_Pnt<3>& center)
{
	theCenter_ = center;

	theSource_->SetCenter(theCenter_.X(), theCenter_.Y(), theCenter_.Z());
}

void ForgVisualLib::FrgVisual_SphereActor::SetRadius(const double radius)
{
	theRadius_ = radius;

	theSource_->SetRadius(theRadius_);
}

void ForgVisualLib::FrgVisual_SphereActor::SetPhiResolution(const int value)
{
	theSource_->SetPhiResolution(value);
}

void ForgVisualLib::FrgVisual_SphereActor::SetThetaResolution(const int value)
{
	theSource_->SetThetaResolution(value);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SphereActor)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_ConicActor<3>>(*this);

	ar& theCenter_;
	ar& theRadius_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SphereActor)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_ConicActor<3>>(*this);

	ar& theCenter_;
	ar& theRadius_;

	SetData(theCenter_, theRadius_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_SphereActor)