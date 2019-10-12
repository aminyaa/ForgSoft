#pragma once
#ifndef _Aft2d_NodeFwd_Header
#define _Aft2d_NodeFwd_Header

namespace AutLib
{

	// Forward Declarations

	struct Aft2d_NodeTraits;

	template<class NodeTraits>
	class Aft_Node;

	typedef Aft_Node<Aft2d_NodeTraits> Aft2d_Node;
}

#endif // !_Aft2d_NodeFwd_Header
