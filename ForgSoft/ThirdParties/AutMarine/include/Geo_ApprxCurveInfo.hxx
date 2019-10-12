#pragma once
#ifndef _Geo_ApprxCurveInfo_Header
#define _Geo_ApprxCurveInfo_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Geo_ApprxCurveInfo
	{

		/*Private Data*/

		Standard_Real theApprox_;
		Standard_Real theAngle_;

		Standard_Integer theMaxNbSubdivision_;
		Standard_Integer theInitNbSubdivision_;
		Standard_Integer theNbSamples_;

	public:

		static const Standard_Real DEFAULT_APPROX;
		static const Standard_Real DEFAULT_ANGLE;

		static const Standard_Integer DEFAULT_MAX_NB_SUBDIVIDE;
		static const Standard_Integer DEFAULT_INIT_NB_SUBDIVIDE;
		static const Standard_Integer DEFAULT_NB_SAMPLES;

		Geo_ApprxCurveInfo()
			: theApprox_(DEFAULT_APPROX)
			, theAngle_(DEFAULT_ANGLE)
			, theMaxNbSubdivision_(DEFAULT_MAX_NB_SUBDIVIDE)
			, theInitNbSubdivision_(DEFAULT_INIT_NB_SUBDIVIDE)
			, theNbSamples_(DEFAULT_NB_SAMPLES)
		{}

		Standard_Integer MaxNbSubdivision() const
		{
			return theMaxNbSubdivision_;
		}

		Standard_Integer InitNbSubdivision() const
		{
			return theInitNbSubdivision_;
		}

		Standard_Integer NbSamples() const
		{
			return theNbSamples_;
		}

		Standard_Real Approx() const
		{
			return theApprox_;
		}

		Standard_Real Angle() const
		{
			return theAngle_;
		}

		void SetApprox(const Standard_Real x)
		{
			theApprox_ = x;
		}

		void SetAngle(const Standard_Real theAngle)
		{
			theAngle_ = theAngle;
		}

		void SetMaxNbSubdivision(const Standard_Integer theValue)
		{
			theMaxNbSubdivision_ = theValue;
		}

		void SetInitNbSubdivision(const Standard_Integer theValue)
		{
			theInitNbSubdivision_ = theValue;
		}

		void SetNbSamples(const Standard_Integer theNbSamples)
		{
			theNbSamples_ = theNbSamples;
		}
	};
}

#endif // !_Geo_ApprxCurveInfo_Header
