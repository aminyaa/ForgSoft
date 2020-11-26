#pragma once
#ifndef _Aft3d_OptNode_Calculator_Header
#define _Aft3d_OptNode_Calculator_Header

#include <Aft_OptNode_Calculator.hxx>
#include <Aft3d_Facet.hxx>
#include <Geo3d_SizeFunction.hxx>

namespace tnbLib
{

	typedef Aft_OptNode_Calculator<Aft3d_Facet, Geo3d_SizeFunction>
		Aft3d_OptNode_Calculator;
}

#endif // !_Aft3d_OptNode_Calculator_Header