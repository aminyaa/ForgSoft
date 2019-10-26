#pragma once
#ifndef _Aft2d_FrontAnIsoInfoAdaptor_Header
#define _Aft2d_FrontAnIsoInfoAdaptor_Header

#include <Aft2d_FrontInfoAdaptorTemplate.hxx>
#include <Aft2d_FrontAnIsoTraits.hxx>

namespace AutLib
{

	typedef Aft2d_FrontInfoAdaptorTemplate<Aft2d_FrontAnIsoTraits>
		Aft2d_FrontAnIsoInfoAdaptor;
}

#endif // !_Aft2d_FrontAnIsoInfoAdaptor_Header