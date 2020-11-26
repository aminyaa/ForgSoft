#pragma once
#ifndef _Mesh3d_Facet_Header
#define _Mesh3d_Facet_Header

#include <Mesh_Facet.hxx>
#include <Mesh3d_FacetTraits.hxx>
#include <Mesh3d_Node.hxx>

namespace tnbLib
{

	typedef Mesh_Facet<Mesh3d_FacetTraits> Mesh3d_Facet;

	template<>
	Standard_Boolean Mesh3d_Facet::IsRightSide(const Pnt3d& theCoord) const;

	template<>
	Standard_Boolean  Mesh3d_Facet::IsLeftSide(const Pnt3d& theCoord) const;
}

#endif // !_Mesh3d_Facet_Header