#pragma once
#ifndef _GModel_ParaCurve_Header
#define _GModel_ParaCurve_Header

#include <Standard_Handle.hxx>
#include <GModel_Entity.hxx>
#include <Pnt2d.hxx>
#include <Entity2d_BoxFwd.hxx>

class Geom2d_Curve;

namespace tnbLib
{

	class GModel_ParaCurve
		: public GModel_Entity
	{

		/*Private Data*/

		Handle(Geom2d_Curve) theGeometry_;


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
			const Handle(Geom2d_Curve)& theCurve,
			const char* theName
		);

	public:

		GModel_ParaCurve
		(
			const Handle(Geom2d_Curve)& theGeometry
		);

		Standard_Real FirstParameter() const;

		Standard_Real LastParameter() const;

		Pnt2d Value(const Standard_Real x) const;

		Pnt2d Value_normParam(const Standard_Real x) const;

		Pnt2d FirstCoord() const;

		Pnt2d LastCoord() const;

		Entity2d_Box CalcBoundingBox() const;

		const auto& Geometry() const
		{
			return theGeometry_;
		}
	};
}

#include <GModel_ParaCurveI.hxx>

#endif // !_GModel_ParaCurve_Header
