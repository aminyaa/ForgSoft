#pragma once
#ifndef _Mesh_BndEdgeAdaptor_Header
#define _Mesh_BndEdgeAdaptor_Header

#include <Mesh_BndEdgeGeomAdaptor.hxx>

namespace tnbLib
{

	template
		<
		class CurveType,
		class SurfType,
		class FacetType,
		class MetricPrcsr,
		Mesh_BndEdge_Position POS = Mesh_BndEdge_Position_Segment
		>
		class Mesh_BndEdgeAdaptor
		: public Mesh_BndEdgeGeomAdaptor<CurveType, SurfType, POS>
	{

		/*Private Data*/

	public:

		Mesh_BndEdgeAdaptor()
		{}
	};

	template<class CurveType>
	class Mesh_BndEdgeAdaptor<CurveType, void, void, void>
		: public Mesh_BndEdgeGeomAdaptor<CurveType, void, Mesh_BndEdge_Position_Segment>
	{

		/*Private Data*/

	public:

		Mesh_BndEdgeAdaptor()
		{}
	};

	template<class CurveType, class MetricPrcsr>
	class Mesh_BndEdgeAdaptor<CurveType, void, void, MetricPrcsr>
		: public Mesh_BndEdgeGeomAdaptor<CurveType, void, Mesh_BndEdge_Position_Segment>
	{

		/*Private Data*/

	public:

		Mesh_BndEdgeAdaptor()
		{}

		virtual void SingularityContraction(const MetricPrcsr&);
	};
}

#include <Mesh_BndEdgeAdaptorI.hxx>

#endif // !_Mesh_BndEdgeAdaptor_Header
