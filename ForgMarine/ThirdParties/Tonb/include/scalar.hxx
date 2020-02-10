#pragma once
#ifndef _scalar_Header
#define _scalar_Header

#include <floatScalar.hxx>
#include <doubleScalar.hxx>
#include <longDoubleScalar.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#if defined(WM_SP)

// Define scalar as a float

namespace tnbLib
{

	typedef floatScalar scalar;

	static const scalar GREAT = floatScalarGREAT;
	static const scalar VGREAT = floatScalarVGREAT;
	static const scalar ROOTVGREAT = floatScalarROOTVGREAT;
	static const scalar SMALL = floatScalarSMALL;
	static const scalar VSMALL = floatScalarVSMALL;
	static const scalar ROOTVSMALL = floatScalarROOTVSMALL;

	scalar readScalar(Istream& is);
}

#elif defined(WM_DP)

// Define scalar as a double

namespace tnbLib
{

	typedef doubleScalar scalar;

	static const scalar GREAT = doubleScalarGREAT;
	static const scalar VGREAT = doubleScalarVGREAT;
	static const scalar ROOTVGREAT = doubleScalarROOTVGREAT;
	static const scalar SMALL = doubleScalarSMALL;
	static const scalar VSMALL = doubleScalarVSMALL;
	static const scalar ROOTVSMALL = doubleScalarROOTVSMALL;

	scalar readScalar(Istream& is);
}

#elif defined(WM_LDP)

// Define scalar as a long double

namespace tnbLib
{

	typedef longDoubleScalar scalar;

	static const scalar GREAT = longDoubleScalarGREAT;
	static const scalar VGREAT = longDoubleScalarVGREAT;
	static const scalar ROOTVGREAT = longDoubleScalarROOTVGREAT;
	static const scalar SMALL = longDoubleScalarSMALL;
	static const scalar VSMALL = longDoubleScalarVSMALL;
	static const scalar ROOTVSMALL = longDoubleScalarROOTVSMALL;

	scalar readScalar(Istream& is);
}

#else

#error "Undefined precision for scalar in scalar.hxx"

#endif // defined(WM_SP)

#endif // !_scalar_Header
