#pragma once
#ifndef _Aft2d_FrontAnIsoInfoAdaptorFwd_Header
#define _Aft2d_FrontAnIsoInfoAdaptorFwd_Header

#include <Aft_FrontTraits.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class FrontTraits>
	class Aft2d_FrontInfoAdaptorTemplate;

	typedef Aft2d_FrontInfoAdaptorTemplate<Aft_FrontTraits<Aft2d_EdgeAnIso>>
		Aft2d_FrontAnIsoInfoAdaptor;
}

#endif // !_Aft2d_FrontAnIsoInfoAdaptorFwd_Header