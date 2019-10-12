#pragma once
#ifndef _int_Header
#define _int_Header

#include <word.hxx>

namespace AutLib
{

	//- Return a word representation of an int
	word name(const int);

	int readInt(Istream&);
	Istream& operator>>(Istream&, int&);
	Ostream& operator<<(Ostream&, const int);
}

#endif // !_int_Header
