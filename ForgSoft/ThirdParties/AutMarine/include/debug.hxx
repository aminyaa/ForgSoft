#pragma once
#ifndef _debug_Header
#define _debug_Header

#include <word.hxx>

namespace AutLib
{

	// Forward declaration of classes
	class dictionary;
	class fileName;

	namespace debug
	{

		//- Define central control dictionary switchSet
		enum globalControlDictSwitchSet
		{
			DEBUG_SWITCHES,
			INFO_SWITCHES,
			OPTIMISATION_SWITCHES,
			TOLERANCES,
			DIMENSIONED_CONSTANTS
		};

		// Number of global controlDict switches sets
		// Currently, we have:
		//     DebugSwitches
		//     InfoSwitches
		//     OptimisationSwitches
		//     Tolerances,
		//     DimensionedConstants
		static const int DIM_GLOBAL_CONTROL_DICT_SWITCH_SET = 5;

		//- The central control dictionary.
		dictionary& controlDict();

		//- The DebugSwitches sub-dictionary in the central controlDict.
		dictionary& debugSwitches();

		//- The InfoSwitches sub-dictionary in the central controlDict.
		dictionary& infoSwitches();

		//- The OptimisationSwitches sub-dictionary in the central controlDict.
		dictionary& optimisationSwitches();

		//- The Tolerances sub-dictionary in the central controlDict.
		dictionary& tolerances();

		//- The DimensionedConstants sub-dictionary in the central controlDict.
		dictionary& constants();

		//- Lookup debug switch or add default value.
		int debugSwitchFromDict(const char* name, const int defaultValue = 0);

		//- Lookup info switch or add default value.
		int infoSwitchFromDict(const char* name, const int defaultValue = 0);

		//- Lookup optimisation switch or add default value.
		int optimisationSwitchFromDict
		(
			const char* name,
			const int defaultValue = 0
		);

		int optimisationSwitchFromDict
		(
			const string name,
			const word defaultValue
		);

		//- Lookup tolerances switch or add default value.
		double tolerancesFromDict
		(
			const char* name,
			const double defaultValue = 0
		);

		//- Lookup dimensionedConstants switch or add default value.
		double constantsFromDict
		(
			const char* name,
			const double defaultValue = 0
		);

		//- Update central controlDict variables
		//  supported keyValues format: key1=value1,key2=value2
		void updateCentralDictVars
		(
			const globalControlDictSwitchSet centralDictSwitchSetName,
			const string& keyValues,
			const bool verbose = true
		);

		//- Update central controlDict variables from a file
		void updateCentralDictVars
		(
			const fileName& file,
			const bool verbose = true
		);

		//- Dump the central controlDict variables to the console using a standard
		// dictionary format. If a description is available for a given switch, a
		// comment will be added just besides the switch name and value.
		void dumpControlSwitchesToConsole();
	}
}

#endif // !_debug_Header
