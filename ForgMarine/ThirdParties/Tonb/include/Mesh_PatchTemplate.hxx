#pragma once
#ifndef _Mesh_PatchTemplate_Header
#define _Mesh_PatchTemplate_Header

#include <Standard_TypeDef.hxx>
#include <Mesh_PatchTemplate_Traits.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class NumAlg_AdaptiveInteg_Info;

	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnRegion;

	template<class SurfType, class SizeFun, class MetricFun>
	class Mesh_PatchTemplate
		: public SurfType
	{

		typedef NumAlg_AdaptiveInteg_Info intgInfo;

		/*Private Data*/

	public:

		typedef typename Mesh_PatchTemplate_Traits<SurfType>::parCurveType 
			parCurveType;
		typedef Mesh_PlnRegion<parCurveType, SizeFun, MetricFun>
			plnRegion;

		Mesh_PatchTemplate(const SurfType& theSurface)
			: SurfType(theSurface)
		{}

		virtual std::shared_ptr<plnRegion> GetPlane() const;

		//- Static functions and operators

		static std::shared_ptr<SurfType>
			ReParameterization
			(
				const SurfType& theSurface,
				const Standard_Real thsScale
			);

		static std::shared_ptr<SurfType>
			ReParameterization
			(
				const SurfType& theSurface,
				intgInfo& theInfo
			);
	};
}

//#include <Mesh_PatchTemplateI.hxx>

#endif // !_Mesh_PatchTemplate_Header