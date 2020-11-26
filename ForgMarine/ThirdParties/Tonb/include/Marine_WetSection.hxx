#pragma once
#ifndef _Marine_WetSection_Header
#define _Marine_WetSection_Header

#include <Marine_Section.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Curve;

	class Marine_WetSection
		: public Marine_Section
	{

		/*Private Data*/

		Standard_Boolean IsDeep_;

	public:

		Marine_WetSection
		(
			const std::shared_ptr<Pln_Wire>& theWire
		);

		Marine_WetSection
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Wire>& theWire
		);

		Marine_WetSection
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Wire>& theWire
		);


		auto DeepCondition() const
		{
			return IsDeep_;
		}

		Standard_Boolean IsWet() const override
		{
			return Standard_True;
		}

		void SetDeep(const Standard_Boolean deep)
		{
			IsDeep_ = deep;
		}

		std::vector<std::shared_ptr<Pln_Curve>>
			RetrieveCurvesOnWater() const;

		void RetrieveCurvesOnWaterTo
		(
			std::vector<std::shared_ptr<Pln_Curve>>& theCurves
		) const;

		std::shared_ptr<Marine_Section> Copy() const override;
	};
}

#endif // !_Marine_WetSection_Header
