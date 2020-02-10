#pragma once
#ifndef _Geo_SearchTree_Header
#define _Geo_SearchTree_Header

#include <Entity_Box.hxx>

namespace tnbLib
{

	class Geo_SearchTree_Base
	{

		/*Private Data*/

		Standard_Integer theNbItems_;

	protected:

		Geo_SearchTree_Base()
			: theNbItems_(0)
		{}

		auto& ChangeNbItems()
		{
			return theNbItems_;
		}

		void Increment()
		{
			theNbItems_++;
		}

		void Decrement()
		{
			theNbItems_--;
		}

	public:

		auto NbItems() const
		{
			return theNbItems_;
		}

		auto GeometrySize() const
		{
			return NbItems();
		}
	};

	template<class T>
	class Geo_SearchTree
		: public Geo_SearchTree_Base
	{

		typedef typename remove_pointer<T>::type::ptType Point;

		/*Private Data*/

		Entity_Box<Point> theRegion_;

	protected:

		const Point& (*CoordinateOf)(const T&);

		Geo_SearchTree()
		{}

		Geo_SearchTree
		(
			const Entity_Box<Point>& theRegion
		)
			: theRegion_(theRegion)
		{}
	

	public:


		Standard_Boolean IsGeometryEmpty() const
		{
			return !GeometrySize();
		}

		const auto& GeometryBoundingBox() const
		{
			return theRegion_;
		}

		void SetGeometryRegion(const Entity_Box<Point>& theBound)
		{
			theRegion_ = theBound;
		}

		void SetGeometryCoordFunc(const Point& (*theCoordinateOf)(const T&))
		{
			CoordinateOf = theCoordinateOf;
		}
	};
}

#include <Geo_PrTreeI.hxx>

#endif // !_Geo_SearchTree_Header
