#pragma once
#ifndef _vector2D_Header
#define _vector2D_Header

#include <scalar.hxx>
#include <Vector2DTemplate.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef Vector2D<scalar> vector2D;

	//- Data associated with vector2D type are contiguous
	template<>
	inline bool contiguous<vector2D>()
	{
		return true;
	}
}

#endif // !_vector2D_Header
