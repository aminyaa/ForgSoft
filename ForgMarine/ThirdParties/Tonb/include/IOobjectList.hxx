#pragma once
#ifndef _IOobjectList_Header
#define _IOobjectList_Header

#include <HashPtrTable.hxx>
#include <IOobject.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class IOobjectList Declaration
\*---------------------------------------------------------------------------*/

	class IOobjectList
		:
#ifndef SWIG
		public HashPtrTable<IOobject>
#else
		public HashPtrTable<IOobject, word, string_hash>
#endif
	{
		// Private Member Functions

			//- Disallow default bitwise assignment
		void operator=(const IOobjectList&);


	public:

		// Constructors

			//- Construct given an initial estimate for the number of entries
		explicit IOobjectList(const label nIoObjects = 128);

		//- Construct from objectRegistry and instance path
		IOobjectList
		(
			const objectRegistry& db,
			const fileName& instance,
			const fileName& local = ""
		);

		//- Construct as copy
		IOobjectList(const IOobjectList&);


		// Destructor

		~IOobjectList();


		// Member functions

			//- Add an IOobject to list
		bool add(IOobject&);

		//- Remove an IOobject from list
		bool remove(IOobject&);

		//- Lookup a given name and return IOobject ptr if found else NULL
		IOobject* lookup(const word& name) const;

		//- Return the list for all IOobjects of given class
		IOobjectList lookupClass(const word& className) const;

		//- Return the list of names of the IOobjects
		wordList names() const;

		//- Return the list of names of the IOobjects of given class
		wordList names(const word& className) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_IOobjectList_Header
