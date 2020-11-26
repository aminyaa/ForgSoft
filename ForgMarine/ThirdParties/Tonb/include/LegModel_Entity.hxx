#pragma once
#ifndef _LegModel_Entity_Header
#define _LegModel_Entity_Header

#include <CadModel_Entity.hxx>

namespace tnbLib
{

	class LegModel_Entity
		: public CadModel_Entity
	{

		/*Private Data*/

	protected:

		LegModel_Entity()
		{}

		LegModel_Entity
		(
			const Standard_Integer theIndex
		)
			: CadModel_Entity(theIndex)
		{}

		LegModel_Entity
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: CadModel_Entity(theIndex, theName)
		{}

	public:


	};
}

#endif // !_LegModel_Entity_Header
