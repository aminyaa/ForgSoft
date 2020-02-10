#pragma once
#ifndef _pointHitSort_Header
#define _pointHitSort_Header

#include <pointHit.hxx>
#include <label.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes

	/*---------------------------------------------------------------------------*\
							   Class pointHitSort Declaration
	\*---------------------------------------------------------------------------*/

	class pointHitSort
	{
		// Private data

			//- intersection
		pointHit inter_;

		//- original index
		label index_;

	public:

		// Constructors

			//- Construct null
		pointHitSort()
			:
			inter_(false, vector::zero, GREAT),
			index_(-1)
		{}

		//- Construct from intersection, index
		pointHitSort(const pointHit& inter, const label index)
			:
			inter_(inter),
			index_(index)
		{}


		// Member Functions

		const pointHit& inter() const
		{
			return inter_;
		}

		label index() const
		{
			return index_;
		}

		// Member Operators

		bool operator==(const pointHitSort& rhs) const
		{
			return inter_.distance() == rhs.inter().distance();
		}

		bool operator>(const pointHitSort& rhs) const
		{
			return inter_.distance() > rhs.inter().distance();
		}

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointHitSort_Header
