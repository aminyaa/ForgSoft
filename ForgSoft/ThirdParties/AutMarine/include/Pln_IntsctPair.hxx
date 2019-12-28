#pragma once
#ifndef _Pln_IntsctPair_Header
#define _Pln_IntsctPair_Header

#include <Global_AccessMethod.hxx>
#include <Pln_IntsctEntity.hxx>

#include <memory>

namespace AutLib
{

	class Pln_IntsctPair
	{

		/*Private Data*/

		std::shared_ptr<Pln_IntsctEntity> theEntity0_;
		std::shared_ptr<Pln_IntsctEntity> theEntity1_;

	public:

		Pln_IntsctPair()
		{}

		//- Macros

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<Pln_IntsctEntity>, Entity0)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<Pln_IntsctEntity>, Entity1)
	};
}

#endif // !_Pln_IntsctPair_Header
