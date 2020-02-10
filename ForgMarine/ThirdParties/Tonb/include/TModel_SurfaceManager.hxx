#pragma once
#ifndef _TModel_SurfaceManager_Header
#define _TModel_SurfaceManager_Header

#include <Cad_EntityManager.hxx>

namespace tnbLib
{

	// Forward Declarations
	class TModel_Surface;

	typedef Cad_EntityManager<TModel_Surface>
		TModel_SurfaceManager;
}

#endif // !_TModel_SurfaceManager_Header
