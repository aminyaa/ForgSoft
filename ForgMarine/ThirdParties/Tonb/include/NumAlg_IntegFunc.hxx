#pragma once
#ifndef _NumAlg_IntegFunc_Header
#define _NumAlg_IntegFunc_Header

#include <Standard_TypeDef.hxx>
#include <error.hxx>
#include <OSstream.hxx>

namespace tnbLib
{

	struct NumAlg_IntegFunc
	{

		virtual Standard_Real Value(const Standard_Real) const
		{
			FatalErrorIn("Standard_Real Value(const Standard_Real) const")
				<< " Found no function" << endl
				<< abort(FatalError);
			return 0;
		}
	};
}

#endif // !_NumAlg_IntegFunc_Header
