#pragma once
#ifndef _Aft2d_EdgeFwd_Header
#define _Aft2d_EdgeFwd_Header

namespace tnbLib
{

	// Forward Declarations

	struct Aft2d_EdgeTraits;

	template<class EdgeTraits>
	class Aft_Edge;

	typedef Aft_Edge<Aft2d_EdgeTraits> Aft2d_Edge;
}

#endif // !_Aft2d_EdgeFwd_Header