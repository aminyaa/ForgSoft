#pragma once
#ifndef _constantsSwitch_Header
#define _constantsSwitch_Header

#include <controlSwitches.hxx>

namespace AutLib
{
	namespace debug
	{

		// Typedefs
		// Hashtables to static class attributes addresses holding the
		// runtime dimensionedConstants values
		typedef std::map<std::string, std::list<controlSwitches<scalar> *> >
			ListConstantsControlSwitches;

		extern ListConstantsControlSwitches* constantsSwitchValues_;

		class constantsSwitch
			: public controlSwitches<scalar>
		{
			// Private member functions

			//- Disallow construct as copy
			constantsSwitch(const constantsSwitch&) = delete;

			//- Disallow default bitwise assignment
			void operator=(const constantsSwitch&) = delete;


		public:

			// Constructors

			//- Construct from name and value
			constantsSwitch
			(
				const std::string& switchName,
				const scalar& switchValue,
				const std::string& switchDescription = ""
			)
				:
				controlSwitches<scalar>
				(
					switchName,
					debug::constantsFromDict(switchName.c_str(), switchValue),
					switchDescription,
					debug::DIMENSIONED_CONSTANTS,
					&constantsSwitchValues_
					)
			{
			}


			//- Destructor
			virtual ~constantsSwitch()
			{
			}


			// Member operators

			//- Assignement operator
			void operator=(const scalar& rhs)
			{
				controlSwitches<scalar>::operator=(rhs);
			}
		};
	}
}

#endif // !_constantsSwitch_Header
