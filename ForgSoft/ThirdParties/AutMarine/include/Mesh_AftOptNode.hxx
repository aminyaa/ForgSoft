#pragma once
#ifndef _Mesh_AftOptNode_Header
#define _Mesh_AftOptNode_Header

#include <Standard_TypeDef.hxx>
#include <Mesh_AftMetricPrcsr.hxx>

#include <memory>

namespace AutLib
{

	template
		<
		class FrontType,
		class SizeFun, 
		class MetricFun,
		class InfoAlg,
		class AnalyAlg, 
		class CorrtAlg, 	
		class AltrAlg = void
		>
	class Mesh_AftOptNode_Calculator
	{

		typedef Mesh_AftMetricPrcsr<FrontType, SizeFun, MetricFun>
			metricMap;
		typedef FrontType frontType;
		typedef MetricFun metricFun;
		typedef SizeFun sizeFun;

		typedef typename sizeFun::ptType Point;

		/*Private Data*/

		const std::shared_ptr<metricMap>& theMetricMap_;
		
		Standard_Real theSize_;

		const frontType& theFront_;

	public:

		Mesh_AftOptNode_Calculator
		(
			const std::shared_ptr<metricMap>& theMetricMap,
			const Standard_Real theSize,
			const frontType& theFront
		)
			: theMetricMap_(theMetricMap)
			, theSize_(theSize)
			, theFront_(theFront)
		{}

		const std::shared_ptr<metricMap>& MetricMap() const
		{
			return theMetricMap_;
		}

		Standard_Real ElementSize() const
		{
			return theSize_;
		}

		const frontType& Front() const
		{
			return theFront_;
		}

		void Perform();
	};

	template
		<
		class FrontType,
		class SizeFun,
		class InfoAlg,
		class AnalyAlg,
		class CorrtAlg
		>
		class Mesh_AftOptNode_Calculator<FrontType, SizeFun, InfoAlg, void, AnalyAlg, CorrtAlg>
	{

		typedef Mesh_AftMetricPrcsr<FrontType, SizeFun, void>
			metricMap;
		typedef FrontType frontType;
		typedef SizeFun sizeFun;

		typedef typename sizeFun::ptType Point;

		/*Private Data*/

		const std::shared_ptr<metricMap>& theMetricMap_;
		const std::shared_ptr<InfoAlg>& theInfo_;

		Standard_Real theSize_;

		const frontType& theFront_;


		std::shared_ptr<AnalyAlg> theAnalytical_;
		std::shared_ptr<CorrtAlg> theCorrector_;

		Point theCoord_;


		std::shared_ptr<AnalyAlg>& ChangeAnalytical()
		{
			return theAnalytical_;
		}

		std::shared_ptr<CorrtAlg>& ChangeCorrector()
		{
			return theCorrector_;
		}

		Point& ChangeCoord()
		{
			return theCoord_;
		}

	public:

		Mesh_AftOptNode_Calculator
		(
			const std::shared_ptr<metricMap>& theMetricMap,
			const Standard_Real theSize,
			const frontType& theFront
		)
			: theMetricMap_(theMetricMap)
			, theSize_(theSize)
			, theFront_(theFront)
		{}

		const std::shared_ptr<metricMap>& MetricMap() const
		{
			return theMetricMap_;
		}

		Standard_Real ElementSize() const
		{
			return theSize_;
		}

		const frontType& Front() const
		{
			return theFront_;
		}

		const std::shared_ptr<AnalyAlg>& Analytical() const
		{
			return theAnalytical_;
		}

		const std::shared_ptr<CorrtAlg>& Corrector() const
		{
			return theCorrector_;
		}

		const std::shared_ptr<InfoAlg>& Info() const
		{
			return theInfo_;
		}

		const Point& Coord() const
		{
			return theCoord_;
		}

		void Perform();
	};

	template<class AftMetricPrcsr, class AnalyAlg, class CorrtAlg, class AltrAlg = void>
	class Mesh_AftOptNode
	{

		/*Private Data*/


	};

	template<class AftMetricPrcsr, class AnalyAlg, class CorrtAlg>
	class Mesh_AftOptNode<AftMetricPrcsr, AnalyAlg, CorrtAlg, void>
	{

		typedef typename AftMetricPrcsr::frontType frontType;

		/*Private Data*/

		std::shared_ptr<AftMetricPrcsr> theMetricMap_;

		Standard_Real theSize_;


		std::shared_ptr<AnalyAlg> theAnalytical_;
		std::shared_ptr<CorrtAlg> theCorrection_;

	public:

		Mesh_AftOptNode
		(
			const std::shared_ptr<AftMetricPrcsr>& theMetricMap,
			const std::shared_ptr<AnalyAlg>& theAnalytical,
			const std::shared_ptr<CorrtAlg>& theCorrection
		)
			: theMetricMap_(theMetricMap)
			, theAnalytical_(theAnalytical)
			, theCorrection_(theCorrection)
		{}


	};
}

#include <Mesh_AftOptNodeI.hxx>

#endif // !_Mesh_AftOptNode_Header
