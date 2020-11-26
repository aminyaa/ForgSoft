#pragma once
#ifndef _TModel_VertexManager_Header
#define _TModel_VertexManager_Header

#include <Cad_EntityManager.hxx>

namespace tnbLib
{

	// Forward Declarations
	class TModel_Vertex;

	typedef Cad_EntityManager<TModel_Vertex>
		TModel_VertexManager;
}

#endif // !_TModel_VertexManager_Header
