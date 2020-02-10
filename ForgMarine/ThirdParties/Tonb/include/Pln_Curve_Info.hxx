#pragma once
#ifndef _Pln_Curve_Info_Header
#define _Pln_Curve_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace tnbLib
{

	class Pln_Curve_Info
	{

		/*Private Data*/

		Standard_Integer theNbDivisions_;

	public:

		static const Standard_Integer DEFAULT_NB_DIVISIONS;

		Pln_Curve_Info()
			: theNbDivisions_(DEFAULT_NB_DIVISIONS)
		{}

		//- Macros
		GLOBAL_ACCESS_SINGLE(Standard_Integer, NbDivisions)
	};
}

#endif // !_Pln_Curve_Info_Header
