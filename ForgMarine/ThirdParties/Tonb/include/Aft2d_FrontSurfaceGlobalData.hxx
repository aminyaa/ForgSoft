#pragma once
#ifndef _Aft2d_FrontSurfaceGlobalData_Header
#define _Aft2d_FrontSurfaceGlobalData_Header

#include <Aft_FrontGlobalData.hxx>
#include <Geo_PriorityList.hxx>
#include <Geo_AdTree.hxx>
#include <Aft2d_EdgeSurface.hxx>

namespace tnbLib
{

	typedef Aft_FrontGlobalData<Aft2d_EdgeSurface, Geo_AdTree, Geo_PriorityList>
		Aft2d_FrontSurfaceGlobalData;
}

#endif // !_Aft2d_FrontSurfaceGlobalData_Header