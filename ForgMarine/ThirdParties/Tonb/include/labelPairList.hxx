#pragma once
#ifndef _labelPairList_Header
#define _labelPairList_Header

#include <labelPair.hxx>
#include <List.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef List<labelPair> labelPairList;
	typedef List<labelPairList> labelPairListList;
	typedef List<labelPairListList> labelPairListListList;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_labelPairList_Header
