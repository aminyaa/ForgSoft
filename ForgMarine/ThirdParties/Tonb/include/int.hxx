#pragma once
#ifndef _int_Header
#define _int_Header

#include <word.hxx>

namespace tnbLib
{

	class Istream;
	class Ostream;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	//- Return a word representation of an int
	word name(const int);

	// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

	int readInt(Istream&);
	Istream& operator>>(Istream&, int&);
	Ostream& operator<<(Ostream&, const int);
}

#endif // !_int_Header
