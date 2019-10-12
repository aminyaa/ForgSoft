#pragma once
#ifndef _LIFOStack_Header
#define _LIFOStack_Header

#include <SLList.hxx>

namespace AutLib
{

	template<class T>
	class LIFOStack
		: public SLList<T>
	{

	public:

		// Constructors

		//- Construct null
		LIFOStack()
		{}

		//- Construct given initial T
		LIFOStack(T a)
			: SLList<T>(a)
		{}

		//- Construct from Istream
		LIFOStack(Istream& is)
			: SLList<T>(is)
		{}

		// Member Functions

		// Access

		//- Return a copy of the top element
		T top() const
		{
			return this->first();
		}

		//- Return a copy of the bottom element
		T bottom() const
		{
			return this->last();
		}

		// Edit

		//- Push an element onto the stack
		void push(const T& a)
		{
			this->insert(a);
		}

		//- Pop the top element off the stack
		T pop()
		{
			return this->removeHead();
		}
	};
}

#endif // !_LIFOStack_Header
