#pragma once
#ifndef _plane_Header
#define _plane_Header

#include <point.hxx>
#include <scalarList.hxx>
#include <dictionary.hxx>
#include <line.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class plane;
	bool operator==(const plane&, const plane&);
	bool operator!=(const plane&, const plane&);
	Ostream& operator<<(Ostream&, const plane&);


	/*---------------------------------------------------------------------------*\
							   Class plane Declaration
	\*---------------------------------------------------------------------------*/

	class plane
	{
	public:

		//- A direction and a reference point
		class ray
		{
			point refPoint_;

			vector dir_;

		public:

			ray(const point& refPoint, const vector& dir)
				:
				refPoint_(refPoint),
				dir_(dir)
			{}

			const point& refPoint() const
			{
				return refPoint_;
			}

			const vector& dir() const
			{
				return dir_;
			}
		};


	private:

		// Private data

			//- Plane normal
		vector unitVector_;

		//- Base point
		point basePoint_;


		// Private Member Functions

			//- Calculates basePoint and normal vector given plane coefficients
		void calcPntAndVec(const scalarList& C);

		//- Calculates basePoint and normal vector given three points
		//- Normal vector determined using right hand rule
		void calcPntAndVec
		(
			const point& point1,
			const point& point2,
			const point& point3
		);


	public:

		// Constructors

			//- Construct from normal vector through the origin
		plane(const vector& normalVector);

		//- Construct from normal vector and point in plane
		plane(const point& basePoint, const vector& normalVector);

		//- Construct from three points in plane
		plane(const point& point1, const point& point2, const point& point3);

		//- Construct from coefficients for the
		//  plane equation: ax + by + cz + d = 0
		plane(const scalarList& C);

		//- Construct from dictionary
		plane(const dictionary& planeDict);

		//- Construct from Istream. Assumes the base + normal notation.
		plane(Istream& is);


		// Member Functions

			//- Return plane normal
		const vector& normal() const;

		//- Return or return plane base point
		const point& refPoint() const;

		//- Return coefficients for the
		//  plane equation: ax + by + cz + d = 0
		scalarList planeCoeffs() const;

		//- Return nearest point in the plane for the given point
		point nearestPoint(const point& p) const;

		//- Return distance from the given point to the plane
		scalar distance(const point& p) const;

		//- Return cut coefficient for plane and line defined by
		//  origin and direction
		scalar normalIntersect(const point& pnt0, const vector& dir) const;

		//- Return cut coefficient for plane and ray
		scalar normalIntersect(const ray& r) const
		{
			return normalIntersect(r.refPoint(), r.dir());
		}

		//- Return the cutting point between the plane and
		// a line passing through the supplied points
		template<class Point, class PointRef>
		scalar lineIntersect(const line<Point, PointRef>& l) const
		{
			return normalIntersect(l.start(), l.vec());
		}

		//- Return the cutting line between this plane and another.
		//  Returned as direction vector and point line goes through.
		ray planeIntersect(const plane&) const;

		//- Return the cutting point between this plane and two other planes
		point planePlaneIntersect(const plane&, const plane&) const;


		// friend Operators

		friend bool operator==(const plane&, const plane&);
		friend bool operator!=(const plane&, const plane&);


		// IOstream Operators

			//- Write plane properties
		friend Ostream& operator<<(Ostream&, const plane&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_plane_Header
