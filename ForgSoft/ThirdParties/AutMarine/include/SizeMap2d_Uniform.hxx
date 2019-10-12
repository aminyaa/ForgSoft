#pragma once
#ifndef _SizeMap2d_Uniform_Header
#define _SizeMap2d_Uniform_Header

#include <Mesh2d_SizeMap.hxx>
#include <Aft2d_Edge.hxx>
#include <Aft2d_Node.hxx>
#include <GeoProcessor.hxx>

#include <gp.hxx>

namespace AutLib
{

	struct SizeMap2d_UniformCache
	{
		Standard_Real InvSize;
	};

	class SizeMap2d_Uniform
		: public Mesh2d_SizeMap
		, public SizeMap2d_UniformCache
	{

		/*Private Data*/

		Standard_Real theSize_;

	public:

		typedef Aft2d_Edge front;

		SizeMap2d_Uniform()
			: theSize_(0)
		{}

		SizeMap2d_Uniform(const Standard_Real theSize)
			: theSize_(theSize)
		{
			Make();
		}

		Standard_Real BaseElementSize() const override
		{
			return theSize_;
		}

		Standard_Real CalcElementSize
		(
			const Pnt2d& /*thePoint*/
		) const override
		{
			return theSize_;
		}

		Standard_Real CalcElementSize
		(
			const front& theEdge
		) const override
		{
			return CalcElementSize(theEdge.Centre());
		}

		Standard_Real Oriented
		(
			const Pnt2d& theP,
			const front& theEdge
		) const override
		{
			return Processor::Oriented_cgal
			(
				theP, theEdge.Node0()->Coord(),
				theEdge.Node1()->Coord());
		}

		Standard_Real CalcDistance
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		) const override
		{
			return Distance(theP0, theP1);
		}

		Standard_Real CalcSquareDistance
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		) const override
		{
			return SquareDistance(theP0, theP1);
		}

		Standard_Real CalcDistance
		(
			const Pnt2d& theP,
			const front& theEdge
		) const override
		{
			return Processor::Distance_cgal
			(
				theP, theEdge.Node0()->Coord(),
				theEdge.Node1()->Coord());
		}

		Standard_Real CalcSquareDistance
		(
			const Pnt2d& theP,
			const front& theEdge
		) const override
		{
			return Processor::SquareDistance_cgal
			(
				theP, theEdge.Node0()->Coord(),
				theEdge.Node1()->Coord());
		}

		Standard_Real CalcUnitDistance
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		) const override
		{
			return Distance(theP0, theP1)*InvSize;
		}

		Pnt2d CalcOptimumCoord
		(
			const Standard_Real theSize,
			const front& theEdge
		) const override
		{
			const auto& middle = theEdge.Centre();
			auto vec = (theEdge.Node1()->Coord() - middle).UnitLength();
			vec.Rotate90ccw();
			return middle + theSize * vec;
		}

		Pnt2d CalcCentreOf
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		) const override
		{
			return MEAN(theP0, theP1);
		}

		Pnt2d CalcCentreOf
		(
			const front& theEdge
		) const override
		{
			return CalcCentreOf
			(
				theEdge.Node0()->Coord(),
				theEdge.Node1()->Coord());
		}

		box CalcSearchRegion
		(
			const Standard_Real theRadius,
			const Pnt2d& theCentre
		) const override
		{
			return box(theCentre - theRadius, theCentre + theRadius);
		}

		box CalcSearchRegion
		(
			const Standard_Real theRadius,
			const Pnt2d& theCentre,
			const front& /*theEdge*/
		) const override
		{
			return box(theCentre - theRadius, theCentre + theRadius);
		}

		box CalcEffectiveRegion
		(
			const Standard_Real theRadius,
			const Pnt2d& theCentre,
			const front& /*theEdge*/
		) const override
		{
			return box(theCentre - theRadius, theCentre + theRadius);
		}

		Standard_Real Integrand
		(
			const Pnt2d& thePoint,
			const gp_Vec2d& theVector
		) const override
		{
			return sqrt(theVector.Dot(theVector));
		}

		Standard_Real Integrand
		(
			const Pnt2d& thePoint,
			const Pnt2d& theVector
		) const override
		{
			return sqrt(DotProduct(theVector, theVector));
		}

		Standard_Real IntegrandPerSize
		(
			const Pnt2d& thePoint,
			const gp_Vec2d& theVector
		) const override
		{
			return (Standard_Real)1.0 / CalcElementSize(thePoint) * sqrt(theVector.Dot(theVector));
		}

		Standard_Real IntegrandPerSize
		(
			const Pnt2d& thePoint,
			const Pnt2d& theVector
		) const override
		{
			return (Standard_Real)1.0 / CalcElementSize(thePoint) * sqrt(DotProduct(theVector, theVector));
		}

		void SetSize(const Standard_Real theSize)
		{
			theSize_ = theSize;
			Make();
		}

		void Make() override
		{
			if (BaseElementSize() <= gp::Resolution())
			{
				FatalErrorIn("SizeMap2d_Uniform(const Standard_Real theSize)")
					<< " Invalid size map value: " << BaseElementSize() << endl
					<< abort(FatalError);
			}
			InvSize = (Standard_Real)1.0 / theSize_;
		}
	};
}

#endif // !_SizeMap2d_Uniform_Header