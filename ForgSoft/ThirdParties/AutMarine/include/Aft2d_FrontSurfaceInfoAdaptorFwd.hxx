#pragma once
#ifndef _Aft2d_FrontSurfaceInfoAdaptorFwd_Header
#define _Aft2d_FrontSurfaceInfoAdaptorFwd_Header

#include <Aft_FrontTraits.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class FrontTraits>
	class Aft2d_FrontInfoAdaptorTemplate;

	typedef Aft2d_FrontInfoAdaptorTemplate<Aft_FrontTraits<Aft2d_EdgeSurface>>
		Aft2d_FrontSurfaceInfoAdaptor;
}

#endif // !_Aft2d_FrontSurfaceInfoAdaptorFwd_Header