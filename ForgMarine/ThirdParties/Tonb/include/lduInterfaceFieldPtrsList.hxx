#pragma once
#ifndef _lduInterfaceFieldPtrsList_Header
#define _lduInterfaceFieldPtrsList_Header

#include <lduInterfaceField.hxx>
#include <UPtrList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef UPtrList<const lduInterfaceField> lduInterfaceFieldPtrsList;
	typedef List<lduInterfaceFieldPtrsList> lduInterfaceFieldPtrsListList;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_lduInterfaceFieldPtrsList_Header
