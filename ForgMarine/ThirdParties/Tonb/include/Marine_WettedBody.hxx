#pragma once
#ifndef _Marine_WettedBody_Header
#define _Marine_WettedBody_Header

#include <Marine_Body.hxx>

namespace tnbLib
{

	class Marine_WettedBody
		: public Marine_Body
	{

		/*private Data*/

	public:

		Marine_WettedBody();

		Marine_WettedBody
		(
			const Standard_Integer theIndex
		);

		Marine_WettedBody
		(
			const Standard_Integer theIndex,
			const word& theName
		);

		Standard_Boolean IsWetted() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Marine_WettedBody_Header
