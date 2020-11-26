#pragma once
#ifndef _Cad2d_CmpIntsctEntity_Header
#define _Cad2d_CmpIntsctEntity_Header

#include <Cad2d_IntsctEntity.hxx>

#include <map>

namespace tnbLib
{

	class Cad2d_CmpIntsctEntity
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/

		std::map<Standard_Integer, std::shared_ptr<Cad2d_IntsctEntity>>
			theEntities_;

		std::weak_ptr<Cad2d_CmpIntsctEntity> thePair_;

	public:

		Cad2d_CmpIntsctEntity();

		Cad2d_CmpIntsctEntity(const Standard_Integer theIndex);

		Cad2d_CmpIntsctEntity(const Standard_Integer theIndex, const word &theName);


		Standard_Integer NbEntities() const;

		const auto& Entities() const
		{
			return theEntities_;
		}

		void Import(const Standard_Integer theIndex, std::shared_ptr<Cad2d_IntsctEntity>& theEntity);

		void Remove(const Standard_Integer theIndex);

		//- Macros
		GLOBAL_ACCESS_ONLY_SINGLE(std::weak_ptr<Cad2d_CmpIntsctEntity>, Pair)
	};
}

#endif // !_Cad2d_CmpIntsctEntity_Header
