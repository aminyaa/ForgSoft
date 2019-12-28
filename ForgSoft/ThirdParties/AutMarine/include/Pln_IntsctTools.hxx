#pragma once
#ifndef _Pln_IntsctTools_Header
#define _Pln_IntsctTools_Header

#include <Standard_TypeDef.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Pln_Vertex;
	class Pln_Edge;
	class Pln_IntsctPair;
	class Pln_IntsctEntity;
	class Pln_CmpEdge;

	class Pln_IntsctTools
	{

	public:

		static Standard_Boolean IsIntsctEntity(const std::shared_ptr<Pln_Vertex>& theVertex);

		static Standard_Boolean IsIntsctEntity(const std::shared_ptr<Pln_Edge>& theEdge);

		static void Sort(std::vector<std::shared_ptr<Pln_IntsctEntity>>& theEntities);

		static void SubdivideEdge(const std::vector<std::shared_ptr<Pln_IntsctEntity>>& theEntities, std::shared_ptr<Pln_CmpEdge>& theC0, std::shared_ptr<Pln_CmpEdge>& theC1);
	};
}

#endif // !_Pln_IntsctTools_Header
