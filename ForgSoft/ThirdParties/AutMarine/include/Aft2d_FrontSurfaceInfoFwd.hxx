#pragma once
#ifndef _Aft2d_FrontSurfaceInfoFwd_Header
#define _Aft2d_FrontSurfaceInfoFwd_Header

#include <Aft2d_FrontSurfaceTraits.hxx>
#include <Aft2d_FrontSurfaceInfoAdaptorFwd.hxx>
#include <Aft2d_ElementSurfaceFwd.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>
#include <Aft2d_NodeSurfaceFwd.hxx>

namespace AutLib
{

	// Forward Declarations

	template<class FrontTraits, class FrontAdaptor>
	class Aft2d_FrontInfoTemplate;

	typedef Aft2d_FrontInfoTemplate<Aft2d_FrontSurfaceTraits, Aft2d_FrontSurfaceInfoAdaptor>
		Aft2d_FrontSurfaceInfo;
}

#endif // !_Aft2d_FrontSurfaceInfoFwd_Header
