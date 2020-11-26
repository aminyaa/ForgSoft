#pragma once
#ifndef _primitiveFaceZone_Header
#define _primitiveFaceZone_Header

#include <face.hxx>
#include <PrimitivePatchTemplate.hxx>
#include <indirectFaceList.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef PrimitivePatch<face, IndirectList, const pointField&>
		primitiveFaceZone;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_primitiveFaceZone_Header
