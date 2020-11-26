#pragma once
#ifndef _Cad_FastDiscrete_Header
#define _Cad_FastDiscrete_Header

class TopoDS_Shape;
class TopoDS_Face;
class Bnd_Box;

namespace tnbLib
{

	// Forward Declarations
	struct FastDiscrete_Params;


	class Cad_FastDiscrete
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

#endif // !_Cad_FastDiscrete_Header
