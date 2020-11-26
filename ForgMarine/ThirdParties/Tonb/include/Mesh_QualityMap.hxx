#pragma once
#ifndef _Mesh_QualityMap_Header
#define _Mesh_QualityMap_Header

#include <Standard_TypeDef.hxx>

#include <map>

namespace tnbLib
{
	typedef std::map<Standard_Integer, Standard_Real> Mesh_QualityMap;
}

#endif // !_Mesh_QualityMap_Header