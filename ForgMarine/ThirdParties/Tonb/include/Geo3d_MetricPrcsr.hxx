#pragma once
#ifndef _Geo3d_MetricPrcsr_Header
#define _Geo3d_MetricPrcsr_Header

#include <Geo_MetricPrcsr.hxx>
#include <Geo3d_SizeFunction.hxx>

namespace tnbLib
{
	typedef Geo_MetricPrcsr<Geo3d_SizeFunction>
		Geo3d_MetricPrcsr;

	template<>
	Standard_Real Geo3d_MetricPrcsr::CalcUnitDistance(const Pnt3d& theP0, const Pnt3d& theP1) const;
}

#endif // !_Geo3d_MetricPrcsr_Header