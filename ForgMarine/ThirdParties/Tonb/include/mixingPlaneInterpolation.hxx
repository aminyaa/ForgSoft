#pragma once
#ifndef _mixingPlaneInterpolation_Header
#define _mixingPlaneInterpolation_Header

#include <MixingPlaneInterpolationTemplate.hxx>
#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <SubList.hxx>
#include <pointField.hxx>
#include <polyPatch.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	typedef MixingPlaneInterpolation
		<
		PrimitivePatch<face, SubList, const pointField&>,
		PrimitivePatch<face, SubList, const pointField&>
		>   mixingPlaneInterpolation;

	typedef MixingPlaneInterpolation
		<
		PrimitivePatch<face, List, const pointField&>,
		PrimitivePatch<face, List, const pointField&>
		>   mixingPlaneZoneInterpolation;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_mixingPlaneInterpolation_Header
