#pragma once
#ifndef _Marine_CompoundSection_Header
#define _Marine_CompoundSection_Header

#include <Standard_TypeDef.hxx>
#include <Marine_TableSection.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	template<class SectType>
	class Marine_CompoundSection
		: public Marine_TableSection
	{

		/*Private Data*/

		std::vector<std::shared_ptr<SectType>> theSections_;

	public:

		Marine_CompoundSection()
			: Marine_TableSection(0, "compound section")
		{}

		Marine_CompoundSection
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Marine_TableSection(theIndex, theName)
		{}

		const std::vector<std::shared_ptr<SectType>>& Sections() const
		{
			return theSections_;
		}

		Standard_Integer Size() const
		{
			return (Standard_Integer)theSections_.size();
		}

		void InsertSection
		(
			const std::shared_ptr<SectType>& theSection
		)
		{
			theSections_.push_back(theSection);
		}

	};


	// Forward Declarations
	class Marine_TableCurve;
	class Marine_TableOffsets;

	namespace marineLib
	{

		typedef Marine_CompoundSection<Marine_TableCurve> cmpSectCurve;
		typedef Marine_CompoundSection<Marine_TableOffsets> cmpSectOffsets;
	}
}

#endif // !_Marine_CompoundSection_Header
