#pragma once
#ifndef _Entity3d_Tetrahedralization_Header
#define _Entity3d_Tetrahedralization_Header

#include <Pnt3d.hxx>
#include <Entity_Connectivity.hxx>
#include <Entity_StaticData.hxx>

namespace tnbLib
{

	typedef Entity_StaticData<Pnt3d, connectivity::quadruple>
		Entity3d_Tetrahedralization;

	template<>
	void Entity3d_Tetrahedralization::ExportToPlt(OFstream& File) const;
}

#endif // !_Entity3d_Tetrahedralization_Header
