#pragma once
#ifndef _contiguous_Header
#define _contiguous_Header

namespace AutLib
{

	// Forward declaration of friend functions and operators
	template<class T, unsigned Size> class FixedList;
	template<class T> class Pair;

	//- Assume the data associated with type T are not contiguous
	template<class T>
	inline bool contiguous()
	{
		return false;
	}

	// Data associated with primitive types (and simple fixed size containers
	//  - only size 2 defined here) are contiguous

	template<>
	inline bool contiguous<bool>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<bool, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<bool> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<char>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<char, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<char> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<unsigned char>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<unsigned char, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<unsigned char> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<short>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<short, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<short> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<unsigned short>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<unsigned short, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<unsigned short> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<int>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<int, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<int> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<unsigned int>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<unsigned int, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<unsigned int> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<long>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<long, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<long> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<unsigned long>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<unsigned long, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<unsigned long> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<long long>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<long long, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<long long> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<unsigned long long>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<unsigned long long, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<unsigned long long> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<float>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<float, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<float> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<double>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<double, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<double> >()
	{
		return true;
	}

	template<>
	inline bool contiguous<long double>()
	{
		return true;
	}
	template<>
	inline bool contiguous<FixedList<long double, 2> >()
	{
		return true;
	}
	template<>
	inline bool contiguous<Pair<long double> >()
	{
		return true;
	}
}

#endif // !_contiguous_Header
