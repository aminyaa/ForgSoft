#pragma once
#ifndef _cellShapeList_Header
#define _cellShapeList_Header

#include <cellShape.hxx>
#include <List.hxx>
#include <PtrList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef List<cellShape> cellShapeList;
	typedef PtrList<cellShapeList> cellShapeListList;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cellShapeList_Header
