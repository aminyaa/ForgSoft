#pragma once
#ifndef _Cad2d_IntsctEntity_Header
#define _Cad2d_IntsctEntity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Cad2d_IntsctEntity_Adaptor.hxx>

#include <memory>

namespace tnbLib
{

	class Cad2d_IntsctEntity
		: public Global_Indexed
		, public Global_Named
		, public Cad2d_IntsctEntity_Adaptor
		, public std::enable_shared_from_this<Cad2d_IntsctEntity>
	{

		/*Private Data*/

	protected:

		Cad2d_IntsctEntity()
		{}

		Cad2d_IntsctEntity
		(
			const Standard_Integer theIndex
		);

		Cad2d_IntsctEntity
		(
			const Standard_Integer theIndex,
			const word& theName
		);

	public:

		virtual ~Cad2d_IntsctEntity()
		{}

		virtual Standard_Boolean IsPoint() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsSegment() const
		{
			return Standard_False;
		}
	};
}

#endif // !_Cad2d_IntsctEntity_Header
