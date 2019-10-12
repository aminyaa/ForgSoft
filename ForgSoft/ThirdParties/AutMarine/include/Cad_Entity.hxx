#pragma once
#ifndef _Cad_Entity_Header
#define _Cad_Entity_Header

#include <Global_Named.hxx>
#include <Global_Indexed.hxx>

#include <memory>

namespace AutLib
{

	class Cad_Entity
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<Cad_Entity>
	{

		/*Private Data*/

	public:

		Cad_Entity()
		{}

		Cad_Entity(const Standard_Integer theIndex)
			: Global_Indexed(theIndex)
		{}

		Cad_Entity
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

		virtual ~Cad_Entity()
		{}
	};
}

#endif // !_Cad_Entity_Header