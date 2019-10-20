#pragma once
#ifndef _Marine_TableCurve_Header
#define _Marine_TableCurve_Header

#include <Marine_TableSection.hxx>
#include <Cad_Curve.hxx>

class Geom_Curve;

namespace AutLib
{

	class Marine_TableCurve
		: public Marine_TableSection
		, public Cad_Curve<Geom_Curve>
	{

		/*Private Data*/

	public:

		Marine_TableCurve
		(
			const Handle(Geom_Curve)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast
		)
			: Cad_Curve<Geom_Curve>(theFirst, theLast, theCurve)
		{}

		Marine_TableCurve
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Handle(Geom_Curve)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast
		)
			: Cad_Curve<Geom_Curve>(theFirst, theLast, theCurve)
			, Marine_TableSection(theIndex, theName)
		{}
	};
}

#endif // !_Marine_TableCurve_Header
