#pragma once
#ifndef _Mesh_SingularDetection_Header
#define _Mesh_SingularDetection_Header

#include <Global_Done.hxx>
#include <Global_Verbose.hxx>
#include <Global_AccessMethod.hxx>
#include <Entity2d_Polygon.hxx>
#include <Entity2d_Box.hxx>
#include <GeoMesh2d_Data.hxx>
#include <Geo3d_SizeFunction.hxx>
#include <Mesh_SingularDetection_Info.hxx>
#include <OFstream.hxx>

#include <memory>
#include <vector>

class Geom_Surface;

namespace AutLib
{

	// Forward Declarations
	class Mesh_SingularHorizon;
	class CadAnalys_ColoringSurfMetric;
	class Mesh_SingularDetection_Info;

	template<class SurfPln>
	class Mesh_SingularZone;

	template<class CurveType, class SizeFun, class MetricFun>
	class SingularCurve_Pole;

	template<class CurveType, class SizeFun, class MetricFun>
	class SingularCurve_Line;

	template<class SurfPln>
	class Mesh_SingularZone;

	template<class CurveType>
	class Mesh_SingularDetection_Base
	{

	protected:

		static std::shared_ptr<CurveType> ParametricCurve(const Entity2d_Polygon& thePoly);

		static std::shared_ptr<CurveType> ParametricCurve_Pole(const Entity2d_Polygon& thePoly);

		static std::shared_ptr<CurveType> ParametricCurve_Line(const Entity2d_Polygon& thePoly);

		static std::vector<std::shared_ptr<CurveType>>
			LineHorizonCurves_Dangle
			(
				const Entity2d_Box& theBox,
				const Standard_Integer s0
			);

		static std::vector<std::shared_ptr<CurveType>> 
			LineHorizonCurves_Corner
			(
				const Entity2d_Box& theBox,
				const Standard_Integer s0,
				const Geom_Surface& theSurface, 
				const Standard_Real theTol
			);

		static std::vector<std::shared_ptr<CurveType>>
			LineHorizonCurves_WholeSide
			(
				const Entity2d_Box& theBox, 
				const Standard_Integer s0
			);

		static std::vector<std::shared_ptr<CurveType>>
			LineHorizonCurves_Loop
			(
				const Entity2d_Box& theBox
			);

		static std::vector<std::shared_ptr<CurveType>>
			LineHorizonCurves_TwoSided
			(
				const Entity2d_Box& theBox,
				const Standard_Integer s0
			);


	};

	template<class SurfPln>
	class Mesh_SingularDetection
		: public Mesh_SingularDetection_Base<typename SurfPln::plnCurveType>
		, public Global_Done
		, public Global_Verbose
	{

		typedef Mesh_SingularDetection_Info info;
		typedef Mesh_SingularZone<SurfPln> singularZone;
		typedef std::vector<std::shared_ptr<singularZone>> zoneList;
		typedef Mesh_SingularDetection_Base<typename SurfPln::plnCurveType> base;

		typedef typename SurfPln::plnCurveType plnCurve;
		typedef typename SurfPln::sizeFun sizeFun;
		typedef typename SurfPln::metricFun metricFun;

		/*Private Data*/

		std::shared_ptr<Mesh_SingularHorizon> theHorizons_;
		std::shared_ptr<CadAnalys_ColoringSurfMetric> theColors_;

		std::shared_ptr<Geo3d_SizeFunction> theSizeFun_;

		std::shared_ptr<info> theInfo_;


		Standard_Integer theCount_;
		Standard_Real theWeight_;

		zoneList theZones_;


		//- private function and operators

		zoneList& ChangeZones()
		{
			return theZones_;
		}

		std::shared_ptr<singularZone> TypeDetection
		(
			const Entity2d_Polygon& thePoly, 
			const GeoMesh2d_Data& bMesh,
			const std::vector<std::shared_ptr<plnCurve>>& theSides,
			const Geom_Surface& theSurface,
			const sizeFun& theSize
		);

		std::shared_ptr<singularZone> TypeDetection
		(
			const Entity2d_Polygon& thePolygon0,
			const Entity2d_Polygon& thePolygon1,
			const GeoMesh2d_Data& bMesh,
			const std::vector<std::shared_ptr<plnCurve>>& theSides,
			const Geom_Surface& theSurface,
			const sizeFun& theSize
		);

	public:

		Mesh_SingularDetection()
			: theWeight_(1.25)
			, theCount_(0)
		{}

		Standard_Integer NbZones() const
		{
			return (Standard_Integer)theZones_.size();
		}

		const zoneList& Zones() const
		{
			return theZones_;
		}

		const std::shared_ptr<Mesh_SingularHorizon>& Horizons() const
		{
			return theHorizons_;
		}

		const std::shared_ptr<singularZone>& Zone(const Standard_Integer theIndex) const;

		const std::shared_ptr<CadAnalys_ColoringSurfMetric>& Colors() const
		{
			return theColors_;
		}

		const std::shared_ptr<Geo3d_SizeFunction>& SizeFunction() const
		{
			return theSizeFun_;
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		Standard_Boolean IsHorizonsLoaded() const;

		Standard_Boolean IsColorsLoaded() const;

		Standard_Boolean IsSizeFunLoaded() const;

		Standard_Boolean IsInfoLoaded() const;

		void LoadHorizons(const std::shared_ptr<Mesh_SingularHorizon>& theHorizons)
		{
			theHorizons_ = theHorizons;
		}

		void LoadColors(const std::shared_ptr<CadAnalys_ColoringSurfMetric>& theColors)
		{
			theColors_ = theColors;
		}

		void LoadSizeFunction(const std::shared_ptr<Geo3d_SizeFunction>& theFun)
		{
			theSizeFun_ = theFun;
		}

		void LoadInfo(const std::shared_ptr<info>& theInfo)
		{
			theInfo_ = theInfo;
		}

		void Perform();

		void ExportToPlt(OFstream& File) const;


		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Weight)
	};
}

#include <Mesh_SingularDetectionI.hxx>

#endif // !_Mesh_SingularDetection_Header
