#pragma once
#ifndef _functionEntry_Header
#define _functionEntry_Header

#include <word.hxx>
#include <HashTable.hxx>

namespace AutLib
{
	class primitiveEntry;
	class dictionary;

	class functionEntry
	{
		// Private Member Functions

		//- Disallow default bitwise copy construct
		functionEntry(const functionEntry&);

		//- Disallow default bitwise assignment
		void operator=(const functionEntry&);


	public:

		// Member Function Selectors

		/* Construct from argList function pointer type */
		typedef bool(*executedictionaryIstreamMemberFunctionPtr)(
			dictionary& parentDict,
			Istream& is
			);

		/* Construct from argList function table type */
		typedef HashTable
			<executedictionaryIstreamMemberFunctionPtr, word, string::hash>
			executedictionaryIstreamMemberFunctionTable;

		/* Construct from argList function pointer table pointer */
		static executedictionaryIstreamMemberFunctionTable*
			executedictionaryIstreamMemberFunctionTablePtr_;

		/* Class to add constructor from argList to table */
		template<class functionEntryType>
		class addexecutedictionaryIstreamMemberFunctionToTable
		{
		public:

			addexecutedictionaryIstreamMemberFunctionToTable
			(
				const word& lookup = functionEntryType::typeName
			)
			{
				constructexecutedictionaryIstreamMemberFunctionTables();
				executedictionaryIstreamMemberFunctionTablePtr_->insert
				(
					lookup,
					functionEntryType::execute
				);
			}

			~addexecutedictionaryIstreamMemberFunctionToTable()
			{
				destroyexecutedictionaryIstreamMemberFunctionTables();
			}
		};

		/* Table execute called from the table add function */
		static void constructexecutedictionaryIstreamMemberFunctionTables();

		/* Table destructor called from the table add function destructor */
		static void destroyexecutedictionaryIstreamMemberFunctionTables();

		//- Execute the functionEntry in a sub-dict context
		static bool execute
		(
			const word& functionName,
			dictionary& parentDict,
			Istream&
		);

		/* Construct from argList function pointer type */
		typedef bool(*executeprimitiveEntryIstreamMemberFunctionPtr)(
			const dictionary& parentDict,
			primitiveEntry& entry,
			Istream& is
			);

		/* Construct from argList function table type */
		typedef HashTable
			<executeprimitiveEntryIstreamMemberFunctionPtr, word, string::hash>
			executeprimitiveEntryIstreamMemberFunctionTable;

		/* Construct from argList function pointer table pointer */
		static executeprimitiveEntryIstreamMemberFunctionTable*
			executeprimitiveEntryIstreamMemberFunctionTablePtr_;

		/* Class to add constructor from argList to table */
		template<class functionEntryType>
		class addexecuteprimitiveEntryIstreamMemberFunctionToTable
		{
		public:

			addexecuteprimitiveEntryIstreamMemberFunctionToTable
			(
				const word& lookup = functionEntryType::typeName
			)
			{
				constructexecuteprimitiveEntryIstreamMemberFunctionTables();
				executeprimitiveEntryIstreamMemberFunctionTablePtr_->insert
				(
					lookup,
					functionEntryType::execute
				);
			}

			~addexecuteprimitiveEntryIstreamMemberFunctionToTable()
			{
				destroyexecuteprimitiveEntryIstreamMemberFunctionTables();
			}
		};

		/* Table execute called from the table add function */
		static void constructexecuteprimitiveEntryIstreamMemberFunctionTables();

		/* Table destructor called from the table add function destructor */
		static void destroyexecuteprimitiveEntryIstreamMemberFunctionTables();

		//- Execute the functionEntry in a primitiveEntry context
		static bool execute
		(
			const word& functionName,
			const dictionary& parentDict,
			primitiveEntry&,
			Istream&
		);


	};
}

#endif // !_functionEntry_Header
