#pragma once
#ifndef _Entity_Box_Header
#define _Entity_Box_Header

#include <Standard_Real.hxx>
#include <Global_Macros.hxx>
#include <Geo_Traits.hxx>
#include <error.hxx>
#include <OSstream.hxx>
#include <IOstream.hxx>

#include <iostream>
#include <vector>
#include <tuple>

namespace tnbLib
{

	// Forward Declarations
	class OFstream;

	template<class Point>
	class Entity_Box
	{

		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;

		/*Private Data*/

		Point theP0_;
		Point theP1_;

	public:

		typedef Point ptType;

		Entity_Box()
		{}

		Entity_Box
		(
			const Point& theP0,
			const Point& theP1
		)
			: theP0_(theP0)
			, theP1_(theP1)
		{}

		Standard_Real Diameter() const
		{
			return Distance(P0(), P1());
		}

		Standard_Real SquareDiameter() const
		{
			return SquareDistance(P0(), P1());
		}

		Standard_Boolean IsInside(const Point& theP) const
		{
			forThose(Index, 1, Point::nbCmpts)
				if (!INSIDE(theP.Coord(Index), P0().Coord(Index), P1().Coord(Index)))
				{
					return Standard_False;
				}
			return Standard_True;
		}

		Standard_Boolean IsIntersect(const Entity_Box& theOther) const
		{
			forThose(Index, 1, Point::nbCmpts)
				if (
					!(
						P1().Coord(Index) < theOther.P0().Coord(Index)
						|| P0().Coord(Index) > theOther.P1().Coord(Index)
						)
					)
				{
					return Standard_True;
				}
			return Standard_False;
		}

		const Point& P0() const
		{
			return theP0_;
		}

		Point& P0()
		{
			return theP0_;
		}

		const Point& P1() const
		{
			return theP1_;
		}

		Point& P1()
		{
			return theP1_;
		}

		Point CalcCentre() const
		{
			return (Standard_Real)0.5*(P0() + P1());
		}

		Entity_Box OffSet(const Standard_Real theTol) const
		{
			return Entity_Box(P0() - theTol, P1() + theTol);
		}

		Entity_Box Expanded(const Standard_Real theOffset) const;

		template<class U = Entity_Box>
		resolvedType<is_two_dimension<(int)Point::dim>::value, U>
			Expanded
			(
				const Standard_Real dx, 
				const Standard_Real dy
			) const
		{
			auto c = *this;
			c.Expand(dx, dy);
			return std::move(c);
		}

		template<class U = Entity_Box>
		resolvedType<is_three_dimension<(int)Point::dim>::value, U>
			Expanded
			(
				const Standard_Real dx,
				const Standard_Real dy,
				const Standard_Real dz
			) const
		{
			auto c = *this;
			c.Expand(dx, dy, dz);
			return std::move(c);
		}

		template<class SubAlg>
		Entity_Box SubDivide(const SubAlg theAlgorithm) const;

		template<class SubAlg>
		Entity_Box Half
		(
			const Standard_Integer theIndex,
			const SubAlg theAlgorithm
		) const
		{
			Point Pm = MEAN(P0(), P1());
			Point P;
			switch (theAlgorithm)
			{
			case SubAlg::Box2d_SubDivideAlgorithm_Half_Left:
				P = P1();
				P.SetCoord(theIndex + 1, Pm.Coord(theIndex + 1));
				return Entity_Box(P0(), P);
			case SubAlg::Box2d_SubDivideAlgorithm_Half_Right:
				P = P0();
				P.SetCoord(theIndex + 1, Pm.Coord(theIndex + 1));
				return Entity_Box(P, P1());
			default:
				FatalErrorIn("Entity_Box Half()")
					<< "Invalid side select: ONLY 'Left' or 'Right' is valid"
					<< abort(FatalError);
			}
			return Entity_Box();
		}

		template<class PickAlg>
		Point Corner(const PickAlg theAlgorithm) const;

		template<class U = std::tuple<Standard_Real, Standard_Real>>
		resolvedType<is_two_dimension<(int)Point::dim>::value, U>
			Length() const
		{
			Standard_Real dx, dy;
			Length(dx, dy);
			return std::make_tuple(dx, dy);
		}

		template<class U = std::tuple<Standard_Real, Standard_Real, Standard_Real>>
		resolvedType<is_three_dimension<(int)Point::dim>::value, U>
			Length() const
		{
			Standard_Real dx, dy, dz;
			Length(dx, dy, dz);
			return std::make_tuple(dx, dy, dz);
		}

		void Expand(const Standard_Real theOffset);

		template<class U = void>
		resolvedType<is_two_dimension<(int)Point::dim>::value, U>
			Expand
			(
				const Standard_Real dx,
				const Standard_Real dy
			)
		{
			auto& p0 = P0();
			auto& p1 = P1();

			p0.X() -= dx;
			p0.Y() -= dy;

			p1.X() += dx;
			p1.Y() += dy;
		}

		template<class U = void>
		resolvedType<is_three_dimension<(int)Point::dim>::value, U>
			Expand
			(
				const Standard_Real dx,
				const Standard_Real dy,
				const Standard_Real dz
			)
		{
			auto& p0 = P0();
			auto& p1 = P1();

			p0.X() -= dx;
			p0.Y() -= dy;
			p0.Z() -= dz;

			p1.X() += dx;
			p1.Y() += dy;
			p1.Z() += dz;
		}

		void Transform
		(
			const typename transform_point_type<Point>::type& theTrasf
		)
		{
			P0().Transform(theTrasf);
			P1().Transform(theTrasf);
		}

		void Get(Point& theP0, Point& theP1)
		{
			theP0 = P0();
			theP1 = P1();
		}

		void GetBound
		(
			const Standard_Integer theIndex,
			Standard_Real& theLower,
			Standard_Real& theUpper
		) const
		{
			theLower = P0().Coord(theIndex + 1);
			theUpper = P1().Coord(theIndex + 1);
		}

		template<class U = void>
		resolvedType<is_two_dimension<(int)Point::dim>::value, U>
			Length
			(
				Standard_Real& dx, 
				Standard_Real& dy
			) const
		{
			dx = P1().X() - P0().X();
			dy = P1().Y() - P0().Y();
		}

		template<class U = void>
		resolvedType<is_three_dimension<(int)Point::dim>::value, U>
			Length
			(
				Standard_Real& dx,
				Standard_Real& dy,
				Standard_Real& dz
			) const
		{
			dx = P1().X() - P0().X();
			dy = P1().Y() - P0().Y();
			dz = P1().Z() - P0().Z();
		}

		void SetP0(const Point& theP0)
		{
			P0() = theP0;
		}

		void SetP1(const Point& theP1)
		{
			P1() = theP1;
		}

		void Init
		(
			const Point& theP0,
			const Point& theP1
		)
		{
			P0() = theP0;
			P1() = theP1;
		}

		void Print(std::ostream& os) const
		{
			os << *this;
		}

		//- Static functions and members

		static Entity_Box Box
		(
			const Point& theCentre,
			const Standard_Real theRadius
		)
		{
			return Entity_Box(theCentre - theRadius, theCentre + theRadius);
		}

		static Entity_Box Union(const Entity_Box& theBox0, const Entity_Box& theBox1);

		static Entity_Box BoundingBoxOf(const std::vector<Point>& thePts);

		static Entity_Box BoundingBoxOf(const Point& P0, const Point& P1);

		static Standard_Boolean IsInside(const Entity_Box& theInner, const Entity_Box& theBox);

		// IO functions and operators

		void ExportToPlt(OFstream& theFile) const;
	};
}

#include <Entity_BoxI.hxx>

#endif // !_Entity_Box_Header
