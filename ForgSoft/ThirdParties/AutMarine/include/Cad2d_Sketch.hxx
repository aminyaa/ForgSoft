#pragma once
#ifndef _Cad2d_Sketch_Header
#define _Cad2d_Sketch_Header

#include <Cad_Sketch.hxx>
#include <Cad2d_SketchEngine.hxx>

namespace AutLib
{

	// Forward Declarations
	class Pln_Vertex;
	class Pln_Edge;
	class Pln_Wire;
	class Cad2d_Plane;


	class Cad2d_Sketch
		: public Cad_Sketch
		, public Cad2d_SketchEngine
	{

		/*Private Data*/

	protected:

		Cad2d_Sketch()
		{}

	public:


	};
}

#endif // !_Cad2d_Sketch_Header
