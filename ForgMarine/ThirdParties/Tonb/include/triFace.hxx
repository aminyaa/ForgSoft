#pragma once
#ifndef _triFace_Header
#define _triFace_Header

#include <FixedList.hxx>
#include <edgeList.hxx>
#include <pointHit.hxx>
#include <intersection.hxx>
#include <pointField.hxx>
#include <triPointRef.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class face;

	// Forward declaration of friend functions and operators

	class triFace;
	inline bool operator==(const triFace&, const triFace&);
	inline bool operator!=(const triFace&, const triFace&);


	/*---------------------------------------------------------------------------*\
							  class triFace Declaration
	\*---------------------------------------------------------------------------*/

	class triFace
		: public FixedList<label, 3>
	{

	public:

		// Constructors

			//- Construct null
		triFace();

		//- Construct from three point labels
		triFace
		(
			const label a,
			const label b,
			const label c
		);

		//- Construct from a UList<label>
		explicit triFace(const UList<label>&);

		//- Construct from Istream
		triFace(Istream&);


		// Member Functions

			//- Collapse face by removing duplicate point labels
			//  return the collapsed size, set collapsed point labels to -1
		label collapse();

		//- Return the edge direction on the face
		//  - +1: forward (counter-clockwise) on the face
		//  - -1: reverse (clockwise) on the face
		//  -  0: edge not found on the face
		int edgeDirection(const edge&) const;


		// Properties

			//- Return the points corresponding to this face
		pointField points(const pointField& points) const;

		//- Return triangle as a face
		face triFaceFace() const;

		//- Return number of edges
		label nEdges() const;

		//- Return edges
		edgeList edges() const;

		//- Return centre (centroid)
		point centre(const pointField&) const;

		//- Return scalar magnitude
		scalar mag(const pointField&) const;

		//- Return vector normal
		vector normal(const pointField&) const;

		//- Number of triangles after splitting
		label nTriangles() const;

		//- Return face with reverse direction
		triFace reverseFace() const;

		//- Return swept-volume
		scalar sweptVol
		(
			const pointField& oldPoints,
			const pointField& newPoints
		) const;

		//- Return point intersection with a ray starting at p, with
		//  direction n.
		pointHit ray
		(
			const point& p,
			const vector& q,
			const pointField& points,
			const intersection::algorithm = intersection::FULL_RAY,
			const intersection::direction dir = intersection::VECTOR
		) const;

		//- Return contact sphere diameter
		scalar contactSphereDiameter
		(
			const point& p,
			const vector& n,
			const pointField& meshPoints
		) const;

		//- Return the triangle
		triPointRef tri(const pointField&) const;

		//- compare triFaces
		//  -  0: different
		//  - +1: identical
		//  - -1: same face, but different orientation
		static int compare(const triFace&, const triFace&);

		// Friend Operators

		friend bool operator==(const triFace&, const triFace&);
		friend bool operator!=(const triFace&, const triFace&);
	};


	//- Hash specialization for hashing triFace - a commutative hash value.
	//  Hash incrementally.
	template<>
	inline unsigned Hash<triFace>::operator()
		(
			const triFace& t,
			unsigned seed
			) const
	{
		// Fortunately we don't need this very often
		const uLabel t0(t[0]);
		const uLabel t1(t[1]);
		const uLabel t2(t[2]);

		const uLabel val = (t0*t1*t2 + t0 + t1 + t2);

		return Hash<uLabel>()(val, seed);
	}


	//- Hash specialization for hashing triFace - a commutative hash value.
	//  Hash incrementally.
	template<>
	inline unsigned Hash<triFace>::operator()(const triFace& t) const
	{
		return Hash<triFace>::operator()(t, 0);
	}


	template<>
	inline bool contiguous<triFace>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <triFaceI.hxx>

#endif // !_triFace_Header
