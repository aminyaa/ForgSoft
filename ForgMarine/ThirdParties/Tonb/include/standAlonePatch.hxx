#pragma once
#ifndef _standAlonePatch_Header
#define _standAlonePatch_Header

#include <PrimitivePatchTemplate.hxx>
#include <face.hxx>
#include <List.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef PrimitivePatch<face, List, pointField> standAlonePatch;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_standAlonePatch_Header
