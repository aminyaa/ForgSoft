#pragma once
#ifndef _Cad2d_SubEntity_Edge_Header
#define _Cad2d_SubEntity_Edge_Header

#include <Cad2d_SubEntity.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Cad2d_SubEntity_Vertex;
	class Pln_CmpEdge;

	class Cad2d_SubEntity_Edge
		: public Cad2d_SubEntity
	{

		/*Private Data*/

		std::shared_ptr<Cad2d_SubEntity_Vertex> theVtx0_;
		std::shared_ptr<Cad2d_SubEntity_Vertex> theVtx1_;

		std::shared_ptr<Pln_CmpEdge> theCmpEdge_;

	public:

		Cad2d_SubEntity_Edge();

		Cad2d_SubEntity_Edge(const Standard_Integer theIndex);

		Cad2d_SubEntity_Edge(const Standard_Integer theIndex, const word& theName);

		const auto& Vtx0() const
		{
			return theVtx0_;
		}

		const auto& Vtx1() const
		{
			return theVtx1_;
		}

		const auto& CmpEdge() const
		{
			return theCmpEdge_;
		}

		Standard_Boolean IsEdge() const override
		{
			return Standard_True;
		}

	};
}

#endif // !_Cad2d_SubEntity_Edge_Header
