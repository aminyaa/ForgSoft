#pragma once
#ifndef _Aft2d_FrontAnIsoGlobalData_Header
#define _Aft2d_FrontAnIsoGlobalData_Header

#include <Aft_FrontGlobalData.hxx>
#include <Geo_PriorityList.hxx>
#include <Geo_AdTree.hxx>
#include <Aft2d_EdgeAnIso.hxx>

namespace tnbLib
{

	typedef Aft_FrontGlobalData<Aft2d_EdgeAnIso, Geo_AdTree, Geo_PriorityList>
		Aft2d_FrontAnIsoGlobalData;
}

#endif // !_Aft2d_FrontAnIsoGlobalData_Header