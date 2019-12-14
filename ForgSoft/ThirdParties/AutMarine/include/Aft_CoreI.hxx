#pragma once
namespace AutLib
{

	template<class OptNodeAlg, class SizeFun, class FrontInfo, class FrontData, class MetricFun>
	void Aft_Core<OptNodeAlg, SizeFun, FrontInfo, FrontData, MetricFun>::RetrieveLocalFrontNodes
	(
		std::vector<std::shared_ptr<nodeType>>& theLocals, 
		std::vector<std::shared_ptr<nodeType>>& theSearching
	) const
	{
		Debug_Null_Pointer(base::MetricMap());
		Debug_Null_Pointer(frontInfo::CurrentFront());

		const auto& sizeMap = *base::MetricMap();
		const auto& current = *frontInfo::CurrentFront();

		Entity_Box<Point> box;
		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			box = sizeMap.CalcSearchRegion
			(
				frontInfo::LocFrontRadius(),
				frontInfo::Coord(),
				current
			);
		}
		else
		{
			box = sizeMap.CalcSearchRegion
			(
				frontInfo::LocFrontRadius(),
				current
			);
		}

		frontData::GeometrySearch
		(
			box,
			theLocals
		);

		Debug_If_Condition_Message
		(
			frontInfo::SquareSearchRadius() <= 0,
			"Invalid Searching Radius"
		);
		const auto squareSearchingRadius =
			frontInfo::SquareSearchRadius();

		Debug_If_Condition_Message
		(
			frontInfo::SquareLocFrontRadius() <= 0,
			"Invalid Local Radius"
		);
		const auto squareLocalRadius =
			frontInfo::SquareLocFrontRadius();

		const auto& coord = frontInfo::Coord();

		std::vector<Point> Pts;
		Pts.reserve(theLocals.size());

		for (const auto& node : theLocals)
		{
			Standard_Boolean cond = Standard_False;
			forThose(Index, 0, frontType::nbNodes - 1)
			{
				if (node IS_EQUAL current.Node(Index))
				{
					cond = Standard_True;
					break;
				}
			}
			if (cond)
			{
				continue;
			}

			auto radius2 =
				sizeMap.CalcSquareDistance(coord, node->Coord());

			if (radius2 <= squareSearchingRadius)
			{
				theSearching.push_back
				(
					node
				);

				Pts.push_back(node->Coord());
			}
		}

		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			frontInfo::SetCandidateSize((Standard_Integer)Pts.size());

			if (Pts.size()) frontInfo::SetBoundingBox(Entity_Box<Point>::BoundingBoxOf(Pts));
		}
	}

	template<class OptNodeAlg, class SizeFun, class FrontInfo, class FrontData, class MetricFun>
	void Aft_Core<OptNodeAlg, SizeFun, FrontInfo, FrontData, MetricFun>::ModifyLocalFront
	(
		const Standard_Real theFactor
	)
	{
		if (theFactor < (Standard_Real)1.0)
		{
			FatalErrorIn(FunctionSIG)
				<< "Invalid Factor"
				<< abort(FatalError);
		}

		if (frontData::IsGeometryEmpty())
		{
			return;
		}

		Debug_Null_Pointer(base::MetricMap());
		const auto& sizeMap = *base::MetricMap();

		std::vector<std::shared_ptr<nodeType>> nodes;
		frontData::RetrieveFromGeometryTo(nodes);

		for (auto& ptr : nodes)
		{
			Debug_Null_Pointer(ptr);
			auto& node = *ptr;
			const auto& pt = node.Coord();

			auto fronts = node.RetrieveFrontEdges();
			Debug_If_Condition(NOT fronts.size());

			//- Retrieve max_length attached to the current node
			Standard_Real maxLength = (Standard_Real)0.;
			for (auto& w_entity : fronts)
			{
				Debug_Null_Pointer(w_entity.second.lock());
				auto entity = w_entity.second.lock();

				if (entity->CharLength() > maxLength)
					maxLength = entity->CharLength();
			}

			//- Retrieve worst metric attached to the current node
			auto Iter = fronts.begin();
			auto M = Iter->second.lock()->EffectiveMetric();
			Iter++;

			while (Iter NOT_EQUAL fronts.end())
			{
				const auto& Mi = Iter->second.lock()->EffectiveMetric();
				if (M.Determinant() < Mi.Determinant())
				{
					M = Entity2d_Metric1::UnionSR(M, Mi);
				}
				else
				{
					M = Entity2d_Metric1::UnionSR(Mi, M);
				}
				Iter++;
			}

			maxLength *= theFactor;
			Debug_If_Condition_Message
			(
				maxLength <= (Standard_Real)0.,
				" Invalid MaxLength Value"
			);

			//- save the max_length
			node.SetRadius
			(
				MAX(node.Radius(), maxLength)
			);

			auto detM = M.Determinant();
			//- save worst metric
			if (node.Metric().Determinant() < detM)
			{
				node.SetMetric(Entity2d_Metric1::UnionSR(node.Metric(), M));
			}
			else
			{
				node.SetMetric(Entity2d_Metric1::UnionSR(M, node.Metric()));
			}

			//auto h = sizeMap.CalcElementSize(node.Coord());

			std::vector<std::shared_ptr<nodeType>> locals;
			frontData::GeometrySearch
			(
				sizeMap.CalcSearchRegion(MAX(maxLength, sizeMap.CalcElementSize(node.Coord())), M, node.Coord()),
				locals
			);

			std::vector<std::shared_ptr<nodeType>> inners;
			NodesInRadius
			(
				maxLength,
				node.Coord(),
				locals,
				inners
			);

			for (auto& innerNode : inners)
			{
				innerNode->SetRadius
				(
					MAX(innerNode->Radius(), maxLength)
				);

				if (innerNode->Metric().Determinant() < detM)
				{
					innerNode->SetMetric(Entity2d_Metric1::UnionSR(innerNode->Metric(), M));
				}
				else
				{
					innerNode->SetMetric(Entity2d_Metric1::UnionSR(M, innerNode->Metric()));
				}
			}
		}
	}

	template<class OptNodeAlg, class SizeFun, class FrontInfo, class FrontData, class MetricFun>
	void Aft_Core<OptNodeAlg, SizeFun, FrontInfo, FrontData, MetricFun>::UpdateFront()
	{
		Debug_Null_Pointer(frontInfo::ValidNode());
		const auto& node = frontInfo::ValidNode();

		const auto& current = frontInfo::CurrentFront();

		frontInfo::PointCondition() = Aft_PointCondition_PickedUp;

		// check for updating the nodes tree
		if (node->Index() IS_EQUAL frontInfo::NodeCounter() + 1)
		{
			frontInfo::NodeCounter()++;

			const auto effect = base::MetricMap()->CalcEffectiveMetric(node->Coord(), current->Centre());
			node->SetMetric(effect);

			frontInfo::PointCondition() = Aft_PointCondition_NewPoint;

			// insert the new node into the NODES TREE
			frontData::InsertToGeometry(frontInfo::ValidNode());
		}

		frontInfo::SetPaires();

		frontInfo::UpdatePaires(*base::MetricMap());

		frontInfo::CreateElement();

		frontInfo::UpdateElement();

		base::RemoveEntitiesFromGeometry();

		base::RegisterElement();
	}

	template<class OptNodeAlg, class SizeFun, class FrontInfo, class FrontData>
	void Aft_Core<OptNodeAlg, SizeFun, FrontInfo, FrontData>::RetrieveLocalFrontNodes
	(
		std::vector<std::shared_ptr<nodeType>>& theLocals,
		std::vector<std::shared_ptr<nodeType>>& theSearching
	) const
	{
		Debug_Null_Pointer(base::MetricMap());
		Debug_Null_Pointer(frontInfo::CurrentFront());

		const auto& sizeMap = *base::MetricMap();
		const auto& current = *frontInfo::CurrentFront();

		std::vector<std::shared_ptr<nodeType>> locals;

		Entity_Box<Point> box;
		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			box = sizeMap.CalcSearchRegion
			(
				frontInfo::LocFrontRadius(),
				frontInfo::Coord(),
				current
			);
		}
		else
		{
			box = sizeMap.CalcSearchRegion
			(
				frontInfo::LocFrontRadius(),
				current
			);
		}

		frontData::GeometrySearch
		(
			box,
			locals
		);

		Debug_If_Condition_Message
		(
			frontInfo::SquareSearchRadius() <= 0,
			"Invalid Searching Radius"
		);
		const auto squareSearchingRadius =
			frontInfo::SquareSearchRadius();

		Debug_If_Condition_Message
		(
			frontInfo::SquareLocFrontRadius() <= 0,
			"Invalid Local Radius"
		);
		const auto squareLocalRadius =
			frontInfo::SquareLocFrontRadius();

		const auto& coord = frontInfo::Coord();

		std::vector<Point> Pts;
		Pts.reserve(locals.size());
		for (const auto& node : locals)
		{
			Standard_Boolean cond = Standard_False;
			forThose(Index, 0, frontType::nbNodes - 1)
			{
				if (node IS_EQUAL current.Node(Index))
				{
					cond = Standard_True;
					break;
				}
			}
			if (cond)
			{
				continue;
			}

			auto radius2 =
				sizeMap.CalcSquareDistance(coord, node->Coord());

			if (radius2 <= squareSearchingRadius)
			{
				theSearching.push_back
				(
					node
				);
				Pts.push_back(node->Coord());
			}
			if (radius2 <= squareLocalRadius)
				theLocals.push_back
				(
					node
				);
		}

		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			frontInfo::SetCandidateSize((Standard_Integer)Pts.size());

			if (Pts.size()) frontInfo::SetBoundingBox(Entity_Box<Point>::BoundingBoxOf(Pts));
		}
	}

	template<class OptNodeAlg, class SizeFun, class FrontInfo, class FrontData>
	void Aft_Core<OptNodeAlg, SizeFun, FrontInfo, FrontData>::ModifyLocalFront
	(
		const Standard_Real theFactor
	)
	{
		if (theFactor < (Standard_Real)1.0)
		{
			FatalErrorIn(FunctionSIG)
				<< "Invalid Factor"
				<< abort(FatalError);
		}

		if (frontData::IsGeometryEmpty())
		{
			return;
		}

		Debug_Null_Pointer(base::MetricMap());
		const auto& sizeMap = *base::MetricMap();

		std::vector<std::shared_ptr<nodeType>> nodes;
		frontData::RetrieveFromGeometryTo(nodes);

		for (auto& ptr : nodes)
		{
			Debug_Null_Pointer(ptr);
			auto& node = *ptr;
			const auto& pt = node.Coord();

			auto fronts = node.RetrieveFrontEdges();
			Debug_If_Condition(NOT fronts.size());

			//- Retrieve max_length attached to the current node
			Standard_Real maxLength = (Standard_Real)0.;
			for (auto& w_entity : fronts)
			{
				Debug_Null_Pointer(w_entity.second.lock());
				auto entity = w_entity.second.lock();

				if (entity->CharLength() > maxLength)
					maxLength = entity->CharLength();
			}

			maxLength *= theFactor;
			Debug_If_Condition_Message
			(
				maxLength <= (Standard_Real)0.,
				" Invalid MaxLength Value"
			);

			//- save the max_length
			node.SetRadius
			(
				MAX(node.Radius(), maxLength)
			);

			std::vector<std::shared_ptr<nodeType>> locals;
			frontData::GeometrySearch
			(
				sizeMap.CalcSearchRegion(maxLength, node.Coord()),
				locals
			);

			std::vector<std::shared_ptr<nodeType>> inners;
			base::NodesInRadius
			(
				maxLength,
				node.Coord(),
				locals,
				inners
			);

			for (auto& innerNode : inners)
				innerNode->SetRadius
				(
					MAX(innerNode->Radius(), maxLength)
				);
		}
	}

	template<class OptNodeAlg, class SizeFun, class FrontInfo, class FrontData>
	void Aft_Core<OptNodeAlg, SizeFun, FrontInfo, FrontData, void>::UpdateFront()
	{
		Debug_Null_Pointer(frontInfo::ValidNode());
		const auto& node = *frontInfo::ValidNode();

		frontInfo::PointCondition() = Aft_PointCondition_PickedUp;

		// check for updating the nodes tree
		if (node.Index() IS_EQUAL frontInfo::NodeCounter() + 1)
		{
			frontInfo::NodeCounter()++;

			frontInfo::PointCondition() = Aft_PointCondition_NewPoint;

			// insert the new node into the NODES TREE
			frontData::InsertToGeometry(frontInfo::ValidNode());
		}

		frontInfo::SetPaires();

		frontInfo::UpdatePaires(*base::MetricMap());

		frontInfo::CreateElement();

		frontInfo::UpdateElement();

		base::RemoveEntitiesFromGeometry();

		base::RegisterElement();
	}
}