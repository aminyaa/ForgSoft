#pragma once
#ifndef _primitiveFacePatch_Header
#define _primitiveFacePatch_Header

#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <List.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef PrimitivePatch<face, List, const pointField&>
		primitiveFacePatch;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_primitiveFacePatch_Header
