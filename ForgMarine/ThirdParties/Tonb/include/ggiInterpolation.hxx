#pragma once
#ifndef _ggiInterpolation_Header
#define _ggiInterpolation_Header

#include <GGIInterpolationTemplate.hxx>
#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <SubList.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef GGIInterpolation
		<
		PrimitivePatch<face, SubList, const pointField&>,
		PrimitivePatch<face, SubList, const pointField&>
		>   ggiInterpolation;

	typedef GGIInterpolation
		<
		PrimitivePatch<face, List, const pointField&>,
		PrimitivePatch<face, List, const pointField&>
		>   ggiZoneInterpolation;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ggiInterpolation_Header
