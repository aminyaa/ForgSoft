#pragma once
#ifndef _Aft2d_NodeAnIsoFwd_Header
#define _Aft2d_NodeAnIsoFwd_Header

namespace AutLib
{

	// Forward Declarations

	struct Aft2d_NodeAnIsoTraits;

	template<class NodeTraits>
	class Aft_Node;

	typedef Aft_Node<Aft2d_NodeAnIsoTraits> Aft2d_NodeAnIso;
}

#endif // !_Aft2d_NodeAnIsoFwd_Header
