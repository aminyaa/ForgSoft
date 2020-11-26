#pragma once
#ifndef _Marine_GraphAxis_Header
#define _Marine_GraphAxis_Header

#include <Marine_GraphEntity.hxx>
#include <Global_Bound.hxx>

namespace tnbLib
{

	class Marine_GraphAxis
		: public Marine_GraphEntity
		, public Global_Bound<Standard_Real>
	{

		/*Private Data*/

	protected:

		Marine_GraphAxis();

		Marine_GraphAxis
		(
			const Standard_Integer theIndex
		);

		Marine_GraphAxis
		(
			const Standard_Integer theIndex, 
			const word& theName
		);


		virtual Standard_Boolean IsX() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsY() const
		{
			return Standard_False;
		}
	};
}

#endif // !_Marine_GraphAxis_Header
