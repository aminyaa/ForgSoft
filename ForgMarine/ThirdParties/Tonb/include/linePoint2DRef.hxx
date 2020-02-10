#pragma once
#ifndef _linePoint2DRef_Header
#define _linePoint2DRef_Header

#include <point2D.hxx>
#include <line.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef line<point2D, const point2D&> linePoint2DRef;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#endif // !_linePoint2DRef_Header
