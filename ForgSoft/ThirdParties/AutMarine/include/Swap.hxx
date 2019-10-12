#pragma once
#ifndef _Swap_Header
#define _Swap_Header

#include <iostream>

namespace AutLib
{
	template<class T>
	inline void Swap(T& a, T& b)
	{
		std::swap(a, b);
	}
}

#endif // !_Swap_Header
