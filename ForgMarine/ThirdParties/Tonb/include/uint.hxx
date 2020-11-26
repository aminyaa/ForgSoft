#pragma once
#ifndef _uint_Header
#define _uint_Header

#include <word.hxx>

namespace tnbLib
{

	class Istream;
	class Ostream;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	//- Return a string representation of an uint
	word name(const unsigned int);

	// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

	unsigned int readUint(Istream&);
	Istream& operator>>(Istream&, unsigned int&);
	Ostream& operator<<(Ostream&, const unsigned int);
}

#endif // !_uint_Header
