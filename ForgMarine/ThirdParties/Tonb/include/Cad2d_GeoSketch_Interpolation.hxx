#pragma once
#ifndef _Cad2d_GeoSketch_Interpolation_Header
#define _Cad2d_GeoSketch_Interpolation_Header

#include <Global_Done.hxx>
#include <Cad2d_GeoSketch.hxx>
#include <Pnt2d.hxx>
#include <Vec2d.hxx>

#include <memory>
#include <map>

namespace tnbLib
{

	class Cad2d_GeoSketch_Interpolation
		: public Cad2d_GeoSketch
		, public Global_Done
	{

		/*Private Data*/

		std::map<Standard_Integer, Pnt2d> thePts_;

	public:

		Standard_Boolean HasPoint(const Standard_Integer theIndex) const;

		auto NbPoints() const
		{
			return (Standard_Integer)thePts_.size();
		}

		const auto& Points() const
		{
			return thePts_;
		}

		void LoadPoint(const Standard_Integer theIndex, const Pnt2d& thePt);

		void RemovePoint(const Standard_Integer theIndex);

		void Perform(const Standard_Real theTol);

		void Perform
		(
			const Standard_Real theTol,
			const Vec2d& theFirst,
			const Vec2d& theLast,
			const Standard_Boolean Scale = Standard_True
		);
	};
}

#endif // !_Cad2d_GeoSketch_Interpolation_Header
