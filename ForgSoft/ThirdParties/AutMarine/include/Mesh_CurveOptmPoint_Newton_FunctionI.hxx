#pragma once
namespace AutLib
{

	template<class gCurveType, class MetricPrcsrType>
	Mesh_CurveOptmPoint_Newton_Function<gCurveType, MetricPrcsrType>::Mesh_CurveOptmPoint_Newton_Function
	(
		const Standard_Real theX0,
		const Standard_Real theStep, 
		const entity& theCurve, 
		const std::shared_ptr<info>& theInfo
	)
		: Mesh_CurveOptmPoint_Newton_Function_Base(theX0, theStep, theInfo)
		, theCurve_(theCurve)
	{
		Lower() = Entity().FirstParameter();
		Upper() = Entity().LastParameter();
	}

	template<class gCurveType, class MetricPrcsrType>
	Standard_Real Mesh_CurveOptmPoint_Newton_Function<gCurveType, MetricPrcsrType>::Value(const Standard_Real x) const
	{
		Geo_CurveIntegrand<gCurveType, MetricPrcsrType> Integrand(Entity().Curve(), Entity().SizeMap());
		return GeoLib::CalcCurveLength<gCurveType, MetricPrcsrType>::_(Integrand, X0(), x, *Info()) - Step();
	}
}