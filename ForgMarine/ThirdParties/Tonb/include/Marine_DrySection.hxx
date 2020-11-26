#pragma once
#ifndef _Marine_DrySection_Header
#define _Marine_DrySection_Header

#include <Marine_Section.hxx>

namespace tnbLib
{

	class Marine_DrySection
		: public Marine_Section
	{

		/*Private Data*/

	public:

		Marine_DrySection
		(
			const std::shared_ptr<Pln_Wire>& theWire
		);

		Marine_DrySection
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Wire>& theWire
		);

		Marine_DrySection
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Wire>& theWire
		);


		Standard_Boolean IsDry() const override
		{
			return Standard_True;
		}

		std::shared_ptr<Marine_Section> Copy() const override;
	};
}

#endif // !_Marine_DrySection_Header
