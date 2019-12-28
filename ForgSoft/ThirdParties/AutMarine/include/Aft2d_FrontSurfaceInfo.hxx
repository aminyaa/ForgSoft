#pragma once
#ifndef _Aft2d_FrontSurfaceInfo_Header
#define _Aft2d_FrontSurfaceInfo_Header

#include <Aft2d_FrontInfoTemplate.hxx>
#include <Aft_FrontTraits.hxx>
#include <Aft2d_FrontSurfaceInfoAdaptor.hxx>
#include <Aft2d_ElementSurface.hxx>
#include <Aft2d_EdgeSurface.hxx>
#include <Aft2d_NodeSurface.hxx>
#include <Aft2d_MetricPrcsrSurface.hxx>

namespace AutLib
{

	typedef Aft2d_FrontInfoTemplate<Aft_FrontTraits<Aft2d_EdgeSurface>, Aft2d_FrontSurfaceInfoAdaptor>
		Aft2d_FrontSurfaceInfo;

	template<>
	template<>
	void Aft2d_FrontSurfaceInfo::UpdateEdges<void, Aft2d_MetricPrcsrSurface>(const Aft2d_MetricPrcsrSurface& theSizeMap);
}

#endif // !_Aft2d_FrontSurfaceInfo_Header