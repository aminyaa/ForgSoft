#pragma once
#ifndef _Mesh3d_SizeMap_Header
#define _Mesh3d_SizeMap_Header

#include <Mesh_SizeMap.hxx>
#include <Entity3d_Box.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft3d_EdgeFwd.hxx>

namespace AutLib
{

	struct Mesh3d_SizeMapShield
	{};

	template<>
	struct remove_shield<Mesh3d_SizeMapShield> { typedef Aft3d_Facet type; };

	template<>
	class Mesh_SizeMap<Aft3d_Facet>
		: public Mesh_SizeMap<Mesh3d_SizeMapShield>
		, public std::enable_shared_from_this<Mesh_SizeMap<Aft3d_Facet>>
	{

		/*Private Data*/

	public:

		typedef Entity3d_Box box;

		Mesh_SizeMap()
		{}

		virtual Standard_Real CalcEdgeDistance
		(
			const Point& theQ,
			const Aft3d_Edge& theEdge
		) const = 0;

		virtual Standard_Real CalcSquareEdgeDistance
		(
			const Point& theQ,
			const Aft3d_Edge& theEdge
		) const = 0;

		virtual Standard_Real CalcEdgeDistance
		(
			const Aft3d_Edge&,
			const Aft3d_Edge&
		) const = 0;

		virtual Standard_Real CalcSquareEdgeDistance
		(
			const Aft3d_Edge&,
			const Aft3d_Edge&
		) const = 0;
	};

	typedef Mesh_SizeMap<Aft3d_Facet> Mesh3d_SizeMap;
}

#endif // !_Mesh3d_SizeMap_Header