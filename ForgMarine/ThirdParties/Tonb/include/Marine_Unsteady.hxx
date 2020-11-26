#pragma once
#ifndef _Marine_Unsteady_Header
#define _Marine_Unsteady_Header

#include <Marine_TimeModel.hxx>

namespace tnbLib
{

	class Marine_Unsteady
		: public Marine_TimeModel
	{

		/*Private Data*/

	protected:

		Marine_Unsteady();

		Standard_Boolean IsUnsteady() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Marine_Unsteady_Header
