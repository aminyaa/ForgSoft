#pragma once
#ifndef _Aft2d_CorrOptNodeSurface_Iterative_Header
#define _Aft2d_CorrOptNodeSurface_Iterative_Header

#include <Aft_OptNode_Corrector.hxx>
#include <Aft_SizeCorr_Iterative_Info.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace AutLib
{

	typedef Aft_OptNode_Corrector
		<
		Aft_OptNode_Corrector_Iterative, Aft2d_EdgeSurface,
		Aft_SizeCorr_Iterative_Info, Geo2d_SizeFunction,
		Geo2d_MetricFunction>
		Aft2d_CorrOptNodeSurface_Iterative;

	template<>
	void Aft2d_CorrOptNodeSurface_Iterative::Perform(const Aft_SizeCorr_Iterative_Info& theInfo);
}

#endif // !_Aft2d_CorrOptNodeSurface_Iterative_Header
