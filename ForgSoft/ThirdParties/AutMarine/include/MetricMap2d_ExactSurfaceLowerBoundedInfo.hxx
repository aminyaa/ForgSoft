#pragma once
#ifndef _MetricMap2d_ExactSurfaceLowerBoundedInfo_Header
#define _MetricMap2d_ExactSurfaceLowerBoundedInfo_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class MetricMap2d_ExactSurfaceLowerBoundedInfo
	{

		/*Private Data*/

		Standard_Real theEpsilon_;

	public:

		static const Standard_Real DEFAULT_EPSILON;

		MetricMap2d_ExactSurfaceLowerBoundedInfo()
			: theEpsilon_(DEFAULT_EPSILON)
		{}

		Standard_Real Epsilon() const
		{
			return theEpsilon_;
		}

		void SetEpsilon(const Standard_Real theEps)
		{
			theEpsilon_ = theEps;
		}
	};
}

#endif // !_MetricMap2d_ExactSurfaceLowerBoundedInfo_Header