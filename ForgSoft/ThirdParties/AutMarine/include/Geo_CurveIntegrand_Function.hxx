#pragma once
#ifndef _Geo_CurveIntegrand_Function_Header
#define _Geo_CurveIntegrand_Function_Header

#include <Numeric_IntegrationFunction.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class MetricPrcsrType>
	class Geo_CurveIntegrand;

	template<class CurveType, class MetricPrcsrType, bool UnitLength>
	class Geo_CurveIntegrand_Function
		: public Numeric_IntegrationFunction
	{

		typedef Geo_CurveIntegrand<CurveType, MetricPrcsrType> entity;

		/*Private Data*/

		const entity& theEntity_;

	public:

		Geo_CurveIntegrand_Function(const entity& theEntity)
			: theEntity_(theEntity)
		{}

		const entity& Entity() const
		{
			return theEntity_;
		}

		Standard_Real Value(const Standard_Real x) const override;
	};


	template<class CurveType>
	class Geo_CurveIntegrand_Function<CurveType, void, false>
		: public Numeric_IntegrationFunction
	{

		typedef Geo_CurveIntegrand<CurveType, void> entity;

		/*Private Data*/

		const entity& theEntity_;

	public:

		Geo_CurveIntegrand_Function(const entity& theEntity)
			: theEntity_(theEntity)
		{}

		const entity& Entity() const
		{
			return theEntity_;
		}

		Standard_Real Value(const Standard_Real x) const override;
	};
}

#include <Geo_CurveIntegrand_FunctionI.hxx>

#endif // !_Geo_CurveIntegrand_Function_Header
