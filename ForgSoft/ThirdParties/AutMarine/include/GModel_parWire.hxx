#pragma once
#ifndef _GModel_parWire_Header
#define _GModel_parWire_Header

#include <GModel_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <error.hxx>
#include <OSstream.hxx>
#include <OFstream.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class GModel_parCurve;

	class GModel_parWire
		: public GModel_Entity
	{

		typedef std::shared_ptr<GModel_parCurve> curve_ptr;
		typedef std::vector<curve_ptr> curveList;

		/*Private Data*/

		std::shared_ptr<curveList> theCurves_;

	public:

		GModel_parWire
		(
			const std::shared_ptr<curveList>& theCurves
		)
			: theCurves_(theCurves)
		{}

		GModel_parWire
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<curveList>& theCurves
		)
			: GModel_Entity(theIndex, theName)
			, theCurves_(theCurves)
		{}

		GModel_parWire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<curveList>& theCurves
		)
			: GModel_Entity(theIndex)
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


		//- IO functions and operators

		void ExportToPlt(OFstream& File) const;


		//- Static functions and operators

		static std::vector<std::shared_ptr<GModel_parCurve>> 
			RetrieveCurves
			(
				const std::vector<std::shared_ptr<GModel_parWire>>& theWires
			);
	};
}

#endif // !_GModel_parWire_Header
