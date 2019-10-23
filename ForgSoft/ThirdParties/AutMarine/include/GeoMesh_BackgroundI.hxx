#pragma once
namespace AutLib
{

	template<class MeshData, class Type>
	Type GeoMesh_Background<MeshData, Type>::InterpolateAt
	(
		const Point & theCoord
	) const
	{
		Standard_Boolean Sense;
		auto Value = InterpolateAt(theCoord, Sense);

		if (NOT Sense)
		{
			FatalErrorIn("Type InterpolateAt(const Point& theCoord) const")
				<< "the element is not found!" << endl
				<< abort(FatalError);
			return 0;
		}
		return Value;
	}

	template<class MeshData, class Type>
	Type GeoMesh_Background<MeshData, Type>::InterpolateAt
	(
		const Point & theCoord,
		Standard_Boolean & Sense
	) const
	{
		Debug_Null_Pointer(this->Mesh());
		Debug_Null_Pointer(Sources());

		const auto& mesh = *this->Mesh();
		const auto ptr = mesh.TriangleLocation(this->CurrentElement(), theCoord);

		if (!ptr)
		{
			Sense = Standard_False;
			return -RealLast();
		}

		this->Current = ptr;
		const auto& element = *ptr;

		auto weights = element.InterpWeights(theCoord);

		Standard_Real sumA = 0;
		Type numer = 0;

		const auto& sources = *Sources();

		forThose(Index, 0, elementType::rank)
		{
			numer += weights[Index] * sources[element.Node(Index)->Index() - 1];
			sumA += weights[Index];
		}

		Sense = Standard_True;
		return (1.0 / sumA)*numer;
	}

	template<class MeshData, class Type>
	void GeoMesh_Background<MeshData, Type>::HvCorrection
	(
		const std::shared_ptr<hvInfo> theInfo
	)
	{
		if (NOT theInfo)
		{
			FatalErrorIn(FunctionSIG) << endl
				<< "Null pointer has been detected!" << endl
				<< abort(FatalError);
		}

		std::vector<std::shared_ptr<nodeType>> nodes;
		base::Mesh()->RetrieveNodesTo(nodes);

		HvCorrection(nodes, theInfo->Factor(), theInfo->MaxNbIters());
	}
}