#pragma once
#ifndef _CadAnalys_Model_Info_Header
#define _CadAnalys_Model_Info_Header

#include <Global_Verbose.hxx>
#include <Global_AccessMethod.hxx>

#include <CadRepair_ApproxSurfMetric_Info.hxx>
#include <CadRepair_NormalizeMetric_Info.hxx>
#include <CadRepair_ParaPlaneAR_Info.hxx>
#include <CadSingularity_Detection_Info.hxx>

#include <memory>
#include <map>

namespace AutLib
{

	// Forward Declarations
	class CadRepair_ApproxSurfMetric_Info;
	class CadRepair_NormalizeMetric_Info;
	class CadRepair_ParaPlaneAR_Info;
	class CadSingularity_Detection_Info;

	class CadAnalys_Model_Info
		: public Global_Verbose
	{

		typedef CadRepair_ApproxSurfMetric_Info metricApproxInfo;
		typedef CadSingularity_Detection_Info singlDetectInfo;
		typedef CadRepair_NormalizeMetric_Info normInfo;
		typedef CadRepair_ParaPlaneAR_Info planeArInfo;

		/*Private Data*/

		Standard_Real theMinSize_;
		Standard_Real theOpenWireTolerance_;
		Standard_Real theIntersectWireTolerance_;

		std::shared_ptr<metricApproxInfo> theGlobalMetricApproximation_;
		std::shared_ptr<singlDetectInfo> theGlobalSingularityDetection_;
		std::shared_ptr<normInfo> theGlobalNormalizeMetric_;
		std::shared_ptr<planeArInfo> theGlobalParaPlaneAR_;

		std::map
			<
			Standard_Integer,
			std::shared_ptr<metricApproxInfo>
			> theMetricApproximation_;

		std::map
			<
			Standard_Integer,
			std::shared_ptr<singlDetectInfo>
			> theSingularityDetection_;

		std::map
			<
			Standard_Integer,
			std::shared_ptr<normInfo>
			> theNormalizeMetric_;

		std::map
			<
			Standard_Integer, 
			std::shared_ptr<planeArInfo>
			> theParaPlaneAR_;

		Standard_Boolean OverrideMetricApproximation_;
		Standard_Boolean OverrideSingularityDetection_;
		Standard_Boolean OverrideNormalizeMetric_;
		Standard_Boolean OverrideParaPlaneAR_;

	public:

		static const Standard_Real DEFAULT_MIN_SIZE;
		static const Standard_Real DEFAULT_OPEN_WIRE_TOLERANCE;
		static const Standard_Real DEFAULT_INTERSECT_WIRE_TOLERANCE;

		CadAnalys_Model_Info();


		Standard_Real MinSize() const
		{
			return theMinSize_;
		}

		Standard_Boolean OverrideMetricApproximation() const
		{
			return OverrideMetricApproximation_;
		}

		Standard_Boolean OverrideSingularityDetection() const
		{
			return OverrideSingularityDetection_;
		}

		Standard_Boolean OverrideNormalizeMetric() const
		{
			return OverrideNormalizeMetric_;
		}

		Standard_Boolean OverrideParaPlaneAR() const
		{
			return OverrideParaPlaneAR_;
		}

		const std::map
			<
			Standard_Integer,
			std::shared_ptr<metricApproxInfo>
			>& MetricApproximation() const
		{
			return theMetricApproximation_;
		}

		std::map
			<
			Standard_Integer,
			std::shared_ptr<metricApproxInfo>
			>& MetricApproximation()
		{
			return theMetricApproximation_;
		}

		const std::map
			<
			Standard_Integer,
			std::shared_ptr<singlDetectInfo>
			>& SingularityDetection() const
		{
			return theSingularityDetection_;
		}

		std::map
			<
			Standard_Integer,
			std::shared_ptr<singlDetectInfo>
			>& SingularityDetection()
		{
			return theSingularityDetection_;
		}

		const std::map
			<
			Standard_Integer,
			std::shared_ptr<normInfo>
			>& NormalizeMetric() const
		{
			return theNormalizeMetric_;
		}

		std::map
			<
			Standard_Integer,
			std::shared_ptr<normInfo>
			>& NormalizeMetric()
		{
			return theNormalizeMetric_;
		}

		const std::map
			<
			Standard_Integer,
			std::shared_ptr<planeArInfo>
			>& ParaPlaneAR() const
		{
			return theParaPlaneAR_;
		}

		std::map
			<
			Standard_Integer,
			std::shared_ptr<planeArInfo>
			>& ParaPlaneAR()
		{
			return theParaPlaneAR_;
		}

		void SetMinSize(const Standard_Real theSize)
		{
			theMinSize_ = theSize;
		}

		void OverrideMetricApproximation
		(
			const Standard_Integer theIndex, 
			const std::shared_ptr<metricApproxInfo>& theInfo
		);

		void OverrideSingularityDetection
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<singlDetectInfo>& theInfo
		);

		void OverrideNormalizeMetric
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<normInfo>& theInfo
		);

		void OverrideParaPlaneAR
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<planeArInfo>& theInfo
		);

		void SetOverrideMetricApproximation(const Standard_Boolean cond)
		{
			OverrideMetricApproximation_ = cond;
		}

		void SetOverrideSingularityDetection(const Standard_Boolean cond)
		{
			OverrideSingularityDetection_ = cond;
		}

		void SetOverrideNormalizeMetric(const Standard_Boolean cond)
		{
			OverrideNormalizeMetric_ = cond;
		}

		void SetOverrideParaPlaneAR(const Standard_Boolean cond)
		{
			OverrideParaPlaneAR_ = cond;
		}

		void OverrideGlobalMetricApproximation(const std::shared_ptr<metricApproxInfo>& theInfo)
		{
			theGlobalMetricApproximation_ = theInfo;
		}

		void OverrideGlobalSingularityDetection(const std::shared_ptr<singlDetectInfo>& theInfo)
		{
			theGlobalSingularityDetection_ = theInfo;
		}

		void OverrideGlobalNormalizeMetric(const std::shared_ptr<normInfo>& theInfo)
		{
			theGlobalNormalizeMetric_ = theInfo;
		}

		void OverrideGlobalParaPlaneAR(const std::shared_ptr<planeArInfo>& theInfo)
		{
			theGlobalParaPlaneAR_ = theInfo;
		}

		//- Macros
		GLOBAL_ACCESS_ONLY_SINGLE(std::shared_ptr<metricApproxInfo>, GlobalMetricApproximation)
			GLOBAL_ACCESS_ONLY_SINGLE(std::shared_ptr<singlDetectInfo>, GlobalSingularityDetection)
			GLOBAL_ACCESS_ONLY_SINGLE(std::shared_ptr<normInfo>, GlobalNormalizeMetric)
			GLOBAL_ACCESS_ONLY_SINGLE(std::shared_ptr<planeArInfo>, GlobalParaPlaneAR)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, OpenWireTolerance)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, IntersectWireTolerance)

	};
}

#endif // !_CadAnalys_Model_Info_Header
