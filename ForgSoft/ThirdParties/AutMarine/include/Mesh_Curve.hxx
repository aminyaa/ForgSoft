#pragma once
#ifndef _Mesh_Curve_Header
#define _Mesh_Curve_Header

#include <Standard_Handle.hxx>
#include <Global_Done.hxx>
#include <Entity_Connectivity.hxx>
#include <Entity_StaticData.hxx>
#include <Mesh_CurveInfo.hxx>
#include <Mesh_CurveLength.hxx>

#include <memory>
#include <vector>


namespace AutLib
{

	/*class Mesh_CurveBase
	{

	public:

		static void InitRunTime();
	};*/

	template<class CurveType, class SizeMap>
	class Mesh_Curve
		: public Global_Done
		//, public Mesh_CurveBase
	{

		typedef Mesh_CurveInfo info;
		typedef typename SizeMap::ptType Point;

		typedef Entity_StaticData<Point, connectivity::dual> chain;
		typedef Mesh_CurveEntity<CurveType, SizeMap> entity;
		typedef Numeric_AdaptIntegrationInfo intgInfo;

		/*Private Data*/

		Handle(CurveType) theCurve_;

		Standard_Real theFirst_;
		Standard_Real theLast_;

		std::shared_ptr<SizeMap> theSizeMap_;

		std::shared_ptr<info> theInfo_;

		std::shared_ptr<chain> theChain_;


		void MakeChain(const std::vector<Standard_Real>& theParameters);



		//- Static functions and operators

	public:

		static Standard_Real CalcLength
		(
			const entity& theCurve,
			const Standard_Integer theMaxLevel,
			intgInfo& theInfo
		);

		static Standard_Real CalcLength
		(
			const entity& theCurve,
			const Standard_Integer theLevel,
			const Standard_Integer theMaxLevel,
			intgInfo& theInfo
		);

	private:

		static Standard_Real CalcNextParameter
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

		static Standard_Real CalcNextParameter
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
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const Handle(CurveType)& theCurve,
			const std::shared_ptr<SizeMap>& theSizeMap,
			const std::shared_ptr<info>& theInfo
		)
			: theFirst_(theFirst)
			, theLast_(theLast)
			, theCurve_(theCurve)
			, theSizeMap_(theSizeMap)
			, theInfo_(theInfo)
		{}

		const Handle(CurveType)& Curve() const
		{
			return theCurve_;
		}

		Standard_Real FirstParameter() const
		{
			return theFirst_;
		}

		Standard_Real LastParameter() const
		{
			return theLast_;
		}

		const std::shared_ptr<SizeMap>& Map() const
		{
			return theSizeMap_;
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		const std::shared_ptr<chain>& Mesh() const
		{
			return theChain_;
		}

		void LoadCurve
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const Handle(CurveType)& theCurve
		)
		{
			theFirst_ = theFirst;
			theLast_ = theLast;
			theCurve_ = theCurve;
		}

		void LoadMap(const std::shared_ptr<SizeMap>& theSizeMap)
		{
			theSizeMap_ = theSizeMap;
		}

		void LoadInfo(const std::shared_ptr<info>& theInfo)
		{
			theInfo_ = theInfo;
		}

		void Perform();
	};


}

#include <Mesh_CurveI.hxx>

#endif // !_Mesh_Curve_Header