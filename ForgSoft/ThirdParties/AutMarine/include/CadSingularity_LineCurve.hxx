#pragma once
#ifndef _CadSingularity_LineCurve_Header
#define _CadSingularity_LineCurve_Header

#include <CadSingularity_Curve.hxx>

namespace AutLib
{

	template<class CurveType>
	class CadSingularity_LineCurve
		: public CadSingularity_Curve<CurveType>
	{

		/*Private Data*/

	public:

		typedef CadSingularity_Curve<CurveType> base;

		typedef typename base::geomType geomType;
		typedef typename base::infoType info;

		/*CadSingularity_LineCurve(const CurveType& theCurve)
			: CadSingularity_Curve<CurveType>(theCurve)
		{}*/

		CadSingularity_LineCurve
		(
			const Handle(geomType)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<info>& theInfo
		)
			: CadSingularity_Curve<CurveType>(theCurve, theFirst, theLast, theInfo)
		{}


		Standard_Boolean IsLine() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_CadSingularity_LineCurve_Header
