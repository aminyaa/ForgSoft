#pragma once
#ifndef _Geo_CurveLength_Header
#define _Geo_CurveLength_Header

#include <NumAlg_AdaptiveInteg_Info.hxx>
#include <Geo_CurveIntegrand.hxx>

namespace tnbLib
{

	namespace GeoLib
	{

		template<class gCurveType, class MetricPrcsrType = void>
		struct CalcCurveLength
		{

			typedef NumAlg_AdaptiveInteg_Info info;

			static Standard_Real _
			(
				const Geo_CurveIntegrand<gCurveType, MetricPrcsrType>& theIntegrand,
				const Standard_Real theU0,
				const Standard_Real theU1,
				info& theInfo
			);

		};


		template<class gCurveType>
		struct CalcCurveLength<gCurveType, void>
		{

			typedef NumAlg_AdaptiveInteg_Info info;

			static Standard_Real _
			(
				const Geo_CurveIntegrand<gCurveType>& theIntegrand,
				const Standard_Real theU0,
				const Standard_Real theU1,
				info& theInfo
			);
		};
	}
}

#include <Geo_CurveLengthI.hxx>

#endif // !_Geo_CurveLength_Header
