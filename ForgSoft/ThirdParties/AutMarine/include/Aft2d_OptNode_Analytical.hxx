#pragma once
#ifndef _Aft2d_OptNode_Analytical_Header
#define _Aft2d_OptNode_Analytical_Header

#include <Global_Done.hxx>
#include <Aft_OptNode_Analytical.hxx>
#include <Aft2d_Edge.hxx>

namespace AutLib
{

	typedef Aft_OptNode_Analytical<Aft2d_Edge>
		Aft2d_OptNode_Analytical;

	template<>
	void Aft2d_OptNode_Analytical::Perform();	
}

#endif // !_Aft2d_OptNode_Analytical_Header
