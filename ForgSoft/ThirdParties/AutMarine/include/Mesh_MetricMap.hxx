#pragma once
#ifndef _Mesh_MetricMap_Header
#define _Mesh_MetricMap_Header

#include <Global_Named.hxx>
#include <Entity_Box.hxx>
#include <Mesh_MetricMapTraits.hxx>

namespace AutLib
{

	template<class Point>
	class Mesh_MetricMap
		: public Global_Named
	{

		/*Private Data*/

		Entity_Box<Point> theBoundingBox_;

	protected:

		Mesh_MetricMap()
		{}

		Mesh_MetricMap(const Entity_Box<Point>& theBox)
			: theBoundingBox_(theBox)
		{}

	public:

		typedef Point ptType;
		typedef typename metric_map_traits<Point>::type metric;

		virtual metric MetricAt(const Point& theCoord) const = 0;

		const Entity_Box<Point>& BoundingBox() const
		{
			return theBoundingBox_;
		}

		void SetBoundingBox(const Entity_Box<Point>& theBox)
		{
			theBoundingBox_ = theBox;
		}
	};
}

#endif // !_Mesh_MetricMap_Header