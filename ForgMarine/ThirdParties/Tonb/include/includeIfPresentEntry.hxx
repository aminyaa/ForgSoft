#pragma once
#ifndef _includeIfPresentEntry_Header
#define _includeIfPresentEntry_Header

#include <includeEntry.hxx>

namespace tnbLib
{

	namespace functionEntries
	{

		/*---------------------------------------------------------------------------*\
							Class includeIfPresentEntry Declaration
		\*---------------------------------------------------------------------------*/

		class includeIfPresentEntry
			: public includeEntry
		{
			// Private Member Functions

				//- Disallow default bitwise copy construct
			includeIfPresentEntry(const includeIfPresentEntry&);

			//- Disallow default bitwise assignment
			void operator=(const includeIfPresentEntry&);

		public:

			//- Runtime type information
			ClassName("includeIfPresent");


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

#endif // !_includeIfPresentEntry_Header
