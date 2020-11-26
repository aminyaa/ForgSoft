#pragma once
#ifndef _Pln_Orientation_Header
#define _Pln_Orientation_Header

namespace tnbLib
{

	enum Pln_Orientation
	{
		Pln_Orientation_Unknown = 0,
		Pln_Orientation_CCW,
		Pln_Orientation_CW
	};

	Pln_Orientation Reverse(const Pln_Orientation theOrient);
}

#endif // !_Pln_Orientation_Header
