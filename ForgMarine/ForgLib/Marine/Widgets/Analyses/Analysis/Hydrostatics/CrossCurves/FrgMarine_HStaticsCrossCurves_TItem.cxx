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

#include <TopoDS_Shape.hxx>
#include <Cad_Tools.hxx>
#include <Bnd_Box.hxx>
#include <HydroStatic_CrossCurves.hxx>
#include <Marine_Graph.hxx>
#include <Marine_GraphCurve.hxx>
#include <Pln_CurveTools.hxx>
#include <Geom2d_Curve.hxx>

ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::FrgMarine_HStaticsCrossCurves_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgMarine_AnalysisHStatics_TItem(itemTitle, parentItem, parentTree)
{
	auto marineTree = dynamic_cast<FrgMarine_Tree*>(parentTree);
	if (marineTree)
	{
		theShapeVrnt_ = new ForgBaseLib::FrgBase_PrptsVrntSelectTItems("Select Shape:", marineTree->GetGeometryTItem());
		thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntSelectTItems>(theShapeVrnt_);

		connect
		(
			theShapeVrnt_,
			SIGNAL(SelectedTItemsChangedSignal(std::vector<QTreeWidgetItem*>)),
			this,
			SLOT(ShapeVrntChangedSlot(std::vector<QTreeWidgetItem*>))
		);

		std::vector<QTreeWidgetItem*> geometry;
		geometry.push_back(dynamic_cast<FrgMarine_Tree*>(GetParentTree())->GetGeometryTItem()->GetParametricModelsTItem()->GetChild("Ship Type 01"));
		ShapeVrntChangedSlot(geometry);
	}

	theContextMenu_->addSeparator();
	auto performAction = theContextMenu_->AddItem(ICON_Menu_Solution_Run, "Perform", false);
	connect(performAction, SIGNAL(triggered()), this, SLOT(PerformCrossCurvesSlot()));
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

void ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::ShapeVrntChangedSlot(std::vector<QTreeWidgetItem*> items)
{
	if (items.size() == 0)
		return;
	for (int i = 0; i < items.size(); i++)
	{
		auto partTItem = dynamic_cast<FrgMarine_GeomPart_TItem*>(items[i]);
		auto parametricModel = dynamic_cast<FrgMarine_GeomPModel_TItem*>(items[i]);

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

		theCrossCurve_ = std::make_shared<tnbLib::HydroStatic_CrossCurves>(theDomainTItem_->GetDomain());
		theCrossCurve_->LoadModel(theModelTItem_->GetModel());
		theCrossCurve_->LoadHeel(theHeelTItem_->GetHeel());
	}
}

void ForgMarineLib::FrgMarine_HStaticsCrossCurves_TItem::PerformCrossCurvesSlot()
{
	theCrossCurve_->Perform();

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

			//tnbLib::Pln_CurveTools::ExportToPlt(x->Curve(), myFile);
		}
	}
}