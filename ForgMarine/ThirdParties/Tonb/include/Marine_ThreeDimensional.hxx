#pragma once
#ifndef _Marine_ThreeDimensional_Header
#define _Marine_ThreeDimensional_Header

#include <Marine_SpaceModel.hxx>

namespace tnbLib
{

	class Marine_ThreeDimensional
		: public Marine_SpaceModel
	{

		/*Private Data*/

	protected:

		Marine_ThreeDimensional();

		
		Standard_Boolean IsThreeDimensional() const override
		{
			return Standard_True;
		}

	};
}

#endif // !_Marine_ThreeDimensional_Header
