#pragma once
#ifndef _GModel_Tools_Header
#define _GModel_Tools_Header

#include <Standard_TypeDef.hxx>
#include <Entity2d_PolygonFwd.hxx>
#include <Entity3d_PolygonFwd.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class GModel_Curve;
	class GModel_parCurve;

	class GModel_Tools
	{

	public:


		static std::shared_ptr<Entity2d_Polygon>
			UniformDiscrete
			(
				const GModel_parCurve& theCurve,
				const Standard_Integer theNbSegments
			);

		static std::shared_ptr<Entity3d_Polygon>
			UniformDiscrete
			(
				const GModel_Curve& theCurve,
				const Standard_Integer theNbSegments
			);
	};
}

#endif // !_GModel_Tools_Header
