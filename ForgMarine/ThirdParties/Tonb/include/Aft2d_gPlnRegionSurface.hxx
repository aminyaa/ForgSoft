#pragma once
#ifndef _Aft2d_gPlnRegionSurface_Header
#define _Aft2d_gPlnRegionSurface_Header

#include <Mesh_PlnRegion.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo2d_MetricFunction.hxx>

namespace tnbLib
{

	// Forward Declarations
	class GModel_ParaCurve;
	class GModel_Surface;
	class GModel_ParaWire;
	class GModel_Wire;

	template<class PlnCurve>
	class Mesh_PlnWire;

	template<>
	class Mesh_PlnRegion<GModel_ParaCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		: public Global_Indexed
		, public Global_Named
	{

	public:

		typedef Mesh_PlnCurve<GModel_ParaCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
			plnCurveType;

		typedef Mesh_PlnWire<plnCurveType> plnWireType;

		typedef std::shared_ptr<plnWireType > outer;
		typedef std::shared_ptr<std::vector<outer>> inner;
		typedef std::vector<std::shared_ptr<plnWireType>> wireList;

		typedef Geo2d_SizeFunction sizeFun;
		typedef Geo2d_MetricFunction metricFun;

	private:

		/*Private Data*/

		outer theOutter_;
		inner theInner_;

		std::shared_ptr<GModel_Surface> theSurface_;

	public:

		typedef GModel_Surface SurfType;

		Mesh_PlnRegion
		(
			const std::shared_ptr<GModel_Surface>& theSurface,
			const outer& theOuter,
			const inner& theInner = nullptr
		)
			: theSurface_(theSurface)
			, theOutter_(theOuter)
			, theInner_(theInner)
		{}

		Mesh_PlnRegion
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<GModel_Surface>& theSurface,
			const outer& theOuter,
			const inner& theInner = nullptr
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
			, theSurface_(theSurface)
			, theOutter_(theOuter)
			, theInner_(theInner)
		{}

		auto HasHole() const
		{
			return (Standard_Boolean)theInner_;
		}

		auto NbHoles() const
		{
			if (!HasHole()) return 0;
			return (Standard_Integer)theInner_->size();
		}

		const auto& Surface() const
		{
			return theSurface_;
		}

		const auto& Inner() const
		{
			return theInner_;
		}

		const auto& Outer() const
		{
			return theOutter_;
		}

		void RetrieveWiresTo(wireList& theWires) const;

		void ExportToPlt(OFstream& File) const;


		//- Static functions and operators

		static std::shared_ptr<plnWireType> MakeMeshWire(const GModel_Wire& theWire);

		static std::shared_ptr<Mesh_PlnRegion> MakePlane(const std::shared_ptr<GModel_Surface>& theSurface);
	};

	typedef Mesh_PlnRegion<GModel_ParaCurve, Geo2d_SizeFunction, Geo2d_MetricFunction>
		Aft2d_gPlnRegionSurface;
}

#endif // !_Aft2d_gPlnRegionSurface_Header