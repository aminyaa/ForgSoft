#pragma once
#ifndef _Cad_Entity_Header
#define _Cad_Entity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace tnbLib
{

	class Cad_Entity
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<Cad_Entity>
	{

		/*Private Data*/

	protected:

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
		

	public:

		virtual ~Cad_Entity()
		{}

		auto This() const
		{
			return std::const_pointer_cast<Cad_Entity>(this->shared_from_this());
		}
	};
}

#endif // !_Cad_Entity_Header
