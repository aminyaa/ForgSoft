#pragma once
#ifndef _Aft3d_CorrOptNode_Fraction_Header
#define _Aft3d_CorrOptNode_Fraction_Header

#include <Aft_OptNode_Corrector.hxx>
#include <Aft_SizeCorr_Fraction_Info.hxx>
#include <Aft3d_Facet.hxx>
#include <Geo3d_SizeFunction.hxx>

namespace AutLib
{

	typedef Aft_OptNode_Corrector<Aft3d_Facet, Aft_SizeCorr_Fraction_Info, Geo3d_SizeFunction>
		Aft3d_CorrOptNode_Fraction;

	template<>
	void Aft3d_CorrOptNode_Fraction::Perform(const Aft_SizeCorr_Fraction_Info& theInfo);
}

#endif // !_Aft3d_CorrOptNode_Fraction_Header
