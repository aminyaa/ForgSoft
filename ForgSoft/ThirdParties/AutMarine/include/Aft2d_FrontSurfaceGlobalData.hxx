#pragma once
#ifndef _Aft2d_FrontSurfaceGlobalData_Header
#define _Aft2d_FrontSurfaceGlobalData_Header

#include <Aft_FrontGlobalData.hxx>
#include <Geom_PriorityList.hxx>
#include <Geom_AdTree.hxx>
#include <Aft2d_EdgeSurface.hxx>

namespace AutLib
{

	typedef Aft_FrontGlobalData<Aft2d_EdgeSurface, Geom_AdTree, Geom_PriorityList>
		Aft2d_FrontSurfaceGlobalData;
}

#endif // !_Aft2d_FrontSurfaceGlobalData_Header
