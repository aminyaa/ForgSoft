#pragma once
#ifndef _SizeMap2d_FullIntAnIso_Header
#define _SizeMap2d_FullIntAnIso_Header

#include <Global_InitRunTime.hxx>
#include <Mesh2d_SizeMapAnIso.hxx>
#include <Mesh2d_MetricMap.hxx>
#include <Aft2d_EdgeAnIso.hxx>

#include <memory>

namespace AutLib
{

	struct SizeMap2d_FullIntAnIsoCache
	{
		mutable Entity2d_Metric1 CurrentMetric;
	};

	// Forward Declarations
	template<class SizeMap>
	class Mesh_LineIntegrand;

	template<class SizeMap, bool UnitLength>
	class Mesh_LineIntegrand_Function;

	template<class Function, bool RefInfo>
	class Numeric_AdaptIntegration;

	class SizeMap2d_FullIntAnIso;
	class Numeric_AdaptIntegrationInfo;
	class Entity2d_Eigen;
	class SizeMap2d_FullIntAnIsoInfo;

	typedef Mesh_LineIntegrand<SizeMap2d_FullIntAnIso> Mesh_LineIntegrand_FullIntAnIso;
	typedef Mesh_LineIntegrand_Function<SizeMap2d_FullIntAnIso, false>
		Mesh_LineIntegrand_Function_FullIntAnIso;

	typedef Mesh_LineIntegrand_Function<SizeMap2d_FullIntAnIso, true>
		Mesh_LineIntegrand_UnitLengthFunction_FullIntAnIso;

	typedef Numeric_AdaptIntegration<Mesh_LineIntegrand_Function_FullIntAnIso, true>
		Numeric_AdaptIntegration_FullIntAnIso;

	typedef Numeric_AdaptIntegration<Mesh_LineIntegrand_UnitLengthFunction_FullIntAnIso, true>
		Numeric_AdaptIntegration_UnitLengthFullIntAnIso;

	class SizeMap2d_FullIntAnIso
		: public Mesh2d_SizeMapAnIso
		, public Global_InitRunTime
		, public SizeMap2d_FullIntAnIsoCache
	{

		typedef SizeMap2d_FullIntAnIsoInfo info;

		/*Private Data*/

		std::shared_ptr<Mesh2d_SizeMapAnIso> theSizeMap_;
		std::shared_ptr<Mesh2d_MetricMap> theMetricMap_;

		std::shared_ptr<info> theInfo_;

		Entity2d_Box theBoundingBox_;


		Pnt2d CorrEffRegion(const Pnt2d& theCentre, const Pnt2d& theP, const Standard_Real theRadius) const;

	protected:

		Entity2d_Box& Change_BoundingBox()
		{
			return theBoundingBox_;
		}

	public:

		typedef Aft2d_EdgeAnIso front;

		SizeMap2d_FullIntAnIso
		(
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
		{}

		Standard_Real DimSize() const override;

		const Entity2d_Box& BoundingBox() const override
		{
			return theBoundingBox_;
		}

		//- exclusive functions and operators

		const std::shared_ptr<Mesh2d_SizeMapAnIso>& SizeMap() const
		{
			return theSizeMap_;
		}

		const std::shared_ptr<Mesh2d_MetricMap>& MetricMap() const
		{
			return theMetricMap_;
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		Standard_Boolean IsLoaded() const
		{
			if (NOT theSizeMap_) return Standard_False;
			if (NOT theMetricMap_) return Standard_False;
			return Standard_True;
		}

		void LoadSizeMap
		(
			const std::shared_ptr<Mesh2d_SizeMapAnIso>& theMap
		)
		{
			theSizeMap_ = theMap;
		}

		void LoadMetricMap
		(
			const std::shared_ptr<Mesh2d_MetricMap>& theMap
		)
		{
			theMetricMap_ = theMap;
		}


		//- override virtual functions

		Standard_Real BaseElementSize() const override;

		Standard_Real CalcElementSize
		(
			const Pnt2d&
		) const override;

		Standard_Real CalcElementSize
		(
			const front&
		) const override;

		Standard_Real Oriented
		(
			const Pnt2d&,
			const front&
		) const override;

		Standard_Real CalcDistance
		(
			const Pnt2d&,
			const Pnt2d&
		) const override;

		Standard_Real CalcSquareDistance
		(
			const Pnt2d&,
			const Pnt2d&
		) const override;

		Standard_Real CalcDistance
		(
			const Pnt2d&,
			const front&
		) const override;

		Standard_Real CalcSquareDistance
		(
			const Pnt2d&,
			const front&
		) const override;

		Standard_Real CalcUnitDistance
		(
			const Pnt2d&,
			const Pnt2d&
		) const override;

		Pnt2d CalcOptimumCoord
		(
			const Standard_Real theSize,
			const front&
		) const override;

		Pnt2d CalcCentreOf
		(
			const Pnt2d&,
			const Pnt2d&
		) const override;

		Pnt2d CalcCentreOf
		(
			const frontType&
		) const;

		box CalcSearchRegion
		(
			const Standard_Real theRadius,
			const metric& theMetric,
			const Pnt2d& theCentre
		) const override;

		box CalcSearchRegion
		(
			const Standard_Real theRadius,
			const Pnt2d& theCentre,
			const front&
		) const override;

		box CalcSearchRegion
		(
			const Standard_Real theRadius,
			const front&
		) const override;

		box CalcEffectiveRegion
		(
			const Standard_Real theRadius,
			const Point& theCentre,
			const frontType&
		) const override;

		metric CalcEffectiveMetric
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		) const override;

		Standard_Real Integrand
		(
			const Pnt2d& thePoint,
			const Pnt2d& theVector
		) const override;

		Standard_Real Integrand
		(
			const Pnt2d& thePoint,
			const gp_Vec2d& theVector
		) const override;

		Standard_Real IntegrandPerSize
		(
			const Pnt2d& thePoint,
			const Pnt2d& theVector
		) const override;

		Standard_Real IntegrandPerSize
		(
			const Pnt2d& thePoint,
			const gp_Vec2d& theVector
		) const override;

		void Make() override;
	};

	extern std::shared_ptr<Entity2d_Eigen>
		size_map2d_full_aniso_adapt_eigen;
}

#include <SizeMap2d_FullIntAnIsoI.hxx>

#endif // !_SizeMap2d_FullIntAnIso_Header