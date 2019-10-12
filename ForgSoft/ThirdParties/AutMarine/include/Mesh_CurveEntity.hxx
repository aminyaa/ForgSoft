#pragma once
#ifndef _Mesh_CurveEntity_Header
#define _Mesh_CurveEntity_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	template<class CurveType, class SizeMap>
	class Mesh_CurveEntity
	{

		typedef typename CurveType::ptType Point;

		/*Private Data*/

		const CurveType& theCurve_;

		const SizeMap& theSizeMap_;

		Standard_Real theFirst_;
		Standard_Real theLast_;

	public:

		Mesh_CurveEntity
		(
			const CurveType& theCurve,
			const SizeMap& theSizeMap,
			const Standard_Real theFirst,
			const Standard_Real theLast
		)
			: theCurve_(theCurve)
			, theSizeMap_(theSizeMap)
			, theFirst_(theFirst)
			, theLast_(theLast)
		{}

		const CurveType& Curve() const
		{
			return theCurve_;
		}

		const SizeMap& SizeMap() const
		{
			return theSizeMap_;
		}

		Point Value(const Standard_Real x) const
		{
			return theCurve_.Value(x);
		}

		Standard_Real FirstParameter() const
		{
			return theFirst_;
		}

		Standard_Real& FirstParameter()
		{
			return theFirst_;
		}

		Standard_Real LastParameter() const
		{
			return theLast_;
		}

		Standard_Real& LastParameter()
		{
			return theLast_;
		}

		void SetFirstParameter(const Standard_Real theFirst)
		{
			theFirst_ = theFirst;
		}

		void SetLastParameter(const Standard_Real theLast)
		{
			theLast_ = theLast;
		}

		//- Static members
		static Standard_Real Integrand
		(
			const Standard_Real theParam,
			const Mesh_CurveEntity& theEntity
		)
		{
			auto first = theEntity.FirstParameter();
			auto last = theEntity.LastParameter();

			auto param = theParam;
			if (param < first) param = first;
			if (param > last) param = last;

			typename CurveType::ptType point;
			typename CurveType::vtType vector;

			theEntity.Curve().D1(param, point, vector);
			return theEntity.SizeMap().IntegrandPerSize(point, vector);
		}
	};
}

#endif // !_Mesh_CurveEntity_Header