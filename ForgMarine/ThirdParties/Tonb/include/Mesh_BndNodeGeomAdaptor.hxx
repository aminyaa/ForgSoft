#pragma once
#ifndef _Mesh_BndNodeGeomAdaptor_Header
#define _Mesh_BndNodeGeomAdaptor_Header

#include <Mesh_EntityAdaptorM.hxx>
#include <Mesh_BndNode_Position.hxx>

namespace tnbLib
{

	Mesh_EntityToEntityAdaptor(BndNode, Curve, CurveType);
	Mesh_EntityToEntityAdaptor(BndNode, Surface, SurfType);

	template<class CurveType, class SurfType, Mesh_BndNode_Position POS = Mesh_BndNode_Position_Corner>
	class Mesh_BndNodeGeomAdaptor
		: public Mesh_BndNodeToCurveAdaptor<CurveType>
		, public Mesh_BndNodeToSurfaceAdaptor<SurfType>
	{

		/*Private Data*/

	public:

		Mesh_BndNodeGeomAdaptor()
		{}

	};

	template<class CurveType, class SurfType>
	class Mesh_BndNodeGeomAdaptor<CurveType, SurfType, Mesh_BndNode_Position_Segment>
		: public Mesh_BndNodeToSurfaceAdaptor<SurfType>
	{

		/*private Data*/

		std::weak_ptr<CurveType> theCurve_;

	public:

		Mesh_BndNodeGeomAdaptor()
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

	template<class CurveType, class SurfType>
	class Mesh_BndNodeGeomAdaptor<CurveType, SurfType, Mesh_BndNode_Position_Facet>
	{

		/*Private Data*/

		std::weak_ptr<CurveType> theCurve_;
		std::weak_ptr<SurfType> theSurface_;

	public:

		Mesh_BndNodeGeomAdaptor()
		{}

		const std::weak_ptr<CurveType>& Curve() const
		{
			return theCurve_;
		}

		const std::weak_ptr<SurfType>& Surface() const
		{
			return theSurface_;
		}

		void SetCurve(const std::weak_ptr<CurveType>& theCurve)
		{
			theCurve_ = theCurve;
		}

		void SetSurface(const std::weak_ptr<SurfType>& theSurface)
		{
			theSurface_ = theSurface;
		}
	};

	template<class CurveType>
	class Mesh_BndNodeGeomAdaptor<CurveType, void, Mesh_BndNode_Position_Corner>
		: public Mesh_BndNodeToCurveAdaptor<CurveType>
	{

		/*Private Data*/

	public:

		Mesh_BndNodeGeomAdaptor()
		{}

	};

	template<class CurveType>
	class Mesh_BndNodeGeomAdaptor<CurveType, void, Mesh_BndNode_Position_Segment>
	{

		/*Private Data*/

		std::weak_ptr<CurveType> theCurve_;

	public:

		Mesh_BndNodeGeomAdaptor()
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
}

#endif // !_Mesh_BndNodeGeomAdaptor_Header