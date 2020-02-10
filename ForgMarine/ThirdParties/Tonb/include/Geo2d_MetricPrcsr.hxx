#pragma once
#ifndef _Geo2d_MetricPrcsr_Header
#define _Geo2d_MetricPrcsr_Header

#include <Geo_MetricPrcsr.hxx>
#include <Geo2d_SizeFunction.hxx>

namespace tnbLib
{
	typedef Geo_MetricPrcsr<Geo2d_SizeFunction>
		Geo2d_MetricPrcsr;

	template<>
	Standard_Real Geo2d_MetricPrcsr::CalcUnitDistance(const Pnt2d& theP0, const Pnt2d& theP1) const;
}

#endif // !_Geo2d_MetricPrcsr_Header