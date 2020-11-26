#pragma once
#ifndef _Aft2d_OptNodeAnIso_Analytical_Header
#define _Aft2d_OptNodeAnIso_Analytical_Header

#include <Global_Done.hxx>
#include <Aft_OptNode_Analytical.hxx>
#include <Aft2d_EdgeAnIso.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Entity2d_Metric1;

	typedef Aft_OptNode_Analytical<Aft2d_EdgeAnIso, Entity2d_Metric1>
		Aft2d_OptNodeAnIso_Analytical;

	template<>
	void Aft2d_OptNodeAnIso_Analytical::Perform();
}


#endif // !_Aft2d_OptNodeAnIso_Analytical_Header