#pragma once
#ifndef _Aft_CavityData_Header
#define _Aft_CavityData_Header

#include <Mesh_RegisterEntityM.hxx>

namespace AutLib
{

	Mesh_RegisterEntity(UnCertaintyCavitie, FrontEnity);
	Mesh_RegisterEntity(CertaintyCavitie, FrontEntity);

	template<class FrontEntity>
	class Mesh_CavityData
		: public Mesh_RegisterCertaintyCavitie<FrontEntity>
		, public Mesh_RegisterUnCertaintyCavitie<FrontEntity>
	{

		/*Private Data*/

	public:

		Mesh_CavityData()
		{}

	};
}

#endif // !_Aft_CavityData_Header
