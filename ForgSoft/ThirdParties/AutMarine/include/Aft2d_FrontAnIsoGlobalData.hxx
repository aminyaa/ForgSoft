#pragma once
#ifndef _Aft2d_FrontAnIsoGlobalData_Header
#define _Aft2d_FrontAnIsoGlobalData_Header

#include <Aft_FrontGlobalData.hxx>
#include <Geom_PriorityList.hxx>
#include <Geom_AdTree.hxx>
#include <Aft2d_EdgeAnIso.hxx>

namespace AutLib
{

	typedef Aft_FrontGlobalData<Aft2d_EdgeAnIso, Geom_AdTree, Geom_PriorityList>
		Aft2d_FrontAnIsoGlobalData;
}

#endif // !_Aft2d_FrontAnIsoGlobalData_Header