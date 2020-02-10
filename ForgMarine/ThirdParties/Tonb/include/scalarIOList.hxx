#pragma once
#ifndef _scalarIOList_Header
#define _scalarIOList_Header

#include <scalarList.hxx>
#include <IOList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef IOList<scalar> scalarIOList;
	typedef IOList<scalarList> scalarListIOList;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarIOList_Header
