#pragma once
#ifndef _CadSingularity_PoleCurve_Header
#define _CadSingularity_PoleCurve_Header

#include <CadSingularity_Curve.hxx>
#include <Pnt2d.hxx>

namespace AutLib
{

	template<class CurveType>
	class CadSingularity_PoleCurve
		: public CadSingularity_Curve<CurveType>
	{

		/*Private Data*/

		Pnt2d theMid_;

	public:

		typedef CadSingularity_Curve<CurveType> base;

		typedef typename base::geomType geomType;
		typedef typename base::infoType info;

		/*CadSingularity_PoleCurve(const CurveType& theCurve)
			: CadSingularity_Curve<CurveType>(theCurve)
		{}*/

		CadSingularity_PoleCurve
		(
			const Handle(geomType)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<info>& theInfo
		)
			: CadSingularity_Curve<CurveType>(theCurve, theFirst, theLast, theInfo)
		{}

		const Pnt2d& Mid() const
		{
			return theMid_;
		}

		void SetMid(const Pnt2d& theP)
		{
			theMid_ = theP;
		}

		Standard_Boolean IsPole() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_CadSingularity_PoleCurve_Header
