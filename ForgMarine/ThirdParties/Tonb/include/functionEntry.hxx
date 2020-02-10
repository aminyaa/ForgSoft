#pragma once
#ifndef _functionEntry_Header
#define _functionEntry_Header

#include <word.hxx>
#include <memberFunctionSelectionTables.hxx>

namespace tnbLib
{

	class primitiveEntry;
	class dictionary;

	/*---------------------------------------------------------------------------*\
							   Class functionEntry Declaration
	\*---------------------------------------------------------------------------*/

	class functionEntry
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		functionEntry(const functionEntry&);

		//- Disallow default bitwise assignment
		void operator=(const functionEntry&);


	public:

		// Member Function Selectors

		declareMemberFunctionSelectionTable
		(
			bool,
			functionEntry,
			execute,
			dictionaryIstream,
			(
				dictionary& parentDict,
				Istream& is
				),
				(parentDict, is)
		);

		//- Execute the functionEntry in a sub-dict context
		static bool execute
		(
			const word& functionName,
			dictionary& parentDict,
			Istream&
		);

		declareMemberFunctionSelectionTable
		(
			bool,
			functionEntry,
			execute,
			primitiveEntryIstream,
			(
				const dictionary& parentDict,
				primitiveEntry& entry,
				Istream& is
				),
				(parentDict, entry, is)
		);

		//- Execute the functionEntry in a primitiveEntry context
		static bool execute
		(
			const word& functionName,
			const dictionary& parentDict,
			primitiveEntry&,
			Istream&
		);


	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_functionEntry_Header
