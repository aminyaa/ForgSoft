#pragma once
#ifndef _IOpatchToPatchInterpolation_Header
#define _IOpatchToPatchInterpolation_Header

#include <IOPatchToPatchInterpolationTemplate.hxx>
#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <SubList.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef IOPatchToPatchInterpolation
		<
		PrimitivePatch<face, SubList, const pointField&>,
		PrimitivePatch<face, SubList, const pointField&>
		>   IOpatchToPatchInterpolation;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_IOpatchToPatchInterpolation_Header
