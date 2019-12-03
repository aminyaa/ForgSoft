#pragma once
#ifndef _Aft_BndEdgeAdaptor_Header
#define _Aft_BndEdgeAdaptor_Header

#include <Mesh_BndEdgeGeomAdaptor.hxx>

namespace AutLib
{

	template
		<
		class CurveType,
		class SurfType,
		class FacetType,
		class AftMetricPrcsr,
		Mesh_BndEdge_Position POS = Mesh_BndEdge_Position_Segment
		>
		class Aft_BndEdgeAdaptor
		: public Mesh_BndEdgeGeomAdaptor<CurveType, SurfType, POS>
	{

		/*Private Data*/

	public:

		Aft_BndEdgeAdaptor()
		{}
	};

	template<class CurveType>
	class Aft_BndEdgeAdaptor<CurveType, void, void, void>
		: public Mesh_BndEdgeGeomAdaptor<CurveType, void, Mesh_BndEdge_Position_Segment>
	{

		/*Private Data*/

	public:

		Aft_BndEdgeAdaptor()
		{}
	};

	template<class CurveType, class AftMetricPrcsr>
	class Aft_BndEdgeAdaptor<CurveType, void, void, AftMetricPrcsr>
		: public Mesh_BndEdgeGeomAdaptor<CurveType, void, Mesh_BndEdge_Position_Segment>
	{

		/*Private Data*/

	public:

		Aft_BndEdgeAdaptor()
		{}

		virtual void SingularityContraction(const AftMetricPrcsr&);
	};

	//template
	//	<
	//	class SurfType,
	//	class FacetType
	//	>
	//	class Aft_BndEdgeAdaptor<void, SurfType, FacetType, Mesh_BndEdge_Position_Facet>
	//	: public Mesh_BndEdgeGeomAdaptor<void, SurfType, Mesh_BndEdge_Position_Facet>
	//	, public Mesh_EdgeToFacetAdaptor<FacetType>
	//{

	//	/*Private Data*/

	//public:

	//	Aft_BndEdgeAdaptor()
	//	{}
	//};
}

#endif // !_Aft_BndEdgeAdaptor_Header
