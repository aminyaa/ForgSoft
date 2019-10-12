#pragma once
#ifndef _Aft2d_FrontAnIsoInfoAdaptorFwd_Header
#define _Aft2d_FrontAnIsoInfoAdaptorFwd_Header

#include <Aft2d_FrontAnIsoTraits.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class FrontTraits>
	class Aft2d_FrontInfoAdaptorTemplate;

	typedef Aft2d_FrontInfoAdaptorTemplate<Aft2d_FrontAnIsoTraits>
		Aft2d_FrontAnIsoInfoAdaptor;
}

#endif // !_Aft2d_FrontAnIsoInfoAdaptorFwd_Header