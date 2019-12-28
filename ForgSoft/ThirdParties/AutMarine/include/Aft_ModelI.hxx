#pragma once
template<class ModelType, class SizeFun, class MetricFun>
AutLib::Entity_Box<typename AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::Point> 
AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::RetrieveBoundingBox
(
	const std::vector<std::shared_ptr<nodeType>>& theNodes
)
{
	std::vector<Point> pts;
	pts.reserve(theNodes.size());
	for (const auto& x : theNodes)
	{
		Debug_Null_Pointer(x);
		pts.push_back(x->Coord());
	}
	auto box = Entity_Box<Point>::BoundingBoxOf(pts);
	return std::move(box);
}

template<class ModelType, class SizeFun, class MetricFun>
void AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::CheckBoundary
(
	const std::vector<std::shared_ptr<frontType>>& theFronts
)
{
	for (const auto& x : theFronts)
	{
		Debug_Null_Pointer(x->Node0());
		Debug_Null_Pointer(x->Node1());

		const auto& n0 = *x->Node0();
		const auto& n1 = *x->Node1();

		if (n0.NbFrontEdges() NOT_EQUAL 2 OR n1.NbFrontEdges() NOT_EQUAL 2)
		{
			FatalErrorIn("void CheckBoundary(const std::vector<std::shared_ptr<frontType>>& theFronts)")
				<< "The edge is not manifold" << endl
				<< abort(FatalError);
		}
	}
}

namespace AutLib
{
	template<class ModelType, class SizeFun, class MetricFun>
	void Aft_Model<ModelType, SizeFun, MetricFun>::Import
	(
		const std::vector<std::shared_ptr<frontType>>& theBoundary,
		const std::shared_ptr<metricPrcsr>& theBoundaryMap
	)
	{
		base::NodeCounter() = (Standard_Integer)theBoundary.size();
		base::ElementCounter() = 0;
		base::EdgeCounter() = (Standard_Integer)theBoundary.size();

		CheckBoundary(BoundaryEdges());

		const auto& nodes = RetrieveNodesFrom(BoundaryEdges());

		auto box = RetrieveBoundingBox(nodes);

		// Set Searching Region
		base::SetGeometryRegion(box.OffSet(0.01 * box.Diameter()));

		// Insert To Front
		base::InsertToGeometry(nodes);
		base::InsertToPriority(BoundaryEdges());
	}

	template<class ModelType, class SizeFun, class MetricFun>
	Standard_Integer Aft_Model<ModelType, SizeFun, MetricFun>::Meshing()
	{
		if (base::IsPriorityEmpty())
		{
			FatalErrorIn("void AutLib::Mesh_Plane::Perform()")
				<< "Empty priority list" << endl
				<< abort(FatalError);
		}

		frontData::SetLevelNumber(0);
		frontData::SetLevelMaxIndex(base::NodeCounter());

		base::AlgCondition() = Aft_AlgCondition_Generation;

		//const auto startTime = (Standard_Real)getCPUTime();

		/*fileName outPutName("meshingOutPuts.txt");
		OFstream outPuts(outPutName);*/

		while (NOT base::IsPriorityEmpty())
		{
			MeshingOneLevel(/*outPuts*/);

			if (base::IsSameLevelFueled())
			{
				base::AlgCondition() = Aft_AlgCondition_Generation;
				continue;
			}

			if (base::IsCavityRemoverFueled())
			{
				base::AlgCondition() = Aft_AlgCondition_Repair;
				continue;
			}

			frontData::SetLevelNumber(frontData::LevelNumber() + 1);

			if (frontData::LevelNumber() >= ALLOWED_MAX_LEVEL_GENERATION)
			{
				return 1;
			}

			if (base::IsNextLevelFueled())
			{
				base::AlgCondition() = Aft_AlgCondition_Generation;
			}
		}

		return 0;
	}

	template<class ModelType, class SizeFun, class MetricFun>
	Standard_Boolean Aft_Model<ModelType, SizeFun, MetricFun>::CheckAngle
	(
		const frontType& theFront,
		const nodeType& theNode,
		const Standard_Real CosAngle
	) const
	{
		const auto& sizeMap = *base::MetricMap();
		const auto clength = theFront.CharLength();

		const auto& vrtx0 = *theFront.Node0();
		const auto& vrtx1 = *theFront.Node1();
		
		const auto l0 = sizeMap.CalcDistance(vrtx0.Coord(), theNode.Coord());
		const auto l1 = sizeMap.CalcDistance(vrtx1.Coord(), theNode.Coord());

		const auto angN0 = (l0 * l0 + clength * clength - l1 * l1) / (2.0 * l0 * clength);
		if (NOT INSIDE(angN0, -CosAngle, CosAngle))
		{
			return Standard_True;
		}

		const auto angN1 = (l1 * l1 + clength * clength - l0 * l0) / (2.0 * l1 * clength);
		if (NOT INSIDE(angN1, -CosAngle, CosAngle))
		{
			return Standard_True;
		}
		return Standard_False;
	}

	template<class ModelType, class SizeFun, class MetricFun>
	void Aft_Model<ModelType, SizeFun, MetricFun>::MeshingOneLevel()
	{
		base::ModifyLocalFront(DEFAULT_LOCALFRONT_FACTOR);

		while (base::GetFrontEntity())
		{
			std::vector<std::shared_ptr<nodeType>>
				CandidateNodes,
				LocalNodes;

			std::vector<std::shared_ptr<frontType>>
				Effectives,
				Local;

			if (NOT base::IsBelongToFront())
				continue;
			/*cout << "element index = " << this->NbElements() << std::endl;
			cout << "condition = " << base::AlgCondition() << std::endl;
			PAUSE;*/
			//if (this->NbElements() > 61) continue; 
			//cout << base::CurrentFront()->Node0()->Coord().Y() << "   " << base::CurrentFront()->Node1()->Coord().Y() << std::endl;
			/*cout << "index = " << this->NbElements() << std::endl;
			cout << base::CurrentFront()->Centre() << std::endl;
			if (this->NbElements() > 142) continue;*/
			// Remove the Current from front
			base::RemoveCurrentFromFront();
			//cout << "calculate size" << std::endl;
			// get desired element size from back-ground mesh
			base::CalcElementSize();
			//cout << "calculate opt point" << std::endl;
			// Calculate optimum coordinate of new point
			base::CalcOptimumCoord();
			//cout << "calculate local radius" << std::endl;
			base::CalcLocalFrontRadius();

			// Set depth of searching radius
			base::SetDepthSearching();

			/*if (this->NbElements() == 9)
			{
				fileName fname("temp.plt");
				OFstream file(fname);
				cout << this->LocFrontRadius() << std::endl;
				const auto mm = this->theSizeMap_->CalcEffectiveMetric(this->Coord(), this->CurrentFront()->Centre());
				const auto elm = this->theSizeMap_->CalcElementSize(this->CurrentFront()->Centre());
				const auto sr = this->LocFrontRadius();
				Entity2d_Eigen eigen;
				eigen.CalcEigen(mm*(1.0/ (sr*sr)));
				eigen.ExportToPlt(this->Coord(), file);
				cout << Entity2d_Metric1::Distance(this->Coord(), this->CurrentFront()->Centre(), mm) << std::endl;
				cout << this->theSizeMap_->CalcDistance(this->Coord(), this->CurrentFront()->Centre()) << std::endl;
				PAUSE;
				const auto box = this->theSizeMap_->CalcSearchRegion(this->LocFrontRadius(), this->Coord(), *this->CurrentFront());
				box.ExportToPlt(file);

			}*/

			base::RetrieveLocalFrontNodes(LocalNodes, CandidateNodes);

			base::RetrieveLocalFrontEntities(LocalNodes, Local);

			base::RetrieveEffectiveFronts(Local, Effectives);

			/*if (base::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
			{
				File << (int)Local.size() << ", " << (int)Effectives.size() << endl;

			}*/

			base::SortNodes(CandidateNodes);

			if (base::IsNewPointCandidate(Effectives))
			{
				base::AddOptimumNodeTo(CandidateNodes);
			}

			FindValidNode(CandidateNodes, Effectives);

			Update();
		}
	}

	template<class ModelType, class SizeFun, class MetricFun>
	void Aft_Model<ModelType, SizeFun, MetricFun>::FindValidNode
	(
		const std::vector<std::shared_ptr<nodeType>>& theCandidates,
		const std::vector<std::shared_ptr<frontType>>& theEffectives
	)
	{
		Debug_Null_Pointer(base::CurrentFront());

		const auto& current = *base::CurrentFront();
		const auto& newNode = base::TempoNode();

		const auto cLength = current.CharLength();
		const auto& sizeMap = *base::MetricMap();

		Debug_Null_Pointer(current.Node0());
		Debug_Null_Pointer(current.Node1());

		const auto& vrtx0 = *current.Node0();
		const auto& vrtx1 = *current.Node1();

		auto v0 = vrtx0.Index();
		auto v1 = vrtx1.Index();

		auto nodes =
			RetrieveNodesFrom(theEffectives);

		Standard_Integer flag = 0;

		for (const auto& x : theCandidates)
		{
			Debug_Null_Pointer(x);
			const auto& node = *x;

			const auto nodeIndex = node.Index();
			if ((nodeIndex IS_EQUAL v0) OR(nodeIndex IS_EQUAL v1))
			{
				continue;
			}

			// test 1: is it the new point on the left side of iEDG
			if (Processor::Oriented_cgal(node.Coord(), vrtx0.Coord(), vrtx1.Coord()) <= 0.0)
			{
				continue;
			}

			flag = 0;

			// test 2: intersection test
			for (const auto& eff_ptr : theEffectives)
			{
				Debug_Null_Pointer(eff_ptr);
				const auto& effective = *eff_ptr;

				const auto& n0 = *effective.Node0();
				const auto& n1 = *effective.Node1();

				if (NOT Processor::IsOneCommonPointTwoSegments(v0, nodeIndex, n0.Index(), n1.Index()))
				{
					if (Processor::HasIntersection_cgal(vrtx0.Coord(), node.Coord(), n0.Coord(), n1.Coord()))
					{
						flag = 1;
						break;
					}
				}

				if (NOT Processor::IsOneCommonPointTwoSegments(nodeIndex, v1, n0.Index(), n1.Index()))
				{
					if (Processor::HasIntersection_cgal(node.Coord(), vrtx1.Coord(), n0.Coord(), n1.Coord()))
					{
						flag = 1;
						break;
					}
				}
			}

			if (flag) continue;

			for (const auto& eff_node : nodes)
			{
				Debug_Null_Pointer(eff_node);
				const auto eff_index = eff_node->Index();

				if ((eff_index NOT_EQUAL nodeIndex) AND(eff_index NOT_EQUAL v0) AND(eff_index NOT_EQUAL v1))
				{
					if (Processor::IsPointInsideTriangle_cgal(eff_node->Coord(), vrtx0.Coord(), vrtx1.Coord(), node.Coord()))
					{
						flag = 2;
						break;
					}
				}
			}

			if (flag) continue;

			if ((x NOT_EQUAL newNode) AND CheckAngle(current, node, 0.998))
			{
				flag = 3;
				continue;
			}

			/*const auto l0 = sizeMap.CalcDistance(vrtx0.Coord(), node.Coord());
			const auto l1 = sizeMap.CalcDistance(vrtx1.Coord(), node.Coord());

			const auto angN0 = (l0*l0 + cLength * cLength - l1 * l1) / (2.0*l0*cLength);
			if (NOT INSIDE(angN0, -0.9986295, 0.9986295))
			{
				flag = 3;
				continue;
			}

			const auto angN1 = (l1*l1 + cLength * cLength - l0 * l0) / (2.0*l1*cLength);
			if (NOT INSIDE(angN1, -0.9986295, 0.9986295))
			{
				flag = 3;
				continue;
			}*/

			base::SetValidNode(x);
			return;
		}

		base::SetValidNode(nullptr);
	}

	template<class ModelType, class SizeFun, class MetricFun>
	void Aft_Model<ModelType, SizeFun, MetricFun>::Update()
	{
		if (base::ValidNode())
		{
			base::UpdateFront();

			InsertNewEdgesToLevels();
		}
		else
		{
			base::RejectCurrent(base::CurrentFront());
		}
	}

	template<class ModelType, class SizeFun, class MetricFun>
	void Aft_Model<ModelType, SizeFun, MetricFun>::InsertNewEdgesToLevels()
	{
		const auto& edge0 = base::CreatedEdge0();
		if (edge0)
		{
			const auto& n0 = edge0->Node0();
			const auto& n1 = edge0->Node1();

			n0->SetRadius(MAX(n0->Radius(), edge0->CharLength()));
			n1->SetRadius(MAX(n1->Radius(), edge0->CharLength()));

			if (base::IsOnLevel(*edge0))
			{
				base::InsertToCurrentFronts(edge0->Index(), edge0);
			}
			else
			{
				base::InsertToNextFronts(edge0->Index(), edge0);
			}
		}

		const auto& edge1 = base::CreatedEdge1();
		if (edge1)
		{
			const auto& n0 = edge1->Node0();
			const auto& n1 = edge1->Node1();

			n0->SetRadius(MAX(n0->Radius(), edge1->CharLength()));
			n1->SetRadius(MAX(n1->Radius(), edge1->CharLength()));

			if (base::IsOnLevel(*edge1))
			{
				base::InsertToCurrentFronts(edge1->Index(), edge1);
			}
			else
			{
				base::InsertToNextFronts(edge1->Index(), edge1);
			}
		}
	}

	template<class ModelType, class SizeFun, class MetricFun>
	void Aft_Model<ModelType, SizeFun, MetricFun>::Perform()
	{
		base::SetPriorityFunction(&frontType::Length);
		base::SetMinDistFactor(DEFAULT_MIN_DISTANCE_FACTOR);

		base::SetGeometryCoordFunc(&nodeType::GetCoord);

		ActiveFront(BoundaryEdges());

		Import(theBoundaryEdges_, BoundaryMap());

		Meshing();
	}

	template<class ModelType, class SizeFun, class MetricFun>
	void Aft_Model<ModelType, SizeFun, MetricFun>::CreateStaticMesh()
	{
		std::vector<std::shared_ptr<elementType>> elements;
		elements.reserve(this->NbElements());
		for (const auto& x : this->RetrieveElements())
		{
			elements.push_back(x.second);
		}

		CompactNumbering(elements);

		theTriangulation_ =
			std::make_shared<staticMesh>
			(
				RetrieveGeometryFrom
				(
					RetrieveNodesFrom(elements)
				), RetrieveGeometryFrom(elements, *cache::NodesIndices));
	}

	template<class ModelType, class SizeFun, class MetricFun>
	void Aft_Model<ModelType, SizeFun, MetricFun>::CompactNumbering
	(
		const std::vector<std::shared_ptr<elementType>>& theElements
	) const
	{
		auto nodes = RetrieveNodesFrom(theElements);
		auto edges = RetrieveEdgesFrom(theElements);

		cache::NodesIndices = std::make_shared<typename cache::indexMap>();
		auto& nodesIndices = *cache::NodesIndices;
		cache::nodeIndex = 0;

		cache::EdgesIndices = std::make_shared<typename cache::indexMap>();
		auto& edgesIndices = *cache::EdgesIndices;
		cache::edgeIndex = 0;

		cache::ElementsIndices = std::make_shared<typename cache::indexMap>();
		auto& elementsIndices = *cache::ElementsIndices;
		cache::elementIndex = 0;

		for (const auto& x : nodes)
		{
			nodesIndices.insert(std::make_pair(x->Index(), ++cache::nodeIndex));
		}

		for (const auto& x : edges)
		{
			edgesIndices.insert(std::make_pair(x->Index(), ++cache::edgeIndex));
		}

		for (const auto& x : theElements)
		{
			elementsIndices.insert(std::make_pair(x->Index(), ++cache::elementIndex));
		}
	}
}

template<class ModelType, class SizeFun, class MetricFun>
void AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::ActiveFront
(
	const std::vector<std::shared_ptr<frontType>>& theEdges
)
{
	for (const auto& x : theEdges)
	{
		Debug_Null_Pointer(x);
		const auto& n0 = x->Node0();
		const auto& n1 = x->Node1();

		n0->InsertToEdges(x->Index(), x);
		n1->InsertToEdges(x->Index(), x);

		n0->InsertToFrontEdges(x->Index(), x);
		n1->InsertToFrontEdges(x->Index(), x);
	}
}

template<class ModelType, class SizeFun, class MetricFun>
std::vector<std::shared_ptr<typename AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::nodeType>> 
AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::RetrieveNodesFrom
(
	const std::vector<std::shared_ptr<frontType>>& theFronts
)
{
	Adt_AvlTree<std::shared_ptr<nodeType>> compact;
	compact.SetComparableFunction(&nodeType::IsLess);

	for (const auto& x : theFronts)
	{
		Debug_Null_Pointer(x);
		const auto& edge = *x;

		compact.InsertIgnoreDup(edge.Node0());
		compact.InsertIgnoreDup(edge.Node1());
	}
	std::vector<std::shared_ptr<nodeType>> nodes;
	compact.RetrieveTo(nodes);

	return std::move(nodes);
}

template<class ModelType, class SizeFun, class MetricFun>
std::vector<std::shared_ptr<typename AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::nodeType>>
AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::RetrieveNodesFrom
(
	const std::vector<std::shared_ptr<elementType>>& theElements
)
{
	Adt_AvlTree<std::shared_ptr<nodeType>> compact;
	compact.SetComparableFunction(&nodeType::IsLess);

	for (const auto& x : theElements)
	{
		Debug_Null_Pointer(x);
		const auto& element = *x;

		compact.InsertIgnoreDup(element.Node0());
		compact.InsertIgnoreDup(element.Node1());
		compact.InsertIgnoreDup(element.Node2());
	}
	std::vector<std::shared_ptr<nodeType>> nodes;
	compact.RetrieveTo(nodes);

	return std::move(nodes);
}

template<class ModelType, class SizeFun, class MetricFun>
std::vector<std::shared_ptr<typename AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::frontType>> 
AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::RetrieveEdgesFrom
(
	const std::vector<std::shared_ptr<elementType>>& theElements
)
{
	Adt_AvlTree<std::shared_ptr<frontType>> compact;
	compact.SetComparableFunction(&frontType::IsLess);

	for (const auto& x : theElements)
	{
		Debug_Null_Pointer(x);
		const auto& element = *x;

		compact.InsertIgnoreDup(element.Edge0());
		compact.InsertIgnoreDup(element.Edge1());
		compact.InsertIgnoreDup(element.Edge2());
	}
	std::vector<std::shared_ptr<frontType>> edges;
	compact.RetrieveTo(edges);

	return std::move(edges);
}

template<class ModelType, class SizeFun, class MetricFun>
std::vector<AutLib::Pnt2d> 
AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::RetrieveGeometryFrom
(
	const std::vector<std::shared_ptr<nodeType>>& theNodes
)
{
	std::vector<Pnt2d> pts;
	pts.reserve(theNodes.size());

	for (const auto& x : theNodes)
	{
		Debug_Null_Pointer(x);
		pts.push_back(x->Coord());
	}
	return std::move(pts);
}

template<class ModelType, class SizeFun, class MetricFun>
std::vector<AutLib::connectivity::triple> 
AutLib::Aft_Model<ModelType, SizeFun, MetricFun>::RetrieveGeometryFrom
(
	const std::vector<std::shared_ptr<elementType>>& theElements,
	std::map<unsigned, unsigned>& theNodesIndices
)
{
	std::vector<connectivity::triple> triangles;
	triangles.reserve(theElements.size());

	for (const auto& x : theElements)
	{
		Debug_Null_Pointer(x);

		connectivity::triple connect;
		connect.Value(0) = (Standard_Integer)theNodesIndices[x->Node0()->Index()];
		connect.Value(1) = (Standard_Integer)theNodesIndices[x->Node1()->Index()];
		connect.Value(2) = (Standard_Integer)theNodesIndices[x->Node2()->Index()];

		triangles.push_back(std::move(connect));
	}
	return std::move(triangles);
}