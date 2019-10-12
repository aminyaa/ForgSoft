#pragma once
#ifndef _FastDiscrete_Header
#define _FastDiscrete_Header

class TopoDS_Shape;
class TopoDS_Face;
class Bnd_Box;

namespace AutLib
{

	struct FastDiscrete_Params;

	class FastDiscrete
	{

	public:

		static void Triangulation
		(
			const TopoDS_Face& theFace,
			const FastDiscrete_Params& theParams
		);

		static void Triangulation
		(
			const TopoDS_Shape& theShape, 
			const FastDiscrete_Params& theParams
		);

		static void Triangulation
		(
			const TopoDS_Shape& theShape,
			const Bnd_Box& theBox,
			const FastDiscrete_Params& theParams
		);
	};
}

#endif // !_FastDiscrete_Header
