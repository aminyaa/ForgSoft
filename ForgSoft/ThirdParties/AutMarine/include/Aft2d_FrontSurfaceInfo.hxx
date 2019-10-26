#pragma once
#ifndef _Aft2d_FrontSurfaceInfo_Header
#define _Aft2d_FrontSurfaceInfo_Header

#include <Aft2d_FrontInfoTemplate.hxx>
#include <Aft2d_FrontSurfaceInfoAdaptor.hxx>
#include <Aft2d_ElementSurface.hxx>
#include <Aft2d_EdgeSurface.hxx>
#include <Aft2d_NodeSurface.hxx>

namespace AutLib
{

	typedef Aft2d_FrontInfoTemplate<Aft2d_FrontSurfaceTraits, Aft2d_FrontSurfaceInfoAdaptor>
		Aft2d_FrontSurfaceInfo;
}

#endif // !_Aft2d_FrontSurfaceInfo_Header
