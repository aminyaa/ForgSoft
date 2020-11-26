#pragma once
#ifndef _Marine_DryBody_Header
#define _Marine_DryBody_Header

#include <Marine_Body.hxx>

namespace tnbLib
{

	class Marine_DryBody
		: public Marine_Body
	{

		/*Private Data*/

	public:

		Marine_DryBody();

		Marine_DryBody
		(
			const Standard_Integer theIndex
		);

		Marine_DryBody
		(
			const Standard_Integer theIndex,
			const word& theName
		);


		Standard_Boolean IsDry() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Marine_DryBody_Header
