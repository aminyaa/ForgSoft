#pragma once
#ifndef _Aft2d_OptNode_Calculator_Header
#define _Aft2d_OptNode_Calculator_Header

#include <Aft_OptNode_Calculator.hxx>
#include <Aft2d_Edge.hxx>
#include <Geo2d_SizeFunction.hxx>

namespace AutLib
{

	typedef Aft_OptNode_Calculator<Aft2d_Edge, Geo2d_SizeFunction>
		Aft2d_OptNode_Calculator;
}

#endif // !_Aft2d_OptNode_Calculator_Header
