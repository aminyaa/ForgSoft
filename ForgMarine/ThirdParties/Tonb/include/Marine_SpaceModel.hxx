#pragma once
#ifndef _Marine_SpaceModel_Header
#define _Marine_SpaceModel_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace tnbLib
{

	class Marine_SpaceModel
		: public std::enable_shared_from_this<Marine_SpaceModel>
	{

		/*Private Data*/

	protected:

		Marine_SpaceModel();

	public:

		virtual ~Marine_SpaceModel()
		{}

		virtual Standard_Boolean IsTwoDimensional() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsThreeDimensional() const
		{
			return Standard_False;
		}

	};
}

#endif // !_Marine_SpaceModel_Header
