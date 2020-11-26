#pragma once
#ifndef _Geo_ApprxCurve_Info_Header
#define _Geo_ApprxCurve_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace tnbLib
{

	class Geo_ApprxCurve_Info
	{

		/*Private Data*/

		Standard_Real theApprox_;
		Standard_Real theAngle_;
		Standard_Real theMinSize_;

		Standard_Integer theMaxNbSubdivision_;
		Standard_Integer theInitNbSubdivision_;
		Standard_Integer theNbSamples_;

	public:

		static const Standard_Real DEFAULT_APPROX;
		static const Standard_Real DEFAULT_ANGLE;
		static const Standard_Real DEFAULT_MIN_SIZE;

		static const Standard_Integer DEFAULT_MAX_NB_SUBDIVIDE;
		static const Standard_Integer DEFAULT_INIT_NB_SUBDIVIDE;
		static const Standard_Integer DEFAULT_NB_SAMPLES;

		Geo_ApprxCurve_Info()
			: theApprox_(DEFAULT_APPROX)
			, theAngle_(DEFAULT_ANGLE)
			, theMaxNbSubdivision_(DEFAULT_MAX_NB_SUBDIVIDE)
			, theInitNbSubdivision_(DEFAULT_INIT_NB_SUBDIVIDE)
			, theNbSamples_(DEFAULT_NB_SAMPLES)
			, theMinSize_(DEFAULT_MIN_SIZE)
		{}

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Approx)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Angle)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MinSize)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, MaxNbSubdivision)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, InitNbSubdivision)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSamples)
	};
}

#endif // !_Geo_ApprxCurve_Info_Header
