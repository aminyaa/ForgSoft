#pragma once
#ifndef _PriorityList_Header
#define _PriorityList_Header

#include <labelList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							  Class PriorityList Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class PriorityList
	{
		// Private data

			//- Indices into weights
		labelList indices_;

		//- Weights
		List<Type> weights_;

		//- Sorted indices
		labelList sortedIndices_;

		//- Active size
		label size_;

		//- Is the list sorted?
		mutable bool listSorted_;


		// Private static functions

			//- Greater element comparison
		inline static bool greater(const Type& a, const Type& b)
		{
			return a > b;
		}


		// Private Member Functions

			//- Disallow default bitwise copy construct
		PriorityList(const PriorityList<Type>&);

		//- Disallow default bitwise assignment
		void operator=(const PriorityList<Type>&);


		//- Sort list
		void sortList();

		//- Bisection sort
		void bisectionSort(const label startIndex);

		//- Sort upwards using bisection with root i
		void sortUpwards(const label startIndex);


	public:

		// Constructors

			//- Construct given capacity
		PriorityList(const label capacity);


		// Destructor - default


		// Member Functions

			//- Return size
		label size() const
		{
			return size_;
		}

		//- Is the list empty?
		bool empty() const
		{
			return size_ <= 0;
		}

		//- Return indices
		const labelList& indices() const
		{
			return indices_;
		}

		//- Return weights
		const List<Type>& weights() const
		{
			return weights_;
		}


		//- Return index with highest weight and remove
		label removeHead();

		//- Set element with weight
		void set(const label i, const Type& value);

		//- Update weight
		void updateWeight(const label i, const Type& newWeight);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <PriorityListI.hxx>

#ifdef NoRepository
#   include <PriorityList.cxx>
#endif

#endif // !_PriorityList_Header
