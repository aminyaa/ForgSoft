#pragma once
#ifndef _CadSingularity_Curve_Header
#define _CadSingularity_Curve_Header

#include <Standard_Handle.hxx>

namespace AutLib
{

	template<class CurveType>
	class CadSingularity_Curve
		: public CurveType
	{

		/*Private Data*/

	protected:

		/*CadSingularity_Curve(const CurveType& theCurve)
			: CurveType(theCurve)
		{}*/

		CadSingularity_Curve
		(
			const Handle(typename CurveType::geomType)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<typename CurveType::infoType>& theInfo
		)
			: CurveType(theFirst, theLast, theCurve, theInfo)
		{}

	public:

		typedef typename CurveType::geomType geomType;
		typedef typename CurveType::infoType info;
		typedef info infoType;

		virtual Standard_Boolean IsPole() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsLine() const
		{
			return Standard_False;
		}
	};
}

#endif // !_CadSingularity_Curve_Header
