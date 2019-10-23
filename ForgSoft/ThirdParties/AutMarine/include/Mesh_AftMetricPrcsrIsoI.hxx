#pragma once
namespace AutLib
{

	template<class SizeFun, class FrontType>
	Standard_Real Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::CalcElementSize
	(
		const frontType & theFront
	) const
	{
		return base::CalcElementSize(theFront.Centre());
	}

	template<class SizeFun, class FrontType>
	Standard_Real Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::Oriented
	(
		const Point & thePt, 
		const frontType & theFront
	) const
	{
		return theFront.Oriented(thePt);
	}

	template<class SizeFun, class FrontType>
	Standard_Real Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::CalcDistance
	(
		const Point & thePt,
		const frontType & theFront
	) const
	{
		return theFront.CalcDistance(thePt);
	}

	template<class SizeFun, class FrontType>
	Standard_Real Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::CalcSquareDistance
	(
		const Point & thePt,
		const frontType & theFront
	) const
	{
		return theFront.CalcSquareDistance(thePt);
	}

	template<class SizeFun, class FrontType>
	typename Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::Point 
		Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::CalcCentreOf
		(
			const frontType & theFront
		) const
	{
		return theFront.Centre();
	}

	template<class SizeFun, class FrontType>
	typename Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::box 
		Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::CalcSearchRegion
		(
			const Standard_Real theRadius,
			const Point & theCentre
		) const
	{
		auto b = box(theCentre - theRadius, theCentre + theRadius);
		return std::move(b);
	}

	template<class SizeFun, class FrontType>
	typename Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::box
		Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::CalcSearchRegion
		(
			const Standard_Real theRadius,
			const Point & theCentre, 
			const frontType & /*theFront*/
		) const
	{
		auto b = box(theCentre - theRadius, theCentre + theRadius);
		return std::move(b);
	}

	template<class SizeFun, class FrontType>
	typename Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::box
		Mesh_AftMetricPrcsrIso_Base<SizeFun, FrontType>::CalcEffectiveFront
		(
			const Standard_Real theRadius,
			const Point & theCentre,
			const frontType & /*theFront*/
		) const
	{
		auto b = box(theCentre - theRadius, theCentre + theRadius);
		return std::move(b);
	}
}