#pragma once
template<class ListType>
ListType AutLib::renumber
(
	const UList<label>& oldToNew,
	const ListType& lst
)
{
	// Create copy
	ListType newLst(lst.size());

	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (lst[elemI] >= 0)
		{
			newLst[elemI] = oldToNew[lst[elemI]];
		}
	}

	return newLst;
}


template<class ListType>
void AutLib::inplaceRenumber
(
	const UList<label>& oldToNew,
	ListType& lst
)
{
	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (lst[elemI] >= 0)
		{
			lst[elemI] = oldToNew[lst[elemI]];
		}
	}
}


template<class ListType>
ListType AutLib::reorder
(
	const UList<label>& oldToNew,
	const ListType& lst
)
{
	// Create copy
	ListType newLst(lst.size());

	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (oldToNew[elemI] >= 0)
		{
			newLst[oldToNew[elemI]] = lst[elemI];
		}
		else
		{
			newLst[elemI] = lst[elemI];
		}
	}
	return newLst;
}


template<class ListType>
void AutLib::inplaceReorder
(
	const UList<label>& oldToNew,
	ListType& lst
)
{
	// Create copy
	ListType newLst(lst.size());

	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (oldToNew[elemI] >= 0)
		{
			newLst[oldToNew[elemI]] = lst[elemI];
		}
		else
		{
			newLst[elemI] = lst[elemI];
		}
	}

	lst.transfer(newLst);
}


template<class Container>
void AutLib::inplaceMapValue
(
	const UList<label>& oldToNew,
	Container& lst
)
{
	for (typename Container::iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		if (iter() >= 0)
		{
			iter() = oldToNew[iter()];
		}
	}
}


template<class Container>
void AutLib::inplaceMapKey
(
	const UList<label>& oldToNew,
	Container& lst
)
{
	Container newLst(lst.size());

	for (typename Container::iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		if (iter.key() >= 0)
		{
			newLst.insert(oldToNew[iter.key()], iter());
		}
	}

	lst.transfer(newLst);
}


template<class T>
void AutLib::sortedOrder
(
	const UList<T>& lst,
	labelList& order
)
{
	// list lengths must be identical
	if (order.size() != lst.size())
	{
		// avoid copying any elements, they are overwritten anyhow
		order.clear();
		order.setSize(lst.size());
	}

	for (AutLib::label elemI = 0; elemI < (order).size(); elemI++)
	{
		order[elemI] = elemI;
	}
	AutLib::stableSort(order, typename UList<T>::less(lst));
}


template<class T>
void AutLib::duplicateOrder
(
	const UList<T>& lst,
	labelList& order
)
{
	if (lst.size() < 2)
	{
		order.clear();
		return;
	}

	sortedOrder(lst, order);

	label n = 0;
	for (label i = 0; i < order.size() - 1; ++i)
	{
		if (lst[order[i]] == lst[order[i + 1]])
		{
			order[n++] = order[i];
		}
	}
	order.setSize(n);
}


template<class T>
void AutLib::uniqueOrder
(
	const UList<T>& lst,
	labelList& order
)
{
	sortedOrder(lst, order);

	if (order.size() > 1)
	{
		label n = 0;
		for (label i = 0; i < order.size() - 1; ++i)
		{
			if (lst[order[i]] != lst[order[i + 1]])
			{
				order[n++] = order[i];
			}
		}
		order.setSize(n);
	}
}


template<class T, class ListType>
ListType AutLib::subset
(
	const UList<T>& select,
	const T& value,
	const ListType& lst
)
{
	// select must at least cover the list range
	if (select.size() < lst.size())
	{
		FatalErrorIn("subset(const UList<T>&, const T&, const ListType&)")
			<< "select is of size " << select.size()
			<< "; but it must index a list of size " << lst.size()
			<< abort(FatalError);
	}

	ListType newLst(lst.size());

	label nElem = 0;
	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (select[elemI] == value)
		{
			newLst[nElem++] = lst[elemI];
		}
	}
	newLst.setSize(nElem);

	return newLst;
}


template<class T, class ListType>
void AutLib::inplaceSubset
(
	const UList<T>& select,
	const T& value,
	ListType& lst
)
{
	// select must at least cover the list range
	if (select.size() < lst.size())
	{
		FatalErrorIn("inplaceSubset(const UList<T>&, const T&, ListType&)")
			<< "select is of size " << select.size()
			<< "; but it must index a list of size " << lst.size()
			<< abort(FatalError);
	}

	label nElem = 0;
	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (select[elemI] == value)
		{
			if (nElem != elemI)
			{
				lst[nElem] = lst[elemI];
			}
			++nElem;
		}
	}

	lst.setSize(nElem);
}


template<class BoolListType, class ListType>
ListType AutLib::subset
(
	const BoolListType& select,
	const ListType& lst
)
{
	// select can have a different size
	// eg, when it is a PackedBoolList or a labelHashSet

	ListType newLst(lst.size());

	label nElem = 0;
	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (select[elemI])
		{
			newLst[nElem++] = lst[elemI];
		}
	}
	newLst.setSize(nElem);

	return newLst;
}


template<class BoolListType, class ListType>
void AutLib::inplaceSubset
(
	const BoolListType& select,
	ListType& lst
)
{
	// select can have a different size
	// eg, when it is a PackedBoolList or a labelHashSet

	label nElem = 0;
	for (label elemI = 0; elemI < (lst).size(); elemI++)
	{
		if (select[elemI])
		{
			if (nElem != elemI)
			{
				lst[nElem] = lst[elemI];
			}
			++nElem;
		}
	}

	lst.setSize(nElem);
}


// As clarification:
// coded as inversion from pointEdges to edges but completely general.
template<class InList, class OutList>
void AutLib::invertManyToMany
(
	const label nEdges,
	const UList<InList>& pointEdges,
	List<OutList>& edges
)
{
	// Number of points per edge
	labelList nPointsPerEdge(nEdges, 0);

	for (label pointI = 0; pointI < (pointEdges).size(); pointI++)
	{
		const InList& pEdges = pointEdges[pointI];

		for (label j = 0; j < (pEdges).size(); j++)
		{
			nPointsPerEdge[pEdges[j]]++;
		}
	}

	// Size edges
	edges.setSize(nEdges);

	for (label edgeI = 0; edgeI < (nPointsPerEdge).size(); edgeI++)
	{
		edges[edgeI].setSize(nPointsPerEdge[edgeI]);
	}
	nPointsPerEdge = 0;

	// Fill edges
	for (label pointI = 0; pointI < (pointEdges).size(); pointI++)
	{
		const InList& pEdges = pointEdges[pointI];

		for (AutLib::label j = 0; j < (pEdges).size(); j++)
		{
			label edgeI = pEdges[j];

			edges[edgeI][nPointsPerEdge[edgeI]++] = pointI;
		}
	}
}


template<class ListType>
AutLib::label AutLib::findIndex
(
	const ListType& l,
	typename ListType::const_reference t,
	const label start
)
{
	label index = -1;

	for (label i = start; i < l.size(); i++)
	{
		if (l[i] == t)
		{
			index = i;
			break;
		}
	}

	return index;
}


template<class ListType>
AutLib::labelList AutLib::findIndices
(
	const ListType& l,
	typename ListType::const_reference t,
	const label start
)
{
	// Count occurrences
	label n = 0;

	for (label i = start; i < l.size(); i++)
	{
		if (l[i] == t)
		{
			n++;
		}
	}

	// Create and fill
	labelList indices(n);
	n = 0;

	for (label i = start; i < l.size(); i++)
	{
		if (l[i] == t)
		{
			indices[n++] = i;
		}
	}

	return indices;
}


template<class ListType>
void AutLib::setValues
(
	ListType& l,
	const UList<label>& indices,
	typename ListType::const_reference t
)
{
	for (AutLib::label i = 0; i < (indices).size(); i++)
	{
		l[indices[i]] = t;
	}
}


template<class ListType>
ListType AutLib::createWithValues
(
	const label sz,
	const typename ListType::const_reference initValue,
	const UList<label>& indices,
	typename ListType::const_reference setValue
)
{
	ListType l(sz, initValue);
	setValues(l, indices, setValue);
	return l;
}


template<class ListType>
AutLib::label AutLib::findMax(const ListType& l, const label start)
{
	if (start >= l.size())
	{
		return -1;
	}

	label index = start;

	for (label i = start + 1; i < l.size(); i++)
	{
		if (l[i] > l[index])
		{
			index = i;
		}
	}

	return index;
}


template<class ListType>
AutLib::label AutLib::findMin(const ListType& l, const label start)
{
	if (start >= l.size())
	{
		return -1;
	}

	label index = start;

	for (label i = start + 1; i < l.size(); i++)
	{
		if (l[i] < l[index])
		{
			index = i;
		}
	}

	return index;
}


template<class ListType>
AutLib::label AutLib::findSortedIndex
(
	const ListType& l,
	typename ListType::const_reference t,
	const label start
)
{
	if (start >= l.size())
	{
		return -1;
	}

	label low = start;
	label high = l.size() - 1;

	while (low <= high)
	{
		label mid = (low + high) / 2;

		if (t < l[mid])
		{
			high = mid - 1;
		}
		else if (t > l[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}


template<class ListType>
AutLib::label AutLib::findLower
(
	const ListType& l,
	typename ListType::const_reference t,
	const label start
)
{
	if (start >= l.size())
	{
		return -1;
	}

	label low = start;
	label high = l.size() - 1;

	while ((high - low) > 1)
	{
		label mid = (low + high) / 2;

		if (l[mid] < t)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}

	if (l[high] < t)
	{
		return high;
	}
	else
	{
		if (l[low] < t)
		{
			return low;
		}
		else
		{
			return -1;
		}
	}
}


template<class Container, class T, int nRows>
AutLib::List<Container> AutLib::initList(const T elems[nRows])
{
	List<Container> lst(nRows);

	for (label rowI = 0; rowI < (lst).size(); rowI++)
	{
		lst[rowI] = Container(elems[rowI]);
	}
	return lst;
}


template<class Container, class T, int nRows, int nColumns>
AutLib::List<Container> AutLib::initListList(const T elems[nRows][nColumns])
{
	List<Container> lst(nRows);

	Container cols(nColumns);

	for (label rowI = 0; rowI < (lst).size(); rowI++)
	{
		for (label colI = 0; colI < (cols).size(); colI++)
		{
			cols[colI] = elems[rowI][colI];
		}
		lst[rowI] = cols;
	}
	return lst;
}