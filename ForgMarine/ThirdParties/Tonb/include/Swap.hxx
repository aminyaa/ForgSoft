#pragma once
#ifndef _Swap_Header
#define _Swap_Header

#include <algorithm>

namespace tnbLib
{

	template<class T>
	void Swap(T& a, T& b)
	{
		/*T tmp = a;
		a = b;
		b = tmp;*/

		std::swap(a, b);
	}
}

#endif // !_Swap_Header
