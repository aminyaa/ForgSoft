#pragma once
#ifndef _Mesh_PlnWire_Header
#define _Mesh_PlnWire_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Entity2d_Box.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	template<class PlnCurve>
	class Mesh_PlnWire
		: public Global_Indexed
		, public Global_Named
	{

		typedef std::shared_ptr<PlnCurve> curve_ptr;
		typedef std::vector<curve_ptr> curveList;

		/*Private Data*/

		std::shared_ptr<curveList> theCurves_;

	public:

		typedef PlnCurve plnCurveType;

		Mesh_PlnWire
		(
			const std::shared_ptr<curveList>& theCurves
		)
			: theCurves_(theCurves)
		{}

		Mesh_PlnWire
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<curveList>& theCurves
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
			, theCurves_(theCurves)
		{}

		Mesh_PlnWire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<curveList>& theCurves
		)
			: Global_Indexed(theIndex)
			, theCurves_(theCurves)
		{}

		auto NbCurves() const
		{
			Debug_Null_Pointer(theCurves_);
			return (Standard_Integer)theCurves_->size();
		}

		Entity2d_Box CalcParametricBoundingBox() const;

		const auto& Curves() const
		{
			return theCurves_;
		}

		void ExportToPlt(OFstream& File) const;

		static std::vector<std::shared_ptr<PlnCurve>>
			RetrieveCurvesFrom
			(
				const std::vector<std::shared_ptr<Mesh_PlnWire>>& theWires
			);
	};
}

#include <Mesh_PlnWireI.hxx>

#endif // !_Mesh_PlnWire_Header
