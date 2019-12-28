#pragma once
#ifndef _Aft_PlnBoundary_Info_Header
#define _Aft_PlnBoundary_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>
#include <map>

namespace AutLib
{

	// Forward Declarations
	class Mesh_CurveInfo;

	struct Aft_PlnBoundary_Info_Base
	{

		static const Standard_Real DEFAULT_TOLERANCE;
	};

	template<class MetricPrcsrInfo>
	class Aft_PlnBoundary_Info
		: public Aft_PlnBoundary_Info_Base
	{

		/*Private Data*/

		Standard_Real theMergeTolerance_;

		std::shared_ptr<Mesh_CurveInfo> theGlobalCurve_;
		std::shared_ptr<MetricPrcsrInfo> theGlobalMetricPrcsr_;

		std::map
			<
			Standard_Integer,
			std::shared_ptr<Mesh_CurveInfo>
			> theCurve_;

		Standard_Boolean OverrideInfo_;

	public:

		Aft_PlnBoundary_Info()
			: OverrideInfo_(Standard_False)
			, theMergeTolerance_(DEFAULT_TOLERANCE)
		{}

		const Standard_Boolean OverrideInfo() const
		{
			return OverrideInfo_;
		}

		const std::shared_ptr<Mesh_CurveInfo>& GlobalCurve() const
		{
			return theGlobalCurve_;
		}

		const std::shared_ptr<MetricPrcsrInfo>& GlobalMetricPrcsr() const
		{
			return theGlobalMetricPrcsr_;
		}

		const std::map
			<
			Standard_Integer,
			std::shared_ptr<Mesh_CurveInfo>
			>& Curve() const
		{
			return theCurve_;
		}

		std::map
			<
			Standard_Integer,
			std::shared_ptr<Mesh_CurveInfo>
			>& Curve()
		{
			return theCurve_;
		}

		void OverrideGlobalCurve(const std::shared_ptr<Mesh_CurveInfo>& theInfo)
		{
			theGlobalCurve_ = theInfo;
		}

		void OverrideGlobalMetricPrcsr(const std::shared_ptr<MetricPrcsrInfo>& theInfo)
		{
			theGlobalMetricPrcsr_ = theInfo;
		}

		void SetOverrideInfo(const Standard_Boolean cond)
		{
			OverrideInfo_ = cond;
		}


		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MergeTolerance)
	};
}

#endif // !_Aft_PlnBoundary_Info_Header
