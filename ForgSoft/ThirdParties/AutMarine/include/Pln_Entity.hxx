#pragma once
#ifndef _Pln_Entity_Header
#define _Pln_Entity_Header

#include <Cad_Entity.hxx>

namespace AutLib
{

	class Pln_Entity
		: public Cad_Entity
	{

		/*Private Data*/

	public:

		Pln_Entity()
		{}

		Pln_Entity(const Standard_Integer theIndex)
			: Cad_Entity(theIndex)
		{}

		Pln_Entity
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Cad_Entity(theIndex, theName)
		{}
	};
}

#endif // !_Pln_Entity_Header