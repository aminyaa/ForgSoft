#pragma once
#ifndef _Entity3d_ChainFwd_Header
#define _Entity3d_ChainFwd_Header

#include <Entity_Connectivity.hxx>

namespace AutLib
{

	template<class Point, class ConnectType, bool NeighbData>
	class Entity_StaticData;

	class Pnt3d;

	typedef Entity_StaticData<Pnt3d, connectivity::dual, false> Entity3d_Chain;

}

#endif // !_Entity3d_ChainFwd_Header
