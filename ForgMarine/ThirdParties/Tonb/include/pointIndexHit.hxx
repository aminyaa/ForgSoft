#pragma once
#ifndef _pointIndexHit_Header
#define _pointIndexHit_Header

#include <point.hxx>
#include <PointIndexHitTemplate.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	typedef PointIndexHit<point> pointIndexHit;


	//- Data associated with pointIndexHit type are contiguous
	template<>
	inline bool contiguous<pointIndexHit>() { return contiguous<point>(); }

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointIndexHit_Header
