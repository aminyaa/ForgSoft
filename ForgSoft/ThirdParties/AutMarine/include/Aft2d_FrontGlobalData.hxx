#pragma once
#ifndef _Aft2d_FrontGlobalData_Header
#define _Aft2d_FrontGlobalData_Header

#include <Aft_FrontGlobalData.hxx>
#include <Geom_PriorityList.hxx>
#include <Geom_AdTree.hxx>
#include <Aft2d_Edge.hxx>

namespace AutLib
{

	typedef Aft_FrontGlobalData<Aft2d_Edge, Geom_AdTree, Geom_PriorityList>
		Aft2d_FrontGlobalData;
}

#endif // !_Aft2d_FrontGlobalData_Header