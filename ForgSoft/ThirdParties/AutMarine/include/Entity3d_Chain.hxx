#pragma once
#ifndef _Entity3d_Chain_Header
#define _Entity3d_Chain_Header

#include <Pnt3d.hxx>
#include <Entity_Connectivity.hxx>
#include <Entity_StaticData.hxx>
#include <Entity3d_BoxFwd.hxx>

namespace AutLib
{

	typedef Entity_StaticData<Pnt3d, connectivity::dual> Entity3d_Chain;

	template<>
	void Entity3d_Chain::CalcBoundingBox();

	template<>
	std::shared_ptr<Entity3d_Chain> Entity3d_Chain::Merged
	(
		const Standard_Real theRes,
		const Standard_Real theRadius
	) const;

	template<>
	void Entity3d_Chain::Merging
	(
		const Standard_Boolean HandleDegeneracy,
		const Standard_Real Resolution,
		const Standard_Real Radius
	);

	template<>
	void Entity3d_Chain::ExportToPlt(OFstream& File) const;
}

#endif // !_Entity3d_Chain_Header
