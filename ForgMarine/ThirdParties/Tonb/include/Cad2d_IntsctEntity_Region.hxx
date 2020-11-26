#pragma once
#ifndef _Cad2d_IntsctEntity_Region_Header
#define _Cad2d_IntsctEntity_Region_Header

#include <Cad2d_IntsctEntity.hxx>

#include <map>

namespace tnbLib
{

	// Forward Declarations
	class Cad2d_CmpIntsctEntity;

	class Cad2d_IntsctEntity_Region
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/

		std::shared_ptr<Cad2d_CmpIntsctEntity> theEntity0_;
		std::shared_ptr<Cad2d_CmpIntsctEntity> theEntity1_;

	public:

		Cad2d_IntsctEntity_Region();

		Cad2d_IntsctEntity_Region(const Standard_Integer theIndex);

		Cad2d_IntsctEntity_Region(const Standard_Integer theIndex, const word& theName);


		const auto& Entity0() const
		{
			return theEntity0_;
		}

		const auto& Entity1() const
		{
			return theEntity1_;
		}
	};
}

#endif // !_Cad2d_IntsctEntity_Region_Header
