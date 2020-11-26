#pragma once
#ifndef _Pln_Entity_Header
#define _Pln_Entity_Header

#include <Cad_Entity.hxx>

namespace tnbLib
{

	class Pln_Entity
		: public Cad_Entity
	{

		/*Private Data*/

	protected:

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

	public:

		virtual std::shared_ptr<Pln_Entity> Copy() const = 0;
	};
}

#endif // !_Pln_Entity_Header
