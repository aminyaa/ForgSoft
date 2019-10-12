#pragma once
#ifndef _optimisationSwitch_Header
#define _optimisationSwitch_Header

#include <controlSwitches.hxx>

namespace AutLib
{

	namespace debug
	{

		// Typedefs
		// Hashtable to static class attributes addresses holding the
		// runtime optimisation switch values
		typedef std::map<std::string, std::list<controlSwitches<int> *>> ListOptimisationControlSwitches;

		extern ListOptimisationControlSwitches* optimisationSwitchValues_;

		class optimisationSwitch
			: public controlSwitches<int>
		{

			// Private member functions

			//- Disallow construct as copy
			optimisationSwitch(const optimisationSwitch&) = delete;

			//- Disallow default bitwise assignment
			void operator=(const optimisationSwitch&) = delete;

		public:

			// Constructors

			//- Construct from name and value
			optimisationSwitch
			(
				const std::string& switchName,
				const int& switchValue,
				const std::string& switchDescription = ""
			)
				: controlSwitches<int>
				(
					switchName,
					debug::optimisationSwitchFromDict
					(
						switchName.c_str(),
						switchValue
					),
					switchDescription,
					debug::OPTIMISATION_SWITCHES,
					&optimisationSwitchValues_
					)
			{}


			//- This constructor is essentially for 'commsType'
			optimisationSwitch
			(
				const std::string& switchName,
				const std::string& switchValue,
				const std::string& switchDescription = ""
			)
				: controlSwitches<int>
				(
					switchName,
					debug::optimisationSwitchFromDict
					(
						switchName.c_str(),
						switchValue
					),
					switchDescription,
					debug::OPTIMISATION_SWITCHES,
					&optimisationSwitchValues_
					)
			{}


			//- Destructor
			virtual ~optimisationSwitch()
			{}

			// Member operators

			// Assignement operator
			void operator=(const int& rhs)
			{
				controlSwitches<int>::operator=(rhs);
			}
		};
	}
}

#endif // !_optimisationSwitch_Header
