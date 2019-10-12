#pragma once
#ifndef _inputModeEntry_Header
#define _inputModeEntry_Header

#include <functionEntry.hxx>

namespace AutLib
{

	namespace functionEntries
	{

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
			inputModeEntry(const inputModeEntry&) = delete;

			//- Disallow default bitwise assignment
			void operator=(const inputModeEntry&) = delete;


		public:

			//- Runtime type information
			static const char* typeName_() { return "inputMode"; }
			static const word typeName;
			static debug::debugSwitch debug;;


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
	}
}

#endif // !_inputModeEntry_Header
