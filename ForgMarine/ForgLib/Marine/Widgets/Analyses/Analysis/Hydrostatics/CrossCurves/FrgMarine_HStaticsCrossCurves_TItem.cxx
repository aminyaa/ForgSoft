#include <FrgMarine_HStaticsCrossCurves_TItem.hxx>
#include <FrgMarine_GeomPart_TItem.hxx>
#include <FrgMarine_GeomPModel_TItem.hxx>
#include <FrgMarine_Tree.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgMarine_Geometry_TItem.hxx>
#include <FrgMarine_GeomPModels_TItem.hxx>
#include <FrgMarine_CrossCurvesModel_TItem.hxx>
#include <FrgMarine_CrossCurvesDomain_TItem.hxx>
#include <FrgMarine_CrossCurvesHeel_TItem.hxx>
#include <FrgMarine_Plots_TItem.hxx>
#include <FrgMarine_Plot2D_TItem.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_Pnt.hxx>
#include <FrgVisual_Scene3D.hxx>
#include <FrgVisual_PolylineActor.hxx>
#include <FrgVisual_BoxActor.hxx>
#include <FrgMarine_GeomPModelShip_TItem.hxx>
#include <FrgMarine_HStaticsCrossCurvesPView_TItem.hxx>
#include <FrgBase_Global_Thread.hxx>

#include <TopoDS_Shape.hxx>
#include <Cad_Tools.hxx>
#include <Bnd_Box.hxx>
#include <HydroStatic_CrossCurves.hxx>
#include <Marine_Graph.hxx>
#include <Marine_GraphCurve.hxx>
#include <Pln_CurveTools.hxx>
#include <Geom2d_Curve.hxx>
#include <CrossSection_xShapeStation.hxx>
#include <Marine_CmpSection.hxx>
#include <OFstream.hxx>
#include <Marine_Section.hxx>
#include <Pln_Wire.hxx>
#include <Pln_CmpEdge.hxx>
#include <Pln_Edge.hxx>
#include <Entity2d_Polygon.hxx>
#include <Pnt2d.hxx>
#include <Marine_FlatWave.hxx>
#include <MarineBase_Tools.hxx>
#include <Marine_Body.hxx>

ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::FrgMarine_HStaticsCrossCurves_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgMarine_AnalysisHStatics_TItem(itemTitle, parentItem, parentTree)
{
	theShapeVrnt_ = new ForgBaseLib::FrgBase_PrptsVrntSelectTItem<ForgMarineLib::FrgMarine_GeomPModel_TItem>("Select Model:", nullptr);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntSelectTItem<ForgMarineLib::FrgMarine_GeomPModel_TItem>>(theShapeVrnt_);

	connect
	(
		theShapeVrnt_,
		SIGNAL(ValueChangedSignal(FrgBase_TreeItem*)),
		this,
		SLOT(ShapeVrntChangedSlot(FrgBase_TreeItem*))
	);

	/*auto marineTree = dynamic_cast<FrgMarine_Tree*>(parentTree);
	if (marineTree)
	{
		std::vector<QString> items;
		items.push_back("None");

		QTreeWidgetItemIterator it(GetParentTree());
		while (*it)
		{
			if (dynamic_cast<FrgMarine_GeomPModel_TItem*>(*it) || dynamic_cast<FrgMarine_GeomPart_TItem*>(*it))
			{
				QString title = (*it)->parent()->text(0) + ":" + (*it)->text(0);
				items.push_back(title);

				theMapFromNameToTItem_.insert(std::pair<QString, QTreeWidgetItem*>(title, (*it)));
			}

			++it;
		}

		theShapeVrnt_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Select Shape:", "None");
		thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntCombo>(theShapeVrnt_);

		connect
		(
			theShapeVrnt_,
			SIGNAL(ValueChangedSignal(const QString&)),
			this,
			SLOT(ShapeVrntChangedSlot(const QString&))
		);
	}*/
	
	theContextMenu_->addSeparator();
	auto performAction = theContextMenu_->AddItem(ICON_Menu_Solution_Run, "Perform", false);
	connect(performAction, SIGNAL(triggered()), this, SLOT(PerformCrossCurvesSlot()));
	performAction->setEnabled(false);
}

ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::~FrgMarine_HStaticsCrossCurves_TItem()
{
	FreePointer(theShape_);
	FreePointer(theShapeVrnt_);
	FreePointer(theModelTItem_);
	FreePointer(theDomainTItem_);
	FreePointer(theHeelTItem_);

	theBox_ = nullptr;
}

void ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::FormTItem()
{
	ForgMarineLib::FrgMarine_AnalysisHStatics_TItem::FormTItem();
}

void ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::ShapeVrntChangedSlot(FrgBase_TreeItem* tItem)
{
	if (!tItem)
	{
		FreePointer(theModelTItem_);
		FreePointer(theDomainTItem_);
		FreePointer(theHeelTItem_);
		FreePointer(theShape_);

		ClearSections();
		FreePointer(thePreviewTItem_);

		theBox_ = nullptr;
		return;
	}

	if (theShape_)
	{
		FreePointer(theModelTItem_);
		FreePointer(theDomainTItem_);
		FreePointer(theHeelTItem_);
		FreePointer(theShape_);

		ClearSections();
		FreePointer(thePreviewTItem_);

		theBox_ = nullptr;
	}

	auto partTItem = dynamic_cast<FrgMarine_GeomPart_TItem*>(tItem);
	auto parametricModel = dynamic_cast<FrgMarine_GeomPModel_TItem*>(tItem);

	if (partTItem)
		theShape_ = new TopoDS_Shape(partTItem->GetShape());
	else if (parametricModel)
		theShape_ = new TopoDS_Shape(parametricModel->GetShape());
	else
		return;

	auto b0 = tnbLib::Cad_Tools::BoundingBox(*theShape_);
	theBox_ = &(tnbLib::Cad_Tools::BoundingBox(b0));

	theModelTItem_ = new FrgMarine_CrossCurvesModel_TItem("Model", this, GetParentTree(), theShape_, theBox_);
	theDomainTItem_ = new FrgMarine_CrossCurvesDomain_TItem("Domain", this, GetParentTree(), theBox_);
	theHeelTItem_ = new FrgMarine_CrossCurvesHeel_TItem("Heel", this, GetParentTree());
	thePreviewTItem_ = new FrgMarine_HStaticsCrossCurvesPView_TItem("Preview", this, GetParentTree());
	thePreviewTItem_->FormTItem();

	theCrossCurve_ = std::make_shared<tnbLib::HydroStatic_CrossCurves>(theDomainTItem_->GetDomain());
	theCrossCurve_->LoadModel(theModelTItem_->GetModel());
	theCrossCurve_->LoadHeel(theHeelTItem_->GetHeel());

	auto wave = std::make_shared<tnbLib::Marine_FlatWave>(*theBox_);
	wave->SetCurrent(tnbLib::Vec3d(-1.0, -0.0, 0));
	wave->SetVerticalDirection(tnbLib::Dir3d(.0, 0, 1));
	wave->SetPointOnWater(tnbLib::Pnt3d(75, 0, 8.0));

	ExecuteFunctionInProcess(GetParentMainWindow(), wave->Perform(), nullptr, nullptr);

	auto waters = tnbLib::MarineBase_Tools::WaterSections(*theModelTItem_->GetModel(), *wave, *theBox_, 1.0E-3, 1.0E-6);
	auto wetted = tnbLib::MarineBase_Tools::WettedSections(theModelTItem_->GetModel()->Sections(), waters);
	auto driedSections = tnbLib::MarineBase_Tools::DrySections(theModelTItem_->GetModel()->Sections(), waters);
	auto wettedSections = wetted->Sections();

	DrawSections(driedSections, 1.0, 0.0, 0.0);
	DrawSections(wettedSections, 0.0, 0.0, 1.0);

	DrawBox(theBox_, 1.0, 0.0, 0.0);

	theContextMenu_->GetItem("Perform")->setEnabled(true);
}

void ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::PerformCrossCurvesSlot()
{
	theContextMenu_->GetItem("Perform")->setEnabled(false);

	ExecuteFunctionInProcess(GetParentMainWindow(), theCrossCurve_->Perform(), nullptr, nullptr);

	auto marineTree = dynamic_cast<FrgMarine_Tree*>(GetParentTree());
	if (marineTree)
	{
		auto plotsTItem = marineTree->GetPlotsTItem();
		auto plot2DTItem = plotsTItem->AddPlot2D();

		int n = 40;
		const auto& curves = theCrossCurve_->Graph()->Curves();
		int i = 1;
		for (const auto& x : curves)
		{
			const auto du = (x->Curve()->LastParameter() - x->Curve()->FirstParameter()) / (Standard_Real)n;
			const auto u0 = x->Curve()->FirstParameter();
			std::vector<double> ptsX;
			std::vector<double> ptsY;
			ptsX.reserve(n + 1);
			ptsY.reserve(n + 1);

			for (auto i = 0; i <= n; i++)
			{
				auto ptX = x->Curve()->Value(u0 + i * du).X();
				auto ptY = x->Curve()->Value(u0 + i * du).Y();
				ptsX.push_back(std::move(ptX));
				ptsY.push_back(std::move(ptY));
			}

			plot2DTItem->AddPlot(ptsX, ptsY, QString("Curve " + QString::number(i)).toStdString().c_str());
			i++;
		}
	}

	theContextMenu_->GetItem("Perform")->setEnabled(true);
}

void ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::DrawSections
(
	std::vector<std::shared_ptr<tnbLib::Marine_CmpSection>> sections,
	double red,
	double green,
	double blue
)
{
	for (int iSection = 0; iSection < sections.size(); iSection++)
	{
		auto innerSections = sections[iSection]->Sections();

		for (int iInnerSection = 0; iInnerSection < innerSections.size(); iInnerSection++)

		{
			auto cmpEdge = innerSections[iInnerSection]->Wire()->CmpEdge();
			auto edges = cmpEdge->Edges();

			for (int iEdge = 0; iEdge < edges.size(); iEdge++)
			{
				auto mesh = edges[iEdge]->Mesh();
				auto tnbPoints = mesh->Points();

				std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>>> myPoints;
				for (int iPoint = 0; iPoint < tnbPoints.size(); iPoint++)
				{
					auto pt = tnbPoints[iPoint];
					myPoints.push_back(std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(theModelTItem_->GetModel()->Sections()[iSection]->X(), pt.X(), pt.Y()));
				}

				if (thePreviewTItem_)
				{
					auto scene3D = dynamic_cast<ForgVisualLib::FrgVisual_Scene3D*>(thePreviewTItem_->GetScene());

					if (scene3D)
					{
						auto polyLineActor = scene3D->AddPolyline(myPoints, false);

						polyLineActor->GetProperty()->SetColor(red, green, blue);
					}
				}
			}
		}
	}
	auto scene3D = dynamic_cast<ForgVisualLib::FrgVisual_Scene3D*>(thePreviewTItem_->GetScene());

	if (scene3D)
		scene3D->RenderScene(true);
}

void ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::DrawBox(tnbLib::Entity3d_Box * box, double red, double green, double blue)
{
	if (thePreviewTItem_)
	{
		auto scene3D = dynamic_cast<ForgVisualLib::FrgVisual_Scene3D*>(thePreviewTItem_->GetScene());

		if (scene3D)
		{
			tnbLib::Pnt3d P0, P1;
			box->Get(P0, P1);
			auto cubeActor = scene3D->AddBox(P0.X(), P0.Y(), P0.Z(), P1.X(), P1.Y(), P1.Z(), false);
			cubeActor->SetRepresentationToWireframe();
			cubeActor->SetEdgeColor(red, green, blue);

			scene3D->RenderScene(true);
		}
	}
}

void ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::ClearSections()
{
	if (!thePreviewTItem_)
		return;

	auto scene3D = dynamic_cast<ForgVisualLib::FrgVisual_Scene3D*>(thePreviewTItem_->GetScene());

	if (scene3D)
	{
		scene3D->ClearAllPolylines();
	}
}