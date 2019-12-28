#pragma once
#ifndef _TModel_Tools_Header
#define _TModel_Tools_Header

#include <Standard_TypeDef.hxx>
#include <Entity2d_PolygonFwd.hxx>
#include <Entity3d_PolygonFwd.hxx>

class TopoDS_Face;
class TopoDS_Shape;

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class TModel_Edge;
	class TModel_Surface;
	class TModel_Shell;
	class TModel_Curve;
	class TModel_parCurve;
	class Cad3d_TModel;
	class Geo_ApprxCurveInfo;

	class TModel_Tools
	{

	public:

		static void DicreteEdges
		(
			const TModel_Surface& theSurface,
			const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
		);

		static void DicreteEdges
		(
			const Cad3d_TModel& theModel, 
			const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
		);

		static std::shared_ptr<Entity2d_Polygon> 
			UniformDiscrete
			(
				const TModel_parCurve& theCurve, 
				const Standard_Integer theNbSegments
			);

		static std::shared_ptr<Entity3d_Polygon> 
			UniformDiscrete
			(
				const TModel_Curve& theCurve,
				const Standard_Integer theNbSegments
			);

		static std::vector<std::shared_ptr<TModel_Edge>> 
			RetrieveEdges
			(
				const std::vector<std::shared_ptr<TModel_Surface>>& theSurfaces
			);

		static std::shared_ptr<TModel_Surface>
			GetSurface
			(
				const TopoDS_Face& theFace
			);

		static std::vector<std::shared_ptr<TModel_Surface>>
			GetSurfaces
			(
				const TopoDS_Shape& theShape
			);

		static std::shared_ptr<std::vector<std::shared_ptr<TModel_Shell>>> TrackShells
		(
			const std::vector<std::shared_ptr<TModel_Surface>>& theSurfaces
		);

		//- Warning: This function is on the early stage!
		static Standard_Boolean InnerHoles
		(
			const std::vector<std::shared_ptr<TModel_Shell>>& theShells,
			std::vector<std::shared_ptr<TModel_Shell>>& theInners,
			std::shared_ptr<TModel_Shell>& theOuters
		);

		static std::vector<std::shared_ptr<TModel_Edge>> 
			RetrieveNonSingularEdges
			(
				const std::vector<std::shared_ptr<TModel_Surface>>& theSurfaces
			);


	};
}

#endif // !_TModel_Tools_Header
