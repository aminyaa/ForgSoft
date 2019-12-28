#pragma once
#ifndef _Aft2d_FrontSurfaceGlobalDataFwd_Header
#define _Aft2d_FrontSurfaceGlobalDataFwd_Header

#include <Aft2d_EdgeSurfaceFwd.hxx>

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

	typedef Aft_FrontGlobalData<Aft2d_EdgeSurface, Geom_AdTree, Geom_PriorityList>
		Aft2d_FrontSurfaceGlobalData;
}

#endif // !_Aft2d_FrontSurfaceGlobalDataFwd_Header
