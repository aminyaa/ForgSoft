#pragma once
#ifndef _Aft_Model_Traits_Header
#define _Aft_Model_Traits_Header

#include <Aft2d_CoreFwd.hxx>
#include <Aft2d_CoreAnIsoFwd.hxx>
#include <Aft2d_CoreSurfaceFwd.hxx>
#include <Aft2d_EdgeFwd.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	class Cad2d_Plane;
	class GModel_Surface;
	class TModel_Surface;
	class Aft2d_Model_Cache;
	class Aft3d_Model_Cache;

	template<class ModelType, class SizeFun, class MetricFun = void> struct aft_model_traits {};

	template<class SizeFun> 
	struct aft_model_traits<Cad2d_Plane, SizeFun> 
	{
		typedef Aft2d_Edge frontType;
		typedef Aft2d_Element elementType;
		typedef Aft2d_OptNode_Calculator nodeCalculator;
		typedef Aft2d_FrontInfo frontInfo;
		typedef Aft2d_FrontGlobalData globalData;

		typedef Aft2d_Model_Cache cacheType;
	};

	template<class SizeFun, class MetricFun>
	struct aft_model_traits<Cad2d_Plane, SizeFun, MetricFun>
	{
		typedef Aft2d_EdgeAnIso frontType;
		typedef Aft2d_ElementAnIso elementType;
		typedef Aft2d_OptNodeAnIso_Calculator nodeCalculator;
		typedef Aft2d_FrontAnIsoInfo frontInfo;
		typedef Aft2d_FrontAnIsoGlobalData globalData;

		typedef Aft2d_Model_Cache cacheType;
	};

	template<class SizeFun, class MetricFun>
	struct aft_model_traits<GModel_Surface, SizeFun, MetricFun>
	{
		typedef Aft2d_EdgeSurface frontType;
		typedef Aft2d_ElementSurface elementType;
		typedef Aft2d_OptNodeSurface_Calculator nodeCalculator;
		typedef Aft2d_FrontSurfaceInfo frontInfo;
		typedef Aft2d_FrontSurfaceGlobalData globalData;

		typedef Aft2d_Model_Cache cacheType;
	};

	template<class SizeFun, class MetricFun>
	struct aft_model_traits<TModel_Surface, SizeFun, MetricFun>
	{
		typedef Aft2d_EdgeSurface frontType;
		typedef Aft2d_ElementSurface elementType;
		typedef Aft2d_OptNodeSurface_Calculator nodeCalculator;
		typedef Aft2d_FrontSurfaceInfo frontInfo;
		typedef Aft2d_FrontSurfaceGlobalData globalData;

		typedef Aft2d_Model_Cache cacheType;
	};
}

#endif // !_Aft_Model_Traits_Header
