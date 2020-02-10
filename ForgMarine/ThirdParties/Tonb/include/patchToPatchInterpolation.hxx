#pragma once
#ifndef _patchToPatchInterpolation_Header
#define _patchToPatchInterpolation_Header

#include <PatchToPatchInterpolationTemplate.hxx>
#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <SubList.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef PatchToPatchInterpolation
		<
		PrimitivePatch<face, SubList, const pointField&>,
		PrimitivePatch<face, SubList, const pointField&>
		>   patchToPatchInterpolation;

	typedef PatchToPatchInterpolation
		<
		PrimitivePatch<face, List, const pointField&>,
		PrimitivePatch<face, List, const pointField&>
		>   zoneToZoneInterpolation;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_patchToPatchInterpolation_Header
