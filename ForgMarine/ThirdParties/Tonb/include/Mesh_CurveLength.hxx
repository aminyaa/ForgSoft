#pragma once
#ifndef _Mesh_CurveLength_Header
#define _Mesh_CurveLength_Header

#include <Mesh_CurveEntity.hxx>

namespace tnbLib
{

	// Forward Declarations
	class NumAlg_AdaptiveInteg_Info;

	class Mesh_CurveLength
	{

	public:

		typedef NumAlg_AdaptiveInteg_Info info;

		template<class gCurveType, class MetricPrcsrType>
		static Standard_Real Length
		(
			const Mesh_CurveEntity<gCurveType, MetricPrcsrType>& theEntity,
			const Standard_Real theLower,
			const Standard_Real theUpper,
			info& theInfo
		);

		template<class gCurveType, class MetricPrcsrType>
		static Standard_Real Length
		(
			const Mesh_CurveEntity<gCurveType, MetricPrcsrType>& theEntity,
			info& theInfo
		);
	};
}

#include <Mesh_CurveLengthI.hxx>

#endif // !_Mesh_CurveLength_Header