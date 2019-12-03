#pragma once
#ifndef _Aft3d_MetricPrcsr_Header
#define _Aft3d_MetricPrcsr_Header

#include <Aft_MetricPrcsr.hxx>
#include <Aft3d_Facet.hxx>
#include <Geo3d_SizeFunction.hxx>

namespace AutLib
{

	typedef Aft_MetricPrcsr<Aft3d_Facet, Geo3d_SizeFunction>
		Aft3d_MetricPrcsr;
}

#endif // !_Aft3d_MetricPrcsr_Header
