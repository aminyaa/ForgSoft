#pragma once
#ifndef _Entity2d_Chain_Header
#define _Entity2d_Chain_Header

#include <Pnt2d.hxx>
#include <Entity_Connectivity.hxx>
#include <Entity_StaticData.hxx>
#include <Entity2d_BoxFwd.hxx>

namespace AutLib
{

	typedef Entity_StaticData<Pnt2d, connectivity::dual> Entity2d_Chain;

	template<>
	void Entity2d_Chain::CalcBoundingBox();

	template<>
	std::shared_ptr<Entity2d_Chain> Entity2d_Chain::Merged
	(
		const Standard_Real theRes,
		const Standard_Real theRadius
	) const;

	template<>
	void Entity2d_Chain::Merging
	(
		const Standard_Boolean HandleDegeneracy,
		const Standard_Real Resolution,
		const Standard_Real Radius
	);

	template<>
	void Entity2d_Chain::ExportToPlt(std::fstream& File) const;

	template<>
	void Entity2d_Chain::ExportToPlt(OFstream& File) const;
}

#endif // !_Entity2d_Chain_Header
