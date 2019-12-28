#pragma once
#ifndef _Aft2d_FrontSurfaceInfoAdaptor_Header
#define _Aft2d_FrontSurfaceInfoAdaptor_Header

#include <Aft2d_FrontInfoAdaptorTemplate.hxx>
#include <Aft2d_NodeSurfaceFwd.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>
#include <Aft2d_ElementSurfaceFwd.hxx>
#include <Aft_FrontTraits.hxx>

namespace AutLib
{

	typedef Aft2d_FrontInfoAdaptorTemplate<Aft_FrontTraits<Aft2d_EdgeSurface>>
		Aft2d_FrontSurfaceInfoAdaptor;
}

#endif // !_Aft2d_FrontSurfaceInfoAdaptor_Header