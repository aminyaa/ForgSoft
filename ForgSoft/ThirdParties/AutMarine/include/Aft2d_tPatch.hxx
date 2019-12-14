#pragma once
#ifndef _Aft2d_tPatch_Header
#define _Aft2d_tPatch_Header

#include <Mesh_PatchTemplate.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <TModel_Surface.hxx>
#include <Aft2d_tPlnRegionSurfaceFwd.hxx>

namespace AutLib
{

	typedef Mesh_PatchTemplate<TModel_Surface, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_tPatch;

	template<>
	virtual std::shared_ptr<Aft2d_tPlnRegionSurface> Aft2d_tPatch::GetPlane() const;
}

#endif // !_Aft2d_tPatch_Header

