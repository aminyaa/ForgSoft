#pragma once
#ifndef _Cad_PlaneCurve_Header
#define _Cad_PlaneCurve_Header

#include <Cad_Curve.hxx>

#include <memory>

#include <gp_Pln.hxx>

namespace AutLib
{

	template<class gCurveType>
	class Cad_PlaneCurve
		: public Cad_Curve<gCurveType>
	{

		/*Private Data*/

		std::shared_ptr<gp_Pln> thePlane_;

	public:

		Cad_PlaneCurve()
		{}

		Cad_PlaneCurve
		(
			const Standard_Real theFirst, 
			const Standard_Real theLast, 
			const Handle(gCurveType)& theCurve, 
			const std::shared_ptr<gp_Pln>& thePln
		)
			: Cad_Curve<gCurveType>(theFirst, theLast, theCurve)
			, thePlane_(thePln)
		{}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<gp_Pln>, Plane)
	};
}

#endif // !_Cad_PlaneCurve_Header
