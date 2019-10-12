#pragma once
#ifndef _Mesh_ReferenceValues_Header
#define _Mesh_ReferenceValues_Header

#include <Mesh_SurfaceSizeValues.hxx>
#include <Mesh_SurfaceCurvatureValues.hxx>
#include <Mesh_VariationRate.hxx>

namespace AutLib
{

	class Mesh_ReferenceValues
	{

	private:

		Standard_Real theBaseSize_;  // Specifies the reference length value for all relative size controls.

		Mesh_SurfaceSizeValues theSurfaceSize_;  // Surface size

		Mesh_SurfaceCurvatureValues theSurfaceCurvature_;  // Surface curvature

		Mesh_VariationRateInfo theDefaultGrowthRate_;
		Mesh_VariationRateInfo theBoundaryGrowthRate_;

	public:

		Mesh_ReferenceValues(const Standard_Real BaseSize);

		Standard_Real BaseSize() const;

		Mesh_VariationRateInfo DefaultGrowthRate() const;

		const Mesh_SurfaceSizeValues& SurfaceSize() const;

		const Mesh_SurfaceCurvatureValues& SurfaceCurvature() const;

		Mesh_SurfaceSizeValues& SurfaceSize();

		Mesh_SurfaceCurvatureValues& SurfaceCurvature();

		void SetDefaultGrowthRate(Mesh_VariationRateInfo Rate);
	};
}

#endif // !_Mesh_ReferenceValues_Header
