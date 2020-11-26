#pragma once
#ifndef _Marine_GraphAxis_Y_Header
#define _Marine_GraphAxis_Y_Header

#include <Marine_GraphAxis.hxx>

namespace tnbLib
{

	class Marine_GraphAxis_Y
		: public Marine_GraphAxis
	{

		/*Private Data*/

	public:

		Marine_GraphAxis_Y();

		Marine_GraphAxis_Y
		(
			const Standard_Integer theIndex
		);

		Marine_GraphAxis_Y
		(
			const Standard_Integer theIndex, 
			const word& theName
		);


		Standard_Boolean IsY() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Marine_GraphAxis_Y_Header
