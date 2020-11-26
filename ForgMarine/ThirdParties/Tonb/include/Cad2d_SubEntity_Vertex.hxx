#pragma once
#ifndef _Cad2d_SubEntity_Vertex_Header
#define _Cad2d_SubEntity_Vertex_Header

#include <Cad2d_SubEntity.hxx>
#include <Cad2d_SubEntity_VertexAdaptor.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Vertex;

	class Cad2d_SubEntity_Vertex
		: public Cad2d_SubEntity
		, public Cad2d_SubEntity_VertexAdaptor
	{

		/*Private Data*/

		std::shared_ptr<Pln_Vertex> theVtx_;

	public:

		Cad2d_SubEntity_Vertex();

		Cad2d_SubEntity_Vertex(const Standard_Integer theIndex);

		Cad2d_SubEntity_Vertex(const Standard_Integer theIndex, const word& theName);


		const auto& Vtx() const
		{
			return theVtx_;
		}

		Standard_Boolean IsVertex() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Cad2d_SubEntity_Vertex_Header
