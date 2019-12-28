#pragma once
#ifndef _Aft2d_OptNodeSurface_Analytical_Header
#define _Aft2d_OptNodeSurface_Analytical_Header

#include <Global_Done.hxx>
#include <Aft_OptNode_Analytical.hxx>
#include <Aft2d_EdgeSurface.hxx>

namespace AutLib
{

	// Forward Declarations
	class Entity2d_Metric1;

	typedef Aft_OptNode_Analytical<Aft2d_EdgeSurface, Entity2d_Metric1>
		Aft2d_OptNodeSurface_Analytical;

	template<>
	void Aft2d_OptNodeSurface_Analytical::Perform();
}

#endif // !_Aft2d_OptNodeSurface_Analytical_Header
