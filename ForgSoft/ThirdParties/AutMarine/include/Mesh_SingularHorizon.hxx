#pragma once
#ifndef _Mesh_SingularHorizon_Header
#define _Mesh_SingularHorizon_Header

#include <Global_Done.hxx>
#include <Global_Indexed.hxx>
#include <Entity2d_PolygonFwd.hxx>
#include <Mesh2d_KnitChainFwd.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class CadAnalys_ApprxSurfMetric;

	class Mesh_SingularHorizon
		: public Global_Done
		, public Global_Indexed
	{

		/*Private Data*/

		std::shared_ptr<CadAnalys_ApprxSurfMetric> theMetric_;

		std::shared_ptr<Mesh2d_KnitChain> theChain_;


		//- private functions and operators

		std::shared_ptr<Mesh2d_KnitChain>& ChangeChain()
		{
			return theChain_;
		}

	public:

		Mesh_SingularHorizon()
		{}

		Mesh_SingularHorizon
		(
			const Standard_Integer theIndex
		)
			: Global_Indexed(theIndex)
		{}

		Mesh_SingularHorizon
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<CadAnalys_ApprxSurfMetric>& theMetric
		)
			: Global_Indexed(theIndex)
			, theMetric_(theMetric)
		{}

		Mesh_SingularHorizon
		(
			const std::shared_ptr<CadAnalys_ApprxSurfMetric>& theMetric
		)
			: theMetric_(theMetric)
		{}

		const std::shared_ptr<CadAnalys_ApprxSurfMetric>& Metric() const
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
			const std::shared_ptr<CadAnalys_ApprxSurfMetric>& theMetric
		)
		{
			theMetric_ = theMetric;
		}

		void Perform();

	};

}

#endif // !_Mesh_SingularHorizon_Header
