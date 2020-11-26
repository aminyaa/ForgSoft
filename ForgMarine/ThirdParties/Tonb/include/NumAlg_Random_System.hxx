#pragma once
#ifndef _NumAlg_Random_System_Header
#define _NumAlg_Random_System_Header

#include <stdlib.h>
#include <time.h>

namespace tnbLib
{

	namespace sysLib
	{

		inline void init_random_generator() { srand((int)(time(NULL))); }
	}
}

#endif // !_NumAlg_Random_System_Header
