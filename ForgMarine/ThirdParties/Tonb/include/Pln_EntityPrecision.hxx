#pragma once
#ifndef _Pln_EntityPrecision_Header
#define _Pln_EntityPrecision_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace tnbLib
{

	class Pln_EntityPrecision
	{

		/*Private Data*/

		Standard_Real thePrecision_;

	protected:

		static const Standard_Real DEFAULT_PRECISION;

		Pln_EntityPrecision()
			: thePrecision_(DEFAULT_PRECISION)
		{}

	public:

		//- Macros
		GLOBAL_ACCESS_SINGLE(Standard_Real, Precision)
	};
}

#endif // !_Pln_EntityPrecision_Header
