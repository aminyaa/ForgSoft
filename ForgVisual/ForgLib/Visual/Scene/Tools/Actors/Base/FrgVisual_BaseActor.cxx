#include <FrgVisual_BaseActor.hxx>

#include <FrgBase_Pnt.hxx>

#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>

#include <vtkObjectFactory.h>

//template<int Dim>
//vtkStandardNewMacro(ForgVisualLib::FrgVisual_BaseActor<Dim>);

template<int Dim>
inline ForgVisualLib::FrgVisual_BaseActor<Dim>::FrgVisual_BaseActor()
{

}

template<int Dim>
inline ForgVisualLib::FrgVisual_BaseActor<Dim>::~FrgVisual_BaseActor()
{

}

template<int Dim>
//template<typename>
inline void ForgVisualLib::FrgVisual_BaseActor<Dim>::TranslateActor(double dx, double dy)
{
	this->AddPosition(dx, dy, 0.0);

	emit DataChangedSignal();
}

template<int Dim>
//template<typename>
inline void ForgVisualLib::FrgVisual_BaseActor<Dim>::TranslateActor(double dx, double dy, double dz)
{
	this->AddPosition(dx, dy, dz);

	emit DataChangedSignal();
}

template<int Dim>
std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ForgVisualLib::FrgVisual_BaseActor<Dim>::DiscreteCurve
(
	const opencascade::handle<Standard_Transient>& curve,
	const double degree
)
{
	std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts;

	if (!curve)
		return pts;

	const auto my2dCurve = opencascade::handle<Geom2d_Curve>::DownCast(curve);
	const auto my3dCurve = opencascade::handle<Geom_Curve>::DownCast(curve);

	const bool hasDer1 = my2dCurve ? my2dCurve->IsCN(1) : my3dCurve->IsCN(1);
	if (!hasDer1)
		return pts;

	// uniform discretization
	/*int nu = 300;
	du = 1.0 / static_cast<double>(nu);
	for (int i = 0; i <= nu; i++)
	{
		double u = i * du;
		if constexpr(Dim == 2)
		{
			auto pt = my2dCurve->Value(u);
			pts.emplace_back(pt.X(), pt.Y());
		}
		else if constexpr (Dim == 3)
		{
			auto pt = my3dCurve->Value(u);
			pts.emplace_back(pt.X(), pt.Y(), pt.Z());
		}
	}

	return pts;*/

	double u0, un;

	if constexpr (Dim == 2)
	{
		u0 = my2dCurve->FirstParameter();
		un = my2dCurve->LastParameter();

		if (u0 == un)
			return pts;

		const auto p0Curve = my2dCurve->Value(u0);
		pts.emplace_back(p0Curve.X(), p0Curve.Y());
	}
	else if constexpr (Dim == 3)
	{
		u0 = my3dCurve->FirstParameter();
		un = my3dCurve->LastParameter();

		if (u0 == un)
			return pts;

		const auto p0Curve = my3dCurve->Value(u0);
		pts.emplace_back(p0Curve.X(), p0Curve.Y(), p0Curve.Z());
	}

	double du = 0.1;
	double u1 = u0 + du;

	while (u0 < un)
	{
		if (u1 >= un)
			break;

		if constexpr (Dim == 2)
		{
			if (my2dCurve)
			{

				gp_Pnt2d p0, p1;
				gp_Vec2d v0, v1;
				my2dCurve->D1(u0, p0, v0);
				my2dCurve->D1(u1, p1, v1);

				double myError = std::abs(v0.Angle(v1) * 180.0 / 3.1415927);
				if (myError > degree)
				{
					u1 = (u0 + u1) / 2.0;
					du = u1 - u0;

					continue;
				}
				else
				{
					pts.emplace_back(p1.X(), p1.Y());

					u0 = u1;
					du *= 2.0;
					u1 = u0 + du;
				}
			}
		}
		else if constexpr (Dim == 3)
		{
			if (my3dCurve)
			{
				gp_Pnt p0, p1;
				gp_Vec v0, v1;
				my3dCurve->D1(u0, p0, v0);
				my3dCurve->D1(u1, p1, v1);

				double myError = std::abs(v0.Angle(v1) * 180.0 / 3.1415927);
				if (myError > degree)
				{
					u1 = (u0 + u1) / 2.0;
					du = u1 - u0;

					continue;
				}
				else
				{
					pts.emplace_back(p1.X(), p1.Y(), p1.Z());

					u0 = u1;
					du *= 2.0;
					u1 = u0 + du;
				}
			}
		}
	}

	if constexpr (Dim == 2)
	{
		auto p0Curve = my2dCurve->Value(un);
		pts.emplace_back(p0Curve.X(), p0Curve.Y());
	}
	else if constexpr (Dim == 3)
	{
		auto p0Curve = my3dCurve->Value(un);
		pts.emplace_back(p0Curve.X(), p0Curve.Y(), p0Curve.Z());
	}

	return std::move(pts);
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_BaseActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_BaseActor_Entity>(*this);
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_BaseActor<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_BaseActor_Entity>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BaseActor<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_BaseActor<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_BaseActor<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_BaseActor<3>;