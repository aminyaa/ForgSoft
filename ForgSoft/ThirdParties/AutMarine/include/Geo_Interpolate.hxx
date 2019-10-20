#pragma once
#ifndef _Geo_Interpolate_Header
#define _Geo_Interpolate_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Geo_Interpolate
	{

	public:

		static Standard_Real Linear
		(
			const Standard_Real theX, 
			const Standard_Real theX0, 
			const Standard_Real theY0,
			const Standard_Real theX1, 
			const Standard_Real theY1
		);
	};
}

#include <Geo_InterpolateI.hxx>

#endif // !_Geo_Interpolate_Header
