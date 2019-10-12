#pragma once
#ifndef _Entity2d_Triangulation_Header
#define _Entity2d_Triangulation_Header

#include <Pnt2d.hxx>
#include <Entity_Connectivity.hxx>
#include <Entity_StaticData.hxx>

namespace AutLib
{

	typedef Entity_StaticData<Pnt2d, connectivity::triple>
		Entity2d_Triangulation;

	template<>
	void Entity2d_Triangulation::ExportToPlt(OFstream& File) const;
}

#endif // !_Entity2d_Triangulation_Header
