#pragma once
#ifndef _inputModeEntry_Header
#define _inputModeEntry_Header

#include <functionEntry.hxx>

namespace tnbLib
{

	namespace functionEntries
	{

		/*---------------------------------------------------------------------------*\
								Class inputModeEntry Declaration
		\*---------------------------------------------------------------------------*/

		class inputModeEntry
			: public functionEntry
		{
			//- The input mode options
			enum inputMode
			{
				MERGE,
				OVERWRITE,
				PROTECT,
				WARN,
				FATALERROR
			};

			//- The current input mode
			static inputMode mode_;


			// Private Member Functions

				//- Read the mode as a word and set enum appropriately
			static void setMode(Istream&);

			//- Disallow default bitwise copy construct
			inputModeEntry(const inputModeEntry&);

			//- Disallow default bitwise assignment
			void operator=(const inputModeEntry&);


		public:

			//- Runtime type information
			ClassName("inputMode");


			// Member Functions

				//- Execute the functionEntry in a sub-dict context
			static bool execute(dictionary& parentDict, Istream&);

			//- Reset the inputMode to %default (ie, %merge)
			static void clear();

			//- Return true if the inputMode is %merge
			static bool merge();

			//- Return true if the inputMode is %overwrite
			static bool overwrite();

			//- Return true if the inputMode is %protect
			static bool protect();

			//- Return true if the inputMode is %error
			static bool error();
		};


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	} // End namespace functionEntries
}

#endif // !_inputModeEntry_Header
