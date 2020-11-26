#pragma once
#ifndef _HsEntity_Section_Header
#define _HsEntity_Section_Header

#include <HsVessel_Entity.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Marine_Section;

	class HsEntity_Section
		: public HsVessel_Entity
	{

		/*Private Data*/

		std::shared_ptr<Marine_Section> theSection_;

	protected:

		HsEntity_Section();

		HsEntity_Section(const Standard_Integer theIndex);

		HsEntity_Section(const Standard_Integer theIndex, const word& theName);

	public:

		const auto& Section() const
		{
			return theSection_;
		}
	};
}

#endif // !_HsEntity_Section_Header
