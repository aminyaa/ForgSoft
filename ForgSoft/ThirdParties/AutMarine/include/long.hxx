#pragma once
#ifndef _long_Header
#define _long_Header

#include <word.hxx>

namespace AutLib
{

	//- Return a string representation of a long
	word name(long);

	long readLong(Istream&);

	Istream& operator>>(Istream&, long&);
	Ostream& operator<<(Ostream&, const long);
}

#endif // !_long_Header
