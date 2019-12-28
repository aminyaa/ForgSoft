#pragma once
#ifndef _Aft2d_FrontInfo_Header
#define _Aft2d_FrontInfo_Header

#include <Aft2d_FrontInfoTemplate.hxx>
#include <Aft_FrontTraits.hxx>
#include <Aft2d_FrontInfoAdaptor.hxx>
#include <Aft2d_Element.hxx>
#include <Aft2d_Edge.hxx>
#include <Aft2d_Node.hxx>

namespace AutLib
{

	typedef Aft2d_FrontInfoTemplate<Aft_FrontTraits<Aft2d_Edge>, Aft2d_FrontInfoAdaptor>
		Aft2d_FrontInfo;
}

#endif // !_Aft2d_FrontInfo_Header