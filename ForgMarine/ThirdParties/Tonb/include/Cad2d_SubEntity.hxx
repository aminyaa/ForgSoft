#pragma once
#ifndef _Cad2d_SubEntity_Header
#define _Cad2d_SubEntity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace tnbLib
{

	class Cad2d_SubEntity
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<Cad2d_SubEntity>
	{

		/*Private Data*/

	protected:

		Cad2d_SubEntity();

		Cad2d_SubEntity(const Standard_Integer theIndex);

		Cad2d_SubEntity(const Standard_Integer theIndex, const word& theName);

	public:

		virtual ~Cad2d_SubEntity()
		{}

		virtual Standard_Boolean IsVertex() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsEdge() const
		{
			return Standard_False;
		}
	};
}

#endif // !_Cad2d_SubEntity_Header
