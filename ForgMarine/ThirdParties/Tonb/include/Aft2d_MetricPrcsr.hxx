#pragma once
#ifndef _Aft2d_MetricPrcsr_Header
#define _Aft2d_MetricPrcsr_Header

#include <Aft_MetricPrcsr.hxx>
#include <Aft2d_Edge.hxx>
#include <Geo2d_SizeFunction.hxx>

namespace tnbLib
{

	typedef Aft_MetricPrcsr<Aft2d_Edge, Geo2d_SizeFunction>
		Aft2d_MetricPrcsr;
}

#endif // !_Aft2d_MetricPrcsr_Header