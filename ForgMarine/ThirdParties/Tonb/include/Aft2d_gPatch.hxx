#pragma once
#ifndef _Aft2d_gPatch_Header
#define _Aft2d_gPatch_Header

#include <Mesh_PatchTemplate.hxx>
#include <Geo2d_SizeFunctionFwd.hxx>
#include <Geo2d_MetricFunctionFwd.hxx>
#include <GModel_Surface.hxx>
#include <Aft2d_gPlnRegionSurfaceFwd.hxx>

namespace tnbLib
{

	typedef Mesh_PatchTemplate<GModel_Surface, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_gPatch;

	template<>
	virtual std::shared_ptr<Aft2d_gPlnRegionSurface> Aft2d_gPatch::GetPlane() const;
}

#endif // !_Aft2d_gPatch_Header