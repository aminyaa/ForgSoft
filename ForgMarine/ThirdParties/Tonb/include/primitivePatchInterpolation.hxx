#pragma once
#ifndef _primitivePatchInterpolation_Header
#define _primitivePatchInterpolation_Header

#include <PrimitivePatchInterpolationTemplate.hxx>
#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <SubList.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef PrimitivePatchInterpolation
		<
		PrimitivePatch<face, SubList, const pointField&>
		>   primitivePatchInterpolation;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_primitivePatchInterpolation_Header
