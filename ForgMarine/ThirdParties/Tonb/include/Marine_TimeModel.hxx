#pragma once
#ifndef _Marine_TimeModel_Header
#define _Marine_TimeModel_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace tnbLib
{

	class Marine_TimeModel
		: public std::enable_shared_from_this<Marine_TimeModel>
	{

		/*Private Data*/

	protected:

		Marine_TimeModel();

	public:

		virtual ~Marine_TimeModel()
		{}

		virtual Standard_Boolean IsSteady() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsUnsteady() const
		{
			return Standard_False;
		}
	};
}

#endif // !_Marine_TimeModel_Header
