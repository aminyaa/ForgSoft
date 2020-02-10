#pragma once
#ifndef _triangleFuncs_Header
#define _triangleFuncs_Header

#include <point.hxx>
#include <label.hxx>
#include <scalar.hxx>
#include <pointField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of classes
	class treeBoundBox;

	/*---------------------------------------------------------------------------*\
							   Class triangleFuncs Declaration
	\*---------------------------------------------------------------------------*/

	class triangleFuncs
	{

	public:

		// Public data types

			//- Enumeration defining nearness classification
		enum proxType
		{
			NONE,
			POINT,
			EDGE
		};


	private:

		// Private Member Functions

			//- Helper function for intersect. Sets pt to be anywhere on the edge
			//  between oppositeSidePt and thisSidePt depending on both signs.
		static void setIntersection
		(
			const point& oppositeSidePt,
			const scalar oppositeSign,
			const point& thisSidePt,
			const scalar thisSign,
			const scalar tol,
			point& pt
		);

		//- Helper function.
		static void selectPt
		(
			const bool select0,
			const point& p0,
			const point& p1,
			point& min
		);

	public:

		//- Intersect triangle with parallel edges aligned with axis i0.
		//  Returns true (and intersection in pInter) if any of them intersects
		//  triangle. Used in intersectBb.
		static bool intersectAxesBundle
		(
			const point& V0,
			const point& V10,
			const point& V20,
			const label i0,
			const pointField& origin,
			const scalar maxLength,
			point& pInter
		);

		//- Does triangle intersect bounding box.
		static bool intersectBb
		(
			const point& p0,
			const point& p1,
			const point& p2,
			const treeBoundBox& cubeBb
		);

		//- Does triangle intersect plane. Return bool and set intersection segment
		static bool intersect
		(
			const point& va0,
			const point& va10,
			const point& va20,

			const point& basePoint,
			const vector& normal,

			point& pInter0,
			point& pInter1
		);

		//- Do triangles intersect. Return bool and set intersection segment
		static bool intersect
		(
			const point& va0,
			const point& va10,
			const point& va20,

			const point& vb0,
			const point& vb10,
			const point& vb20,

			point& pInter0,
			point& pInter1
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_triangleFuncs_Header
