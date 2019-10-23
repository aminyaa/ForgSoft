#pragma once
#ifndef _Mesh3d_EdgeFwd_Header
#define _Mesh3d_EdgeFwd_Header

namespace AutLib
{

	// Forward Declarations;

	struct Mesh3d_EdgeTraits;

	template<class EdgeTraits>
	class Mesh_Edge;

	typedef Mesh_Edge<Mesh3d_EdgeTraits> Mesh3d_Edge;
}

#endif // !_Mesh3d_EdgeFwd_Header