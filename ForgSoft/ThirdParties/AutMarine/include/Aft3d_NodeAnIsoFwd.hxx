#pragma once
#ifndef _Aft3d_NodeAnIsoFwd_Header
#define _Aft3d_NodeAnIsoFwd_Header

namespace AutLib
{

	// Forward Declarations

	struct Aft3d_NodeAnIsoTraits;

	template<class NodeTraits>
	class Aft_Node;

	typedef Aft_Node<Aft3d_NodeAnIsoTraits> Aft3d_NodeAnIso;
}

#endif // !_Aft3d_NodeAnIsoFwd_Header
