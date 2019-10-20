#pragma once
#ifndef _Cad2d_SketchCache_Header
#define _Cad2d_SketchCache_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	struct Cad2d_SketchCache
	{

	protected:

		mutable Standard_Boolean PickedUpVertex;
		mutable Standard_Boolean PickedUpEdge;
	};
}

#endif // !_Cad2d_SketchCache_Header
