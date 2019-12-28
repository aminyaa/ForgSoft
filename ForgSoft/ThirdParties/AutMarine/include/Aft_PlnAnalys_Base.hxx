#pragma once
#ifndef _Aft_PlnAnalys_Base_Header
#define _Aft_PlnAnalys_Base_Header

#include <Standard_TypeDef.hxx>
#include <Aft_PlnAnalys_Traits.hxx>
#include <Aft_MetricPrcsr.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	template<class RegionType, class SizeFun, class MetricFun>
	class Aft_PlnBoundary;

	template<class FrontType, class SizeFun, class MetricFun>
	class Aft_MetricPrcsr;

	template<class CurveType, class SizeFun, class MetricFun>
	class Mesh_PlnRegion;

	template<class PlnType, class SizeFun, class MetricFun>
	class Aft_PlnAnalys_Base
	{

	public:

		typedef typename Aft_PlnAnalys_Traits
			<PlnType, SizeFun, MetricFun>::frontType
			frontType;
		typedef typename Aft_PlnAnalys_Traits
			<PlnType, SizeFun, MetricFun>::curveType
			curveType;
		typedef typename Aft_PlnAnalys_Traits
			<PlnType, SizeFun, MetricFun>::regionType
			regionType;

		typedef Aft_PlnBoundary<regionType, SizeFun, MetricFun>
			plnMesher;
		typedef Aft_MetricPrcsr<frontType, SizeFun, MetricFun>
			metricMap;

	private:

		/*private Data*/

		std::shared_ptr<PlnType> thePlane_;
		std::shared_ptr<metricMap> theMetricMap_;

		std::shared_ptr<regionType> theRegion_;
		std::shared_ptr<plnMesher> theMesher_;

		Standard_Boolean Check_;

	protected:

		Standard_Boolean& ChangeCheck()
		{
			return Check_;
		}

		std::shared_ptr<regionType>& ChangeRegion()
		{
			return theRegion_;
		}

	public:

		const std::shared_ptr<PlnType>& Plane() const
		{
			return thePlane_;
		}

		const std::shared_ptr<metricMap>& MetricMap() const
		{
			return theMetricMap_;
		}

		const std::shared_ptr<regionType>& Region() const
		{
			return theRegion_;
		}

		const std::shared_ptr<plnMesher>& MeshAlg() const
		{
			return theMesher_;
		}

		Standard_Boolean Check() const
		{
			return Check_;
		}

		void LoadPlane(const std::shared_ptr<PlnType>& thePlane)
		{
			thePlane_ = thePlane;
		}

		void LoadMetricMap(const std::shared_ptr<metricMap>& theMetricMap)
		{
			theMetricMap_ = theMetricMap;
		}

		//- static functions and operators

		static std::shared_ptr<regionType> MakeRegion(const std::shared_ptr<PlnType>& thePlane);
	};
}

#include <Aft_PlnAnalys_BaseI.hxx>

#endif // !_Aft_PlnAnalys_Base_Header
