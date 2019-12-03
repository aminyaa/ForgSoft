#pragma once
#ifndef _Mesh2d_tPatch_Header
#define _Mesh2d_tPatch_Header

#include <Mesh_PatchTemplate.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <TModel_Surface.hxx>
#include <Mesh2d_tPlnRegionSurfaceFwd.hxx>

namespace AutLib
{

	typedef Mesh_PatchTemplate<TModel_Surface, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Mesh2d_tPatch;

	template<>
	virtual std::shared_ptr<Mesh2d_tPlnRegionSurface> Mesh2d_tPatch::GetPlane() const;
}

#endif // !_Mesh2d_tPatch_Header

