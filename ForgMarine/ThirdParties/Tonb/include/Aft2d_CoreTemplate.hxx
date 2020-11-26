#pragma once
#ifndef _Aft2d_CoreTemplate_Header
#define _Aft2d_CoreTemplate_Header

#include <Aft_Core.hxx>
#include <Aft2d_FrontInfo.hxx>
#include <Aft2d_FrontGlobalData.hxx>

namespace tnbLib
{

	template<class OptNodeAlg, class SizeFun>
	using Aft2d_CoreTemplate =
		Aft_Core
		<
		OptNodeAlg,
		SizeFun, Aft2d_FrontInfo,
		Aft2d_FrontGlobalData, void
		>;
}

#endif // !_Aft2d_CoreTemplate_Header
