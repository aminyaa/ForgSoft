#pragma once
#ifndef _dlLibraryTable_Header
#define _dlLibraryTable_Header

#include <label.hxx>
#include <Hash.hxx>
#include <HashTable.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class dlLibraryTable Declaration
\*---------------------------------------------------------------------------*/

	class dlLibraryTable
		: public HashTable<fileName, void*, Hash<void*>>
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		dlLibraryTable(const dlLibraryTable&);

		//- Disallow default bitwise assignment
		void operator=(const dlLibraryTable&);


	public:

		// Static data members

			//- Static data someStaticData
		static dlLibraryTable loadedLibraries;


		// Public classes

			//- Class whose construction causes the reading of dynamic libraries
		class readDlLibrary
		{
		public:

			//- Read all the libraries listed in the 'libsEntry' entry in the
			//  given dictionary if present
			readDlLibrary(const dictionary&, const word& libsEntry);
		};


		// Constructors

			//- Construct null
		dlLibraryTable();


		// Destructor

		~dlLibraryTable();


		// Member Functions

			//- Open the named library
		static bool open(const fileName& name);

		//- Open all the libraries listed in the 'libsEntry' entry in the
		//  given dictionary if present
		static bool open(const dictionary&, const word& libsEntry);

		//- Open all the libraries listed in the 'libsEntry' entry in the
		//  given dictionary if present and check the additions
		//  to the give constructor table
		template<class TablePtr>
		static bool open
		(
			const dictionary&,
			const word& libsEntry,
			const TablePtr& tablePtr
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#ifdef NoRepository
#   include <dlLibraryTableTemplates.cxx>
#endif

#endif // !_dlLibraryTable_Header
