#pragma once
#ifndef _Marine_CmpSection_Header
#define _Marine_CmpSection_Header

#include <Marine_Entity.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class MarineBase_Tools;
	class Marine_Section;

	class Marine_CmpSection
		: public Marine_Entity
	{

		friend class MarineBase_Tools;

		/*Private Data*/

		std::vector<std::shared_ptr<Marine_Section>> theSections_;

	protected:

		Marine_CmpSection();

		Marine_CmpSection
		(
			const Standard_Integer theIndex
		);

		Marine_CmpSection
		(
			const Standard_Integer theIndex, 
			const word& theName
		);

		void Insert
		(
			const std::shared_ptr<Marine_Section>& theSection
		)
		{
			theSections_.push_back(theSection);
		}

	public:

		auto NbSections() const
		{
			return (Standard_Integer)theSections_.size();
		}

		const auto& Sections() const
		{
			return theSections_;
		}


	};
}

#endif // !_Marine_CmpSection_Header
