#pragma once
#ifndef _Aft3d_FrontGlobalData_Header
#define _Aft3d_FrontGlobalData_Header

#include <Aft_FrontGlobalData.hxx>
#include <Geom_PriorityList.hxx>
#include <Geom_AdTree.hxx>
#include <Aft3d_Facet.hxx>

namespace AutLib
{

	typedef Aft_FrontGlobalData<Aft3d_Facet, Geom_AdTree, Geom_PriorityList>
		Aft3d_FrontGlobalData;
}

#endif // !_Aft3d_FrontGlobalData_Header