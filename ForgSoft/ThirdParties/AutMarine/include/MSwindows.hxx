#pragma once
#ifndef _MSwindows_Header
#define _MSwindows_Header

#include <debugSwitch.hxx>

namespace AutLib
{
	namespace MSwindows
	{
		//- Declare name of the class and it's debug switch
		inline const char* typeName_() { return "MSwindows"; }
		extern const word typeName;
		extern debug::debugSwitch debug;;

		//- Get last windows api error from GetLastError
		std::string getLastError();
	}
}

#endif // !_MSwindows_Header
