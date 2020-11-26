#pragma once
#ifndef _MonoHull_Section_Header
#define _MonoHull_Section_Header

#include <HsEntity_Section.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class HsSection_Dry;
	class HsSection_WaterLine;
	class HsSection_UnderWater;

	class MonoHull_Section
		: public HsEntity_Section
	{

		/*Private Data*/

		std::shared_ptr<HsSection_WaterLine> theWaterLineSection_;

		std::vector<std::shared_ptr<HsSection_Dry>> theDrySections_;
		std::vector<std::shared_ptr<HsSection_UnderWater>> theUnderWaterSections_;

	public:

		MonoHull_Section();

		MonoHull_Section(const Standard_Integer theIndex);

		MonoHull_Section(const Standard_Integer theIndex, const word &theName);

		Standard_Boolean HasWettedArea() const;

		auto HasWaterLineSection() const
		{
			return (Standard_Boolean)theWaterLineSection_;
		}

		auto HasDrySection() const
		{
			return (Standard_Boolean)NbDrySections();
		}

		auto HasUnderWaterSection() const
		{
			return (Standard_Boolean)NbUnderWaterSections();
		}

		Standard_Integer NbDrySections() const
		{
			return (Standard_Integer)theDrySections_.size();
		}

		Standard_Integer NbUnderWaterSections() const
		{
			return (Standard_Integer)theUnderWaterSections_.size();
		}

		//- max beam on hull
		Standard_Real MaxBeam() const;

		Standard_Real BeamOnDeck() const;

		Standard_Real MaxWetBeam() const;

		Standard_Real Depth() const;

		Standard_Real Draft() const;

		Standard_Real WettedArea() const;

		Standard_Real X() const;
	};
}

#endif // !_MonoHull_Section_Header
