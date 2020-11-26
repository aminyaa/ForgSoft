#pragma once
#ifndef _preservePatchTypes_Header
#define _preservePatchTypes_Header

#include <fileName.hxx>
#include <wordList.hxx>
#include <dictionary.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class objectRegistry;

	//- preserve patch types
	void preservePatchTypes
	(
		const objectRegistry& obr,
		const word& meshInstance,
		const fileName& meshDir,
		const wordList& patchNames,
		PtrList<dictionary>& patchDicts,
		const word& defaultFacesName,
		word& defaultFacesType
	);

	//- preserve patch types
	void preservePatchTypes
	(
		const objectRegistry& obr,
		const word& meshInstance,
		const fileName& meshDir,
		const wordList& patchNames,
		wordList& patchTypes,
		const word& defaultFacesName,
		word& defaultFacesType,
		wordList& patchPhysicalTypes
	);

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_preservePatchTypes_Header
