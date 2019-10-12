#pragma once
namespace AutLib
{

	/*template<class SizeMap, class FrontInfo, class FrontData>
	template<class U>
	Aft_Core<SizeMap, FrontInfo, FrontData>::resolvedType<is_two_dimension<(int)Aft_Core<SizeMap, FrontInfo, FrontData>::Point::dim>::value, U>
		Aft_Core<SizeMap, FrontInfo, FrontData>::Update_Pmin_Pmax
		(
			const Point & P,
			Point & Pmin,
			Point & Pmax
		)
	{

	}*/

	/*template<class SizeMap, class FrontInfo, class FrontData>
	template<class U>
	Aft_Core<SizeMap, FrontInfo, FrontData>::resolvedType<is_two_dimension<(int)Aft_Core<SizeMap, FrontInfo, FrontData>::Point::dim>::value, U>
		Aft_Core<SizeMap, FrontInfo, FrontData>::IsIntersect
		(
			const Point & Q0,
			const Point & Q1,
			const Point & Pmin,
			const Point & Pmax
		)
	{

	}*/

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::RemoveEntitiesFromGeometry()
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

	template<class SizeMap, class FrontInfo, class FrontData>
	Standard_Boolean Aft_Core<SizeMap, FrontInfo, FrontData>::IsOnLevel
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

	template<class SizeMap, class FrontInfo, class FrontData>
	Standard_Boolean Aft_Core<SizeMap, FrontInfo, FrontData>::GetFrontEntity()
	{
		front_ptr entity;
		Standard_Boolean Token = frontData::RetrieveFromPriority(entity);

#ifdef RESET_FRONT_INFO
		frontInfo::Reset();
#endif // RESET_FRONT_INFO

		if (NOT Token) return Standard_False;
		frontInfo::SetCurrentFront(entity);
		return Standard_True;
	}

	template<class SizeMap, class FrontInfo, class FrontData>
	Standard_Boolean Aft_Core<SizeMap, FrontInfo, FrontData>::IsBelongToFront() const
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		return edgeType::IsOnFront(frontInfo::CurrentFront());
	}

	template<class SizeMap, class FrontInfo, class FrontData>
	Standard_Boolean Aft_Core<SizeMap, FrontInfo, FrontData>::ChackDistCriteria
	(
		const Stl_Vector<front_ptr>& theFronts
	) const
	{
		Standard_Real factor = frontInfo::MinDistFactor();
		Debug_If_Condition
		(
			factor <= RealSmall()
		);

		Debug_Null_Pointer(theSizeMap_);
		const auto& sizeMap = *theSizeMap_;

		const auto& Pt = frontInfo::Coord();
		for (const auto& front : theFronts)
		{
			Debug_Null_Pointer(front);
			const auto& entity = *front;

			Standard_Real charLength = factor * entity.CharLength();
			if (sizeMap.CalcSquareDistance(Pt, entity) <= charLength * charLength)
			{
				return Standard_True;
			}
		}
		return Standard_False;
	}

	template<class SizeMap, class FrontInfo, class FrontData>
	Standard_Boolean Aft_Core<SizeMap, FrontInfo, FrontData>::IsSameLevelFueled()
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

	template<class SizeMap, class FrontInfo, class FrontData>
	Standard_Boolean Aft_Core<SizeMap, FrontInfo, FrontData>::IsNextLevelFueled()
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

	template<class SizeMap, class FrontInfo, class FrontData>
	Standard_Boolean Aft_Core<SizeMap, FrontInfo, FrontData>::IsCavityRemoverFueled()
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

	template<class SizeMap, class FrontInfo, class FrontData>
	Standard_Boolean Aft_Core<SizeMap, FrontInfo, FrontData>::IsNewPointCandidate
	(
		const Stl_Vector<front_ptr>& theEffectives
	) const
	{
		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Repair)
		{
			return Standard_False;
		}

		Debug_Null_Pointer(frontInfo::CurrentFront());

		auto factor = frontInfo::MinDistFactor();
		Debug_If_Condition(factor <= 0.);

		Debug_Null_Pointer(theSizeMap_);
		const auto& sizeMap = *theSizeMap_;

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
		auto disSq = sizeMap.CalcSquareDistance(coord, edge);
		auto length = factor * edge.CharLength();
		auto criteria = length * length;

		if (disSq < criteria)
		{
			return Standard_False;
		}

		return Standard_True;
	}

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::CalcElementSize()
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& coord = frontInfo::CurrentFront()->Centre();

		Debug_Null_Pointer(theSizeMap_);
		frontInfo::SetElementSize
		(
			theSizeMap_->CalcElementSize(coord)*
			SIZE_TO_HIGHT_ELEMENT_COEFF
		);
	}

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::CalcOptimumCoord()
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		Debug_Null_Pointer(theSizeMap_);

		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			frontInfo::SetCoord
			(
				theSizeMap_->CalcOptimumCoord(frontInfo::ElementSize(),
					*frontInfo::CurrentFront())
			);
		}
		else
		{
			frontInfo::SetCoord(frontInfo::CurrentFront()->Centre());
		}
	}

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::CalcLocalFrontRadius()
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& current = *frontInfo::CurrentFront();

		const auto& coord = frontInfo::Coord();

		Debug_Null_Pointer(theSizeMap_);
		const auto& sizeMap = *theSizeMap_;

		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
		{
			auto maxLenght = (Standard_Real)0.;
			forThose(Iter, 0, frontType::nbNodes - 1)
			{
				Standard_Real length =
					sizeMap.CalcDistance(coord, current.Node(Iter)->Coord());

				if (length > maxLenght) maxLenght = length;
			}
			maxLenght = MAX(maxLenght, frontInfo::ElementSize() / SIZE_TO_HIGHT_ELEMENT_COEFF)*1.05;
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

			frontInfo::SetLocFrontRadius(MIN(sr, MAX(sizeMap.DimSize(), maxLenght)));
		}
		/*cout << "sr = " << sr << std::endl;
		cout << "max length = " << maxLenght << std::endl;*/
		//if (maxLenght > sr)
		//{
		//	const auto ratio = maxLenght / current.CharLength();
		//	//cout << "ratio = " << ratio << std::endl;
		//	frontInfo::SetLocFrontRadius(ratio*maxLenght);
		//}
		//else
		//{
		//	const auto ratio = MAX(frontInfo::ElementSize() / current.CharLength(), 1.0);
		//	frontInfo::SetLocFrontRadius(ratio*sr);
		//}
	}

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::SetDepthSearching()
	{
		Debug_Null_Pointer(theSizeMap_);
		const auto& sizeMap = *theSizeMap_;

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

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::AddOptimumNodeTo
	(
		Stl_Vector<node_ptr>& theNodes
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

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::SortNodes
	(
		Stl_Vector<node_ptr>& theNodes
	) const
	{
		if (theNodes.size() < 2) return;

		auto nodes = theNodes;
		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& centre = frontInfo::CurrentFront()->Centre();

		Sort.Import(theNodes, centre, *theSizeMap_);
		Sort.Perform((Standard_Integer)theNodes.size());

		auto& Indices = Sort.Indices_;

		for (Standard_Integer i = 0; i < theNodes.size() - 1; i++)
		{
			theNodes[i] = nodes[Indices[i]];
		}
	}

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::RemoveCurrentFromFront() const
	{
		Debug_Null_Pointer(frontInfo::CurrentFront());
		frontInfo::deAttachFromFront
		(
			frontInfo::CurrentFront()
		);
	}

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::RetrieveEffectiveFronts
	(
		const Stl_Vector<front_ptr>& theEntities,
		Stl_Vector<front_ptr>& theEffectives
	) const
	{
		if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Repair)
		{
			theEffectives = theEntities;
			return;
		}
		Debug_Null_Pointer(theSizeMap_);
		const auto& sizeMap = *theSizeMap_;

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

		const auto box1 = sizeMap.CalcEffectiveRegion(r, P, current);
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


	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::RetrieveEarlyNodes
	(
		Stl_Vector<node_ptr>& theNodes
	) const
	{
		Debug_Null_Pointer(theSizeMap_);
		const auto& sizeMap = *theSizeMap_;
		const auto& current = *frontInfo::CurrentFront();

		Stl_Vector<node_ptr> nodes;
		frontData::GeometrySearch(sizeMap.CalcSearchRegion(frontInfo::SearchRadius(), frontInfo::Coord(), current), nodes);

		NodesInRadius(frontInfo::SearchRadius(), frontInfo::Coord(), nodes, theNodes);
	}

	/*template<class SizeMap, class FrontInfo, class FrontData>
	void AutLib::Aft_Core<SizeMap, FrontInfo, FrontData>::RetrieveLocalFrontNodes
	(
		Stl_Vector<node_ptr>& theLocals,
		Stl_Vector<node_ptr>& theSearching
	) const
	{
		Stl_Vector<node_ptr> Locals;
		Debug_Null_Pointer(theSizeMap_);
		Debug_Null_Pointer(frontInfo::CurrentFront());
		const auto& sizeMap = *theSizeMap_;
		const auto& current = *frontInfo::CurrentFront();

		auto box = sizeMap.CalcSearchRegion
		(
			frontInfo::LocFrontRadius(),
			frontInfo::Coord(),
			current
		);

		frontData::GeometrySearch
		(
			box,
			Locals
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

		for (const auto& node : Locals)
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
				theSearching.push_back
				(
					node
				);
			if (radius2 <= squareLocalRadius)
				theLocals.push_back
				(
					node
				);
		}
	}*/

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::NodesInRadius
	(
		const Standard_Real theRadius,
		const Point & theCoord,
		const Stl_Vector<node_ptr>& theNodes,
		Stl_Vector<node_ptr>& theInners
	) const
	{
		Debug_If_Condition_Message(theRadius <= 0., "Invalid Radius");
		const Standard_Real squareRadius = theRadius * theRadius;

		Debug_Null_Pointer(theSizeMap_);
		const auto& sizeMap = *theSizeMap_;

		for (auto& node : theNodes)
		{
			if (sizeMap.CalcSquareDistance(theCoord, node->Coord()) <= squareRadius)
				theInners.push_back
				(
					node
				);
		}
	}

	/*template<class SizeMap, class FrontInfo, class FrontData>
	template<class U>
	Aft_Core<SizeMap, FrontInfo, FrontData>::resolvedType<is_isoType<typename Aft_Core<SizeMap, FrontInfo, FrontData>::nodeTyoe>::value, U>
		Aft_Core<SizeMap, FrontInfo, FrontData>::ModifyLocalFront(const Standard_Real theFactor)
	{

	}*/

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::RejectCurrent
	(
		const front_ptr & theEntity
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

	template<class SizeMap, class FrontInfo, class FrontData>
	void Aft_Core<SizeMap, FrontInfo, FrontData>::RegisterElement()
	{
		globalData::InsertToElements(frontInfo::Element()->Index(), frontInfo::Element());
	}

	//template<class SizeMap, class FrontInfo, class FrontData>
	//void Aft_Core<SizeMap, FrontInfo, FrontData>::UpdateFront()
	//{
	//	Debug_Null_Pointer(frontInfo::ValidNode());
	//	const auto& node = *frontInfo::ValidNode();

	//	frontInfo::PointCondition() = Aft_PointCondition_PickedUp;

	//	// check for updating the nodes tree
	//	if (node.Index() IS_EQUAL frontInfo::NodeCounter() + 1)
	//	{
	//		frontInfo::NodeCounter()++;

	//		frontInfo::PointCondition() = Aft_PointCondition_NewPoint;

	//		// insert the new node into the NODES TREE
	//		frontData::InsertToGeometry(frontInfo::ValidNode());
	//	}

	//	frontInfo::SetPaires();

	//	frontInfo::UpdatePaires(*theSizeMap_);

	//	frontInfo::CreateElement();

	//	frontInfo::UpdateElement();

	//	RemoveEntitiesFromGeometry();

	//	RegisterElement();
	//}
}