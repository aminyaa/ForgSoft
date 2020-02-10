#pragma once
#ifndef _bandCompression_Header
#define _bandCompression_Header

#include <labelList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	//- Renumbers the addressing to reduce the band of the matrix.
	//  The algorithm uses a simple search through the neighbour list
	labelList bandCompression(const labelListList& addressing);

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_bandCompression_Header
