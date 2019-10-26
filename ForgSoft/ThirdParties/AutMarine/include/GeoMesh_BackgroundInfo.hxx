#pragma once
#ifndef _GeoMesh_BackgroundInfo_Header
#define _GeoMesh_BackgroundInfo_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class GeoMesh_Background_SmoothingHvCorrectionInfo
	{

		/*Private Data*/

		Standard_Integer theNbIters_;
		Standard_Real theFactor_;

	public:

		static const Standard_Integer DEFAULT_MX_NB_ITERS;
		static const Standard_Real DEFAULT_FACTOR;

		GeoMesh_Background_SmoothingHvCorrectionInfo()
			: theNbIters_(DEFAULT_MX_NB_ITERS)
			, theFactor_(DEFAULT_FACTOR)
		{}

		Standard_Integer MaxNbIters() const
		{
			return theNbIters_;
		}

		Standard_Real Factor() const
		{
			return theFactor_;
		}

		void SetMaxnbIters(const Standard_Integer theValue)
		{
			theNbIters_ = theValue;
		}

		void SetFactor(const Standard_Real theFactor)
		{
			theFactor_ = theFactor;
		}
	};

	class GeoMesh_Background_SmoothingLaplacianInfo
	{

		/*Private Data*/

		Standard_Integer theNbIters_;
		Standard_Real theFactor_;

	public:

		static const Standard_Integer DEFAULT_MX_NB_ITERS;
		static const Standard_Real DEFAULT_FACTOR;

		GeoMesh_Background_SmoothingLaplacianInfo()
			: theNbIters_(DEFAULT_MX_NB_ITERS)
			, theFactor_(DEFAULT_FACTOR)
		{}

		Standard_Integer MaxNbIters() const
		{
			return theNbIters_;
		}

		Standard_Real Factor() const
		{
			return theFactor_;
		}

		void SetMaxnbIters(const Standard_Integer theValue)
		{
			theNbIters_ = theValue;
		}

		void SetFactor(const Standard_Real theFactor)
		{
			theFactor_ = theFactor;
		}
	};
}

#endif // !_GeoMesh_BackgroundInfo_Header