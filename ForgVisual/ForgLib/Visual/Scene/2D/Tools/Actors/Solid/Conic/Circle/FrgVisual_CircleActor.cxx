#include <FrgVisual_CircleActor.hxx>

#include <FrgBase_Pnt.hxx>
#include <FrgVisual_PolylineActor.hxx>
#include <FrgVisual_PointActor.hxx>

#include <Standard_Handle.hxx>
#include <GCE2d_MakeCircle.hxx>
#include <Geom2d_Circle.hxx>
#include <Geom2d_TrimmedCurve.hxx>
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
		GCE2d_MakeCircle maker(axis, radius, true);
		if (maker.IsDone())
		{
			theCurve_ = maker.Value();
		}
		else
			theCurve_ = nullptr;
	}
	else
	{
		auto circle = opencascade::handle<Geom2d_Circle>::DownCast(theCurve_);
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
	auto circle = opencascade::handle<Geom2d_Circle>::DownCast(theCurve_);
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

	auto circle = opencascade::handle<Geom2d_Circle>::DownCast(theCurve_);
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

double ForgVisualLib::FrgVisual_CircleActor::GetRadius() const
{
	auto circle = opencascade::handle<Geom2d_Circle>::DownCast(theCurve_);
	if (!circle)
		return -1;

	return circle->Radius();
}

ForgBaseLib::FrgBase_Pnt<2> ForgVisualLib::FrgVisual_CircleActor::GetCenterPoint() const
{
	ForgBaseLib::FrgBase_Pnt<2> pt;

	auto circle = opencascade::handle<Geom2d_Circle>::DownCast(theCurve_);
	if (!circle)
		return pt;

	pt.X() = circle->Circ2d().Location().X();
	pt.Y() = circle->Circ2d().Location().Y();

	return std::move(pt);
}

void ForgVisualLib::FrgVisual_CircleActor::RemoveActors(vtkRenderer* renderer)
{
	if (renderer && theCenterPoint_)
	{
		renderer->RemoveActor(theCenterPoint_);
		theCenterPoint_->Delete();
		theCenterPoint_ = nullptr;
	}
}

ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType ForgVisualLib::FrgVisual_CircleActor::GetActorType() const
{
	return ForgVisualLib::FrgVisual_BaseActor_Entity::ActorType::Circle;
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

opencascade::handle<Geom2d_TrimmedCurve> ForgVisualLib::FrgVisual_CircleActor::GetTrimmedCurve() const
{
	const auto& curve = opencascade::handle<Geom2d_Circle>::DownCast(theCurve_);
	Handle(Geom2d_TrimmedCurve) t = new Geom2d_TrimmedCurve(curve, curve->FirstParameter(), curve->LastParameter());
	return std::move(t);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_CircleActor)
{
	ar& boost::serialization::base_object<FrgVisual_PolylineActor<2>>(*this);

	ar& theCenterPoint_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_CircleActor)
{
	ar& boost::serialization::base_object<FrgVisual_PolylineActor<2>>(*this);

	ar& theCenterPoint_;
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_CircleActor)