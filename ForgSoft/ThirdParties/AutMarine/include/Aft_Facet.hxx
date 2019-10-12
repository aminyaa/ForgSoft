#pragma once
#ifndef _Aft_Facet_Header
#define _Aft_Facet_Header

#include <Mesh_Facet.hxx>

namespace AutLib
{

	template<class FacetTraits>
	using Aft_Facet = Mesh_Facet<FacetTraits>;
}

#endif // !_Aft_Facet_Header
