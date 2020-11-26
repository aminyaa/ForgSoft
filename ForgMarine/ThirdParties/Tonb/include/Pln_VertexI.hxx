#pragma once
namespace tnbLib
{

	inline Standard_Boolean 
		Pln_Vertex::IsDangle() const
	{
		return NbEdges() IS_EQUAL 1 AND NOT IsRingPoint();
	}

	inline Standard_Boolean 
		Pln_Vertex::IsOrphan() const
	{
		return NOT NbEdges();
	}
}

inline const tnbLib::Pnt2d & 
tnbLib::Pln_Vertex::GetCoord
(
	const std::shared_ptr<Pln_Vertex>& theVtx
)
{
	Debug_Null_Pointer(theVtx);
	return theVtx->Coord();
}

inline Standard_Boolean 
tnbLib::Pln_Vertex::IsLess
(
	const std::shared_ptr<Pln_Vertex>& theVtx0, 
	const std::shared_ptr<Pln_Vertex>& theVtx1
)
{
	Debug_Null_Pointer(theVtx0);
	Debug_Null_Pointer(theVtx1);

	return theVtx0->Index() < theVtx1->Index();
}