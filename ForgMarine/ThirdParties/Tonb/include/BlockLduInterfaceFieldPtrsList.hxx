#pragma once
#ifndef _BlockLduInterfaceFieldPtrsList_Header
#define _BlockLduInterfaceFieldPtrsList_Header

#include <BlockLduInterfaceField.hxx>
#include <UPtrList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<class T>
	struct BlockLduInterfaceFieldPtrsList
	{
		typedef UPtrList<const BlockLduInterfaceField<T> > Type;
	};

	template<class T>
	struct BlockLduInterfaceFieldPtrsListList
	{
		typedef List<typename BlockLduInterfaceFieldPtrsList<T>::Type> Type;
	};

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockLduInterfaceFieldPtrsList_Header
