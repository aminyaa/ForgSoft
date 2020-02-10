#pragma once
#ifndef _IOstreams_Header
#define _IOstreams_Header

#include <ISstream.hxx>
#include <prefixOSstream.hxx>
#include <token.hxx>
#include <char.hxx>
#include <int.hxx>
#include <uint.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Global predefined streams for standard input, output

namespace tnbLib
{

	extern ISstream Sin;
	extern OSstream Sout;
	extern OSstream Serr;
	extern prefixOSstream Pout;
	extern prefixOSstream Perr;
}

#endif // !_IOstreams_Header
