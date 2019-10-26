#pragma once
#ifndef _Mesh_CurveLength_Header
#define _Mesh_CurveLength_Header

#include <Mesh_CurveEntity.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	class Mesh_CurveLength
	{

	public:

		typedef Numeric_AdaptIntegrationInfo info;

		template<class CurveType, class SizeMap>
		static Standard_Real Length
		(
			const Mesh_CurveEntity<CurveType, SizeMap>& theCurve,
			const Standard_Real theLower,
			const Standard_Real theUpper,
			info& theInfo
		);

		template<class CurveType, class SizeMap>
		static Standard_Real Length
		(
			const Mesh_CurveEntity<CurveType, SizeMap>& theCurve,
			info& theInfo
		)
		{
			return Length(theCurve, theCurve.FirstParameter(), theCurve.LastParameter(), theInfo);
		}
	};

	//extern std::shared_ptr<Numeric_AdaptIntegrationInfo> mesh_curve_length_info;
}

#include <Mesh_CurveLengthI.hxx>

#endif // !_Mesh_CurveLength_Header