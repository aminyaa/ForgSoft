#pragma once
#ifndef _longLong_Header
#define _longLong_Header

#include <word.hxx>

namespace tnbLib
{

	class Istream;
	class Ostream;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	//- Return a string representation of a long long
	word name(long long);

	// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

	long long readLongLong(Istream&);
	Istream& operator>>(Istream&, long long&);
	Ostream& operator<<(Ostream&, const long long);
}

#endif // !_longLong_Header
