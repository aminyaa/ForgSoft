#pragma once
#ifndef _ulong_Header
#define _ulong_Header

#include <word.hxx>

namespace AutLib
{

	//- Return a string representation of a ulong
	word name(const unsigned long);

	unsigned long readUlong(Istream&);

	Istream& operator>>(Istream&, unsigned long&);
	Ostream& operator<<(Ostream&, const unsigned long);
}

#endif // !_ulong_Header
