#pragma once
#ifndef _Geo_SizeFunction_Header
#define _Geo_SizeFunction_Header

#include <Global_Done.hxx>
#include <Global_Named.hxx>
#include <Global_Indexed.hxx>
#include <Entity_Box.hxx>

namespace tnbLib
{

	template<class Point>
	class Geo_SizeFunction
		: public Global_Indexed
		, public Global_Named
		, public Global_Done
	{

		/*Private Data*/

		Entity_Box<Point> theBoundingBox_;

	protected:


		Geo_SizeFunction(const Entity_Box<Point>& theBox)
			: theBoundingBox_(theBox)
		{}

		Geo_SizeFunction
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Entity_Box<Point>& theBox
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
			, theBoundingBox_(theBox)
		{}

	public:

		typedef Point ptType;
		typedef Entity_Box<Point> boxType;

		const Entity_Box<Point>& BoundingBox() const
		{
			return theBoundingBox_;
		}

		//- virtual functions and operators

		virtual Standard_Real Value(const Point& theCoord) const = 0;

		virtual void Perform()
		{
			Change_IsDone() = Standard_True;
		}

	};
}

#endif // !_Geo_SizeFunction_Header