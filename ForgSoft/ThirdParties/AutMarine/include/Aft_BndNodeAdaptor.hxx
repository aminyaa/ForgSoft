#pragma once
#ifndef _Aft_BndNodeAdaptor_Header
#define _Aft_BndNodeAdaptor_Header

#include <Mesh_NodeAdaptor.hxx>
#include <Mesh_BndNodeGeomAdaptor.hxx>

namespace AutLib
{

	template
		<
		class CurveType,
		class SurfType,
		class EdgeType,
		class FacetType,
		Mesh_BndNode_Position POS = Mesh_BndNode_Position_Corner
		>
		class Aft_BndNodeAdaptor
		: public Mesh_NodeAdaptor<EdgeType, void, FacetType>
		, public Mesh_BndNodeGeomAdaptor<CurveType, SurfType, POS>
	{

		/*Private Data*/

	public:

		typedef Mesh_NodeAdaptor<EdgeType, void, FacetType> nodeAdaptor;
		typedef Mesh_BndNodeGeomAdaptor<CurveType, SurfType, POS> geomAdaptor;

		Aft_BndNodeAdaptor()
		{}
	};

	template<class CurveType, class EdgeType>
	class Aft_BndNodeAdaptor<CurveType, void, EdgeType, void, Mesh_BndNode_Position_Corner>
		: public Mesh_NodeAdaptor<EdgeType, void, void>
		, public Mesh_BndNodeGeomAdaptor<CurveType, void, Mesh_BndNode_Position_Corner>
	{

		/*Private Data*/

	public:

		typedef Mesh_NodeAdaptor<EdgeType, void, void> nodeAdaptor;
		typedef Mesh_BndNodeGeomAdaptor<CurveType, void, Mesh_BndNode_Position_Corner> geomAdaptor;

		Aft_BndNodeAdaptor()
		{}
	};

	template<class CurveType, class EdgeType>
	class Aft_BndNodeAdaptor<CurveType, void, EdgeType, void, Mesh_BndNode_Position_Segment>
		: public Mesh_NodeAdaptor<EdgeType, void, void>
		, public Mesh_BndNodeGeomAdaptor<CurveType, void, Mesh_BndNode_Position_Segment>
	{

		/*Private Data*/

	public:

		typedef Mesh_NodeAdaptor<EdgeType, void, void> nodeAdaptor;
		typedef Mesh_BndNodeGeomAdaptor<CurveType, void, Mesh_BndNode_Position_Segment> geomAdaptor;

		Aft_BndNodeAdaptor()
		{}
	};
}

#endif // !_Aft_BndNodeAdaptor_Header