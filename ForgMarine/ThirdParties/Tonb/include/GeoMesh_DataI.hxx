#pragma once
#include <Adt_AvlTree.hxx>
namespace tnbLib
{

	template<class ElementType>
	std::shared_ptr<typename GeoMesh_Data<ElementType>::elementType>
		GeoMesh_Data<ElementType>::TriangleLocation
		(
			const std::shared_ptr<elementType>& theStart,
			const Point & theCoord
		) const
	{
		if (NOT theStart)
		{
			FatalErrorIn("element_ptr TriangleLocation(const element_ptr& theStart, const Pnt2d& theCoord) const")
				<< "Null element has been encountered!" << endl
				<< abort(FatalError);
		}

		auto neighbor = theStart;
		auto element = theStart;
#if MESH_DEBUG
		int k = 0;
#endif
		while (Standard_True)
		{
			for (auto i = 0; i <= elementType::rank; i++)
			{
				Debug_Null_Pointer(element->SubEntity<elementType::rank - 1>(i));
				const auto& entity = *element->SubEntity<elementType::rank - 1>(i);

				auto leftElement = entity.LeftElement().lock();
				if (leftElement == element)
				{
					if (entity.IsRightSide(theCoord))
					{
						neighbor = entity.RightElement().lock();
						if (!neighbor)
						{
							//- the point is outside the background mesh
							return nullptr;
						}
						break;
					}
				}
				else
				{
					if (entity.IsLeftSide(theCoord))
					{
						neighbor = leftElement;
						if (!neighbor)
						{
							//- the point is outside the background mesh
							return nullptr;
						}
						break;
					}
				}


			}

			if (neighbor == element)
			{
				// Found the Triangle
				return neighbor;
			}

#if MESH_DEBUG
			++k;
			if (k >= MAX_WALKING_CYCLES)
			{
				FatalErrorIn("element_ptr TriangleLocation(const element_ptr& theStart, const Pnt2d& theCoord) const;")
					<< "It's look like the algorithm stuck in an infinite loop" << endl
					<< " - Unable to find the triangle which encompassed the point" << endl
					<< abort(FatalError);
			}
#endif	

			element = neighbor;
		}
		return nullptr;
	}

	template<class ElementType>
	std::shared_ptr<typename GeoMesh_Data<ElementType>::triangulation>
		GeoMesh_Data<ElementType>::StaticData() const
	{
		std::vector<std::shared_ptr<nodeType>> nodes;
		RetrieveNodesTo(nodes);

		auto staticData = std::make_shared<triangulation>();
		auto& pts = staticData->Points();
		pts.reserve(nodes.size());
		for (const auto& x : nodes)
		{
			pts.push_back(x->Coord());
		}

		auto& indices = staticData->Connectivity();
		indices.reserve(theElements_.size());
		for (const auto& x : theElements_)
		{
			connectType I;
			forThose(Index, 0, elementType::rank)
				I.Value(Index) = x->Node(Index)->Index();
			indices.push_back(std::move(I));
		}
		return std::move(staticData);
	}

	template<class ElementType>
	void GeoMesh_Data<ElementType>::RetrieveNodesTo
	(
		std::vector<std::shared_ptr<nodeType>>& theNodes
	) const
	{
		Adt_AvlTree<std::shared_ptr<nodeType>> merge;
		merge.SetComparableFunction(&nodeType::IsLess);

		for (const auto& x : Elements())
		{
			Debug_Null_Pointer(x);
			const auto& element = *x;

			forThose(Index, 0, elementType::rank)
			{
				merge.InsertIgnoreDup(element.Node(Index));
			}
		}
		merge.RetrieveTo(theNodes);
	}
}