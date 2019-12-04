#pragma once
#ifndef _Mesh_BndEdgeGeomAdaptor_Header
#define _Mesh_BndEdgeGeomAdaptor_Header

#include <Mesh_EntityAdaptorM.hxx>
#include <Mesh_BndEdge_Position.hxx>

namespace AutLib
{

	Mesh_EntityToEntityAdaptor(BndEdge, Surface, SurfType);

	template<class CurveType>
	class Mesh_BndEdgeGeomAdaptorBase
	{

		/*Private Data*/

		std::weak_ptr<CurveType> theCurve_;

	public:

		Mesh_BndEdgeGeomAdaptorBase()
		{}

		const std::weak_ptr<CurveType>& Curve() const
		{
			return theCurve_;
		}

		void SetCurve(const std::weak_ptr<CurveType>& theCurve)
		{
			theCurve_ = theCurve;
		}
	};

	template<class CurveType, class SurfType, Mesh_BndEdge_Position POS = Mesh_BndEdge_Position_Segment>
	class Mesh_BndEdgeGeomAdaptor
		: public Mesh_BndEdgeToSurfaceAdaptor<SurfType>
		, public Mesh_BndEdgeGeomAdaptorBase<CurveType>
	{

		/*Private Data*/

	public:

		Mesh_BndEdgeGeomAdaptor()
		{}
	};

	template<class CurveType>
	class Mesh_BndEdgeGeomAdaptor<CurveType, void, Mesh_BndEdge_Position_Segment>
		: public Mesh_BndEdgeGeomAdaptorBase<CurveType>
	{

		/*Private Data*/

	public:

		Mesh_BndEdgeGeomAdaptor()
		{}

	};

	template<class SurfType>
	class Mesh_BndEdgeGeomAdaptor<void, SurfType, Mesh_BndEdge_Position_Facet>
	{

		/*Private Data*/

		std::weak_ptr<SurfType> theSurface_;

	public:

		Mesh_BndEdgeGeomAdaptor()
		{}

		const std::weak_ptr<SurfType>& Surface() const
		{
			return theSurface_;
		}

		void SetSurface(const std::weak_ptr<SurfType>& theSurface)
		{
			theSurface_ = theSurface;
		}
	};
}

#endif // !_Mesh_BndEdgeGeomAdaptor_Header