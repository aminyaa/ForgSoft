#pragma once
#ifndef _Aft2d_FrontSurfaceInfoAdaptor_Header
#define _Aft2d_FrontSurfaceInfoAdaptor_Header

#include <Aft2d_FrontInfoAdaptorTemplate.hxx>
#include <Aft2d_FrontSurfaceTraits.hxx>

namespace AutLib
{

	typedef Aft2d_FrontInfoAdaptorTemplate<Aft2d_FrontSurfaceTraits>
		Aft2d_FrontSurfaceInfoAdaptor;
}

#endif // !_Aft2d_FrontSurfaceInfoAdaptor_Header