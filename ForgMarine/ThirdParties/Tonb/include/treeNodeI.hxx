#pragma once
// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

// Get type of octant
template <class Type>
tnbLib::label tnbLib::treeNode<Type>::getVolType(const label octant) const
{
	return (volType_ >> 2 * octant) & 0x3;
}


template <class Type>
const tnbLib::point& tnbLib::treeNode<Type>::midpoint() const
{
	return mid_;
}


template <class Type>
tnbLib::treeElem<Type>* const* tnbLib::treeNode<Type>::subNodes() const
{
	return subNodes_;
}


// octant contains pointer to treeNode(1) or treeLeaf(0)
template <class Type>
tnbLib::label tnbLib::treeNode<Type>::isNode(const label octant) const
{
	return subNodeTypes_ & (0x1 << octant);
}


// Get pointer to sub node
template <class Type>
tnbLib::treeNode<Type>* tnbLib::treeNode<Type>::getNodePtr
(
	const label octant
) const
{
#   ifdef FULLDEBUG
	if (!isNode(octant))
	{
		FatalErrorIn("treeNode::getNodePtr(const label)")
			<< "not a treeNode"
			<< abort(FatalError);
	}
#   endif

	return static_cast<treeNode<Type>*>(subNodes_[octant]);
}


// Get pointer to sub leaf
template <class Type>
tnbLib::treeLeaf<Type>* tnbLib::treeNode<Type>::getLeafPtr
(
	const label octant
) const
{
#   ifdef FULLDEBUG
	if (isNode(octant))
	{
		FatalErrorIn("treeNode::getLeafPtr(const label)")
			<< "not a treeLeaf"
			<< abort(FatalError);
	}
#   endif

	return static_cast<treeLeaf<Type>*>(subNodes_[octant]);
}


// ************************************************************************* //