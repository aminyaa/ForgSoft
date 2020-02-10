#pragma once
#ifndef _TModel_ParaCurve_Header
#define _TModel_ParaCurve_Header

#include <TModel_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <OFstream.hxx>

#include <Standard_Handle.hxx>

#include <Geom2d_Curve.hxx>

namespace tnbLib
{

	class TModel_ParaCurve
		: public TModel_Entity
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

		TModel_ParaCurve
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

		//- IO functions and operators

		//void ExportToPlt(OFstream& File) const;
	};
}

#include <TModel_ParaCurveI.hxx>

#endif // !_TModel_ParaCurve_Header
