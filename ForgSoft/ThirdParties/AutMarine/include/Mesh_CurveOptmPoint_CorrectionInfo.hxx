#pragma once
#ifndef _Mesh_CurveOptmPoint_CorrectionInfo_Header
#define _Mesh_CurveOptmPoint_CorrectionInfo_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace AutLib
{

	class Mesh_CurveOptmPoint_CorrectionInfo
	{

		/*Private Data*/

		Standard_Real theTolerance_;
		Standard_Real theUnderRelaxation_;

		Standard_Integer theMaxLevel_;

	public:

		static const Standard_Real DEFAULT_TOLERANCE;
		static const Standard_Real DEFAULT_UNDER_RELAXATION;

		static const Standard_Integer DEFAULT_MAX_LEVEL;

		Mesh_CurveOptmPoint_CorrectionInfo()
			: theTolerance_(DEFAULT_TOLERANCE)
			, theUnderRelaxation_(DEFAULT_UNDER_RELAXATION)
			, theMaxLevel_(DEFAULT_MAX_LEVEL)
		{}

		Standard_Real Tolerance() const
		{
			return theTolerance_;
		}

		Standard_Real UnderRelaxation() const
		{
			return theUnderRelaxation_;
		}

		Standard_Integer MaxLevel() const
		{
			return theMaxLevel_;
		}

		void SetTolerance(const Standard_Real theTol)
		{
			theTolerance_ = theTol;
		}

		void SetUnderRelaxation(const Standard_Real theUnderRelaxation)
		{
			theUnderRelaxation_ = theUnderRelaxation;
		}

		void SetMaxLevel(const Standard_Integer theLevel)
		{
			theMaxLevel_ = theLevel;
		}
	};
}

#endif // !_Mesh_CurveOptmPoint_CorrectionInfo_Header