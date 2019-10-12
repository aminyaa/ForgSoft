#pragma once
namespace AutLib
{

	template<class CrvEntity>
	std::shared_ptr<Entity2d_Chain> 
		Mesh_PlnCurve<CrvEntity>::Discrete
	(
		const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
	) const
	{
		auto mesh =
			base::Discrete
			(
				entity::FirstParam(), entity::LastParam(),
				entity::Curve(), theInfo);
		return std::move(mesh);
	}

	template<class CrvEntity>
	std::shared_ptr<Entity2d_Chain> 
		Mesh_PlnCurve<CrvEntity>::Mesh
	(
		const std::shared_ptr<Mesh2d_SizeMapSurface>& theSizeMap, 
		const std::shared_ptr<Mesh_CurveInfo>& theInfo
	) const
	{
		auto mesh =
			base::Mesh
			(
				entity::FirstParam(), entity::LastParam(),
				entity::Curve(), theSizeMap, theInfo);
		return std::move(mesh);
	}

	template<class CrvEntity>
	std::shared_ptr<Entity2d_Chain>
		Mesh_PlnCurve<CrvEntity>::Mesh
		(
			const std::shared_ptr<Mesh2d_SizeMapAnIso>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		) const
	{
		auto mesh =
			base::Mesh
			(
				entity::FirstParam(), entity::LastParam(),
				entity::Curve(), theSizeMap, theInfo);
		return std::move(mesh);
	}

	template<class CrvEntity>
	std::shared_ptr<Entity2d_Chain>
		Mesh_PlnCurve<CrvEntity>::Mesh
		(
			const std::shared_ptr<Mesh2d_SizeMap>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		) const
	{
		auto mesh =
			base::Mesh
			(
				entity::FirstParam(), entity::LastParam(),
				entity::Curve(), theSizeMap, theInfo);
		return std::move(mesh);
	}

	template<class CrvEntity>
	template<class SizeMap>
	std::shared_ptr<Entity2d_Chain> 
		Mesh_PlnCurve<CrvEntity>::MeshTemp
	(
		const std::shared_ptr<SizeMap>& theSizeMap,
		const std::shared_ptr<Mesh_CurveInfo>& theInfo
	) const
	{
		auto mesh = Mesh(theSizeMap, theInfo);
		return std::move(mesh);
	}

	template<class CrvEntity>
	template<class SizeMap, class EdgeType>
	std::vector<std::shared_ptr<EdgeType>> 
		Mesh_PlnCurve<CrvEntity>::TopoMesh
	(
		const std::shared_ptr<Mesh_PlnCurve>& theCurve,
		const std::shared_ptr<SizeMap>& theSizeMap,
		const std::shared_ptr<Mesh_CurveInfo>& theInfo
	)
	{
		Debug_Null_Pointer(theSizeMap);

		auto mesh = theCurve->MeshTemp(theSizeMap, theInfo);

		Debug_Null_Pointer(mesh);

		const auto& Map = *theSizeMap;
		auto edges = EdgeType::GetTopology(*mesh, theCurve);
		for (const auto& x : edges)
		{
			Debug_Null_Pointer(x);
			x->SetCharLength(Map.CalcDistance(x->Node0()->Coord(), x->Node1()->Coord()));
			x->SetCentre(Map.CalcCentreOf(x->Node0()->Coord(), x->Node1()->Coord()));
		}
		return std::move(edges);
	}
}