#pragma once
#ifndef _Marine_Wave_Header
#define _Marine_Wave_Header

#include <Global_Done.hxx>
#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_AccessMethod.hxx>
#include <Pnt2d.hxx>
#include <Pnt3d.hxx>
#include <Dir3d.hxx>
#include <EnvPropt_Density.hxx>
#include <Entity3d_BoxFwd.hxx>

#include <Standard_Handle.hxx>
#include <gp_Ax2.hxx>

class Geom_Surface;
class Geom2d_Curve;

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	namespace marineLib
	{
		class Density;
	}

	class Marine_WaveGeometry
	{

		/*Private Data*/

		Handle(Geom_Surface) theSurfaceGeometry_;
		Handle(Geom2d_Curve) theCurveGeometry_;

	protected:

		Marine_WaveGeometry()
		{}

		auto& ChangeSurfaceGeometry()
		{
			return theSurfaceGeometry_;
		}

		auto& ChangeCurveGeometry()
		{
			return theCurveGeometry_;
		}

	public:

		Standard_Boolean HasSurfaceGeometry() const
		{
			return (Standard_Boolean)theSurfaceGeometry_;
		}

		Standard_Boolean HasCurveGeometry() const
		{
			return (Standard_Boolean)theCurveGeometry_;
		}

		const auto& SurfaceGeometry() const
		{
			return theSurfaceGeometry_;
		}

		const auto& CurveGeometry() const
		{
			return theCurveGeometry_;
		}

	};

	class Marine_WaveDensity
	{

		/*Private Data*/

		marineLib::Density theLightFluidDensity_;
		marineLib::Density theHeavyFluidDensity_;

	protected:

		Marine_WaveDensity();

	public:

		//- Macros

		GLOBAL_ACCESS_SINGLE(marineLib::Density, LightFluidDensity)
			GLOBAL_ACCESS_SINGLE(marineLib::Density, HeavyFluidDensity)
	};

	struct Marine_WaveCache
	{
		mutable gp_Trsf originToCurrentTransform;
	};

	class Marine_Wave
		: public Global_Indexed
		, public Global_Named
		, public Global_Done
		, public Marine_WaveDensity
		, public Marine_WaveGeometry
		, public Marine_WaveCache
		, public std::enable_shared_from_this<Marine_Wave>
	{

		/*Private Data*/

		Pnt3d thePointOnWater_;

		Dir3d theVerticalDirection_;
		
		Vec3d theCurrent_;
		Vec3d theWind_;

		const Entity3d_Box& theDomain_;
		gp_Ax2 theOrigin_;

		Pnt3d ProjectedCoordOnSurface() const;

		Entity3d_Box BoundingBoxOfRotatedDomain(const Entity3d_Box& theDomain) const;

		void TransformOriginToCurrent() const;

	protected:

		Marine_Wave(const Entity3d_Box& theDomain)
			: theDomain_(theDomain)
		{}

		virtual Vec3d SurfaceDirection() const = 0;

		virtual void MakeProfileCurve(const Pnt2d& x0, const Pnt2d& x1) = 0;

		void MakeGeometrySurface(const Standard_Real y0, const Standard_Real y1);

		void TransportGeometrySurface();

		void TranslateSurfaceToPointOnWater(const Pnt3d& theProj);

	public:

		const auto& Origin() const
		{
			return theOrigin_;
		}

		const auto& Domain() const
		{
			return theDomain_;
		}

		gp_Ax2 SurfaceCoordinateSystem() const;

		void Perform();

		//- Macros
		GLOBAL_ACCESS_SINGLE(Pnt3d, PointOnWater)

			GLOBAL_ACCESS_SINGLE(Dir3d, VerticalDirection)
			GLOBAL_ACCESS_SINGLE(Vec3d, Current)
			GLOBAL_ACCESS_SINGLE(Vec3d, Wind)

			
	};
}

#endif // !_Marine_Wave_Header
