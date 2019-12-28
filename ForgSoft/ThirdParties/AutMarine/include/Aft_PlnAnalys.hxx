#pragma once
#ifndef _Aft_PlnAnalys_Header
#define _Aft_PlnAnalys_Header

#include <Aft_PlnAnalys_Base.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class RegionType, class SizeFun, class MetricFun>
	class Aft_PlnBoundary;

	template<class PlnType, class SizeFun, class MetricFun = void>
	class Aft_PlnAnalys
		: public Aft_PlnAnalys_Base<PlnType, SizeFun, MetricFun>
	{

		typedef Aft_PlnAnalys_Base<PlnType, SizeFun, MetricFun>
			base;

		typedef typename base::curveType curveType;
		typedef typename base::frontType frontType;
		typedef typename base::metricMap metricMap;
		typedef typename base::plnMesher plnMesher;
		typedef typename base::regionType regionType;

		/*Private Data*/

	public:

		void Perform();
	};
}

#endif // !_Aft_PlnAnalys_Header
