#pragma once
#ifndef _Geom_Search_Header
#define _Geom_Search_Header

#include <Entity2d_Box.hxx>
#include <Entity3d_Box.hxx>
#include <Adt_List.hxx>
#include <Stl_Vector.hxx>
#include <Stl_List.hxx>
#include <Traits.hxx>

namespace AutLib
{

	class Geom_SearchBase
	{

		/*Private Data*/

		Standard_Integer theNbItems_;

	protected:

		Geom_SearchBase()
			: theNbItems_(0)
		{}

		Standard_Integer NbItems() const
		{
			return theNbItems_;
		}

		Standard_Integer& NbItems()
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
	};

	template<class T>
	class Geom_Search
		: public Geom_SearchBase
	{

		/*Private Data*/
		typedef typename remove_pointer<T>::type::ptType Point;

		Entity_Box<Point> theRegion_;

	protected:

		const Point& (*CoordinateOf)(const T&);

		Geom_Search()
		{}

		Geom_Search(const Entity_Box<Point>& theBound)
			: theRegion_(theBound)
		{}

		DisallowBitWiseCopy(Geom_Search);

	public:

		Standard_Integer GeometrySize() const
		{
			return NbItems();
		}

		Standard_Boolean IsGeometryEmpty() const
		{
			return !GeometrySize();
		}

		const Entity_Box<Point>& GeometryBoundingBox() const
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

#endif // !_Geom_Search_Header
