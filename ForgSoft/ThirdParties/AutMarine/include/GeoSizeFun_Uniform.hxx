#pragma once
#ifndef _GeoSizeFun_Uniform_Header
#define _GeoSizeFun_Uniform_Header

#include <Entity2d_Box.hxx>
#include <Geo_SizeFunction.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	template <class Point>
	class GeoSizeFun_Uniform
		: public Geo_SizeFunction<Point>
	{

		/*Private Data*/

		Standard_Real theSize_;

	public:

		GeoSizeFun_Uniform
		(
			const Standard_Real theSize, 
			const Entity2d_Box& theBox
		)
			: theSize_(theSize)
			, Geo_SizeFunction<Point>(theBox)
		{}

		GeoSizeFun_Uniform
		(
			const Standard_Integer theIndex,
			const word& theName, 
			const Standard_Real theSize,
			const Entity2d_Box& theBox
		)
			: Geo_SizeFunction(theIndex, theName, theBox)
			, theSize_(theSize)
		{}

		//- override functions and operators

		Standard_Real Value(const Point& theCoord) const override
		{
			return theSize_;
		}

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Size)
	};
}

#include <GeoSizeFun_UniformI.hxx>

#endif // !_GeoSizeFun_Uniform_Header
