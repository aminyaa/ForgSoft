#pragma once
#ifndef _pyramidPointFaceRef_Header
#define _pyramidPointFaceRef_Header

#include <point.hxx>
#include <face.hxx>
#include <pyramid.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef pyramid<point, const point&, const face&> pyramidPointFaceRef;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#endif // !_pyramidPointFaceRef_Header
