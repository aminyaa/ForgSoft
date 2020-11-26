#pragma once
#ifndef _Marine_Body_Header
#define _Marine_Body_Header

#include <Marine_Entity.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Marine_CmpSection;

	class Marine_Body
		: public Marine_Entity
	{

		/*Private Data*/

		std::vector<std::shared_ptr<Marine_CmpSection>> 
			theSections_;

	protected:

		Marine_Body();

		Marine_Body
		(
			const Standard_Integer theIndex
		);

		Marine_Body
		(
			const Standard_Integer theIndex, 
			const word& theName
		);

	public:
	

		Standard_Integer NbSections() const;

		auto& ChangeSections()
		{
			return theSections_;
		}

		const auto& Sections() const
		{
			return theSections_;
		}

		virtual Standard_Boolean IsWetted() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsDry() const
		{
			return Standard_False;
		}
	};
}

#endif // !_Marine_Body_Header
