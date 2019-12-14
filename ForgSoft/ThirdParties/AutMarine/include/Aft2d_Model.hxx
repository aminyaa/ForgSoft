#pragma once
#ifndef _Aft2d_Model_Header
#define _Aft2d_Model_Header

#include <Aft_Model.hxx>
#include <Geo2d_SizeFunction.hxx>

namespace AutLib
{

	// Forward Declarations
	class Cad2d_Plane;

	typedef Aft_Model<Cad2d_Plane, Geo2d_SizeFunction>
		Aft2d_Model;
}

#endif // !_Aft2d_Model_Header
