#pragma once
#ifndef _Mesh_Counters_Header
#define _Mesh_Counters_Header

#include <Standard_TypeDef.hxx>
#include <Mesh_EntityCounterM.hxx>

namespace tnbLib
{

	Mesh_EntityCounter(NodeCounter);
	Mesh_EntityCounter(EdgeCounter);
	Mesh_EntityCounter(FacetCounter);
	Mesh_EntityCounter(ElementCounter);

	class Mesh2d_FrontCounter
		: public Mesh_NodeCounterCounter
		, public Mesh_EdgeCounterCounter
		, public Mesh_ElementCounterCounter
	{

		/*Private Data*/

	public:

		Mesh2d_FrontCounter()
		{}
	};

	class Mesh3d_FrontCounter
		: public Mesh_NodeCounterCounter
		, public Mesh_EdgeCounterCounter
		, public Mesh_FacetCounterCounter
		, public Mesh_ElementCounterCounter
	{

		/*Private Data*/

	public:

		Mesh3d_FrontCounter()
		{}
	};
}

#endif // !_Mesh2d_Counters_Header