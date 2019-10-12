#pragma once
#ifndef _refCount_Header
#define _refCount_Header

namespace AutLib
{

	class refCount
	{

		// Private data

		int count_;

		// Private member functions

		//- Dissallow copy
		refCount(const refCount&) = delete;

		//- Dissallow bitwise assignment
		void operator=(const refCount&) = delete;

	public:

		refCount()
			: count_(0)
		{}

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
