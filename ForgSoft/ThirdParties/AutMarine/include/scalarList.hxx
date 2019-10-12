#pragma once
#ifndef _scalarList_Header
#define _scalarList_Header

#include <scalar.hxx>
#include <List.hxx>

namespace AutLib
{
	typedef List<scalar> scalarList;
	typedef List<scalarList> scalarListList;
	typedef List<scalarListList> scalarListListList;
}

#endif // !_scalarList_Header