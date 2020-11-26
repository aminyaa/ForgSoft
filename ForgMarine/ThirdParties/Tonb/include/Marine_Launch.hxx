#pragma once
#ifndef _Marine_Launch_Header
#define _Marine_Launch_Header

#include <Global_Done.hxx>
#include <Global_AccessMethod.hxx>
#include <Entity3d_BoxFwd.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Marine_CrossSection;
	class Marine_CmpSection;
	class Marine_Section;
	class Marine_Wave;
	class Marine_Launch_Info;
	class Marine_Body;

	class Marine_Launch
		: public Global_Done
	{

		/*Private Data*/

		std::shared_ptr<Marine_CrossSection> theHull_;
		std::shared_ptr<Marine_Wave> theWave_;

		std::vector<std::shared_ptr<Marine_CmpSection>> theSections_;
		std::vector<std::shared_ptr<Marine_Section>> theWaters_;

		const Entity3d_Box& theDomain_;


		std::shared_ptr<Marine_Launch_Info> theInfo_;

		auto& ChangeSections()
		{
			return theSections_;
		}

		auto& ChangeWaters()
		{
			return theWaters_;
		}

	public:

		Marine_Launch(const Entity3d_Box& theDomain);

		const auto& Wave() const
		{
			return theWave_;
		}

		const auto& Domain() const
		{
			return theDomain_;
		}

		const auto& Hull() const
		{
			return theHull_;
		}

		const auto& Sections() const
		{
			return theSections_;
		}

		const auto& Waters() const
		{
			return theWaters_;
		}

		const auto& Info() const
		{
			return theInfo_;
		}

		void Perform();

		void LoadHull
		(
			const std::shared_ptr<Marine_CrossSection>& theHull
		)
		{
			theHull_ = theHull;
		}

		void LoadWave
		(
			const std::shared_ptr<Marine_Wave>& theWave
		)
		{
			theWave_ = theWave;
		}

		//- Macros

	};
}

#endif // !_Marine_Launch_Header
