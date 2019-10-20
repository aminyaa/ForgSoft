#pragma once
#ifndef _Numeric_IntegrationFunction_Header
#define _Numeric_IntegrationFunction_Header

#include <Standard_TypeDef.hxx>
#include <Numeric_System.hxx>

namespace AutLib
{

	struct Numeric_IntegrationFunction
	{

		virtual Standard_Real Value(const Standard_Real) const
		{
			numLib::CheckFun("Standard_Real Value(const Standard_Real) const");
			return 0;
		}
	};
}

#endif // !_Numeric_IntegrationFunction_Header
