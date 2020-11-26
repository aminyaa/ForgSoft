#pragma once
#ifndef _primitivePatch_Header
#define _primitivePatch_Header

#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <SubList.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef PrimitivePatch<face, SubList, const pointField&>
		primitivePatch;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_primitivePatch_Header
