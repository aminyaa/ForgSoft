#pragma once
#ifndef _removeEntry_Header
#define _removeEntry_Header

#include <functionEntry.hxx>

namespace tnbLib
{

	namespace functionEntries
	{

		/*---------------------------------------------------------------------------*\
								   Class removeEntry Declaration
		\*---------------------------------------------------------------------------*/

		class removeEntry
			: public functionEntry
		{
			// Private Member Functions

				//- Disallow default bitwise copy construct
			removeEntry(const removeEntry&);

			//- Disallow default bitwise assignment
			void operator=(const removeEntry&);


		public:

			//- Runtime type information
			ClassName("remove");


			// Member Functions

				//- Execute the functionEntry in a sub-dict context
			static bool execute(dictionary& parentDict, Istream&);
		};


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	} // End namespace functionEntries
}

#endif // !_removeEntry_Header
