#pragma once
#ifndef _Marine_Table_Header
#define _Marine_Table_Header

#include <Standard_TypeDef.hxx>
#include <Global_Macros.hxx>
#include <Marine_CompoundSectionFwd.hxx>
#include <Marine_TableEntity.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	template<class SectType>
	class Marine_Table
		: public Marine_TableEntity
	{

		/*Private Data*/

		std::vector<std::shared_ptr<SectType>> theSections_;

	public:

		Marine_Table()
		{}

		Marine_Table
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Marine_TableEntity(theIndex, theName)
		{}

		Standard_Integer NbSections() const
		{
			return (Standard_Integer)theSections_.size();
		}

		const std::shared_ptr<SectType>& 
			Section
			(
				const Standard_Integer theIndex
			) const
		{
			if (NOT INSIDE(theIndex, 0, NbSections() - 1))
			{
				FatalErrorIn("const std::shared_ptr<SectType>& Section(const Standard_Integer theIndex)")
					<< " Invalid Index: " << theIndex << endl
					<< " - Nb of sections" << NbSections() << endl
					<< abort(FatalError);
			}

			return theSections_[theIndex];
		}

		void Insert
		(
			const std::shared_ptr<SectType>& theSection
		)
		{
			theSections_.push_back(theSection);
		}
	};

	// Forward Declarations

	template<class SectType>
	class Marine_CompoundSection;

	class Marine_TableCurve;
	class Marine_TableOffsets;

	namespace marineLib
	{

		typedef Marine_Table<marineLib::cmpSectCurve> cmpTableCurve;
		typedef Marine_Table<marineLib::cmpSectOffsets> cmpTableOffsets;
	}
}

#endif // !_Marine_Table_Header
