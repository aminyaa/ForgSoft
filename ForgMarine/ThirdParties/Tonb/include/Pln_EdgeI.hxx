#pragma once
#include <error.hxx>
#include <OSstream.hxx>
namespace tnbLib
{

	inline 
		Standard_Boolean tnbLib::Pln_Edge::IsLess
		(
			const std::shared_ptr<Pln_Edge>& theEdge0, 
			const std::shared_ptr<Pln_Edge>& theEdge1
		)
	{
		Debug_Null_Pointer(theEdge0);
		Debug_Null_Pointer(theEdge1);
		return theEdge0->Index() < theEdge1->Index();
	}
}