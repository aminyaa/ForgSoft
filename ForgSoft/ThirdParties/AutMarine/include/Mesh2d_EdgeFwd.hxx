#pragma once
#ifndef _Mesh2d_EdgeFwd_Header
#define _Mesh2d_EdgeFwd_Header

namespace AutLib
{

	// Forward Declarations

	struct Mesh2d_EdgeTraits;

	template<class EdgeTraits>
	class Mesh_Edge;

	typedef Mesh_Edge<Mesh2d_EdgeTraits> Mesh2d_Edge;
}

#endif // !_Mesh2d_EdgeFwd_Header
