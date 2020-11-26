#pragma once
#ifndef _Cad2d_IntsctEntity_Adaptor_Header
#define _Cad2d_IntsctEntity_Adaptor_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

#include <map>
#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class Cad2d_IntsctEntity;

	class Cad2d_IntsctEntity_Adaptor
	{

		/*Private Data*/

		std::weak_ptr<Cad2d_IntsctEntity> thePair_;

	protected:

		Cad2d_IntsctEntity_Adaptor()
		{}

	public:

		const auto& Pair() const
		{
			return thePair_;
		}

		void SetPair
		(
			const std::weak_ptr<Cad2d_IntsctEntity>& thePair
		)
		{
			thePair_ = thePair;
		}
	};
}

#endif // !_Cad2d_IntsctEntity_Adaptor_Header
