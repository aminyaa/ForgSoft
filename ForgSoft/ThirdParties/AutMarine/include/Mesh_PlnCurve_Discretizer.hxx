#pragma once
#ifndef _Mesh_PlnCurve_Discretizer_Header
#define _Mesh_PlnCurve_Discretizer_Header

#include <Mesh_TypeTraits.hxx>
#include <Entity2d_ChainFwd.hxx>
#include <Mesh2d_SizeMapSurface.hxx>
#include <Mesh2d_SizeMapAnIso.hxx>
#include <Mesh2d_SizeMap.hxx>
#include <Mesh_CurveInfo.hxx>

#include <memory>

namespace AutLib
{

	template<class gCurveType>
	struct mesh_pln_curve_dicretizer_traits
	{
		typedef std::shared_ptr<gCurveType> pType;
	};

	template<class gCurveType>
	class Mesh_PlnCurve_Discretizer
	{

		/*Private Data*/

	public:

		static std::shared_ptr<Entity2d_Chain> Mesh
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const typename mesh_pln_curve_dicretizer_traits<gCurveType>::pType& theCurve,
			const std::shared_ptr<Mesh2d_SizeMap>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		);

		static std::shared_ptr<Entity2d_Chain> Mesh
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const typename mesh_pln_curve_dicretizer_traits<gCurveType>::pType& theCurve,
			const std::shared_ptr<Mesh2d_SizeMapAnIso>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		);

		static std::shared_ptr<Entity2d_Chain> Mesh
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const typename mesh_pln_curve_dicretizer_traits<gCurveType>::pType& theCurve,
			const std::shared_ptr<Mesh2d_SizeMapSurface>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		);

		static std::shared_ptr<Entity2d_Chain> Discrete
		(
			const Standard_Real theFirst, 
			const Standard_Real theLast, 
			const typename mesh_pln_curve_dicretizer_traits<gCurveType>::pType& theCurve,
			const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
		);
	};
}

#endif // !_Mesh_PlnCurve_Discretizer_Header
