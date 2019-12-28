#pragma once
#ifndef _Mesh2d_Edge_Header
#define _Mesh2d_Edge_Header

#include <Mesh_Edge.hxx>
#include <Mesh2d_EdgeTraits.hxx>

namespace AutLib
{

	typedef Mesh_Edge<Mesh2d_EdgeTraits> Mesh2d_Edge;

	template<>
	template<>
	Standard_Boolean Mesh2d_Edge::IsLeftSide<Standard_Boolean>
		(
			const Pnt2d& theCoord
			) const;

	template<>
	template<>
	Standard_Boolean Mesh2d_Edge::IsRightSide<Standard_Boolean>
		(
			const Pnt2d& theCoord
			) const;
}

#endif // !_Mesh2d_Edge_Header