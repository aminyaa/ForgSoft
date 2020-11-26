#pragma once
#ifndef _Mesh_Curve_Header
#define _Mesh_Curve_Header

#include <Standard_Handle.hxx>
#include <Global_Done.hxx>
#include <Entity_Connectivity.hxx>
#include <Entity_StaticData.hxx>
#include <Geo_Traits.hxx>
#include <Mesh_Curve_Info.hxx>
#include <Mesh_CurveEntity.hxx>

namespace tnbLib
{

	// Forward Declarations
	class NumAlg_AdaptiveInteg_Info;

	class Mesh_Curve_Base
	{

		typedef Mesh_Curve_Info info;

		/*Private Data*/

		Standard_Real theFirstParameter_;
		Standard_Real theLastParameter_;

		std::shared_ptr<info> theInfo_;

	protected:

		Mesh_Curve_Base();

		Mesh_Curve_Base
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<info>& theInfo
		);

		auto& ChangeFirstParameter()
		{
			return theFirstParameter_;
		}

		auto& ChangeLastParameter()
		{
			return theLastParameter_;
		}

	public:

		auto FirstParameter() const
		{
			return theFirstParameter_;
		}

		auto LastParameter() const
		{
			return theLastParameter_;
		}

		const auto& Info() const
		{
			return theInfo_;
		}

		void LoadInfo(const std::shared_ptr<info>& theInfo)
		{
			theInfo_ = theInfo;
		}

	};


	template<class gCurveType, class MetricPrcsrType>
	class Mesh_Curve
		: public Global_Done
		, public Mesh_Curve_Base
	{

		typedef typename cascadeLib::pt_type_from_curve<gCurveType>::ptType Point;

		typedef Mesh_Curve_Info info;
		typedef NumAlg_AdaptiveInteg_Info intgInfo;
		typedef Entity_StaticData<Point, connectivity::dual> chain;
		typedef Mesh_CurveEntity<gCurveType, MetricPrcsrType> entity;


		/*Private Data*/

		Handle(gCurveType) theCurve_;

		std::shared_ptr<MetricPrcsrType> theMetricMap_;

		std::shared_ptr<chain> theChain_;


		//- private functions and operators

		void MakeChain
		(
			const std::vector<Standard_Real>& theParameters
		);

		static Standard_Real
			CalcNextParameter
			(
				const Standard_Real theU0,
				const Standard_Real theGuess,
				const Standard_Real theStep,
				const Standard_Real theUmax,
				const Standard_Integer theLevel,
				const Standard_Integer theMaxLevel,
				const entity& theCurve,
				const info& theInfo
			);

		static Standard_Real
			CalcNextParameter
			(
				const Standard_Real theU0,
				const Standard_Real theGuess,
				const Standard_Real theStep,
				const Standard_Real theUmax,
				const entity& theCurve,
				const info& theInfo
			);


	public:

		Mesh_Curve()
		{}

		Mesh_Curve
		(
			const Handle(gCurveType)& theCurve,
			const Standard_Real theU0,
			const Standard_Real theU1,
			const std::shared_ptr<MetricPrcsrType>& theMetricMap,
			const std::shared_ptr<info>& theInfo
		);

		const Handle(gCurveType)& Geometry() const
		{
			return theCurve_;
		}

		const auto& MetricMap() const
		{
			return theMetricMap_;
		}

		const auto& Mesh() const
		{
			return theChain_;
		}

		void LoadCurve
		(
			const Handle(gCurveType)& theCurve,
			const Standard_Real theU0,
			const Standard_Real theU1
		);

		void LoadMap
		(
			const std::shared_ptr<MetricPrcsrType>& theSizeMap
		);


		void Perform();


		//- static functions and operators

		static Standard_Real
			CalcLength
			(
				const entity& theEntity,
				const Standard_Integer theMaxLevel,
				intgInfo& theInfo
			);

		static Standard_Real
			CalcLength
			(
				const entity& theEntity,
				const Standard_Integer theLevel,
				const Standard_Integer theMaxLevel,
				intgInfo& theInfo
			);
	};
}

#include <Mesh_CurveI.hxx>

#endif // !_Mesh_Curve_Header