#pragma once
#ifndef _Aft3d_FrontAnIsoGlobalData_Header
#define _Aft3d_FrontAnIsoGlobalData_Header

#include <Aft_FrontGlobalData.hxx>
#include <Geom_PriorityList.hxx>
#include <Geom_AdTree.hxx>
#include <Aft3d_FacetAnIso.hxx>

namespace AutLib
{

	typedef Aft_FrontGlobalData<Aft3d_FacetAnIso, Geom_AdTree, Geom_PriorityList>
		Aft3d_FrontAnIsoGlobalData;
}

#endif // !_Aft3d_FrontAnIsoGlobalData_Header
