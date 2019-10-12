#pragma once
#ifndef _Entity3d_TriangulationFwd_Header
#define _Entity3d_TriangulationFwd_Header

#include <Entity_Connectivity.hxx>

namespace AutLib
{

	// Forward Declarations
	class Pnt3d;

	template<class Point, class ConnectType, bool NeighbData>
	class Entity_StaticData;

	typedef Entity_StaticData<Pnt3d, connectivity::triple, false>
		Entity3d_Triangulation;
}

#endif // !_Entity3d_TriangulationFwd_Header
