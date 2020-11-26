#pragma once
#ifndef _Stack_Header
#define _Stack_Header

#include <label.hxx>
#include <dynamicLabelList.hxx>
#include <multiThreader.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class Stack Declaration
	\*---------------------------------------------------------------------------*/

	class Stack
	{
		// Private data

			//- Internal list
		dynamicLabelList stack_;

		//- Mutex for multi-threading
		Mutex stackMutex_;

	public:

		// Constructor
		Stack() {}

		// Member functions for access to the stack

			//- Push items on to the stack
		void push(const label index);

		//- Insert item onto stack
		void insert(const label index);

		//- Pop an item off the stack
		label pop();

		//- Remove a specific index off the stack
		void remove(const label index);

		//- Return if a stack is empty or not
		bool empty();

		//- Return the size of the stack
		label size();

		//- Clear out the stack
		void clear();

		//- Print out the stack
		void print();

		//- Access the stack as a list
		label operator[](const label index);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <StackI.hxx>

#endif // !_Stack_Header
