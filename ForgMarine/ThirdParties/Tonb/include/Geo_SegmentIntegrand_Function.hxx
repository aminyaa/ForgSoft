#pragma once
#ifndef _Geo_SegmentIntegrand_Function_Header
#define _Geo_SegmentIntegrand_Function_Header

#include <NumAlg_IntegFunc.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class MetricPrcsrType>
	class Geo_SegmentIntegrand;

	template<class MetricPrcsrType, bool UnitLength>
	class Geo_SegmentIntegrand_Function
		: public NumAlg_IntegFunc
	{

		typedef Geo_SegmentIntegrand<MetricPrcsrType> entity;

		/*Private Data*/

		const entity& theEntity_;

	public:

		Geo_SegmentIntegrand_Function(const entity& theEntity)
			: theEntity_(theEntity)
		{}

		const entity& Entity() const
		{
			return theEntity_;
		}

		Standard_Real Value(const Standard_Real x) const override;
	};
}

#include <Geo_SegmentIntegrand_FunctionI.hxx>

#endif // !_Geo_SegmentIntegrand_Function_Header