#pragma once
#ifndef _Marine_SectionDistribution_Uniform_Header
#define _Marine_SectionDistribution_Uniform_Header

#include <Marine_SectionDistribution.hxx>

#include <vector>

namespace tnbLib
{

	class Marine_SectionDistribution_Uniform
		: public Marine_SectionDistribution
	{

		/*Private Data*/

		Standard_Integer theNbSections_;

		std::vector<Standard_Real> theSections_;


		auto& ChangeSections()
		{
			return theSections_;
		}

	public:

		Marine_SectionDistribution_Uniform()
		{}

		Standard_Integer NbSections() const override
		{
			return theNbSections_;
		}

		Standard_Real Section(const Standard_Integer theIndex) const override
		{
			return theSections_[theIndex];
		}

		const std::vector<Standard_Real>& 
			Sections() const override
		{
			return theSections_;
		}

		void Perform() override;

		void SetNbSections(const Standard_Integer size)
		{
			theNbSections_ = size;
		}

		//- Macros

	};
}

#endif // !_Marine_SectionDistribution_Uniform_Header
