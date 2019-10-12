#pragma once
namespace AutLib
{

	template<class SurfEntity>
	std::shared_ptr<Mesh_SurfPlane<SurfEntity>> 
		Mesh_SurfaceTemplate<SurfEntity>::GetPlane() const
	{
		auto This = 
			std::dynamic_pointer_cast<Mesh_SurfaceTemplate<SurfEntity>>
			(
				std::const_pointer_cast<SurfEntity>(this->shared_from_this())
				);
		auto plane = Mesh_SurfPlane<SurfEntity>::MakePlane(This);
		return std::move(plane);
	}
}