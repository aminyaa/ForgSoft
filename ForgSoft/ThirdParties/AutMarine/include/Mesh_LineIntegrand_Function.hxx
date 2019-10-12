#pragma once
#ifndef _Mesh_LineIntegrand_Function_Header
#define _Mesh_LineIntegrand_Function_Header

#include <Numeric_AdaptIntegration.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class SizeMap>
	class Mesh_LineIntegrand;

	template<class SizeMap, bool UnitLength>
	class Mesh_LineIntegrand_Function
		: public Numeric_AdaptIntegration_Value
	{

		typedef Mesh_LineIntegrand<SizeMap> entity;

		/*Private Data*/

		const entity& theEntity_;

	public:

		Mesh_LineIntegrand_Function
		(
			const entity& theEntity
		)
			: theEntity_(theEntity)
		{}

		const entity& Entity() const
		{
			return theEntity_;
		}

		Standard_Real Value(const Standard_Real x) const override;
	};
}

#include <Mesh_LineIntegrand_FunctionI.hxx>

#endif // !_Mesh_LineIntegrand_Function_Header