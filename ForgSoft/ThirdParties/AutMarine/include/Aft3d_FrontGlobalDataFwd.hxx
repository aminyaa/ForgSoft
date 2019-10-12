#pragma once
#ifndef _Aft3d_FrontGlobalDataFwd_Header
#define _Aft3d_FrontGlobalDataFwd_Header

#include <Aft3d_FacetFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template
		<
		class FrontEntity,
		template<class> class GeomSearch,
		template<class> class PriorityList
		>
		class Aft_FrontGlobalData;

	template<class T>
	class Geom_AdTree;

	template<class T>
	class Geom_PriorityList;

	typedef Aft_FrontGlobalData<Aft3d_Facet, Geom_AdTree, Geom_PriorityList>
		Aft3d_FrontGlobalData;
}

#endif // !_Aft3d_FrontGlobalDataFwd_Header
