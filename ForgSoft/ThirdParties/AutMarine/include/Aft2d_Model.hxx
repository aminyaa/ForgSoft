#pragma once
#ifndef _Aft2d_Model_Header
#define _Aft2d_Model_Header

#include <Aft_Model.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Aft2d_OptNode_Calculator.hxx>
#include <Aft2d_FrontGlobalData.hxx>
#include <Aft2d_FrontInfo.hxx>

namespace AutLib
{

	// Forward Declarations
	class Cad2d_Plane;

	typedef Aft_Model<Cad2d_Plane, Geo2d_SizeFunction>
		Aft2d_Model;
}

#endif // !_Aft2d_Model_Header
