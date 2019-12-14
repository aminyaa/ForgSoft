#pragma once
#ifndef _Aft2d_ModelAnIso_Header
#define _Aft2d_ModelAnIso_Header

#include <Aft_Model.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace AutLib
{

	// Forward Declarations
	class Cad2d_Plane;

	typedef Aft_Model<Cad2d_Plane, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_ModelAnIso;
}

#endif // !_Aft2d_ModelAnIso_Header
