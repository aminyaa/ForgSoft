#pragma once
#ifndef _Geo_PrimShape_Header
#define _Geo_PrimShape_Header

#include <Entity_StaticData.hxx>

namespace AutLib
{

	template<class Point, class ConnectType>
	class Geo_PrimShape
		: public Entity_StaticData<Point, ConnectType, false>
	{

		/*Private Data*/

	public:


	protected:

		Geo_PrimShape()
		{}

	};
}

#endif // !_Geo_PrimShape_Header
