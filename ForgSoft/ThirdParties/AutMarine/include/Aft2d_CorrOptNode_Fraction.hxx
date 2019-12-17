#pragma once
#ifndef _Aft2d_CorrOptNode_Fraction_Header
#define _Aft2d_CorrOptNode_Fraction_Header

#include <Aft_OptNode_Corrector.hxx>
#include <Aft_SizeCorr_Fraction_Info.hxx>
#include <Aft2d_Edge.hxx>
#include <Geo2d_SizeFunction.hxx>

namespace AutLib
{

	typedef Aft_OptNode_Corrector<Aft_OptNode_Corrector_Fraction, Aft2d_Edge, Aft_SizeCorr_Fraction_Info, Geo2d_SizeFunction>
		Aft2d_CorrOptNode_Fraction;

	template<>
	void Aft2d_CorrOptNode_Fraction::Perform(const Aft_SizeCorr_Fraction_Info& theInfo);
}

#endif // !_Aft2d_CorrOptNode_Fraction_Header
