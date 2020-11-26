#pragma once
#ifndef _HsEntity_MonoHull_Header
#define _HsEntity_MonoHull_Header

#include <HsEntity_Vessel.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class MonoHull_Section;

	class HsEntity_MonoHull
		: public HsEntity_Vessel
	{

		/*Private Data*/

		std::vector<std::shared_ptr<MonoHull_Section>> theSections_;

		std::shared_ptr<MonoHull_Section> theMidSection_;

	public:

		HsEntity_MonoHull();

		HsEntity_MonoHull(const Standard_Integer theIndex);

		HsEntity_MonoHull(const Standard_Integer theIndex, const word &theName);

	public:

		const auto& Sections() const
		{
			return theSections_;
		}

		Standard_Real FirstWaterLineSectionX() const;

		Standard_Real LastWaterLineSectionX() const;

		Standard_Real FirstUnderWaterSectionX() const;

		Standard_Real LastUnderWaterSectionX() const;

		Standard_Real FirstSectionX() const;

		Standard_Real LastSectionX() const;

		const std::shared_ptr<MonoHull_Section>& FirstUnderWaterSection() const;

		const std::shared_ptr<MonoHull_Section>& LastUnderWaterSection() const;

		const auto& MidSection() const
		{
			return theMidSection_;
		}
	};
}

#endif // !_HsEntity_MonoHull_Header
