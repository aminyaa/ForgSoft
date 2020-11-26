#pragma once
#ifndef _Aft2d_FrontGlobalData_Header
#define _Aft2d_FrontGlobalData_Header

#include <Aft_FrontGlobalData.hxx>
#include <Geo_PriorityList.hxx>
#include <Geo_AdTree.hxx>
#include <Aft2d_Edge.hxx>

namespace tnbLib
{

	typedef Aft_FrontGlobalData<Aft2d_Edge, Geo_AdTree, Geo_PriorityList>
		Aft2d_FrontGlobalData;
}

#endif // !_Aft2d_FrontGlobalData_Header