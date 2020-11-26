#pragma once
#ifndef _Marine_GraphCurve_Header
#define _Marine_GraphCurve_Header

#include <Marine_GraphEntity.hxx>
#include <Marine_GraphLinePattern.hxx>

#include <Standard_Handle.hxx>

class Geom2d_Curve;

namespace tnbLib
{

	class Marine_GraphCurve
		: public Marine_GraphEntity
	{

		/*Private Data*/

		Marine_GraphLinePattern thePattern_;

		Handle(Geom2d_Curve) theCurve_;


		static void 
			CheckCurve
			(
				const Handle(Geom2d_Curve)& theCurve,
				const char* theName
			);

	public:

		Marine_GraphCurve
		(
			const Handle(Geom2d_Curve) theCurve
		);

		Marine_GraphCurve
		(
			const Standard_Integer theIndex,
			const Handle(Geom2d_Curve)& theCurve
		);

		Marine_GraphCurve
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Handle(Geom2d_Curve)& theCurve
		);

		const auto& Curve() const
		{
			return theCurve_;
		}

		auto Pattern() const
		{
			return thePattern_;
		}

		void SetPattern(const Marine_GraphLinePattern thePattern)
		{
			thePattern_ = thePattern;
		}
	};
}

#endif // !_Marine_GraphCurve_Header
