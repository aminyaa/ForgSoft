#pragma once
#ifndef _Marine_TwoDimensional_Header
#define _Marine_TwoDimensional_Header

#include <Marine_SpaceModel.hxx>

namespace tnbLib
{

	class Marine_TwoDimensional
		: public Marine_SpaceModel
	{

		/*Private Data*/

	protected:

		Marine_TwoDimensional();

	public:

		Standard_Boolean IsTwoDimensional() const override
		{
			return Standard_True;
		}

	};
}

#endif // !_Marine_TwoDimensional_Header
