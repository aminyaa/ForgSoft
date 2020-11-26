#pragma once
#ifndef _faceListFwd_Header
#define _faceListFwd_Header

#include <List.hxx>
#include <SubList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	class face;
	typedef UList<face> unallocFaceList;
	typedef List<face> faceList;
	typedef SubList<face> faceSubList;
	typedef List<faceList> faceListList;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_faceListFwd_Header
