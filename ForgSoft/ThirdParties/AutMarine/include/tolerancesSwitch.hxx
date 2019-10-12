#pragma once
#ifndef _tolerancesSwitch_Header
#define _tolerancesSwitch_Header

#include <controlSwitches.hxx>

namespace AutLib
{

	namespace debug
	{

		// Typedefs
		// Hashtable to static class attributes addresses holding the
		// runtime tolerances switch values
		typedef std::map<std::string, std::list<controlSwitches<scalar> *>> ListTolerancesControlSwitches;

		extern ListTolerancesControlSwitches* tolerancesSwitchValues_;

		class tolerancesSwitch
			: public controlSwitches<scalar>
		{
			// Private member functions

			//- Disallow construct as copy
			tolerancesSwitch(const tolerancesSwitch&) = delete;

			//- Disallow default bitwise assignment
			void operator=(const tolerancesSwitch&) = delete;


		public:

			// Constructors

			//- Construct from name and value
			tolerancesSwitch
			(
				const std::string& switchName,
				const scalar& switchValue,
				const std::string& switchDescription = ""
			)
				: controlSwitches<scalar>
				(
					switchName,
					debug::tolerancesFromDict(switchName.c_str(), switchValue),
					switchDescription,
					debug::TOLERANCES,
					&tolerancesSwitchValues_
					)
			{
			}


			//- Destructor
			virtual ~tolerancesSwitch()
			{}


			// Member operators

			//- Assignement operator
			void operator=(const scalar& rhs)
			{
				controlSwitches<scalar>::operator=(rhs);
			}
		};
	}
}

#endif // !_tolerancesSwitch_Header
