#pragma once
#include <Swap.hxx>

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

template<class Type>
void tnbLib::PriorityList<Type>::sortList()
{
	// Reset indices and sorted indices
	for (label i = 0; i < size_; i++)
	{
		indices_[i] = i;
		sortedIndices_[i] = i;
	}

	for (label i = size_ / 2 - 1; i >= 0; i--)
	{
		this->bisectionSort(i);
	}

	listSorted_ = true;
}


template<class Type>
void tnbLib::PriorityList<Type>::bisectionSort(const label startIndex)
{
	label i = startIndex;

	for (;;)
	{
		// Find largest node and left and right children
		label n = i;
		label il = 2 * i + 1;
		label ir = il + 1;

		if
			(
				il < size_
				&& greater(weights_[indices_[il]], weights_[indices_[n]])
				)
		{
			n = il;
		}

		if
			(
				ir < size_
				&& greater(weights_[indices_[ir]], weights_[indices_[n]])
				)
		{
			n = ir;
		}

		// End of bisection
		if (n == i) break;

		// Swap i with largest n
		tnbLib::Swap(indices_[i], indices_[n]);

		// Swap positions in sorted index list
		sortedIndices_[indices_[i]] = i;
		sortedIndices_[indices_[n]] = n;

		// Update for next position
		i = n;
	}
}


template<class Type>
void tnbLib::PriorityList<Type>::sortUpwards(const label startIndex)
{
	// Set root
	label i = startIndex;

	label n = (i - 1) / 2;

	while (i > 0 && greater(weights_[indices_[i]], weights_[indices_[n]]))
	{
		// Swap node i and n if not in proper order
		tnbLib::Swap(indices_[i], indices_[n]);

		// Swap positions in sorted index list
		sortedIndices_[indices_[i]] = i;
		sortedIndices_[indices_[n]] = n;

		// Update for next position
		i = n;
		n = (i - 1) / 2;
	}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

// Construct given capacity
template<class Type>
tnbLib::PriorityList<Type>::PriorityList(const label capacity)
	:
	indices_(capacity),
	weights_(capacity),
	sortedIndices_(capacity),
	size_(capacity),
	listSorted_(false)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
tnbLib::label tnbLib::PriorityList<Type>::removeHead()
{
	if (!listSorted_)
	{
		this->sortList();
	}

	label maxIndex = indices_[0];

	if (--size_ > 0)
	{
		tnbLib::Swap(indices_[0], indices_[size_]);
		sortedIndices_[indices_[0]] = 0;
		this->bisectionSort(0);
	}

	return maxIndex;
}


template<class Type>
void tnbLib::PriorityList<Type>::set
(
	const label i,
	const Type& value
)
{
	weights_[i] = value;

	// List is no longer sorted
	listSorted_ = false;
}


template<class Type>
void tnbLib::PriorityList<Type>::updateWeight
(
	const label i,
	const Type& newWeight
)
{
	if (!listSorted_)
	{
		this->sortList();
	}

	Type delta = newWeight - weights_[i];

	weights_[i] = newWeight;

	if (greater(delta, pTraits<Type>::zero))
	{
		this->sortUpwards(sortedIndices_[i]);
	}
	else
	{
		this->bisectionSort(sortedIndices_[i]);
	}
}


// ************************************************************************* //