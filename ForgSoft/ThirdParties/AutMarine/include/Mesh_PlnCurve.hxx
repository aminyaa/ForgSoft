#pragma once
#ifndef _Mesh_PlnCurve_Header
#define _Mesh_PlnCurve_Header

#include <Entity2d_Chain.hxx>
#include <Geo_ApprxCurveInfo.hxx>
#include <Mesh2d_SizeMapSurface.hxx>
#include <Mesh2d_SizeMapAnIso.hxx>
#include <Mesh2d_SizeMap.hxx>
#include <Mesh_CurveInfo.hxx>
#include <Mesh_PlnCurve_Discretizer.hxx>

namespace AutLib
{

	template<class CrvEntity>
	class Mesh_PlnCurve
		: public Mesh_PlnCurve_Discretizer<typename CrvEntity::gCurveType>
	{

		/*Private Data*/

	public:

		typedef Mesh_PlnCurve_Discretizer<typename CrvEntity::gCurveType> base;

		typedef typename CrvEntity::gCurveType gCurveType;
		typedef typename CrvEntity::infoType infoType;

		Mesh_PlnCurve(const CrvEntity& theCurve)
			: CrvEntity(theCurve)
		{}

		Mesh_PlnCurve
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const typename mesh_pln_curve_dicretizer_traits<gCurveType>::pType& theCurve,
			const std::shared_ptr<infoType>& theInfo
		)
			: CrvEntity(theFirst, theLast, theCurve, theInfo)
		{}

		std::shared_ptr<Entity2d_Chain> Discrete
		(
			const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
		) const;

		virtual std::shared_ptr<Entity2d_Chain> Mesh
		(
			const std::shared_ptr<Mesh2d_SizeMapSurface>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		) const;

		virtual std::shared_ptr<Entity2d_Chain> Mesh
		(
			const std::shared_ptr<Mesh2d_SizeMapAnIso>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		) const;

		virtual std::shared_ptr<Entity2d_Chain> Mesh
		(
			const std::shared_ptr<Mesh2d_SizeMap>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		) const;


		template<class SizeMap>
		std::shared_ptr<Entity2d_Chain> MeshTemp
		(
			const std::shared_ptr<SizeMap>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		) const;


		//- Static functions and operators

		template<class SizeMap, class EdgeType>
		static std::vector<std::shared_ptr<EdgeType>> TopoMesh
		(
			const std::shared_ptr<Mesh_PlnCurve>& theCurve,
			const std::shared_ptr<SizeMap>& theSizeMap,
			const std::shared_ptr<Mesh_CurveInfo>& theInfo
		);

	};
}

#include <Mesh_PlnCurveI.hxx>

#endif // !_Mesh_PlnCurve_Header
