#pragma once
#ifndef _lduInterfacePtrsList_Header
#define _lduInterfacePtrsList_Header

#include <lduInterface.hxx>
#include <UPtrList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef UPtrList<const lduInterface> lduInterfacePtrsList;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_lduInterfacePtrsList_Header
