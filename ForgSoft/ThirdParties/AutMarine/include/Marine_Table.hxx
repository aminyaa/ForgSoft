#pragma once
#ifndef _Marine_Table_Header
#define _Marine_Table_Header

#include <Standard_TypeDef.hxx>
#include <Global_Macros.hxx>
#include <Marine_CompoundSectionFwd.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	template<class SectType, bool Symm = true>
	class Marine_Table
	{

		/*Private Data*/

		std::vector<std::shared_ptr<SectType>> theSections_;

	public:

		Marine_Table()
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

	template<class SectType>
	class Marine_Table<SectType, false>
	{

		/*Private Data*/

		std::vector<std::shared_ptr<SectType>> theSections0_;
		std::vector<std::shared_ptr<SectType>> theSections1_;

	public:

		Marine_Table()
		{}

		Standard_Integer NbSections0() const
		{
			return (Standard_Integer)theSections0_.size();
		}

		Standard_Integer NbSections1() const
		{
			return (Standard_Integer)theSections1_.size();
		}

		const std::shared_ptr<SectType>&
			Section0
			(
				const Standard_Integer theIndex
			) const
		{
			if (NOT INSIDE(theIndex, 0, NbSections0() - 1))
			{
				FatalErrorIn("const std::shared_ptr<SectType>& Section(const Standard_Integer theIndex)")
					<< " Invalid Index: " << theIndex << endl
					<< " - Nb of sections" << NbSections() << endl
					<< abort(FatalError);
			}

			return theSections0_[theIndex];
		}

		const std::shared_ptr<SectType>&
			Section1
			(
				const Standard_Integer theIndex
			) const
		{
			if (NOT INSIDE(theIndex, 0, NbSections1() - 1))
			{
				FatalErrorIn("const std::shared_ptr<SectType>& Section(const Standard_Integer theIndex)")
					<< " Invalid Index: " << theIndex << endl
					<< " - Nb of sections" << NbSections() << endl
					<< abort(FatalError);
			}

			return theSections1_[theIndex];
		}

		void Insert0
		(
			const std::shared_ptr<SectType>& theSection
		)
		{
			theSections0_.push_back(theSection);
		}

		void Insert1
		(
			const std::shared_ptr<SectType>& theSection
		)
		{
			theSections1_.push_back(theSection);
		}
	};

	// Forward Declarations

	template<class SectType>
	class Marine_CompoundSection;

	class Marine_TableCurve;
	class Marine_TableOffsets;

	namespace marineLib
	{

		typedef Marine_Table<marineLib::cmpSectCurve> symCmpTableCurve;
		typedef Marine_Table<marineLib::cmpSectCurve, false> asymmCmpTableCurve;

		typedef Marine_Table<marineLib::cmpSectOffsets> symmTableOffsets;
		typedef Marine_Table<marineLib::cmpSectOffsets, false> asymmCmpTableOffsets;
	}
}

#endif // !_Marine_Table_Header
