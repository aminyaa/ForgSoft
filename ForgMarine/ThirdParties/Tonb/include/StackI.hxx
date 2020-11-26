#pragma once
#include <ListOps.hxx>
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	// Push items on to the stack
	void Stack::push(const label index)
	{
		stackMutex_.lock();

		if (findIndex(stack_, index) == -1)
		{
			stack_.append(index);
		}

		stackMutex_.unlock();
	}


	//- Insert item onto stack (no checking)
	void Stack::insert(const label index)
	{
		stack_.append(index);
	}


	// Pop an item off the stack
	label Stack::pop()
	{
		stackMutex_.lock();

		const label index = stack_.remove();

		stackMutex_.unlock();

		return index;
	}


	// Remove a specific item off the stack
	void Stack::remove(const label index)
	{
		stackMutex_.lock();

		label loc = findIndex(stack_, index);

		if (loc != -1)
		{
			// Create a new list
			labelList newList(stack_.size() - 1);

			label n = 0;

			// Copy items upto location
			for (label i = 0; i < loc; i++)
			{
				newList[n++] = stack_[i];
			}

			// Copy items from location
			for (label i = (loc + 1); i < stack_.size(); i++)
			{
				newList[n++] = stack_[i];
			}

			// Overwrite
			stack_ = newList;
		}

		stackMutex_.unlock();
	}


	// Return if the stack is empty or not
	bool Stack::empty()
	{
		return (stack_.size() == 0);
	}


	//- Return the size of the stack
	label Stack::size()
	{
		return stack_.size();
	}


	//- Clear out the stack
	void Stack::clear()
	{
		stackMutex_.lock();

		stack_.clear();

		stackMutex_.unlock();
	}


	//- Print out the stack
	void Stack::print()
	{
		Info << stack_ << endl;
	}


	//- Access the stack as a list
	label Stack::operator[]
	(
		const label index
		)
	{
		return stack_[index];
	}

} // End namespace tnbLib

// ************************************************************************* //
