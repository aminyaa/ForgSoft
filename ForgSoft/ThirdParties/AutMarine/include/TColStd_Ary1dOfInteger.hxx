#pragma once
#ifndef _TColStd_Ary1dOfInteger_Header
#define _TColStd_Ary1dOfInteger_Header

#include <Adt_Ary1d.hxx>

namespace AutLib
{

	typedef Adt_Ary1d<Standard_Integer> TColStd_Ary1dOfInteger;
}

namespace AutLib
{

	inline TColStd_Ary1dOfInteger IndexedAray(const Standard_Integer theSize)
	{
		TColStd_Ary1dOfInteger a(theSize);
		forThose(Index, 0, MaxIndexOf(a))
			a.SetValue(Index, Index);
		MOVE(a);
	}
}

#endif // !_TColStd_Ary1dOfInteger_Header
