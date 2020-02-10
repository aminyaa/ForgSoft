#pragma once
#ifndef _overlapGgiInterpolation_Header
#define _overlapGgiInterpolation_Header

#include <GGIInterpolationTemplate.hxx>
#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <List.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef GGIInterpolation
		<
		PrimitivePatch<face, List, pointField>,
		PrimitivePatch<face, List, pointField>
		>   overlapGgiInterpolation;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_overlapGgiInterpolation_Header
