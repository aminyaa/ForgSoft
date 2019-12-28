#pragma once
#ifndef _Mesh_PatchTemplate_Header
#define _Mesh_PatchTemplate_Header

#include <Standard_TypeDef.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnRegion;

	template<class SurfType, class SizeFun, class MetricFun>
	class Mesh_PatchTemplate
		: public SurfType
	{

		typedef Numeric_AdaptIntegrationInfo intgInfo;

		/*Private Data*/

	public:

		typedef typename SurfType::parCurveType parCurveType;
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

#include <Mesh_PatchTemplateI.hxx>

#endif // !_Mesh_PatchTemplate_Header
