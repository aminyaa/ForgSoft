#pragma once
#ifndef _Numeric_System_Header
#define _Numeric_System_Header

#include <error.hxx>
#include <OSstream.hxx>

namespace AutLib
{

	namespace numLib
	{

		void inline CheckFun(const char* funcName)
		{
			FatalErrorIn(funcName) << endl
				<< " Found no function" << endl
				<< abort(FatalError);
		}
	}
}

#endif // !_Numeric_System_Header
