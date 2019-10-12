#pragma once
#ifndef _infoSwitch_Header
#define _infoSwitch_Header

#include <controlSwitches.hxx>

namespace AutLib
{
	namespace debug
	{

		// Typedefs
		// Hashtable to static class attributes addresses holding the
		// runtime info switch values
		typedef std::map<std::string, std::list<controlSwitches<int> *> >
			ListInfoControlSwitches;

		extern ListInfoControlSwitches* infoSwitchValues_;

		class infoSwitch
			: public controlSwitches<int>
		{

			// Private member functions

			//- Disallow construct as copy
			infoSwitch(const infoSwitch&) = delete;

			//- Disallow default bitwise assignment
			void operator=(const infoSwitch&) = delete;

		public:

			// Constructors

			//- Construct from name and value
			infoSwitch
			(
				const std::string& switchName,
				const int& switchValue,
				const std::string& switchDescription = ""
			)
				: controlSwitches<int>
				(
					switchName,
					debug::infoSwitchFromDict(switchName.c_str(), switchValue),
					switchDescription,
					debug::INFO_SWITCHES,
					&infoSwitchValues_
					)
			{}


			//- Destructor
			virtual ~infoSwitch()
			{}

			// Member operators

			//- Assignement operator
			void operator=(const int& rhs)
			{
				controlSwitches<int>::operator=(rhs);
			}
		};
	}
}

#endif // !_infoSwitch_Header
