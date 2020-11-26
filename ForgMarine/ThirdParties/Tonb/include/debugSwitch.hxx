#pragma once
#ifndef _debugSwitch_Header
#define _debugSwitch_Header

#include <controlSwitches.hxx>

namespace tnbLib
{

	namespace debug
	{

		// Typedefs
		// Hashtable to static class attributes addresses holding the
		// runtime debug switch values
		typedef std::map<std::string, std::list<controlSwitches<int> *>>
			ListDebugControlSwitches;

		extern ListDebugControlSwitches* debugSwitchValues_;

		class debugSwitch
			:
			public controlSwitches<int>
		{
			// Private member functions

				//- Disallow construct as copy
			debugSwitch(const debugSwitch&);

			//- Disallow default bitwise assignment
			void operator=(const debugSwitch&);


		public:

			// Constructors

				//- Construct from name and value
			debugSwitch
			(
				const std::string& switchName,
				const int& switchValue,
				const std::string& switchDescription = ""
			)
				: controlSwitches<int>
				(
					switchName,
					debug::debugSwitchFromDict(switchName.c_str(), switchValue),
					switchDescription,
					debug::DEBUG_SWITCHES,
					&debugSwitchValues_
					)
			{}


			//- Destructor
			virtual ~debugSwitch()
			{}


			// Member operators

				//- Assignement operator
			void operator=(const int& rhs)
			{
				controlSwitches<int>::operator=(rhs);
			}
		};


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	} // End namespace debug

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_debugSwitch_Header
