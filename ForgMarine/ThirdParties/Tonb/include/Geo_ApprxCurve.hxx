#pragma once
#ifndef _Geo_ApprxCurve_Header
#define _Geo_ApprxCurve_Header

#include <Geo_Traits.hxx>
#include <Global_Done.hxx>
#include <Entity_StaticData.hxx>
#include <Entity_Connectivity.hxx>
#include <Geo_ApprxCurve_Info.hxx>

#include <memory>

namespace tnbLib
{

	template<class CurveType, bool RandSamples>
	class Geo_ApprxCurve
		: public Global_Done
	{

		typedef typename remove_pointer<CurveType>::type CurveTypeR;
		//typedef typename down_cast_point<typename CurveTypeR::ptType>::type Point;
		typedef typename cascadeLib::pt_type_from_curve<CurveTypeR>::ptType Point;

		typedef Entity_StaticData<Point, connectivity::dual> chain;
		typedef std::shared_ptr<chain> chain_ptr;

		typedef Geo_ApprxCurve_Info info;

		/*Private Data*/

		CurveType theCurve_;

		Standard_Real theFirst_;
		Standard_Real theLast_;

		std::shared_ptr<info> theInfo_;

		chain_ptr theChain_;

	public:

		Geo_ApprxCurve()
		{}

		Geo_ApprxCurve
		(
			const CurveType& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<info>& theInfo
		)
			: theCurve_(theCurve)
			, theFirst_(theFirst)
			, theLast_(theLast)
			, theInfo_(theInfo)
		{}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		const CurveType& Curve() const
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

		Standard_Boolean IsLoaded() const
		{
			return (Standard_Boolean)theCurve_;
		}

		const chain_ptr& Chain() const
		{
			return theChain_;
		}

		void LoadCurve
		(
			const CurveType& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<info>& theInfo
		)
		{
			theCurve_ = theCurve;

			theFirst_ = theFirst;
			theLast_ = theLast;

			theInfo_ = theInfo;

			Change_IsDone() = Standard_False;
		}

		void Perform();

		void Reset();
	};
}

#include <Geo_ApprxCurveI.hxx>

#endif // !_Geo_ApprxCurve_Header
