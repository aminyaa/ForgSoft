#pragma once
#ifndef _includeEntry_Header
#define _includeEntry_Header

#include <functionEntry.hxx>

namespace tnbLib
{

	namespace functionEntries
	{

		/*---------------------------------------------------------------------------*\
								Class includeEntry Declaration
		\*---------------------------------------------------------------------------*/

		class includeEntry
			: public functionEntry
		{
			// Private Member Functions

				//- Disallow default bitwise copy construct
			includeEntry(const includeEntry&);

			//- Disallow default bitwise assignment
			void operator=(const includeEntry&);

		protected:

			// Protected Member Functions

				//- Read the include fileName from Istream, expand and return
			static fileName includeFileName(Istream&);


		public:

			//- Runtime type information
			ClassName("include");


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


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	} // End namespace functionEntries
}

#endif // !_includeEntry_Header
