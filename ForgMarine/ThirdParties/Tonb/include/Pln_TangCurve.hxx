#pragma once
#ifndef _Pln_TangCurve_Header
#define _Pln_TangCurve_Header

#include <Pln_Curve.hxx>

namespace tnbLib
{

	template<class CurveType>
	class Pln_TangCurve
		: public CurveType
	{

		/*Private Data*/

	public:

		Pln_TangCurve()
		{}

		Pln_TangCurve
		(
			const Standard_Integer theIndex,
			const Handle(Geom2d_Curve)& theGeom
		)
			: CurveType(theIndex, theGeom)
		{}

		Pln_TangCurve
		(
			const Handle(Geom2d_Curve)& theGeom
		)
			: CurveType(theGeom)
		{}

		Pln_TangCurve
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Handle(Geom2d_Curve)& theGeom
		)
			: CurveType(theIndex, theName, theGeom)
		{}

		Standard_Boolean IsTangential() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Pln_TangCurve_Header
