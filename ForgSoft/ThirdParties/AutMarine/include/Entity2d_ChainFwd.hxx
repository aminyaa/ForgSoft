#pragma once
#ifndef _Entity2d_ChainFwd_Header
#define _Entity2d_ChainFwd_Header

#include <Entity_Connectivity.hxx>

namespace AutLib
{

	template<class Point, class ConnectType, bool NeighbData>
	class Entity_StaticData;

	class Pnt2d;

	typedef Entity_StaticData<Pnt2d, connectivity::dual, false> Entity2d_Chain;

}

#endif // !_Entity2d_ChainFwd_Header
