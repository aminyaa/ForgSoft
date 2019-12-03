#pragma once
#ifndef _Mesh2d_gPatch_Header
#define _Mesh2d_gPatch_Header

#include <Mesh_PatchTemplate.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <GModel_Surface.hxx>
#include <Mesh2d_gPlnRegionSurfaceFwd.hxx>

namespace AutLib
{

	typedef Mesh_PatchTemplate<GModel_Surface, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Mesh2d_gPatch;

	template<>
	virtual std::shared_ptr<Mesh2d_gPlnRegionSurface> Mesh2d_gPatch::GetPlane() const;
}

#endif // !_Mesh2d_gPatch_Header
