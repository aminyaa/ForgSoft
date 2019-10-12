#pragma once
#ifndef _Entity3d_Triangulation_Header
#define _Entity3d_Triangulation_Header

#include <Pnt3d.hxx>
#include <Entity_Connectivity.hxx>
#include <Entity_StaticData.hxx>

namespace AutLib
{

	typedef Entity_StaticData<Pnt3d, connectivity::triple>
		Entity3d_Triangulation;

	template<>
	void Entity3d_Triangulation::ExportToPlt(OFstream& File) const;
}

#endif // !_Entity3d_Triangulation_Header
