#pragma once
#ifndef _Numeric_Random_Header
#define _Numeric_Random_Header

#include <stdlib.h>
#include <time.h>

namespace AutLib
{

	namespace Random
	{

		inline int Randint() { return rand(); }
		inline int Randint(int max) { return int(max*rand() / (RAND_MAX + 1.0)); }
		inline int Randint(int low, int high) { return low + int((high - low + 1)*rand() / (RAND_MAX + 1.0)); }

		inline double Randreal() { return rand() / (double(RAND_MAX) + 1); }
		inline double Randreal(double max) { return Randreal()*max; }
		inline double Randreal(double low, double high) { return low + Randreal()*(high - low); }

		inline void InitRand() { srand((int)(time(NULL))); }
	}
}

#endif // !_Numeric_Random_Header
