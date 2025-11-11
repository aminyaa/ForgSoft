#include "FrgVisual_ShapeActor.hxx"
#include <FrgVisual_Tools.hxx>

#include <vtkObjectFactory.h>
#include <vtkRenderer.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyData.h>
#include <vtkProperty.h>

#include <BRepPrimAPI_MakeCylinder.hxx>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_ShapeActor);

ForgVisualLib::FrgVisual_ShapeActor::FrgVisual_ShapeActor()
{

}

void ForgVisualLib::FrgVisual_ShapeActor::SetData(const TopoDS_Shape& shape)
{
	vtkSmartPointer<vtkPolyData> polyData = FrgVisual_Tools::ShapeToVTK(shape);

	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(polyData);
	this->SetMapper(mapper);
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_ShapeActor::GetActorType() const
{
	return FrgVisual_BaseActor_Entity::ActorType::Shape;
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_ShapeActor::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Cylinder);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Conic);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Solid);

	return types;
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_ShapeActor::GetActorDimension() const
{
	return FrgVisual_BaseActor_Entity::ActorDimension::ThreeDim;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_ShapeActor)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<3>>(*this);
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_ShapeActor)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_BaseActor<3>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_ShapeActor)