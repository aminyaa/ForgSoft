#pragma once
#ifndef _long_Header
#define _long_Header

#include <word.hxx>

namespace tnbLib
{

	class Istream;
	class Ostream;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	//- Return a string representation of a long
	word name(long);

	// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

	long readLong(Istream&);
	Istream& operator>>(Istream&, long&);
	Ostream& operator<<(Ostream&, const long);
}

#endif // !_long_Header
