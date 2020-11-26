#pragma once
#ifndef _Aft2d_FrontGlobalDataFwd_Header
#define _Aft2d_FrontGlobalDataFwd_Header

#include <Aft2d_EdgeFwd.hxx>

namespace tnbLib
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

	typedef Aft_FrontGlobalData<Aft2d_Edge, Geom_AdTree, Geom_PriorityList>
		Aft2d_FrontGlobalData;
}

#endif // !_Aft2d_FrontGlobalDataFwd_Header