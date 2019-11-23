#pragma once
#ifndef _Leg_DuctNo1_Parameters_Header
#define _Leg_DuctNo1_Parameters_Header

#include <Leg_DuctNo1_BreadthForm.hxx>
#include <Leg_DuctNo1_DepthForm.hxx>
#include <Leg_DuctNo1_DimensionForm.hxx>
#include <Leg_DuctNo1_GeneratorForm.hxx>
#include <Leg_DuctNo1_HullForm.hxx>

namespace AutLib
{

	class Leg_DuctNo1_Parameters
	{

		/*Private Data*/

		Leg_DuctNo1_DimensionForm theDimensions_;

		Leg_DuctNo1_HullForm theHull_;

		Leg_DuctNo1_GeneratorForm theGenerator_;

		Leg_DuctNo1_BreadthForm theBreadth_;

		Leg_DuctNo1_DepthForm theDepth_;

	public:

		Leg_DuctNo1_Parameters()
		{}

		//- Macros

		GLOBAL_ACCESS_SINGLE(Leg_DuctNo1_DimensionForm, Dimensions)
			GLOBAL_ACCESS_SINGLE(Leg_DuctNo1_HullForm, Hull)
			GLOBAL_ACCESS_SINGLE(Leg_DuctNo1_GeneratorForm, Generator)
			GLOBAL_ACCESS_SINGLE(Leg_DuctNo1_BreadthForm, Breadth)
			GLOBAL_ACCESS_SINGLE(Leg_DuctNo1_DepthForm, Depth)
	};
}

#endif // !_Leg_DuctNo1_Parameters_Header
