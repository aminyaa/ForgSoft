#pragma once
#ifndef _includeEntry_Header
#define _includeEntry_Header

#include <functionEntry.hxx>

namespace AutLib
{

	namespace functionEntries
	{

		class includeEntry
			: public functionEntry
		{
			// Private Member Functions

			//- Disallow default bitwise copy construct
			includeEntry(const includeEntry&) = delete;

			//- Disallow default bitwise assignment
			void operator=(const includeEntry&) = delete;

		protected:

			// Protected Member Functions

			//- Read the include fileName from Istream, expand and return
			static fileName includeFileName(Istream&);


		public:

			//- Runtime type information
			static const char* typeName_() { return "include"; }
			static const word typeName;
			static debug::debugSwitch debug;;


			// Member Functions

			//- Execute the functionEntry in a sub-dict context
			static bool execute(dictionary& parentDict, Istream&);

			//- Execute the functionEntry in a primitiveEntry context
			static bool execute
			(
				const dictionary& parentDict,
				primitiveEntry&,
				Istream&
			);

		};
	}
}

#endif // !_includeEntry_Header
