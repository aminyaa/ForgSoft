#pragma once
#ifndef _Aft2d_FrontInfoAdaptor_Header
#define _Aft2d_FrontInfoAdaptor_Header

#include <Aft2d_FrontInfoAdaptorTemplate.hxx>
#include <Aft_FrontTraits.hxx>

namespace AutLib
{

	typedef Aft2d_FrontInfoAdaptorTemplate<Aft_FrontTraits<Aft2d_Edge>>
		Aft2d_FrontInfoAdaptor;
}

#endif // !_Aft2d_FrontInfoAdaptor_Header