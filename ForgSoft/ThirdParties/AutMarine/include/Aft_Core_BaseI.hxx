#pragma once
namespace AutLib
{

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::RemoveEntitiesFromGeometry()
	{
		Debug_Null_Pointer(frontInfo::Element());
		auto& element = *frontInfo::Element();

		for (int i = 0; i < elementType::nbNodes; i++)
		{
			Debug_Null_Pointer(element.Node(i));

			if (NOT element.Node(i)->NbFrontEdges())
			{
				frontData::RemoveFromGeometry(element.Node(i));
			}
		}
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	Standard_Boolean Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::IsOnLevel
	(
		const frontType & theFront
	) const
	{
		forThose(Index, 0, frontType::nbNodes - 1)
		{
			Debug_Null_Pointer(theFront.Node(Index));
			if (theFront.Node(Index)->Index() <= frontData::LevelMaxIndex()) return Standard_False;
		}
		return Standard_True;
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	Standard_Boolean Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::GetFrontEntity()
	{
		std::shared_ptr<frontType> entity;
		Standard_Boolean Token = frontData::RetrieveFromPriority(entity);

#ifdef RESET_FRONT_INFO
		frontInfo::Reset();
#endif // RESET_FRONT_INFO

		if (NOT Token) return Standard_False;
		frontInfo::SetCurrentFront(entity);
		return Standard_True;
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	Standard_Boolean Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::IsBelongToFront() const
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		return frontType::IsOnFront(frontInfo::CurrentFront());
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	Standard_Boolean Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::ChackDistCriteria
	(
		const std::vector<std::shared_ptr<frontType>>& theFronts
	) const
	{
		const auto factor = frontInfo::MinDistFactor();
		Debug_If_Condition
		(
			factor <= RealSmall()
		);

		Debug_Null_Pointer(theMetricMap_);
		const auto& sizeMap = *theMetricMap_;

		const auto& Pt = frontInfo::Coord();
		for (const auto& front : theFronts)
		{
			Debug_Null_Pointer(front);
			const auto& entity = *front;

			auto charLength = factor * entity.CharLength();
			if (sizeMap.CalcSquareDistance(Pt, entity) <= charLength * charLength)
			{
				return Standard_True;
			}
		}
		return Standard_False;
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	Standard_Boolean Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::IsSameLevelFueled()
	{
		if (frontData::IsCurrentLevelEmpty())
		{
			return Standard_False;
		}

		const auto& entities = frontData::RetrieveCurrentFronts();
		frontData::SetSizeToPriority((Standard_Integer)entities.size());
		for (const auto& x : entities)
		{
			frontData::InsertToPriority(x.second);
		}

		frontData::ClearCurrentFronts();
		return Standard_True;
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	Standard_Boolean Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::IsNextLevelFueled()
	{
		if (frontData::IsNextLevelEmpty())
		{
			return Standard_False;
		}

		const auto& entities = frontData::RetrieveNextFronts();
		frontData::SetSizeToPriority((Standard_Integer)entities.size());
		for (const auto& x : entities)
		{
			Debug_Null_Pointer(x.second);
			if (x.second->IsOnCavity())
			{
				x.second->RemoveEntityAsCavity();
			}
			frontData::InsertToPriority(x.second);
		}

		frontData::ClearNextFronts();
		frontData::SetLevelMaxIndex(frontInfo::NodeCounter());

		return Standard_True;
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	Standard_Boolean Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::IsCavityRemoverFueled()
	{
		if (NOT frontData::NbUnCertaintyCavities())
		{
			return Standard_False;
		}

		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			const auto& entities = frontData::RetrieveUnCertaintyCavities();
			frontData::SetSizeToPriority((Standard_Integer)entities.size());
			for (const auto& x : entities)
			{
				Debug_Null_Pointer(x.second);
				if (x.second->IsOnCavity())
				{
					x.second->RemoveEntityAsCavity();
				}
				frontData::InsertToPriority(x.second);
			}
			frontData::ClearUnCertaintyCavities();
			return Standard_True;
		}

		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Repair)
		{
			const auto& entities = frontData::RetrieveUnCertaintyCavities();
			for (const auto& x : entities)
			{
				Debug_Null_Pointer(x.second);
				frontData::InsertToCertaintyCavities(x.second->Index(), x.second);
			}

			frontData::ClearUnCertaintyCavities();
			return Standard_False;
		}

		FatalErrorIn(FunctionSIG)
			<< "Something goes wrong!"
			<< abort(FatalError);

		return Standard_True;
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	Standard_Boolean Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::IsNewPointCandidate
	(
		const std::vector<std::shared_ptr<frontType>>& theEffectives
	) const
	{
		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Repair)
		{
			return Standard_False;
		}

		Debug_Null_Pointer(frontInfo::CurrentFront());

		auto factor = frontInfo::MinDistFactor();
		Debug_If_Condition(factor <= 0.);

		Debug_Null_Pointer(theMetricMap_);
		const auto& sizeMap = *theMetricMap_;

		const auto& coord = frontInfo::Coord();
		for (const auto& x : theEffectives)
		{
			Debug_Null_Pointer(x);
			const auto& edge = *x;

			auto length = factor * edge.CharLength();
			auto criteria = length * length;

			auto disSq = sizeMap.CalcSquareDistance(coord, edge);
			if (disSq < criteria)
			{
				return Standard_False;
			}
		}

		const auto& edge = *frontInfo::CurrentFront();
		const auto disSq = sizeMap.CalcSquareDistance(coord, edge);
		const auto length = factor * edge.CharLength();
		const auto criteria = length * length;

		if (disSq < criteria)
		{
			return Standard_False;
		}

		return Standard_True;
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::CalcOptimumCoord()
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		Debug_Null_Pointer(theMetricMap_);
		Debug_Null_Pointer(NodeCalculator());

		auto& nodeCalc = *NodeCalculator();

		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			nodeCalc.SetFront(frontInfo::CurrentFront());
			nodeCalc.SetSize(frontInfo::ElementSize());

			nodeCalc.Perform();

			Debug_If_Condition_Message(NOT nodeCalc.IsDone(), "opt node calculator is not performed!");

			if (NOT nodeCalc.IsConverged())
			{
				std::cout << "warning! the algorithm is not converged!" << std::endl;
			}

			frontInfo::SetCoord(nodeCalc.Coord());
		}
		else
		{
			frontInfo::SetCoord(frontInfo::CurrentFront()->Centre());
		}
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::CalcElementSize()
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& coord = frontInfo::CurrentFront()->Centre();

		Debug_Null_Pointer(theMetricMap_);
		frontInfo::SetElementSize
		(
			theMetricMap_->CalcElementSize(coord)*
			SIZE_TO_HIGHT_ELEMENT_COEFF
		);
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::CalcLocalFrontRadius()
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& current = *frontInfo::CurrentFront();

		const auto& coord = frontInfo::Coord();

		Debug_Null_Pointer(theMetricMap_);
		const auto& sizeMap = *theMetricMap_;
		
		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			auto maxLenght = (Standard_Real)0.;
			forThose(Iter, 0, frontType::nbNodes - 1)
			{
				Standard_Real length =
					sizeMap.CalcDistance(coord, current.Node(Iter)->Coord());

				if (length > maxLenght) maxLenght = length;
			}

			maxLenght = MAX(maxLenght, frontInfo::ElementSize() / SIZE_TO_HIGHT_ELEMENT_COEFF)*1.12;
			frontInfo::SetMaxElmLength(maxLenght);

			auto sr = current.SearchRadius();
			auto ratio = MAX(maxLenght / current.CharLength(), 1.0);
			
			frontInfo::SetLocFrontRadius(ratio*sr);
		}
		else
		{
			auto maxLenght = frontInfo::ElementSize() / SIZE_TO_HIGHT_ELEMENT_COEFF;
			frontInfo::SetMaxElmLength(maxLenght);

			auto sr = current.SearchRadius();

			frontInfo::SetLocFrontRadius(MAX(sr, MIN(sizeMap.DimSize(), maxLenght)));
		}
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::SetDepthSearching()
	{
		Debug_Null_Pointer(theMetricMap_);
		const auto& sizeMap = *theMetricMap_;

		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& current = *frontInfo::CurrentFront();

		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			frontInfo::SetSearchRadius
			(
				0.95*MAX
				(
					sizeMap.CalcDistance(frontInfo::Coord(), current.Centre()),
					frontInfo::ElementSize()
				)
			);

			/*frontInfo::SetSearchRadius
			(
				0.95*sizeMap.CalcDistance(frontInfo::Coord(), current.Centre())
			);*/
		}
		else
		{
			frontInfo::SetSearchRadius(frontInfo::LocFrontRadius());
		}
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::AddOptimumNodeTo
	(
		std::vector<std::shared_ptr<nodeType>>& theNodes
	)
	{
		frontInfo::SetTempoNode
		(
			std::make_shared<nodeType>(frontInfo::NodeCounter() + 1, frontInfo::Coord())
		);

		Debug_Null_Pointer(frontInfo::TempoNode());
		theNodes.push_back
		(
			frontInfo::TempoNode()
		);
		frontInfo::AppendedNode() = Standard_True;
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::SortNodes
	(
		std::vector<std::shared_ptr<nodeType>>& theNodes
	) const
	{
		if (theNodes.size() < 2) return;

		auto nodes = theNodes;
		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& centre = frontInfo::CurrentFront()->Centre();

		Sort.Import(theNodes, centre, *theMetricMap_);
		Sort.Perform((Standard_Integer)theNodes.size());

		auto& Indices = Sort.Indices_;

		for (Standard_Integer i = 0; i < theNodes.size() - 1; i++)
		{
			theNodes[i] = nodes[Indices[i]];
		}
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::RemoveCurrentFromFront() const
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		frontInfo::deAttachFromFront
		(
			frontInfo::CurrentFront()
		);
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::RetrieveEffectiveFronts
	(
		const std::vector<std::shared_ptr<frontType>>& theEntities,
		std::vector<std::shared_ptr<frontType>>& theEffectives
	) const
	{
		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Repair)
		{
			theEffectives = theEntities;
			return;
		}
		Debug_Null_Pointer(theMetricMap_);
		const auto& sizeMap = *theMetricMap_;

		const auto& domain = sizeMap.BoundingBox();
		if (NOT domain.IsInside(frontInfo::Coord()))
		{
			theEffectives = theEntities;
			return;
		}

		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& current =
			*frontInfo::CurrentFront();

		const auto& box0 = frontInfo::BoundingBox();

		const auto& P = frontInfo::Coord();
		const auto r = sizeMap.CalcDistance(P, current.Centre());
		
		const auto box1 = sizeMap.CalcEffectiveFront(r, P, current);
		/*fileName name("box.plt");
		OFstream file(name, ios_base::app);*/


		Entity_Box<Point> box;
		if (frontInfo::CandidateSize())
		{
			box = Entity_Box<Point>::Union(box0, box1);

			/*box0.ExportToPlt(file);
			box1.ExportToPlt(file);*/
		}
		else
		{
			box = box1;
		}
		auto Pmin = box.P0();
		auto Pmax = box.P1();

		forThose(Iter, 0, frontType::nbNodes - 1)
		{
			Debug_Null_Pointer(current.Node(Iter));
			Update_Pmin_Pmax(current.Node(Iter)->Coord(), Pmin, Pmax);
		}
		Update_Pmin_Pmax(box.P0(), Pmin, Pmax);
		Update_Pmin_Pmax(box.P1(), Pmin, Pmax);

		theEffectives.reserve(theEntities.size());
		for (const auto& entityPtr : theEntities)
		{
			Debug_Null_Pointer(entityPtr);
			const auto& entity = *entityPtr;

			if (IsIntersect(entity.Node0()->Coord(), entity.Node1()->Coord(), Pmin, Pmax))
			{
				theEffectives.push_back(entityPtr);
			}
		}
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::RetrieveEarlyNodes
	(
		std::vector<std::shared_ptr<nodeType>>& theNodes
	) const
	{
		Debug_Null_Pointer(theMetricMap_);
		const auto& sizeMap = *theMetricMap_;
		const auto& current = *frontInfo::CurrentFront();

		auto region = sizeMap.CalcSearchRegion(frontInfo::SearchRadius(), frontInfo::Coord(), current);

		std::vector<std::shared_ptr<nodeType>> nodes;
		frontData::GeometrySearch(region, nodes);
		
		NodesInRadius(frontInfo::SearchRadius(), frontInfo::Coord(), nodes, theNodes);
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::RejectCurrent
	(
		const std::shared_ptr<frontType>& theEntity
	)
	{
		Debug_Null_Pointer(theEntity);
		auto& entity = *theEntity;

		if (frontType::IsOnFront(theEntity))
		{
			FatalErrorIn(FunctionSIG)
				<< "Failed to Reject the current"
				<< abort(FatalError);
		}

		entity.MarkEntityAsCavity();

		frontInfo::AttachToFronts(theEntity);
		frontData::InsertToUnCertaintyCavities(theEntity->Index(), theEntity);
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::RegisterElement()
	{
		globalData::InsertToElements(frontInfo::Element()->Index(), frontInfo::Element());
	}

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	void Aft_Core_Base<OptNodeAlg, FrontInfo, FrontData, SizeFun, MetricFun>::NodesInRadius
	(
		const Standard_Real theRadius, 
		const Point & theCoord, 
		const std::vector<std::shared_ptr<nodeType>>& theNodes, 
		std::vector<std::shared_ptr<nodeType>>& theInners
	) const
	{
		Debug_If_Condition_Message(theRadius <= 0., "Invalid Radius");
		const Standard_Real squareRadius = theRadius * theRadius;

		Debug_Null_Pointer(theMetricMap_);
		const auto& sizeMap = *theMetricMap_;

		for (auto& node : theNodes)
		{
			if (sizeMap.CalcSquareDistance(theCoord, node->Coord()) <= squareRadius)
				theInners.push_back
				(
					node
				);
		}
	}
}