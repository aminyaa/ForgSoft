#pragma once
#ifndef _edge_Header
#define _edge_Header

#include <FixedList.hxx>
#include <pointField.hxx>
#include <linePointRef.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class edge;
	inline bool operator==(const edge& a, const edge& b);
	inline bool operator!=(const edge& a, const edge& b);


	/*---------------------------------------------------------------------------*\
							   Class edge Declaration
	\*---------------------------------------------------------------------------*/

	class edge
		: public FixedList<label, 2>
	{

	public:

		// Static data members

		static const char* const typeName;


		// Constructors

			//- Null constructor for lists
		edge();

		//- Constructor given size
		//  Nasty hack for consistency in creation of edges/faces/cells
		//  HJ, 6/Nov/2010
		explicit edge(const label size);

		//- Construct from components
		edge(const label a, const label b);

		//- Construct from FixedList
		edge(const FixedList<label, 2>&);

		//- Construct from Istream
		edge(Istream&);


		// Member Functions

			//- Return start vertex label
		label start() const;

		//- Return start vertex label
		label& start();

		//- Return end vertex label
		label end() const;

		//- Return end vertex label
		label& end();

		//- Given one vertex, return the other
		label otherVertex(const label a) const;

		//- Return common vertex
		label commonVertex(const edge& a) const;

		//- Return reverse edge
		edge reverseEdge() const;

		//- Return centre (centroid)
		point centre(const pointField&) const;

		//- Return the vector (end - start)
		vector vec(const pointField&) const;

		//- Return scalar magnitude
		scalar mag(const pointField&) const;

		//- Return edge line
		linePointRef line(const pointField&) const;

		//- compare edges
		//  -  0: different
		//  - +1: identical
		//  - -1: same edge, but different orientation
		static int compare(const edge&, const edge&);


		// Friend Operators

		friend bool operator==(const edge& a, const edge& b);
		friend bool operator!=(const edge& a, const edge& b);
	};


	//- Hash specialization for hashing edges - a commutative hash value.
	//  Hash incrementally.
	template<>
	inline unsigned Hash<edge>::operator()(const edge& e, unsigned seed) const
	{
		unsigned val = seed;

		if (e[0] < e[1])
		{
			val = Hash<label>()(e[0], val);
			val = Hash<label>()(e[1], val);
		}
		else
		{
			val = Hash<label>()(e[1], val);
			val = Hash<label>()(e[0], val);
		}

		return val;
	}


	//- Hash specialization for hashing edges - a commutative hash value.
	//  Hash incrementally.
	template<>
	inline unsigned Hash<edge>::operator()(const edge& e) const
	{
		return Hash<edge>()(e, 0);
	}


	template<>
	inline bool contiguous<edge>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <edgeI.hxx>

#endif // !_edge_Header
