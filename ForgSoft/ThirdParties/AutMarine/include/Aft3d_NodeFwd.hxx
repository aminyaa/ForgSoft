#pragma once
#ifndef _Aft3d_NodeFwd_Header
#define _Aft3d_NodeFwd_Header

namespace AutLib
{

	// Forward Declarations

	struct Aft3d_NodeTraits;

	template<class NodeTraits>
	class Aft_Node;

	typedef Aft_Node<Aft3d_NodeTraits> Aft3d_Node;
}

#endif // !_Aft3d_NodeFwd_Header