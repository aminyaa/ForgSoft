#pragma once
#ifndef _Cad2d_PlaneInfo_Header
#define _Cad2d_PlaneInfo_Header

#include <Geo_ApprxCurveInfo.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace AutLib
{

	class Cad2d_PlaneInfo
	{

		/*Private Data*/

		Standard_Real theTolerance_;

		std::shared_ptr<Geo_ApprxCurveInfo> theApprxInfo_;

	public:

		static const Standard_Real DEFAULT_TOLERANCE;

		Cad2d_PlaneInfo()
			: theTolerance_(DEFAULT_TOLERANCE)
		{}

		const std::shared_ptr<Geo_ApprxCurveInfo>& ApproxInfo() const
		{
			return theApprxInfo_;
		}

		void OverrideApproxInfo(const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo)
		{
			theApprxInfo_ = theInfo;
		}

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
	};
}

#endif // !_Cad2d_PlaneInfo_Header