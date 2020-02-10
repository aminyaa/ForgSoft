#pragma once
#ifndef _TModel_Curve_Header
#define _TModel_Curve_Header

#include <TModel_Entity.hxx>
#include <Entity3d_BoxFwd.hxx>

#include <Standard_Handle.hxx>

class Geom_Curve;

namespace tnbLib
{

	class TModel_Curve
		: public TModel_Entity
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

		TModel_Curve
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

#include <TModel_CurveI.hxx>

#endif // !_TModel_Curve_Header
