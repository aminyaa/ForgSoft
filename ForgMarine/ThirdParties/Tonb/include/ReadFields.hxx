#pragma once
#ifndef _ReadFields_Header
#define _ReadFields_Header

#include <PtrList.hxx>
#include <wordList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class IOobjectList;

	//- Helper routine to read fields
	template<class GeoField, class Mesh>
	wordList ReadFields
	(
		const Mesh& mesh,
		const IOobjectList& objects,
		PtrList<GeoField>& fields,
		const bool syncPar = true
	);

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <ReadFields.cxx>
#endif

#endif // !_ReadFields_Header
