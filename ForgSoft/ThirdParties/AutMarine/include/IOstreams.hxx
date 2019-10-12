#pragma once
#ifndef _IOstreams_Header
#define _IOstreams_Header

#include <ISstream.hxx>
#include <OSstream.hxx>
#include <prefixOSstream.hxx>

// Global predefined streams for standard input, output

namespace AutLib
{
	extern ISstream Sin;
	extern OSstream Sout;
	extern OSstream Serr;
	extern prefixOSstream Pout;
	extern prefixOSstream Perr;
}

#endif // !_IOstreams_Header
