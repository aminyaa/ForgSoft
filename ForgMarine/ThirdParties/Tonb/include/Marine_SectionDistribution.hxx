#pragma once
#ifndef _Marine_SectionDistribution_Header
#define _Marine_SectionDistribution_Header

#include <Marine_Entity.hxx>
#include <Global_AccessMethod.hxx>
#include <Global_Done.hxx>
#include <Global_Bound.hxx>

#include <vector>

namespace tnbLib
{

	class Marine_SectionDistribution
		: public Marine_Entity
		, public Global_Done
		, public Global_Bound<Standard_Real>
	{

		/*Private Data*/

	protected:

		Marine_SectionDistribution()
		{}

		Marine_SectionDistribution
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Marine_Entity(theIndex, theName)
		{}

	public:

		virtual Standard_Integer NbSections() const = 0;

		virtual Standard_Real Section(const Standard_Integer theIndex) const = 0;

		virtual const std::vector<Standard_Real>&
			Sections() const = 0;

		virtual void Perform() = 0;

		//- Macros
	};
}

#endif // !_Marine_SectionDistribution_Header
