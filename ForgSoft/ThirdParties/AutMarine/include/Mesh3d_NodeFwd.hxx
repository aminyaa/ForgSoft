#pragma once
#ifndef _Mesh3d_NodeFwd_Header
#define _Mesh3d_NodeFwd_Header

namespace AutLib
{

	// Forward Declarations

	struct Mesh3d_NodeTraits;

	template<class NodeTraits>
	class Mesh_Node;

	typedef Mesh_Node<Mesh3d_NodeTraits> Mesh3d_Node;
}

#endif // !_Mesh3d_NodeFwd_Header