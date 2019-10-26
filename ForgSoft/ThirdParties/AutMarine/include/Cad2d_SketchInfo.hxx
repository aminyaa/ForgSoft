#pragma once
#ifndef _Cad2d_SketchInfo_Header
#define _Cad2d_SketchInfo_Header

#include <Cad_CurveInfo.hxx>

#include <memory>

namespace AutLib
{

	class Cad2d_SketchInfo
	{

		/*Private Data*/

		std::shared_ptr<Cad_CurveInfo> theCurveInfo_;

		Standard_Boolean DiscreteEdge_;

	public:

		Cad2d_SketchInfo();

		Standard_Boolean DiscreteEdge() const
		{
			return DiscreteEdge_;
		}

		const std::shared_ptr<Cad_CurveInfo>& CurveInfo() const
		{
			return theCurveInfo_;
		}

		void SetToDiscreteEdge(const Standard_Boolean Discrete)
		{
			DiscreteEdge_ = Discrete;
		}

		void OverridCurveInfo(const std::shared_ptr<Cad_CurveInfo>& theInfo)
		{
			theCurveInfo_ = theInfo;
		}
	};
}

#endif // !_Cad2d_SketchInfo_Header