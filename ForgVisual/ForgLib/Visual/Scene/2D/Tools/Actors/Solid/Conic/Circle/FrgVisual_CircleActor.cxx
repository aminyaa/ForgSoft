#include <FrgVisual_CircleActor.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgVisual_PolylineActor.hxx>
#include <FrgVisual_PointActor.hxx>

#include <Geom2d_Circle.hxx>
#include <gp_Circ2d.hxx>

#include <vtkRenderer.h>
#include <vtkObjectFactory.h>

vtkStandardNewMacro(ForgVisualLib::FrgVisual_CircleActor);

ForgVisualLib::FrgVisual_CircleActor::FrgVisual_CircleActor()
{

}

void ForgVisualLib::FrgVisual_CircleActor::SetData(ForgBaseLib::FrgBase_Pnt<2> center, double radius)
{
	auto ptOnCurve = center;
	ptOnCurve.X() += radius;
	SetDataCenterAndPointOnCurve(center, ptOnCurve);
}

void ForgVisualLib::FrgVisual_CircleActor::SetDataCenterAndPointOnCurve(ForgBaseLib::FrgBase_Pnt<2> center, ForgBaseLib::FrgBase_Pnt<2> pointOnCurve)
{
	ForgBaseLib::FrgBase_Pnt<2> directionWithTwoPoints(pointOnCurve.X() - center.X(), pointOnCurve.Y() - center.Y());
	double radius = directionWithTwoPoints.TwoNorm();
	directionWithTwoPoints = directionWithTwoPoints.UnitLength();
	gp_Dir2d dir(directionWithTwoPoints.X(), directionWithTwoPoints.Y());
	gp_Ax2d axis(gp_Pnt2d(center.X(), center.Y()), dir);

	if (!theCurve_)
	{
		theCurve_ = new Geom2d_Circle(axis, radius, true);
	}
	else
	{
		auto circle = dynamic_cast<Geom2d_Circle*>(theCurve_);
		if (circle)
		{
			circle->Circ2d().SetLocation(gp_Pnt2d(center.X(), center.Y()));
			circle->SetRadius(radius);
			circle->SetAxis(axis);
		}
	}

	FrgVisual_PolylineActor::SetData(DiscreteCurve(theCurve_));
}

void ForgVisualLib::FrgVisual_CircleActor::SetPointOnCurve(ForgBaseLib::FrgBase_Pnt<2> p)
{
	auto circle = dynamic_cast<Geom2d_Circle*>(theCurve_);
	if (circle)
	{
		auto centerP = circle->Circ2d().Location();
		ForgBaseLib::FrgBase_Pnt<2> center(centerP.X(), centerP.Y());
		SetDataCenterAndPointOnCurve(center, p);
	}
}

void ForgVisualLib::FrgVisual_CircleActor::ShowPoints(bool condition)
{
	if (!condition)
	{
		RemoveActors(theRenderer_);
		return;
	}

	auto circle = dynamic_cast<Geom2d_Circle*>(theCurve_);
	if (!circle)
		return;

	auto centerP = circle->Circ2d().Location();

	if (!theCenterPoint_)
	{
		theCenterPoint_ = FrgVisual_PointActor<2>::New();

		theCenterPoint_->SetRenderer(theRenderer_);
		theCenterPoint_->SetRenderPointsAsSpheres(true);
		theCenterPoint_->SetColor(0.0, 1.0, 0.0);
		theCenterPoint_->SetSize(8.0);
		theRenderer_->AddActor(theCenterPoint_);
	}

	theCenterPoint_->SetData(centerP.X(), centerP.Y());
}

void ForgVisualLib::FrgVisual_CircleActor::RemoveActors(vtkRenderer* renderer)
{
	if (renderer)
	{
		renderer->RemoveActor(theCenterPoint_);
		theCenterPoint_->Delete();
		theCenterPoint_ = nullptr;
	}
}

std::vector<ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType> ForgVisualLib::FrgVisual_CircleActor::GetActorTypes() const
{
	std::vector<ActorType> types;

	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Circle);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Conic);
	types.push_back(ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Curve);

	return types;
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension ForgVisualLib::FrgVisual_CircleActor::GetActorDimension() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorDimension::TwoDim;
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_CircleActor)
{
	ar& boost::serialization::base_object<FrgVisual_PolylineActor<2>>(*this);
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_CircleActor)
{
	ar& boost::serialization::base_object<FrgVisual_PolylineActor<2>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_CircleActor)