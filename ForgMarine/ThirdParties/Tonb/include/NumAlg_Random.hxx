#pragma once
#ifndef _NumAlg_Random_Header
#define _NumAlg_Random_Header

#include <stdlib.h>
#include <time.h>

namespace tnbLib
{

	class NumAlg_Random
	{

	public:

		static int Randint() { return rand(); }
		static int Randint(int max) { return int(max*rand() / (RAND_MAX + 1.0)); }
		static int Randint(int low, int high) { return low + int((high - low + 1)*rand() / (RAND_MAX + 1.0)); }

		static double Randreal() { return rand() / (double(RAND_MAX) + 1); }
		static double Randreal(double max) { return Randreal()*max; }
		static double Randreal(double low, double high) { return low + Randreal()*(high - low); }
	};
}

#endif // !_NumAlg_Random_Header
