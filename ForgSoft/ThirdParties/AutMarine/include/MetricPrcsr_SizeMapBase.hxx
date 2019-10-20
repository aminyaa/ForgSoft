//#pragma once
//#ifndef _MetricPrcsr_SizeMapBase_Header
//#define _MetricPrcsr_SizeMapBase_Header
//
//#include <Global_Indexed.hxx>
//#include <Global_Named.hxx>
//#include <Global_Done.hxx>
//#include <Entity_Box.hxx>
//#include <Cad_CascadeTraits.hxx>
//
//namespace AutLib
//{
//
//	template<class Point>
//	class MetricPrcsr_SizeMapBase
//		: public Global_Indexed
//		, public Global_Named
//		, public Global_Done
//	{
//
//		/*Private Data*/
//
//		Entity_Box<Point> theBoundingBox_;
//
//	protected:
//
//		MetricPrcsr_SizeMapBase()
//		{}
//
//		MetricPrcsr_SizeMapBase(const Entity_Box<Point>& theBox)
//			: theBoundingBox_(theBox)
//		{}
//
//		Entity_Box<Point>& ChangeBoundingBox()
//		{
//			return theBoundingBox_;
//		}
//
//	public:
//
//		typedef Entity_Box<Point> boxType;
//		typedef Point ptType;
//		typedef typename cascadeLib::vec_type_from_point<Point>::vcType vcType;
//
//		const Entity_Box<Point>& BoundingBox() const
//		{
//			return theBoundingBox_;
//		}
//
//		virtual Standard_Real DimSize() const = 0;
//
//		virtual Standard_Real CalcElementSize(const Point& thePoint) const = 0;
//
//		virtual Standard_Real CalcDistance(const Point& theP0, const Point& theP1) const = 0;
//
//		virtual Standard_Real CalcSquareDistance(const Point& theP0, const Point& theP1) const = 0;
//
//		virtual Standard_Real CalcUnitDistance(const Point& theP0, const Point& theP1) const = 0;
//
//		virtual Standard_Real Integrand(const Point& thePoint, const Point& theVector) const = 0;
//
//		virtual Standard_Real Integrand(const point& thePoint, const vcType& theVcetor) const = 0;
//
//		virtual Standard_Real IntegrandPerSize(const Point& thePoint, const Point& theVector) const = 0;
//
//		virtual Standard_Real IntegrandPerSize(const point& thePoint, const vcType& theVcetor) const = 0;
//
//		virtual void Make() const = 0;
//	};
//}
//
//#endif // !_MetricPrcsr_SizeMapBase_Header
