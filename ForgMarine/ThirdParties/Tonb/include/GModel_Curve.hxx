#pragma once
#ifndef _GModel_Curve_Header
#define _GModel_Curve_Header

#include <Standard_Handle.hxx>
#include <GModel_Entity.hxx>
#include <Entity3d_BoxFwd.hxx>

class Geom_Curve;

namespace tnbLib
{

	class GModel_Curve
	{

		/*Private Data*/

		Handle(Geom_Curve) theGeometry_;


		auto& ChangeGeometry()
		{
			return theGeometry_;
		}

		void CheckBoundary
		(
			const Standard_Real x,
			const char* theName
		) const;

		static void CheckBounded
		(
			const Handle(Geom_Curve)& theCurve,
			const char* theName
		);

	public:

		GModel_Curve
		(
			const Handle(Geom_Curve) theGeometry
		);

		Standard_Real FirstParameter() const;

		Standard_Real LastParameter() const;

		Pnt3d Value(const Standard_Real x) const;

		Pnt3d Value_normParam(const Standard_Real x) const;

		Pnt3d FirstCoord() const;

		Pnt3d LastCoord() const;

		Entity3d_Box CalcBoundingBox() const;

		const auto& Geometry() const
		{
			return theGeometry_;
		}
	};
}

#include <GModel_CurveI.hxx>

#endif // !_GModel_Curve_Header
