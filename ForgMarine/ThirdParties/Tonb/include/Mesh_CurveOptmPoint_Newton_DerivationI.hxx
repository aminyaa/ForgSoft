#pragma once
namespace tnbLib
{

	template<class gCurveType, class MetricPrcsrType>
	Mesh_CurveOptmPoint_Newton_Derivation<gCurveType, MetricPrcsrType>::Mesh_CurveOptmPoint_Newton_Derivation
	(
		const entity& theEntity
	)
		: theEntity_(theEntity)
	{
		Lower() = Entity().FirstParameter();
		Upper() = Entity().LastParameter();
	}
}