#pragma once
#ifndef _vectorList_Header
#define _vectorList_Header

#include <vector.hxx>
#include <List.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef List<vector> vectorList;
	typedef List<vectorList> vectorListList;
	typedef List<vectorListList> vectorListListList;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_vectorList_Header
