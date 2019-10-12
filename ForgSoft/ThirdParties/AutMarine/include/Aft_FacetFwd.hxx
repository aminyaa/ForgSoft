#pragma once
#ifndef _Aft_FacetFwd_Header
#define _Aft_FacetFwd_Header

#include <Mesh_FacetFwd.hxx>

namespace AutLib
{

	template<class FacetTraits>
	using Aft_Facet = Mesh_Facet<FacetTraits>;
}

#endif // !_Aft_FacetFwd_Header
