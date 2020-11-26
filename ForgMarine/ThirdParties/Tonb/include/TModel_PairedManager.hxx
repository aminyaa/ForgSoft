#pragma once
#ifndef _TModel_PairedManager_Header
#define _TModel_PairedManager_Header

#include <Cad_EntityManager.hxx>

namespace tnbLib
{

	// Forward Declarations
	class TModel_Paired;

	typedef Cad_EntityManager<TModel_Paired>
		TModel_PairedManager;
}

#endif // !_TModel_PairedManager_Header
