#pragma once
#ifndef _Mesh2d_NodeFwd_Header
#define _Mesh2d_NodeFwd_Header

namespace AutLib
{

	// Forward Declarations
	struct Mesh2d_NodeTraits;

	template<class NodeTraits>
	class Mesh_Node;

	typedef Mesh_Node<Mesh2d_NodeTraits> Mesh2d_Node;
}

#endif // !_Mesh2d_NodeFwd_Header