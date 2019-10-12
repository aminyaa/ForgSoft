#pragma once
#ifndef _SizeMap3d_Uniform_Header
#define _SizeMap3d_Uniform_Header

#include <Pnt3d.hxx>
#include <Mesh3d_SizeMap.hxx>
#include <GeoProcessor.hxx>
#include <Aft3d_Facet.hxx>
#include <Aft3d_Edge.hxx>
#include <Aft3d_Node.hxx>
#include <Entity3d_Box.hxx>

namespace AutLib
{

	struct SizeMap3d_UniformCache
	{
		Standard_Real InvSize;
	};

	class SizeMap3d_Uniform
		: public Mesh3d_SizeMap
		, public SizeMap3d_UniformCache
	{

		/*Private Data*/

		Standard_Real theSize_;
		Standard_Real theDimSize_;

		Entity3d_Box theBoundingBox_;

	public:

		SizeMap3d_Uniform()
			: theSize_(0)
			, theDimSize_(RealLast())
		{}

		SizeMap3d_Uniform(const Standard_Real theSize)
			: theSize_(theSize)
		{
			if (IsDone()) Change_IsDone() = Standard_False;
		}

		Standard_Real DimSize() const override
		{
			return theDimSize_;
		}

		const Entity3d_Box& BoundingBox() const
		{
			return theBoundingBox_;
		}

		void SetSize(const Standard_Real theSize)
		{
			theSize_ = theSize;
			if (IsDone()) Change_IsDone() = Standard_False;
		}

		void SetDimSize(const Standard_Real theSize)
		{
			theDimSize_ = theSize;
		}

		Standard_Real BaseElementSize() const override
		{
			return theSize_;
		}

		Standard_Real CalcElementSize
		(
			const Pnt3d& /*thePoint*/
		) const override
		{
			return theSize_;
		}

		Standard_Real CalcElementSize
		(
			const Aft3d_Facet& theFacet
		) const override
		{
			return CalcElementSize(theFacet.Centre());
		}

		Standard_Real Oriented
		(
			const Pnt3d& theP,
			const Aft3d_Facet& theFacet
		) const override
		{
			const auto& n0 = theFacet.Node0();
			const auto& n1 = theFacet.Node1();
			const auto& n2 = theFacet.Node2();

			return Processor::Oriented_cgal
			(
				theP,
				n0->Coord(), n1->Coord(), n2->Coord());
		}

		Standard_Real CalcDistance
		(
			const Pnt3d& P0,
			const Pnt3d& P1
		) const override
		{
			return P0.Distance(P1);
		}

		Standard_Real CalcSquareDistance
		(
			const Pnt3d& P0,
			const Pnt3d& P1
		) const override
		{
			return P0.SquareDistance(P1);
		}

		Standard_Real CalcDistance
		(
			const Pnt3d& theQ,
			const Aft3d_Facet& theFacet
		) const override
		{
			const auto& n0 = theFacet.Node0();
			const auto& n1 = theFacet.Node1();
			const auto& n2 = theFacet.Node2();

			return Processor::Distance_cgal
			(
				theQ,
				n0->Coord(), n1->Coord(), n2->Coord());
		}

		Standard_Real CalcSquareDistance
		(
			const Pnt3d& theQ,
			const Aft3d_Facet& theFacet
		) const override
		{
			const auto& n0 = theFacet.Node0();
			const auto& n1 = theFacet.Node1();
			const auto& n2 = theFacet.Node2();

			return Processor::SquareDistance_cgal
			(
				theQ,
				n0->Coord(), n1->Coord(), n2->Coord());
		}

		Standard_Real CalcEdgeDistance
		(
			const Pnt3d& theQ,
			const Aft3d_Edge& theEdge
		) const override
		{
			const auto& n0 = theEdge.Node0();
			const auto& n1 = theEdge.Node1();

			return Processor::Distance_cgal
			(
				theQ,
				n0->Coord(), n1->Coord());
		}

		Standard_Real CalcSquareEdgeDistance
		(
			const Pnt3d& theQ,
			const Aft3d_Edge& theEdge
		) const override
		{
			const auto& n0 = theEdge.Node0();
			const auto& n1 = theEdge.Node1();

			return Processor::SquareDistance_cgal
			(
				theQ,
				n0->Coord(), n1->Coord());
		}

		Standard_Real CalcEdgeDistance
		(
			const Aft3d_Edge& theE0,
			const Aft3d_Edge& theE1
		) const override
		{
			const auto& n0 = theE0.Node0();
			const auto& n1 = theE0.Node1();

			const auto& n2 = theE1.Node0();
			const auto& n3 = theE1.Node1();

			return Processor::DistanceSegments_cgal
			(
				n0->Coord(),
				n1->Coord(), n2->Coord(), n3->Coord());
		}

		Standard_Real CalcSquareEdgeDistance
		(
			const Aft3d_Edge& theE0,
			const Aft3d_Edge& theE1
		) const override
		{
			const auto& n0 = theE0.Node0();
			const auto& n1 = theE0.Node1();

			const auto& n2 = theE1.Node0();
			const auto& n3 = theE1.Node1();

			return Processor::SquareDistanceSegments_cgal
			(
				n0->Coord(),
				n1->Coord(), n2->Coord(), n3->Coord());
		}

		Standard_Real CalcUnitDistance
		(
			const Pnt3d& P0,
			const Pnt3d& P1
		) const override
		{
			return Distance(P0, P1)*InvSize;
		}

		Pnt3d CalcOptimumCoord
		(
			const Standard_Real theSize,
			const Aft3d_Facet& theFacet
		) const override
		{
			const auto Centre = theFacet.Centre();

			const auto& P0 = theFacet.Node0()->Coord();
			const auto& P1 = theFacet.Node1()->Coord();
			const auto& P2 = theFacet.Node2()->Coord();

			auto n = CrossProduct(P1 - P0, P2 - P0);
			n /= n.TwoNorm();

			auto P = Centre + theSize * n;
			return std::move(P);
		}

		void Make() override
		{
			if (BaseElementSize() <= gp::Resolution())
			{
				FatalErrorIn("SizeMap3d_Uniform(const Standard_Real theSize)")
					<< " Invalid size map value: " << BaseElementSize() << endl
					<< abort(FatalError);
			}
			InvSize = (Standard_Real)1.0 / theSize_;
			if (NOT IsDone()) Change_IsDone() = Standard_True;
		}

		void SetBoundingBox(const Entity3d_Box& theBox)
		{
			theBoundingBox_ = theBox;
		}

		Standard_Real Integrand
		(
			const Pnt3d& thePoint,
			const Pnt3d& theVector
		) const override
		{
			return sqrt(DotProduct(theVector, theVector));
		}

		Standard_Real Integrand
		(
			const Pnt3d& thePoint,
			const gp_Vec& theVector
		) const override
		{
			return sqrt(theVector.Dot(theVector));
		}

		Standard_Real IntegrandPerSize
		(
			const Pnt3d& thePoint,
			const Pnt3d& theVector
		) const override
		{
			return (Standard_Real)1.0 / CalcElementSize(thePoint) * sqrt(DotProduct(theVector, theVector));
		}

		Standard_Real IntegrandPerSize
		(
			const Pnt3d& thePoint,
			const gp_Vec& theVector
		) const override
		{
			return (Standard_Real)1.0 / CalcElementSize(thePoint) * sqrt(theVector.Dot(theVector));
		}
	};
}

#endif // !_SizeMap3d_Uniform_Header