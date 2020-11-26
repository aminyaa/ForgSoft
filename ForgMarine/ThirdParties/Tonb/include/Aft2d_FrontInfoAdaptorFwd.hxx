#pragma once
#ifndef _Aft2d_FrontInfoAdaptorFwd_Header
#define _Aft2d_FrontInfoAdaptorFwd_Header

#include <Aft_FrontTraits.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class FrontTraits>
	class Aft2d_FrontInfoAdaptorTemplate;

	typedef Aft2d_FrontInfoAdaptorTemplate<Aft_FrontTraits<Aft2d_Edge>>
		Aft2d_FrontInfoAdaptor;
}

#endif // !_Aft2d_FrontInfoAdaptorFwd_Header