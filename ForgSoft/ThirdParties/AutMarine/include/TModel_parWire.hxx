#pragma once
#ifndef _TModel_parWire_Header
#define _TModel_parWire_Header

#include <TModel_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <error.hxx>
#include <OSstream.hxx>
#include <OFstream.hxx>

namespace AutLib
{

	// Forward Declarations
	class TModel_parCurve;

	class TModel_parWire
		: public TModel_Entity
	{

		typedef std::shared_ptr<TModel_parCurve> curve_ptr;
		typedef std::vector<curve_ptr> curveList;

		/*Private Data*/

		std::shared_ptr<curveList> theCurves_;

	public:

		TModel_parWire
		(
			const std::shared_ptr<curveList>& theCurves
		)
			: theCurves_(theCurves)
		{}

		TModel_parWire
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<curveList>& theCurves
		)
			: TModel_Entity(theIndex, theName)
			, theCurves_(theCurves)
		{}

		TModel_parWire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<curveList>& theCurves
		)
			: TModel_Entity(theIndex)
			, theCurves_(theCurves)
		{}


		Standard_Integer NbCurves() const
		{
			Debug_Null_Pointer(theCurves_);
			return (Standard_Integer)theCurves_->size();
		}

		Entity2d_Box CalcParametricBoundingBox() const;

		const curveList& Curves() const
		{
			Debug_Null_Pointer(theCurves_);
			return *theCurves_;
		}

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_TModel_parWire_Header
