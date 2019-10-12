#pragma once
#ifndef _Mesh2d_SizeMapAnIsoFwd_Header
#define _Mesh2d_SizeMapAnIsoFwd_Header

#include <Aft2d_EdgeAnIsoFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class FrontType>
	class Mesh_SizeMap;

	typedef Mesh_SizeMap<Aft2d_EdgeAnIso> Mesh2d_SizeMapAnIso;
}

#endif // !_Mesh2d_SizeMapAnIsoFwd_Header