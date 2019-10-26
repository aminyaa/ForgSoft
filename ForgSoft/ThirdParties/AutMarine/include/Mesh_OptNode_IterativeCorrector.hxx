#pragma once
#ifndef _Mesh_OptNode_IterativeCorrector_Header
#define _Mesh_OptNode_IterativeCorrector_Header

#include <Mesh_OptNode_Corrector.hxx>
#include <Mesh_OptNode_IterativeCorrectorInfo.hxx>

#include <memory>

namespace AutLib
{

	template<class AftMetricPrcsr>
	class Mesh_OptNode_IterativeCorrector
		: public Mesh_OptNode_Corrector<AftMetricPrcsr>
	{

	public:

		typedef Mesh_OptNode_Corrector<AftMetricPrcsr> base;

		typedef typename AftMetricPrcsr::frontType frontType;
		typedef typename AftMetricPrcsr::sizeFun sizeFun;
		typedef typename AftMetricPrcsr::metricFun metricFun;

		typedef typename sizeFun::ptType Point;

	private:

		/*Private Data*/

		const std::shared_ptr<AftMetricPrcsr>& theMetricMap_;

		const std::shared_ptr<Mesh_OptNode_IterativeCorrectorInfo>& theInfo_;

	public:

		Mesh_OptNode_IterativeCorrector
		(
			const Standard_Real theSize,
			const frontType& theFront,
			const Point& theP0,
			const std::shared_ptr<AftMetricPrcsr>& theMetricMap,
			const std::shared_ptr<Mesh_OptNode_IterativeCorrectorInfo>& theInfo
		)
			: Mesh_OptNode_Corrector<AftMetricPrcsr>(theSize, theFront, theP0)
			, theMetricMap_(theMetricMap)
			, theInfo_(theInfo)
		{}


		const std::shared_ptr<AftMetricPrcsr>& MetricMap() const
		{
			return theMetricMap_;
		}

		const std::shared_ptr<Mesh_OptNode_IterativeCorrectorInfo>& Info() const
		{
			return theInfo_;
		}

		void Perform() override;
	};
}

#include <Mesh_OptNode_IterativeCorrectorI.hxx>

#endif // !_Mesh_OptNode_IterativeCorrector_Header
