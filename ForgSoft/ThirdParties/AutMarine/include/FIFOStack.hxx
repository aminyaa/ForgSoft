#pragma once
#ifndef _FIFOStack_Header
#define _FIFOStack_Header

#include <SLList.hxx>

namespace AutLib
{

	template<class T>
	class FIFOStack
		: public SLList<T>
	{

	public:

		// Constructors

		//- Construct null
		FIFOStack()
		{}

		//- Construct given initial T
		FIFOStack(T a)
			: SLList<T>(a)
		{}

		//- Construct from Istream
		FIFOStack(Istream& is)
			: SLList<T>(is)
		{}

		// Member Functions

		// Access

		//- Return a copy of the top element
		T top() const
		{
			return this->last();
		}

		//- Return a copy of the bottom element
		T bottom() const
		{
			return this->first();
		}

		// Edit

		//- Push an element onto the stack
		void push(const T& a)
		{
			this->append(a);
		}

		//- Pop the bottom element off the stack
		T pop()
		{
			return this->removeHead();
		}
	};
}

#endif // !_FIFOStack_Header
