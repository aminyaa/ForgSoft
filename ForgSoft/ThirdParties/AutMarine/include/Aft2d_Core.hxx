#pragma once
#ifndef _Aft2d_Core_Header
#define _Aft2d_Core_Header

#include <Aft_Core.hxx>
#include <Aft2d_FrontInfo.hxx>
#include <Aft2d_FrontGlobalData.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Aft2d_OptNode_Calculator.hxx>

namespace AutLib
{

	typedef Aft_Core<Aft2d_OptNode_Calculator, Geo2d_SizeFunction, Aft2d_FrontInfo, Aft2d_FrontGlobalData>
		Aft2d_Core;
}

#endif // !_Aft2d_Core_Header
