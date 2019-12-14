#pragma once
#ifndef _CadSingularity_Horizon_Header
#define _CadSingularity_Horizon_Header

#include <Global_Done.hxx>
#include <Global_Indexed.hxx>
#include <Entity2d_PolygonFwd.hxx>
#include <Mesh2d_KnitChainFwd.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class CadRepair_ApproxSurfMetric;

	class CadSingularity_Horizon
		: public Global_Done
		, public Global_Indexed
	{

		/*Private Data*/

		std::shared_ptr<CadRepair_ApproxSurfMetric> theMetric_;

		std::shared_ptr<Mesh2d_KnitChain> theChain_;


		//- private functions and operators

		std::shared_ptr<Mesh2d_KnitChain>& ChangeChain()
		{
			return theChain_;
		}

	public:

		CadSingularity_Horizon()
		{}

		CadSingularity_Horizon
		(
			const Standard_Integer theIndex
		)
			: Global_Indexed(theIndex)
		{}

		CadSingularity_Horizon
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<CadRepair_ApproxSurfMetric>& theMetric
		)
			: Global_Indexed(theIndex)
			, theMetric_(theMetric)
		{}

		CadSingularity_Horizon
		(
			const std::shared_ptr<CadRepair_ApproxSurfMetric>& theMetric
		)
			: theMetric_(theMetric)
		{}

		const std::shared_ptr<CadRepair_ApproxSurfMetric>& Metric() const
		{
			return theMetric_;
		}

		const std::shared_ptr<Mesh2d_KnitChain>& Chain() const
		{
			return theChain_;
		}

		Standard_Boolean IsLoaded() const;

		Standard_Boolean HasHorizon() const;

		Standard_Integer NbHorizons() const;

		const std::shared_ptr<Entity2d_Polygon>
			Horizon
			(
				const Standard_Integer theIndex
			) const;

		void LoadMetric
		(
			const std::shared_ptr<CadRepair_ApproxSurfMetric>& theMetric
		)
		{
			theMetric_ = theMetric;
		}

		void Perform();
	};
}

#endif // !_CadSingularity_Horizon_Header
