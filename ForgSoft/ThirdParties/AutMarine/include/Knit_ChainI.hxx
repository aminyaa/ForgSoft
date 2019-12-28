#pragma once
namespace AutLib
{
	template<class KnitTraits>
	std::shared_ptr<typename Knit_Chain<KnitTraits>::nodeType> 
		AutLib::Knit_Chain<KnitTraits>::Next(const std::shared_ptr<nodeType>& theNode)
	{
		if (theNode->Type() NOT_EQUAL Knit_ChainNode_Type::REGULAR)
		{
			if (NOT theNode->NbEdges())
			{
				nodeRegistery::RemoveFromKnit_ChainNodes(theNode->Index());
			}
			return nullptr;
		}

		auto edges = theNode->RetrieveEdges();

		auto Edge = edges.begin()->second.lock();
		Debug_Null_Pointer(Edge);

		theNode->RemoveFromEdges(Edge->Index());
		edgeRegistery::RemoveFromKnit_ChainEdges(Edge->Index());

		const auto& left = std::dynamic_pointer_cast<nodeType>(Edge->Node0());
		const auto& right = std::dynamic_pointer_cast<nodeType>(Edge->Node1());

		std::shared_ptr<nodeType> next;
		if (left IS_EQUAL theNode) next = right;
		else if (right IS_EQUAL theNode) next = left;
		else
		{
			FatalErrorIn("node_ptr Next(const node_ptr& theNode)")
				<< "Unable to find the next node" << endl
				<< abort(FatalError);
		}

		if (edges.size() IS_EQUAL 1)
		{
			nodeRegistery::RemoveFromKnit_ChainNodes(theNode->Index());
		}
		else
		{
			theNode->Type() = Knit_ChainNode_Type::START;
		}

		next->RemoveFromEdges(Edge->Index());
		return std::move(next);
	}

	template<class KnitTraits>
	std::shared_ptr<typename Knit_Chain<KnitTraits>::nodeType> 
		Knit_Chain<KnitTraits>::FindStart(const Knit_ChainNode_Type type) const
	{
		const auto& nodes = nodeRegistery::RetrieveKnit_ChainNodes();
		for (const auto& x : nodes)
		{
			Debug_Null_Pointer(x.second);

			if (x.second->Type() IS_EQUAL type)
			{
				x.second->Type() = Knit_ChainNode_Type::START;
				return x.second;
			}
		}
		return nullptr;
	}

	template<class KnitTraits>
	std::shared_ptr<typename Knit_Chain<KnitTraits>::polygon> 
		Knit_Chain<KnitTraits>::GetPolygon
		(
			const std::shared_ptr<nodeType>& theStart
		)
	{
		theStart->Type() = Knit_ChainNode_Type::REGULAR;

		auto poly = std::make_shared<polygon>();
		Debug_Null_Pointer(poly);

		auto& Pts = poly->Points();

		Pts.push_back(theStart->Coord());
		auto next = Next(theStart);

		while (next)
		{
			Pts.push_back(next->Coord());
			next = Next(next);
		}

		return std::move(poly);
	}

	template<class KnitTraits>
	void Knit_Chain<KnitTraits>::SetTypes()
	{
		auto nodes = nodeRegistery::RetrieveKnit_ChainNodes();
		for (const auto& x : nodes)
		{
			Debug_Null_Pointer(x.second);

			if (x.second->NbEdges() IS_EQUAL 1)
			{
				// start node
				x.second->Type() = Knit_ChainNode_Type::START;
			}
			else
			{
				// regular node
				x.second->Type() = Knit_ChainNode_Type::REGULAR;
			}
		}
	}

	template<class KnitTraits>
	void Knit_Chain<KnitTraits>::Perform()
	{
		// Create regular chains
		auto start = FindStart(Knit_ChainNode_Type::START);
		while (start)
		{
			thePolygons_.push_back(GetPolygon(start));
			start = FindStart(Knit_ChainNode_Type::START);
		}

		// Create cycle chain
		if (edgeRegistery::NbKnit_ChainEdges())
		{
			start = FindStart(Knit_ChainNode_Type::REGULAR);
			while (start)
			{
				thePolygons_.push_back(GetPolygon(start));
				start = FindStart(Knit_ChainNode_Type::REGULAR);
			}
		}

		if (nodeRegistery::NbKnit_ChainNodes())
		{
			FatalErrorIn("void Perform()")
				<< "The Nodes tree is not empty" << endl
				<< abort(FatalError);
		}

		if (edgeRegistery::NbKnit_ChainEdges())
		{
			FatalErrorIn("void Perform()")
				<< "The Edges tree is not empty" << endl
				<< abort(FatalError);
		}

		Change_IsDone() = Standard_True;
	}

	template<class KnitTraits>
	void Knit_Chain<KnitTraits>::Import
	(
		const Entity_StaticData<Point, connectivity::dual>& theChain
	)
	{
		const auto& points = theChain.Points();
		const auto& indices = theChain.Connectivity();

		std::vector<std::shared_ptr<nodeType>> nodes;
		nodes.reserve(points.size());

		Standard_Integer K = 0;
		for (const auto& x : points)
		{
			auto n = std::make_shared<nodeType>(++K, x);
			nodes.push_back(n);
			nodeRegistery::InsertToKnit_ChainNodes(n->Index(), n);
		}

		K = 0;
		for (const auto& x : indices)
		{
			auto v0 = x.Value(0);
			auto v1 = x.Value(1);

			auto e = std::make_shared<edgeType>(++K, nodes[Index_Of(v0)], nodes[Index_Of(v1)]);

			edgeRegistery::InsertToKnit_ChainEdges(e->Index(), e);

			nodes[Index_Of(v0)]->InsertToEdges(e->Index(), e);
			nodes[Index_Of(v1)]->InsertToEdges(e->Index(), e);
		}

		SetTypes();
	}
}