#pragma once
#ifndef _Mesh_CurveLength_Function_Header
#define _Mesh_CurveLength_Function_Header

#include <Numeric_AdaptIntegration.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class CurveType, class SizeMap>
	class Mesh_CurveEntity;

	template<class CurveType, class SizeMap>
	class Mesh_CurveLength_Function
		: public Numeric_AdaptIntegration_Value
	{

		typedef Mesh_CurveEntity<CurveType, SizeMap> entity;

		/*Private Data*/

		const entity& theEntity_;

	public:

		Mesh_CurveLength_Function
		(
			const entity& theEntity
		)
			: theEntity_(theEntity)
		{}

		Standard_Real Value(const Standard_Real x) const override;
	};
}

#include <Mesh_CurveLength_FunctionI.hxx>

#endif // !_Mesh_CurveLength_Function_Header