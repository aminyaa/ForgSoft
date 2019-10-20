#pragma once
#ifndef _Marine_DimensionedParamFwd_Header
#define _Marine_DimensionedParamFwd_Header

#include <Vec2d.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class T>
	class Marine_DimensionedParam;

	namespace marineLib
	{

		typedef Marine_DimensionedParam<Standard_Real> realParam;
		typedef Marine_DimensionedParam<Vec2d> vecParam;
	}
}

#endif // !_Marine_DimensionedParamFwd_Header
