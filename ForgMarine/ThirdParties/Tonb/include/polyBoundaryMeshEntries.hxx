#pragma once
#ifndef _polyBoundaryMeshEntries_Header
#define _polyBoundaryMeshEntries_Header

#include <regIOobject.hxx>
#include <PtrList.hxx>
#include <entry.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	class polyBoundaryMeshEntries
		: public regIOobject
		, public PtrList<entry>
	{

	public:

		//- Runtime type information
		TypeName("polyBoundaryMesh");


		// Constructors

		explicit polyBoundaryMeshEntries(const IOobject& io)
			:
			regIOobject(io),
			PtrList<entry>(readStream(typeName))
		{
			close();
		}


		// Member functions

		bool writeData(Ostream&) const
		{
			notImplemented("writeData(Ostream&) const");
			return false;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_polyBoundaryMeshEntries_Header
