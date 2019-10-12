#pragma once
#include <GeoProcessor.hxx>

namespace AutLib
{

	template<class FrontTraits, class FrontAdaptor>
	void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::AttachToMeshNodes
	(
		const std::shared_ptr<elementType>& theElement
	)
	{
		Debug_Null_Pointer(theElement);
		auto& element = *theElement;

		if (element.Node(0)->InsertToElements(theElement->Index(), theElement))
		{
			FatalErrorIn("void AttachToMeshNodes(const std::shared_ptr<elementType>& theElement)")
				<< "Failed to register the element to the mesh" << endl
				<< abort(FatalError);
		}
		if (element.Node(1)->InsertToElements(theElement->Index(), theElement))
		{
			FatalErrorIn("void AttachToMeshNodes(const std::shared_ptr<elementType>& theElement)")
				<< "Failed to register the element to the mesh" << endl
				<< abort(FatalError);
		}
		if (element.Node(2)->InsertToElements(theElement->Index(), theElement))
		{
			FatalErrorIn("void AttachToMeshNodes(const std::shared_ptr<elementType>& theElement)")
				<< "Failed to register the element to the mesh" << endl
				<< abort(FatalError);
		}
	}

	template<class FrontTraits, class FrontAdaptor>
	void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::AttachToMeshNodes
	(
		const std::shared_ptr<frontType>& theEdge
	)
	{
		Debug_Null_Pointer(theEdge);
		auto& edge = *theEdge;

		if (edge.Node0()->InsertToEdges(theEdge->Index(), theEdge))
		{
			FatalErrorIn("void AttachToMeshNodes(const std::shared_ptr<frontType>& theEdge)")
				<< "Failed to register the edge to the mesh" << endl
				<< abort(FatalError);
		}
		if (edge.Node1()->InsertToEdges(theEdge->Index(), theEdge))
		{
			FatalErrorIn("void AttachToMeshNodes(const std::shared_ptr<frontType>& theEdge)")
				<< "Failed to register the edge to the mesh" << endl
				<< abort(FatalError);
		}
	}

	template<class FrontTraits, class FrontAdaptor>
	void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::AttachToFrontNodes
	(
		const std::shared_ptr<frontType>& theEdge
	)
	{
		Debug_Null_Pointer(theEdge);
		auto& edge = *theEdge;

		if (edge.Node0()->InsertToFrontEdges(theEdge->Index(), theEdge))
		{
			FatalErrorIn("void AttachToFrontNodes(const std::shared_ptr<frontType>& theEdge)")
				<< "Failed to register the edge to the front" << endl
				<< abort(FatalError);
		}
		if (edge.Node1()->InsertToFrontEdges(theEdge->Index(), theEdge))
		{
			FatalErrorIn("void AttachToFrontNodes(const std::shared_ptr<frontType>& theEdge)")
				<< "Failed to register the edge to the front" << endl
				<< abort(FatalError);
		}
	}

	template<class FrontTraits, class FrontAdaptor>
	void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::AttachToFronts
	(
		const std::shared_ptr<frontType>& theEdge
	)
	{
		AttachToFrontNodes(theEdge);
	}

	template<class FrontTraits, class FrontAdaptor>
	void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::deAttachFromMesh
	(
		const std::shared_ptr<frontType>& theEdge
	)
	{
		Debug_Null_Pointer(theEdge);
		auto& edge = *theEdge;

		if (!edge.IsOrphan())
		{
			FatalErrorIn(FunctionSIG)
				<< " Try to delete a non-orphan edge!"
				<< abort(FatalError);
		}

		if (edge.Node0()->RemoveFromEdges(theEdge->Index()))
		{
			FatalErrorIn("void deAttachFromMesh(const std::shared_ptr<frontType>& theEdge)")
				<< "Failed to remove the edge from the mesh" << endl
				<< abort(FatalError);
		}
		if (edge.Node1()->RemoveFromEdges(theEdge->Index()))
		{
			FatalErrorIn("void deAttachFromMesh(const std::shared_ptr<frontType>& theEdge)")
				<< "Failed to remove the edge from the mesh" << endl
				<< abort(FatalError);
		}
	}

	template<class FrontTraits, class FrontAdaptor>
	void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::deAttachFromFront
	(
		const std::shared_ptr<frontType>& theEdge
	)
	{
		Debug_Null_Pointer(theEdge);
		auto& edge = *theEdge;

		if (edge.Node0()->RemoveFromFrontEdges(theEdge->Index()))
		{
			FatalErrorIn("void deAttachFromFront(const std::shared_ptr<frontType>& theEdge)")
				<< "Failed to remove the edge from the front" << endl
				<< abort(FatalError);
		}
		if (edge.Node1()->RemoveFromFrontEdges(theEdge->Index()))
		{
			FatalErrorIn("void deAttachFromFront(const std::shared_ptr<frontType>& theEdge)")
				<< "Failed to remove the edge from the front" << endl
				<< abort(FatalError);
		}
	}

	template<class FrontTraits, class FrontAdaptor>
	void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::SetPairedEdges()
	{
		frontInfo::SetPairedEdge0(nullptr);
		frontInfo::SetPairedEdge1(nullptr);

		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& current = *frontInfo::CurrentFront();

		Debug_Null_Pointer(current.Node0());
		Debug_Null_Pointer(current.Node1());

		const auto v0 = current.Node0()->Index();
		const auto v1 = current.Node1()->Index();

		const auto& valid = *frontInfo::ValidNode();

		const auto vn = valid.Index();

		for (const auto& x : valid.RetrieveFrontEdges())
		{
			Debug_Null_Pointer(x.second.lock());
			const auto edge_ptr = x.second.lock();
			const auto edge = *edge_ptr;

			const auto e0 = edge.Node0()->Index();
			const auto e1 = edge.Node1()->Index();

			if (Processor::IsPairedTwoSegments(e0, e1, v0, vn))
			{
				frontInfo::SetPairedEdge1(edge_ptr);
			}

			if (Processor::IsPairedTwoSegments(e0, e1, v1, vn))
			{
				frontInfo::SetPairedEdge0(edge_ptr);
			}
		}
	}

	//template<class FrontTraits, class FrontAdaptor>
	//template<class SizeMap>
	//void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::UpdateEdges
	//(
	//	const SizeMap & theSizeMap
	//)
	//{
	//	Debug_Null_Pointer(frontInfo::CurrentFront());
	//	const auto& current = *frontInfo::CurrentFront();

	//	if (frontInfo::IsPairedEdge0())
	//	{
	//		frontInfo::SetCreatedEdge0(nullptr);

	//		// remove the old coicident face from the GF
	//		deAttachFromFront(frontInfo::PairedEdge0());

	//		// remove cavity face
	//		if (frontInfo::PairedEdge0()->IsOnCavity())
	//			frontInfo::PairedEdge0()->RemoveEntityAsCavity();
	//	}
	//	else
	//	{
	//		EdgeCounter()++;

	//		const auto& P1 = frontInfo::ValidNode()->Coord();
	//		const auto& P2 = current.Node1()->Coord();

	//		frontInfo::SetCreatedEdge0(std::make_shared<frontType>(EdgeCounter()));
	//		auto& edge = *frontInfo::CreatedEdge0();

	//		edge.SetCharLength(theSizeMap.CalcDistance(P1, P2));
	//		edge.SetCentre(theSizeMap.CalcCentreOf(P1, P2));
	//		edge.SetNode0(frontInfo::ValidNode());
	//		edge.SetNode1(current.Node1());

	//		Debug_If_Condition(frontInfo::ValidNode() == current.Node1());

	//		AttachToFrontNodes(frontInfo::CreatedEdge0());
	//		AttachToMeshNodes(frontInfo::CreatedEdge0());
	//	}

	//	if (frontInfo::IsPairedEdge1())
	//	{
	//		frontInfo::SetCreatedEdge1(nullptr);

	//		// remove the old coicident face from the GF
	//		deAttachFromFront(frontInfo::PairedEdge1());

	//		// remove cavity face
	//		if (frontInfo::PairedEdge1()->IsOnCavity())
	//			frontInfo::PairedEdge1()->RemoveEntityAsCavity();
	//	}
	//	else
	//	{
	//		EdgeCounter()++;

	//		const auto& P1 = current.Node0()->Coord();
	//		const auto& P2 = frontInfo::ValidNode()->Coord();

	//		frontInfo::SetCreatedEdge1(std::make_shared<frontType>(EdgeCounter()));
	//		auto& edge = *frontInfo::CreatedEdge1();

	//		edge.SetCharLength(theSizeMap.CalcDistance(P1, P2));
	//		edge.SetCentre(theSizeMap.CalcCentreOf(P1, P2));
	//		edge.SetNode0(current.Node0());
	//		edge.SetNode1(frontInfo::ValidNode());

	//		Debug_If_Condition(frontInfo::ValidNode() == current.Node0());

	//		AttachToFrontNodes(frontInfo::CreatedEdge1());
	//		AttachToMeshNodes(frontInfo::CreatedEdge1());
	//	}
	//}

	template<class FrontTraits, class FrontAdaptor>
	void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::CreateElement()
	{
		ElementCounter()++;

		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& current = *frontInfo::CurrentFront();

		auto element_p =
			std::make_shared<elementType>(ElementCounter());
		Debug_Null_Pointer(element_p);

		auto& element = *element_p;
		element.Node0() = current.Node0();
		element.Node1() = current.Node1();
		element.Node2() = frontInfo::ValidNode();

		if (frontInfo::IsCreatedEdge0())
		{
			element.SetEdge(0, frontInfo::CreatedEdge0());
		}
		else
		{
			element.SetEdge(0, frontInfo::PairedEdge0());
		}

		if (frontInfo::IsCreatedEdge1())
		{
			element.SetEdge(1, frontInfo::CreatedEdge1());
		}
		else
		{
			element.SetEdge(1, frontInfo::PairedEdge1());
		}

		element.SetEdge(2, frontInfo::CurrentFront());

		frontInfo::SetElement(element_p);
	}

	template<class FrontTraits, class FrontAdaptor>
	void Aft2d_FrontInfoTemplate<FrontTraits, FrontAdaptor>::UpdateElement()
	{
		Debug_Null_Pointer(frontInfo::Element());
		auto& element = *frontInfo::Element();

		AttachToMeshNodes(frontInfo::Element());

		/* Attach the element to the edges */
		auto& current = *frontInfo::CurrentFront();

		// update right/ left side element pointer of the faces
		// update adjacent elements
		current.SetLeftElement(frontInfo::Element());
		element.SetNeighbor2(current.RightElement());

		auto rightElement = current.RightElement().lock();
		if (rightElement)
		{
			rightElement->Neighbor(rightElement->OppositeVertexIndex(frontInfo::CurrentFront())) = frontInfo::Element();
		}

		if (frontInfo::IsCreatedEdge0())
		{
			frontInfo::CreatedEdge0()->SetRightElement(frontInfo::Element());
			//element.Neighbor(0) = nullptr;
		}
		else
		{
			auto edge = frontInfo::PairedEdge0();
			Debug_Null_Pointer(edge);

			auto neighbor0 = edge->RightElement().lock();
			element.Neighbor(0) = edge->RightElement();

			if (edge->LeftElement().lock())
			{
				FatalErrorIn("void AutLib::Aft2d_FrontInfo::UpdateElement()")
					<< "Contradiction data" << endl
					<< abort(FatalError);
			}

			edge->SetLeftElement(frontInfo::Element());

			if (neighbor0)
			{
				neighbor0->Neighbor(neighbor0->OppositeVertexIndex(edge)) = frontInfo::Element();
			}
		}

		if (frontInfo::IsCreatedEdge1())
		{
			frontInfo::CreatedEdge1()->SetRightElement(frontInfo::Element());
			//element.Neighbor(0) = nullptr;
		}
		else
		{
			auto edge = frontInfo::PairedEdge1();
			Debug_Null_Pointer(edge);

			auto neighbor1 = edge->RightElement().lock();
			element.Neighbor(1) = edge->RightElement();

			if (edge->LeftElement().lock())
			{
				FatalErrorIn("void AutLib::Aft2d_FrontInfo::UpdateElement()")
					<< "Contradiction data" << endl
					<< abort(FatalError);
			}

			edge->SetLeftElement(frontInfo::Element());

			if (neighbor1)
			{
				neighbor1->Neighbor(neighbor1->OppositeVertexIndex(edge)) = frontInfo::Element();
			}
		}
	}
}