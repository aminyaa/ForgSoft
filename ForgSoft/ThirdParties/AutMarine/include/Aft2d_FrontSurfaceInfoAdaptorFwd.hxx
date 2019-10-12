#pragma once
#ifndef _Aft2d_FrontSurfaceInfoAdaptorFwd_Header
#define _Aft2d_FrontSurfaceInfoAdaptorFwd_Header

#include <Aft2d_FrontSurfaceTraits.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class FrontTraits>
	class Aft2d_FrontInfoAdaptorTemplate;

	typedef Aft2d_FrontInfoAdaptorTemplate<Aft2d_FrontSurfaceTraits>
		Aft2d_FrontSurfaceInfoAdaptor;
}

#endif // !_Aft2d_FrontSurfaceInfoAdaptorFwd_Header