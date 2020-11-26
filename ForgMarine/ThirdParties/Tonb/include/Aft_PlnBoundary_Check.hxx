#pragma once
#ifndef _Aft_PlnBoundary_Check_Header
#define _Aft_PlnBoundary_Check_Header

#include <Standard_TypeDef.hxx>
#include <Entity2d_ChainFwd.hxx>
#include <Entity2d_PolygonFwd.hxx>

namespace tnbLib
{

	class Aft_PlnBoundary_Check
	{

	protected:

		Aft_PlnBoundary_Check();

	public:


		enum class WireOrientation
		{
			CCW = 0,
			CW
		};


		static Standard_Boolean CheckWireOrientation(const Entity2d_Polygon& thePoly, const WireOrientation ori);

		static Standard_Boolean CheckSimple(const Entity2d_Polygon& thePoly);
	};
}

#endif // !_Aft_PlnBoundary_Check_Header
