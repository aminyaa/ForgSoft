#pragma once
#ifndef _Aft3d_FrontAnIsoGlobalDataFwd_Header
#define _Aft3d_FrontAnIsoGlobalDataFwd_Header

#include <Aft3d_FacetAnIsoFwd.hxx>

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

	typedef Aft_FrontGlobalData<Aft3d_FacetAnIso, Geom_AdTree, Geom_PriorityList>
		Aft3d_FrontAnIsoGlobalData;
}

#endif // !_Aft3d_FrontAnIsoGlobalDataFwd_Header
