#pragma once
#ifndef _refCount_Header
#define _refCount_Header

#include <bool.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class refCount Declaration
\*---------------------------------------------------------------------------*/

	class refCount
	{
		// Private data

		int count_;

		// Private member functions

			//- Dissallow copy
		refCount(const refCount&);

		//- Dissallow bitwise assignment
		void operator=(const refCount&);


	public:

		// Constructors

		//- Construct null with zero count
		refCount()
			:
			count_(0)
		{}


		// Member Functions

			//- Return the reference count
		int count() const
		{
			return count_;
		}


		//- Return true if the reference count is zero
		bool okToDelete() const
		{
			return !count_;
		}


		//- Reset the reference count to zero
		void resetRefCount()
		{
			count_ = 0;
		}


		// Member Operators

			//- Increment the reference count
		void operator++()
		{
			count_++;
		}

		//- Increment the reference count
		void operator++(int)
		{
			count_++;
		}

		//- Decrement the reference count
		void operator--()
		{
			count_--;
		}

		//- Decrement the reference count
		void operator--(int)
		{
			count_--;
		}
	};

}

#endif // !_refCount_Header
