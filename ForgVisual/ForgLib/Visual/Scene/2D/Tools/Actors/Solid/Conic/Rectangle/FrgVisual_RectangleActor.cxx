#include <FrgVisual_RectangleActor.hxx>
#include <FrgVisual_PolylineActor.hxx>

#include <FrgBase_Pnt.hxx>

#include <vtkObjectFactory.h>
#include <vtkPolyLine.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkProperty.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_RectangleActor);

ForgVisualLib::FrgVisual_RectangleActor::FrgVisual_RectangleActor()
{

}

void ForgVisualLib::FrgVisual_RectangleActor::SetData(ForgBaseLib::FrgBase_Pnt<2> P0, ForgBaseLib::FrgBase_Pnt<2> P1)
{
	SetData(P0.X(), P0.Y(), P1.X(), P1.Y());
}

void ForgVisualLib::FrgVisual_RectangleActor::SetData(double P0_X, double P0_Y, double P1_X, double P1_Y)
{
	auto p0 = ForgBaseLib::FrgBase_Pnt<2>(P0_X, P0_Y);
	auto p1 = ForgBaseLib::FrgBase_Pnt<2>(P1_X, P0_Y);
	auto p2 = ForgBaseLib::FrgBase_Pnt<2>(P1_X, P1_Y);
	auto p3 = ForgBaseLib::FrgBase_Pnt<2>(P0_X, P1_Y);
	auto p4 = ForgBaseLib::FrgBase_Pnt<2>(P0_X, P0_Y);

	FrgVisual_PolylineActor::SetData({ p0, p1, p2, p3, p4 });
}

void ForgVisualLib::FrgVisual_RectangleActor::SetP0(ForgBaseLib::FrgBase_Pnt<2> p0)
{
	SetP0(p0.X(), p0.Y());
}

void ForgVisualLib::FrgVisual_RectangleActor::SetP0(double x, double y)
{
	const auto& p1 = GetPoint(2);
	SetPoint(0, x, y);
	SetPoint(1, p1.X(), y);
	SetPoint(3, x, p1.Y());
	SetPoint(4, x, y);
}

void ForgVisualLib::FrgVisual_RectangleActor::SetP1(ForgBaseLib::FrgBase_Pnt<2> p1)
{
	SetP1(p1.X(), p1.Y());
}

void ForgVisualLib::FrgVisual_RectangleActor::SetP1(double x, double y)
{
	const auto& p0 = GetPoint(0);
	SetPoint(1, x, p0.Y());
	SetPoint(2, x, y);
	SetPoint(3, p0.X(), y);
}

ForgBaseLib::FrgBase_Pnt<2> ForgVisualLib::FrgVisual_RectangleActor::GetP0()
{
	return GetPoint(0);
}

ForgBaseLib::FrgBase_Pnt<2> ForgVisualLib::FrgVisual_RectangleActor::GetP1()
{
	return GetPoint(2);
}

void ForgVisualLib::FrgVisual_RectangleActor::SetRepresentationToPoints()
{
	GetProperty()->SetRepresentationToPoints();
}

void ForgVisualLib::FrgVisual_RectangleActor::SetRepresentationToSurface()
{
	GetProperty()->SetRepresentationToSurface();
}

void ForgVisualLib::FrgVisual_RectangleActor::SetRepresentationToWireframe()
{
	GetProperty()->SetRepresentationToWireframe();
	GetProperty()->EdgeVisibilityOn();
}

void ForgVisualLib::FrgVisual_RectangleActor::SetEdgeColor(double red, double green, double blue)
{
	GetProperty()->SetInterpolationToFlat();
	GetProperty()->SetEdgeColor(red, green, blue);
	GetProperty()->SetLineWidth(2.0f);
	GetProperty()->SetAmbient(0.0);
	GetProperty()->SetSpecular(0.0);
}

void ForgVisualLib::FrgVisual_RectangleActor::SetColor(double red, double green, double blue)
{
	FrgVisual_PolylineActor::SetColor(red, green, blue);
}

void ForgVisualLib::FrgVisual_RectangleActor::RemoveActors(vtkRenderer* renderer)
{
	
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_RectangleActor::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Rectangle);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Conic);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Curve);

	return types;
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_RectangleActor::GetActorDimension() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_RectangleActor)
{
	ar& boost::serialization::base_object<FrgVisual_PolylineActor<2>>(*this);

	/*ar& theP0_;
	ar& theP1_;*/
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_RectangleActor)
{
	ar& boost::serialization::base_object<FrgVisual_PolylineActor<2>>(*this);

	/*ar& theP0_;
	ar& theP1_;*/

	//SetData(theP0_, theP1_);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_RectangleActor)