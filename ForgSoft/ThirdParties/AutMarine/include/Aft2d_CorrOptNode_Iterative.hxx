#pragma once
#ifndef _Aft2d_CorrOptNode_Iterative_Header
#define _Aft2d_CorrOptNode_Iterative_Header

#include <Aft_OptNode_Corrector.hxx>
#include <Aft_SizeCorr_Iterative_Info.hxx>
#include <Aft2d_EdgeFwd.hxx>
#include <Geo2d_SizeFunction.hxx>

namespace AutLib
{

	typedef Aft_OptNode_Corrector<Aft_OptNode_Corrector_Iterative, Aft2d_Edge, Aft_SizeCorr_Iterative_Info, Geo2d_SizeFunction>
		Aft2d_CorrOptNode_Iterative;

	template<>
	void Aft2d_CorrOptNode_Iterative::Perform(const Aft_SizeCorr_Iterative_Info& theInfo);
}

#endif // !_Aft2d_CorrOptNode_Iterative_Header
