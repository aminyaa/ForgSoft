#pragma once
#ifndef _Marine_Steady_Header
#define _Marine_Steady_Header

#include <Marine_TimeModel.hxx>

namespace tnbLib
{

	class Marine_Steady
		: public Marine_TimeModel
	{

		/*Private Data*/

	protected:

		Marine_Steady();

	public:

		Standard_Boolean IsSteady() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Marine_Steady_Header
