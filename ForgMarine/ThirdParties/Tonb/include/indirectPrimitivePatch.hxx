#pragma once
#ifndef _indirectPrimitivePatch_Header
#define _indirectPrimitivePatch_Header

#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <IndirectList.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef PrimitivePatch<face, IndirectList, const pointField&>
		indirectPrimitivePatch;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_indirectPrimitivePatch_Header
