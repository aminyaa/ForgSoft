#pragma once
#ifndef _Mesh_SingularCurve_Header
#define _Mesh_SingularCurve_Header

#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <Mesh_PlnCurve.hxx>

#include <memory>

class Geom2d_Curve;
class Geom_Curve;
class Geom_Surface;

namespace AutLib
{

	template<class CurveType, class SizeFun, class MetricFun = void>
	class Mesh_SingularCurve
		: public Mesh_PlnCurve<CurveType, SizeFun, MetricFun>
	{

		/*Private Data*/

		//Handle(Geom_Curve) thePaired3d_;

	protected:

		typedef Mesh_PlnCurve<CurveType, SizeFun, MetricFun> base;

		typedef typename base::infoType info;
		typedef typename base::geomType geomType;

		Mesh_SingularCurve
		(
			const Handle(geomType)& theCurve,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const std::shared_ptr<info>& theInfo
		)
			: base(theFirst, theLast, theCurve, theInfo)
		{}


	public:

		typedef info infoType;

		/*const Handle(Geom_Curve)& Paired3d() const
		{
			return thePaired3d_;
		}

		void CreatePaired3d(const Geom_Surface& theSurface);*/

	};
}

#endif // !_Mesh_SingularCurve_Header
