#pragma once
#ifndef _CadSingularity_Detection_Header
#define _CadSingularity_Detection_Header

#include <Global_Done.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <CadSingularity_Detection_Info.hxx>
#include <CadSingularity_Detection_Base.hxx>
#include <Cad_SingularZone.hxx>
#include <GeoMesh2d_DataFwd.hxx>
#include <Geo2d_SizeFunction.hxx>

#include <vector>
#include <memory>

class Geom_Surface;

#include "GModel_Plane.hxx"
#include "GModel_parCurve.hxx"

namespace AutLib
{

	// Forward Declarations
	class CadSingularity_Horizon;
	class CadRepair_ColoringSurfMetric;
	class Pln_Curve;

	template<class SurfPln>
	class CadSingularity_Detection
		: public CadSingularity_Detection_Base<typename SurfPln::parCurveType>
		, public Global_Done
	{

		typedef CadSingularity_Detection_Info info;
		typedef CadSingularity_Detection_Base<typename SurfPln::parCurveType> base;
		typedef Cad_SingularZone<SurfPln> singularZone;
		typedef std::vector<std::shared_ptr<singularZone>> zoneList;
		typedef Geo2d_SizeFunction sizeFun;
		typedef typename SurfPln::parCurveType plnCurve;

		/*Private Data*/

		std::shared_ptr<CadSingularity_Horizon> theHorizons_;
		std::shared_ptr<CadRepair_ColoringSurfMetric> theColors_;

		std::shared_ptr<sizeFun> theSizeFun_;

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
			const std::vector<std::shared_ptr<Pln_Curve>>& theSides,
			const Geom_Surface& theSurface,
			const sizeFun& theSize
		);

		std::shared_ptr<singularZone> TypeDetection
		(
			const Entity2d_Polygon& thePolygon0,
			const Entity2d_Polygon& thePolygon1,
			const GeoMesh2d_Data& bMesh,
			const std::vector<std::shared_ptr<Pln_Curve>>& theSides,
			const Geom_Surface& theSurface,
			const sizeFun& theSize
		);

	public:

		CadSingularity_Detection()
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

		const std::shared_ptr<CadSingularity_Horizon>& Horizons() const
		{
			return theHorizons_;
		}

		const std::shared_ptr<singularZone>& Zone(const Standard_Integer theIndex) const;

		const std::shared_ptr<CadRepair_ColoringSurfMetric>& Colors() const
		{
			return theColors_;
		}

		const std::shared_ptr<sizeFun>& SizeFunction() const
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

		void LoadHorizons(const std::shared_ptr<CadSingularity_Horizon>& theHorizons)
		{
			theHorizons_ = theHorizons;
		}

		void LoadColors(const std::shared_ptr<CadRepair_ColoringSurfMetric>& theColors)
		{
			theColors_ = theColors;
		}

		void LoadSizeFunction(const std::shared_ptr<sizeFun>& theFun)
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

#include <CadSingularity_DetectionI.hxx>

#endif // !_CadSingularity_Detection_Header
