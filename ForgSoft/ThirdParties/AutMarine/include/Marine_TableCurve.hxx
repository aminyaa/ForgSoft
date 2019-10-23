#pragma once
#ifndef _Marine_TableCurve_Header
#define _Marine_TableCurve_Header

#include <Marine_TableSection.hxx>
#include <Cad_PlaneCurve.hxx>

class Geom2d_Curve;

namespace AutLib
{

	class Marine_TableCurve
		: public Marine_TableSection
		, public Cad_PlaneCurve<Geom2d_Curve>
	{

		/*Private Data*/

	public:

		Marine_TableCurve
		(
			const Handle(Geom2d_Curve)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<gp_Pln>& thePlane
		)
			: Cad_PlaneCurve<Geom2d_Curve>(theFirst, theLast, theCurve, thePlane)
		{}

		Marine_TableCurve
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Handle(Geom2d_Curve)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<gp_Pln>& thePlane
		)
			: Cad_PlaneCurve<Geom2d_Curve>(theFirst, theLast, theCurve, thePlane)
			, Marine_TableSection(theIndex, theName)
		{}



	};
}

#endif // !_Marine_TableCurve_Header
