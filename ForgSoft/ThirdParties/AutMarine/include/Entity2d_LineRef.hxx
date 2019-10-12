#pragma once
#ifndef _Entity2d_LineRef_Header
#define _Entity2d_LineRef_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	// Forward Declarations
	class Pnt2d;
	class Dir2d;

	template<class PointRef, class DirectRef> class Entity_Line;

	typedef Entity_Line<const Pnt2d&, const Dir2d&> Entity2d_LineRef;

	namespace gProcessor
	{

		Standard_Boolean IsIntersect
		(
			const Entity2d_LineRef& theLine1,
			const Entity2d_LineRef& theLine2
		);

		Pnt2d Intersect
		(
			const Entity2d_LineRef& theLine1,
			const Entity2d_LineRef& theLine2,
			const Standard_Real theTol
		);
	}
}

#endif // !_Entity2d_LineRef_Header
