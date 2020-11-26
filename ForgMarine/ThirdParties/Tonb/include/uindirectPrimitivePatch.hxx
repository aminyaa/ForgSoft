#pragma once
#ifndef _uindirectPrimitivePatch_Header
#define _uindirectPrimitivePatch_Header

#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <UIndirectList.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef PrimitivePatch<face, UIndirectList, const pointField&>
		uindirectPrimitivePatch;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_uindirectPrimitivePatch_Header
