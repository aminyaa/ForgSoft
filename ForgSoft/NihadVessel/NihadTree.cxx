#include <NihadTree.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseMenu.hxx>
#include <FrgBaseTreeItemProperties.hxx>
#include <FrgBasePlot2D.hxx>
#include <FrgBaseTabWidget.hxx>
#include <FrgBaseCADPartFeatures.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseCADScene.hxx>
#include <FrgMenu_Models.hxx>
#include <CADPartItem.hxx>
#include <ViewPorts.hxx>
#include <qtpropertybrowser.h>

#include <NihadMainWindow.hxx>
#include <NihadVesselGeometryTreeItem.hxx>
#include <NihadVesselPartTreeItem.hxx>
#include <NihadVesselScenePartTreeItem.hxx>
#include <NihadVesselScenePreviewTreeItem.hxx>

#include <Pnt2d.hxx>
#include <Entity2d_Box.hxx>
#include <FastDiscrete_Params.hxx>
#include <Leg_Vessel_Nihad2.hxx>
#include <Leg_Model_PropNo1.hxx>
#include <Leg_PropNo1_Parameters.hxx>
#include <Leg_Model_DuctNo1.hxx>
#include <Leg_DuctNo1_Parameters.hxx>
#include <Cad_Tools.hxx>
#include <IO_IGES.hxx>
#include <TModel_Tools.hxx>
#include <Cad3d_TModel.hxx>
#include <Cad_Tools.hxx>
#include <Cad_BlockEntity.hxx>
#include <TModel_Surface.hxx>
#include <TModel_Paired.hxx>

#include <QtWidgets/QAction>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>

#include <vtkActor.h>
#include <FrgBaseInteractorStyle.hxx>
#include <FrgBaseCADPartFeatures.hxx>

#include <FrgBaseGlobalsThread.hxx>

#define NbNetColumnsID 222
#define NbNetRowsID 223
#define PartsListID 1285

#define NbSegments_U 35
#define NbSegments_V 35

#define NihadName FrgString("Ship")
#define PropellerName FrgString("Propeller")

#define PropellerNbBladesID 1222
#define PropellerNbNSectionsID 1223
#define PropellerNbSpansID 1224
#define PropellerRemoveHubApex 1225

#define DuctName FrgString("Duct")

#define DuctNBSectionsID 2222

ForgBaseLib::NihadTree::NihadTree(FrgBaseMainWindow* parent)
	: FrgBaseTree(parent)
{
	connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(itemDoubleClickedSlot(QTreeWidgetItem*, int)));
}

void ForgBaseLib::NihadTree::FormTree()
{
	FrgString GeometryItem = "Geometry";
	FrgString AnalysisItem = "Analysis";
	FrgString PartsItem = "Parts";
	FrgString ScenesItem = "Scenes";
	FrgString PlotsItem = "Plots";

	FrgNew FrgBaseTreeItem(GeometryItem, FrgNullPtr, this, GetParentMainWindow());

	FrgNew FrgBaseTreeItem(AnalysisItem, FrgNullPtr, this, GetParentMainWindow());

	FrgNew FrgBaseTreeItem(PartsItem, FrgNullPtr, this, GetParentMainWindow());

	FrgNew FrgBaseTreeItem(ScenesItem, FrgNullPtr, this, GetParentMainWindow());

	FrgNew FrgBaseTreeItem(PlotsItem, FrgNullPtr, this, GetParentMainWindow());

	FrgString GeometryNewMenu = "New " + NihadName;
	GetTreeItem(GeometryItem)->GetContextMenu()->AddItem(GeometryNewMenu);
	connect(GetTreeItem(GeometryItem)->GetContextMenu()->GetItem(GeometryNewMenu), SIGNAL(triggered(bool)), this, SLOT(NewGeometryShipClickedSlot(bool)));
	connect(GetParentMainWindow()->GetModelsMenu()->GetItem("New Ship"), SIGNAL(triggered(bool)), this, SLOT(NewGeometryShipClickedSlot(bool)));

	GeometryNewMenu = "New " + PropellerName;
	GetTreeItem(GeometryItem)->GetContextMenu()->AddItem(GeometryNewMenu);
	connect(GetTreeItem(GeometryItem)->GetContextMenu()->GetItem(GeometryNewMenu), SIGNAL(triggered(bool)), this, SLOT(NewGeometryPropellerClickedSlot(bool)));
	connect(GetParentMainWindow()->GetModelsMenu()->GetItem("New Propeller"), SIGNAL(triggered(bool)), this, SLOT(NewGeometryPropellerClickedSlot(bool)));

	GeometryNewMenu = "New " + DuctName;
	GetTreeItem(GeometryItem)->GetContextMenu()->AddItem(GeometryNewMenu);
	connect(GetTreeItem(GeometryItem)->GetContextMenu()->GetItem(GeometryNewMenu), SIGNAL(triggered(bool)), this, SLOT(NewGeometryDuctClickedSlot(bool)));
	connect(GetParentMainWindow()->GetModelsMenu()->GetItem("New Duct"), SIGNAL(triggered(bool)), this, SLOT(NewGeometryDuctClickedSlot(bool)));

	FrgString ScenesNewMenu = "&New Scene";
	GetTreeItem(ScenesItem)->GetContextMenu()->AddItem(ScenesNewMenu);
	connect(GetTreeItem(ScenesItem)->GetContextMenu()->GetItem(ScenesNewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(NewSceneClickedSlot(bool)));

	FrgString AnalysisNewMenu = "&New Analyze";
	GetTreeItem(AnalysisItem)->GetContextMenu()->AddItem(AnalysisNewMenu);
	connect(GetTreeItem(AnalysisItem)->GetContextMenu()->GetItem(AnalysisNewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(NewAnalysisClickedSlot(bool)));

	FrgString PlotsNewMenu = "&New Plot";
	GetTreeItem(PlotsItem)->GetContextMenu()->AddItem(PlotsNewMenu);
	connect(GetTreeItem(PlotsItem)->GetContextMenu()->GetItem(PlotsNewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(NewPlotClickedSlot(bool)));

	connect(GetParentMainWindow()->GetTabWidget(), SIGNAL(tabBarClicked(int)), this, SLOT(TabBarClickedSlot(int)));

	connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(TreeItemDoubleClickedSlot(QTreeWidgetItem*, int)));
}

void ForgBaseLib::NihadTree::itemClickedSlot(QTreeWidgetItem* item, int column)
{
	FrgBaseTree::itemClickedSlot(item, column);
	auto& SelectedItems = this->selectedItems();
	for (int iItem = 0; iItem < SelectedItems.size(); iItem++)
	{
		auto feature = dynamic_cast<FrgBaseCADPartFeatureBase*>(SelectedItems[iItem]);

		if (feature)
		{
			auto scenes = feature->GetPointerToScenes();
			if (!scenes.isEmpty())
			{
				for (int iScene = 0; iScene < scenes.size(); iScene++)
				{
					auto actor = (scenes.at(iScene))->GetPartFeatureToActor().value(feature);
					if (SelectedItems.size() > 1)
						scenes.at(iScene)->GetInteractorStyle()->SelectActor(actor.Get(), 1, FrgTrue);
					else
						scenes.at(iScene)->GetInteractorStyle()->SelectActor(actor.Get(), 0, FrgTrue);
				}
			}
		}
	}
}

void ForgBaseLib::NihadTree::NewGeometryShipClickedSlot(bool)
{
	theGeometryTreeItems_.push_back(FrgNew NihadVesselGeometryTreeItem(CorrectName<FrgBaseTreeItem>(GetTreeItem("Geometry"), NihadName), GetTreeItem("Geometry")));

	theGeometryTreeItems_.at(theGeometryTreeItems_.size() - 1)->GetEntity() = FrgMakeSharedPtr(AutLib::Leg_Nihad2_BareHull)();

	FrgBaseTreeItem* NihadGeometryTreeItem = theGeometryTreeItems_.at(theGeometryTreeItems_.size() - 1);
	FrgSharedPtr<AutLib::Leg_Nihad2_BareHull> patch = std::dynamic_pointer_cast<AutLib::Leg_Nihad2_BareHull>(theGeometryTreeItems_.at(theGeometryTreeItems_.size() - 1)->GetEntity());

	patch->FwdSection().Tightness0()->SetValue(0.9);
	patch->FwdSection().Tightness1()->SetValue(0.9);

	patch->AftSection().Trim0()->SetValue(0.1);
	patch->AftSection().Trim1()->SetValue(0.1);
	patch->MidSection().Trim0()->SetValue(0.1);
	patch->MidSection().Trim1()->SetValue(0.1);
	patch->FwdSection().Trim0()->SetValue(0.1);
	patch->FwdSection().Trim1()->SetValue(0.1);

	auto NihadProperties = NihadGeometryTreeItem->GetProperties();

	NihadProperties->AddTopProperty("Dimensions");
	NihadProperties->AddProperty<double>("Dimensions", "Length on deck", patch->Dimensions().LengthOnDeck()->Value(), FrgString::number(patch->Dimensions().LengthOnDeck()->Index()), 1.0, 500.0, 1.0);
	NihadProperties->AddProperty<double>("Dimensions", "Beam on deck", patch->Dimensions().BeamOnDeck()->Value(), FrgString::number(patch->Dimensions().BeamOnDeck()->Index()), 1.0, 500.0, 0.15);
	NihadProperties->AddProperty<double>("Dimensions", "Depth at bow", patch->Dimensions().DepthAtBow()->Value(), FrgString::number(patch->Dimensions().DepthAtBow()->Index()), 1.0, 500.0, 0.15);
	NihadProperties->AddProperty<double>("Dimensions", "Depth at transom", patch->Dimensions().DepthAtTransom()->Value(), FrgString::number(patch->Dimensions().DepthAtTransom()->Index()), 1.0, 500.0, 0.15);
	NihadProperties->AddProperty<double>("Dimensions", "Transom height", patch->Dimensions().TransomHeight()->Value(), FrgString::number(patch->Dimensions().TransomHeight()->Index()), 0.0, 500.0, 0.15);
	NihadProperties->AddProperty<int>("Dimensions", "Number of sections", patch->Dimensions().NbNetColumns(), FrgString::number(NbNetColumnsID), 5, 90);
	NihadProperties->AddProperty<int>("Dimensions", "Number of rows", patch->Dimensions().NbNetRows(), FrgString::number(NbNetRowsID), 5, 90);
	NihadProperties->GetProperty("Number of rows")->setEnabled(FrgFalse);

	NihadProperties->AddTopProperty("Hull Parameters");
	NihadProperties->AddProperty<double>("Hull Parameters", "Max area location", patch->MaxAreaLocation()->Value(), FrgString::number(patch->MaxAreaLocation()->Index()));
	NihadProperties->AddProperty<double>("Hull Parameters", "Aft fullness", patch->AftFullness()->Value(), FrgString::number(patch->AftFullness()->Index()));
	NihadProperties->AddProperty<double>("Hull Parameters", "Fwd fullness", patch->FwdFullness()->Value(), FrgString::number(patch->FwdFullness()->Index()));

	NihadProperties->AddTopProperty("Aft Parameters", "Hull Parameters");
	NihadProperties->AddProperty<double>("Aft Parameters", "Deadrise", patch->AftSection().Deadrise()->Value(), FrgString::number(patch->AftSection().Deadrise()->Index()));
	NihadProperties->AddProperty<double>("Aft Parameters", "Side slope", patch->AftSection().SideSlope()->Value(), FrgString::number(patch->AftSection().SideSlope()->Index()));
	NihadProperties->AddProperty<double>("Aft Parameters", "Trim 0", patch->AftSection().Trim0()->Value(), FrgString::number(patch->AftSection().Trim0()->Index()));
	NihadProperties->AddProperty<double>("Aft Parameters", "Trim 1", patch->AftSection().Trim1()->Value(), FrgString::number(patch->AftSection().Trim1()->Index()));
	NihadProperties->AddProperty<double>("Aft Parameters", "Tightness0", patch->AftSection().Tightness0()->Value(), FrgString::number(patch->AftSection().Tightness0()->Index()));
	NihadProperties->AddProperty<double>("Aft Parameters", "Tightness1", patch->AftSection().Tightness1()->Value(), FrgString::number(patch->AftSection().Tightness1()->Index()));

	NihadProperties->AddTopProperty("Mid Parameters", "Hull Parameters");
	NihadProperties->AddProperty<double>("Mid Parameters", "Deadrise", patch->MidSection().Deadrise()->Value(), FrgString::number(patch->MidSection().Deadrise()->Index()));
	NihadProperties->AddProperty<double>("Mid Parameters", "Side slope", patch->MidSection().SideSlope()->Value(), FrgString::number(patch->MidSection().SideSlope()->Index()));
	NihadProperties->AddProperty<double>("Mid Parameters", "Trim 0", patch->MidSection().Trim0()->Value(), FrgString::number(patch->MidSection().Trim0()->Index()));
	NihadProperties->AddProperty<double>("Mid Parameters", "Trim 1", patch->MidSection().Trim1()->Value(), FrgString::number(patch->MidSection().Trim1()->Index()));
	NihadProperties->AddProperty<double>("Mid Parameters", "Tightness0", patch->MidSection().Tightness0()->Value(), FrgString::number(patch->MidSection().Tightness0()->Index()));
	NihadProperties->AddProperty<double>("Mid Parameters", "Tightness1", patch->MidSection().Tightness1()->Value(), FrgString::number(patch->MidSection().Tightness1()->Index()));

	NihadProperties->AddTopProperty("Fwd Parameters", "Hull Parameters");
	NihadProperties->AddProperty<double>("Fwd Parameters", "Deadrise", patch->FwdSection().Deadrise()->Value(), FrgString::number(patch->FwdSection().Deadrise()->Index()));
	NihadProperties->AddProperty<double>("Fwd Parameters", "Side slope", patch->FwdSection().SideSlope()->Value(), FrgString::number(patch->FwdSection().SideSlope()->Index()));
	NihadProperties->AddProperty<double>("Fwd Parameters", "Trim 0", patch->FwdSection().Trim0()->Value(), FrgString::number(patch->FwdSection().Trim0()->Index()));
	NihadProperties->AddProperty<double>("Fwd Parameters", "Trim 1", patch->FwdSection().Trim1()->Value(), FrgString::number(patch->FwdSection().Trim1()->Index()));
	NihadProperties->AddProperty<double>("Fwd Parameters", "Tightness0", patch->FwdSection().Tightness0()->Value(), FrgString::number(patch->FwdSection().Tightness0()->Index()));
	NihadProperties->AddProperty<double>("Fwd Parameters", "Tightness1", patch->FwdSection().Tightness1()->Value(), FrgString::number(patch->FwdSection().Tightness1()->Index()));

	NihadProperties->AddTopProperty("Keel Parameters");
	NihadProperties->AddProperty<double>("Keel Parameters", "Position", patch->Position()->Value(), FrgString::number(patch->Position()->Index()));
	NihadProperties->AddProperty<double>("Keel Parameters", "Rise point", patch->RisePoint()->Value(), FrgString::number(patch->RisePoint()->Index()));
	NihadProperties->AddProperty<double>("Keel Parameters", "Rise slope", patch->RiseSlope()->Value(), FrgString::number(patch->RiseSlope()->Index()));
	NihadProperties->AddProperty<double>("Keel Parameters", "Transom slope", patch->TransomSlope()->Value(), FrgString::number(patch->TransomSlope()->Index()));

	NihadProperties->AddTopProperty("Transom Parameters");
	NihadProperties->AddProperty<double>("Transom Parameters", "Rake", patch->Rake()->Value(), FrgString::number(patch->Rake()->Index()), -30.0, 30.0, 1.0);
	NihadProperties->AddProperty<double>("Transom Parameters", "Width", patch->Width()->Value(), FrgString::number(patch->Width()->Index()));

	NihadProperties->AddTopProperty("Stem Parameters");
	NihadProperties->AddProperty<double>("Stem Parameters", "Bow rounding", patch->BowRounding()->Value(), FrgString::number(patch->BowRounding()->Index()));
	NihadProperties->AddProperty<double>("Stem Parameters", "Stem rake", patch->StemRake()->Value(), FrgString::number(patch->StemRake()->Index()), -45.0, 45.0, 1.0);
	NihadProperties->AddProperty<double>("Stem Parameters", "Fore foot shape", patch->ForeFootShape()->Value(), FrgString::number(patch->ForeFootShape()->Index()));


	NihadProperties->SetExpanded("Aft Parameters", FrgFalse);
	NihadProperties->SetExpanded("Fwd Parameters", FrgFalse);
	NihadProperties->SetExpanded("Mid Parameters", FrgFalse);
	NihadProperties->SetExpanded("Keel Parameters", FrgFalse);
	NihadProperties->SetExpanded("Transom Parameters", FrgFalse);
	NihadProperties->SetExpanded("Stem Parameters", FrgFalse);

	connect
	(
		NihadGeometryTreeItem->GetProperties()->GetPropertyManager()
		, SIGNAL(valueChanged(QtProperty*, const QVariant&))
		, this
		, SLOT(GeometryPropertyValueChangedSlot(QtProperty*, const QVariant&))
	);

	FrgString CreatePartFromGeometryMenu = "&Create Part from Geometry";
	GetTreeItem(NihadGeometryTreeItem->text(0))->GetContextMenu()->AddItem(CreatePartFromGeometryMenu);
	connect
	(
		GetTreeItem(NihadGeometryTreeItem->text(0))->GetContextMenu()->GetItem(CreatePartFromGeometryMenu.remove('&'))
		, SIGNAL(triggered(bool))
		, this
		, SLOT(CreatePartFromGeometryClickedSlot(bool))
	);

	GetParentMainWindow()->ParseInfoToConsole("\"" + NihadGeometryTreeItem->text(0) + "\" geometry successfully created.");

	FrgString GeometryPreviewMenu = "&Preview";
	GetTreeItem(NihadGeometryTreeItem->text(0))->GetContextMenu()->AddItem(GeometryPreviewMenu);
	connect(GetTreeItem(NihadGeometryTreeItem->text(0))->GetContextMenu()->GetItem(GeometryPreviewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(PreviewGeometryClickedSlot(bool)));

	ScrollToItem(NihadGeometryTreeItem);
}

void ForgBaseLib::NihadTree::NewGeometryPropellerClickedSlot(bool b)
{
	theGeometryTreeItems_.push_back(FrgNew NihadVesselGeometryTreeItem(CorrectName<FrgBaseTreeItem>(GetTreeItem("Geometry"), "Propeller"), GetTreeItem("Geometry")));

	theGeometryTreeItems_.at(theGeometryTreeItems_.size() - 1)->GetEntity() = FrgMakeSharedPtr(AutLib::Leg_Model_PropNo1)();

	FrgBaseTreeItem* PropellerGeometryTreeItem = theGeometryTreeItems_.at(theGeometryTreeItems_.size() - 1);
	FrgSharedPtr<AutLib::Leg_Model_PropNo1> patch = std::dynamic_pointer_cast<AutLib::Leg_Model_PropNo1>(theGeometryTreeItems_.at(theGeometryTreeItems_.size() - 1)->GetEntity());

	auto PropellerProperties = PropellerGeometryTreeItem->GetProperties();

	PropellerProperties->AddTopProperty("Main Parameters");
	PropellerProperties->AddProperty<int>("Main Parameters", "Number of blades", patch->Parameters()->NbBlades(), FrgString::number(PropellerNbBladesID), 3, 7);
	PropellerProperties->AddProperty<int>("Main Parameters", "Number of sections", patch->Parameters()->NbSections(), FrgString::number(PropellerNbNSectionsID), 5, 35);
	PropellerProperties->AddProperty<int>("Main Parameters", "Number of spans", patch->Parameters()->NbSpans(), FrgString::number(PropellerNbSpansID), 5, 35);
	PropellerProperties->AddProperty<double>("Main Parameters", "Diameter", patch->Parameters()->Diameter()->Value(), FrgString::number(patch->Parameters()->Diameter()->Index()), 0.1, 25.0, 0.05);
	PropellerProperties->AddProperty<double>("Main Parameters", "Hub radius", patch->Parameters()->HubRadius()->Value(), FrgString::number(patch->Parameters()->HubRadius()->Index()), 0.1, 25.0, 0.05);
	PropellerProperties->AddProperty<bool>("Main Parameters", "Remove hub apex?", patch->Parameters()->RemoveHubApex(), FrgString::number(PropellerRemoveHubApex));

	PropellerProperties->AddTopProperty("Blade Parameters");
	PropellerProperties->AddTopProperty("Pitch form", "Blade Parameters");
	PropellerProperties->AddProperty<double>("Pitch form", "Root pitch", patch->Parameters()->Blade().Pitch().RootPitch()->Value(), FrgString::number(patch->Parameters()->Blade().Pitch().RootPitch()->Index()), 0.0, 90.0, 1.0);
	PropellerProperties->AddProperty<double>("Pitch form", "Root steep", patch->Parameters()->Blade().Pitch().RootSteep()->Value(), FrgString::number(patch->Parameters()->Blade().Pitch().RootSteep()->Index()));
	PropellerProperties->AddProperty<double>("Pitch form", "Tip pitch", patch->Parameters()->Blade().Pitch().TipPitch()->Value(), FrgString::number(patch->Parameters()->Blade().Pitch().TipPitch()->Index()), 0.0, 90.0, 1.0);
	PropellerProperties->AddProperty<double>("Pitch form", "Tip steep", patch->Parameters()->Blade().Pitch().TipSteep()->Value(), FrgString::number(patch->Parameters()->Blade().Pitch().TipSteep()->Index()));

	PropellerProperties->AddTopProperty("Chord form", "Blade Parameters");
	PropellerProperties->AddProperty<double>("Chord form", "Root chord", patch->Parameters()->Blade().Chord().RootChord()->Value(), FrgString::number(patch->Parameters()->Blade().Chord().RootChord()->Index()), 0.1, 100.0, 0.05);
	PropellerProperties->AddProperty<double>("Chord form", "Tip chord", patch->Parameters()->Blade().Chord().TipChord()->Value(), FrgString::number(patch->Parameters()->Blade().Chord().TipChord()->Index()), 0.0, 100.0, 0.05);
	PropellerProperties->AddProperty<double>("Chord form", "Maximum chord", patch->Parameters()->Blade().Chord().MaxChord()->Value(), FrgString::number(patch->Parameters()->Blade().Chord().MaxChord()->Index()), 0.0, 100.0, 0.05);
	PropellerProperties->AddProperty<double>("Chord form", "Maximum chord location", patch->Parameters()->Blade().Chord().MaxChordLocation()->Value(), FrgString::number(patch->Parameters()->Blade().Chord().MaxChordLocation()->Index()));
	PropellerProperties->AddProperty<double>("Chord form", "Root weight", patch->Parameters()->Blade().Chord().RootWeight()->Value(), FrgString::number(patch->Parameters()->Blade().Chord().RootWeight()->Index()));
	PropellerProperties->AddProperty<double>("Chord form", "Tip weight", patch->Parameters()->Blade().Chord().TipWeight()->Value(), FrgString::number(patch->Parameters()->Blade().Chord().TipWeight()->Index()));

	PropellerProperties->AddTopProperty("Camber form", "Blade Parameters");
	PropellerProperties->AddProperty<double>("Camber form", "Root camber", patch->Parameters()->Blade().Camber().RootCamber()->Value(), FrgString::number(patch->Parameters()->Blade().Camber().RootCamber()->Index()), 0.0, 0.1, 0.005);
	PropellerProperties->AddProperty<double>("Camber form", "Tip camber", patch->Parameters()->Blade().Camber().TipCamber()->Value(), FrgString::number(patch->Parameters()->Blade().Camber().TipCamber()->Index()), 0.0, 0.1, 0.005);
	PropellerProperties->AddProperty<double>("Camber form", "Max camber", patch->Parameters()->Blade().Camber().MaxCamber()->Value(), FrgString::number(patch->Parameters()->Blade().Camber().MaxCamber()->Index()), 0.0, 0.1, 0.005);
	PropellerProperties->AddProperty<double>("Camber form", "Max camber location", patch->Parameters()->Blade().Camber().MaxCamberLocation()->Value(), FrgString::number(patch->Parameters()->Blade().Camber().MaxCamberLocation()->Index()));
	PropellerProperties->AddProperty<double>("Camber form", "Root weight", patch->Parameters()->Blade().Camber().RootWeight()->Value(), FrgString::number(patch->Parameters()->Blade().Camber().RootWeight()->Index()));
	PropellerProperties->AddProperty<double>("Camber form", "Tip weight", patch->Parameters()->Blade().Camber().TipWeight()->Value(), FrgString::number(patch->Parameters()->Blade().Camber().TipWeight()->Index()));

	PropellerProperties->AddTopProperty("Skew form", "Blade Parameters");
	PropellerProperties->AddProperty<double>("Skew form", "Tip skew", patch->Parameters()->Blade().Skew().TipSkew()->Value(), FrgString::number(patch->Parameters()->Blade().Skew().TipSkew()->Index()), 0.0, 100.0, 1.0);
	PropellerProperties->AddProperty<double>("Skew form", "Tip steep", patch->Parameters()->Blade().Skew().TipSteep()->Value(), FrgString::number(patch->Parameters()->Blade().Skew().TipSteep()->Index()));
	PropellerProperties->AddProperty<double>("Skew form", "Root steep", patch->Parameters()->Blade().Skew().RootSteep()->Value(), FrgString::number(patch->Parameters()->Blade().Skew().RootSteep()->Index()));

	PropellerProperties->AddTopProperty("Thickness form", "Blade Parameters");
	PropellerProperties->AddProperty<double>("Thickness form", "Root thickness", patch->Parameters()->Blade().Thickness().RootThickness()->Value(), FrgString::number(patch->Parameters()->Blade().Thickness().RootThickness()->Index()), 0.0, 10.0, 0.05);
	PropellerProperties->AddProperty<double>("Thickness form", "Tip thickness", patch->Parameters()->Blade().Thickness().TipThickness()->Value(), FrgString::number(patch->Parameters()->Blade().Thickness().TipThickness()->Index()), 0.0, 10.0, 0.05);
	PropellerProperties->AddProperty<double>("Thickness form", "Root steep", patch->Parameters()->Blade().Thickness().RootSteep()->Value(), FrgString::number(patch->Parameters()->Blade().Thickness().RootSteep()->Index()));
	PropellerProperties->AddProperty<double>("Thickness form", "Tip steep", patch->Parameters()->Blade().Thickness().TipSteep()->Value(), FrgString::number(patch->Parameters()->Blade().Thickness().TipSteep()->Index()));

	PropellerProperties->AddTopProperty("Rake form", "Blade Parameters");
	PropellerProperties->AddProperty<double>("Rake form", "Tip rake", patch->Parameters()->Blade().Rake().TipRake()->Value(), FrgString::number(patch->Parameters()->Blade().Rake().TipRake()->Index()), 0.0, 30.0, 1.0);

	PropellerProperties->AddTopProperty("Hub Parameters");
	PropellerProperties->AddProperty<double>("Hub Parameters", "Hub length", patch->Parameters()->Hub().HubLength()->Value(), FrgString::number(patch->Parameters()->Hub().HubLength()->Index()), 0.0, 200.0, 0.1);
	PropellerProperties->AddProperty<double>("Hub Parameters", "Hub weight", patch->Parameters()->Hub().HubWeight()->Value(), FrgString::number(patch->Parameters()->Hub().HubWeight()->Index()));
	PropellerProperties->AddProperty<double>("Hub Parameters", "Shaft radius", patch->Parameters()->Hub().ShaftRadius()->Value(), FrgString::number(patch->Parameters()->Hub().ShaftRadius()->Index()), 0.0, 20.0, 0.05);
	PropellerProperties->AddProperty<double>("Hub Parameters", "Shaft offset", patch->Parameters()->Hub().ShaftOffset()->Value(), FrgString::number(patch->Parameters()->Hub().ShaftOffset()->Index()), 0.0, 20.0, 0.05);
	PropellerProperties->AddProperty<double>("Hub Parameters", "Shaft length", patch->Parameters()->Hub().ShaftLength()->Value(), FrgString::number(patch->Parameters()->Hub().ShaftLength()->Index()), 0.0, 20.0, 0.05);

	PropellerProperties->SetExpanded("Pitch form", FrgFalse);
	PropellerProperties->SetExpanded("Chord form", FrgFalse);
	PropellerProperties->SetExpanded("Camber form", FrgFalse);
	PropellerProperties->SetExpanded("Skew form", FrgFalse);
	PropellerProperties->SetExpanded("Thickness form", FrgFalse);
	PropellerProperties->SetExpanded("Rake form", FrgFalse);

	connect
	(
		PropellerGeometryTreeItem->GetProperties()->GetPropertyManager()
		, SIGNAL(valueChanged(QtProperty*, const QVariant&))
		, this
		, SLOT(GeometryPropertyValueChangedSlot(QtProperty*, const QVariant&))
	);

	FrgString CreatePartFromGeometryMenu = "&Create Part from Geometry";
	GetTreeItem(PropellerGeometryTreeItem->text(0))->GetContextMenu()->AddItem(CreatePartFromGeometryMenu);
	connect
	(
		GetTreeItem(PropellerGeometryTreeItem->text(0))->GetContextMenu()->GetItem(CreatePartFromGeometryMenu.remove('&'))
		, SIGNAL(triggered(bool))
		, this
		, SLOT(CreatePartFromGeometryClickedSlot(bool))
	);

	GetParentMainWindow()->ParseInfoToConsole("\"" + PropellerGeometryTreeItem->text(0) + "\" geometry successfully created.");

	FrgString GeometryPreviewMenu = "&Preview";
	GetTreeItem(PropellerGeometryTreeItem->text(0))->GetContextMenu()->AddItem(GeometryPreviewMenu);
	connect(GetTreeItem(PropellerGeometryTreeItem->text(0))->GetContextMenu()->GetItem(GeometryPreviewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(PreviewGeometryClickedSlot(bool)));

	ScrollToItem(PropellerGeometryTreeItem);
}

void ForgBaseLib::NihadTree::NewGeometryDuctClickedSlot(bool b)
{
	theGeometryTreeItems_.push_back(FrgNew NihadVesselGeometryTreeItem(CorrectName<FrgBaseTreeItem>(GetTreeItem("Geometry"), "Duct"), GetTreeItem("Geometry")));

	theGeometryTreeItems_.at(theGeometryTreeItems_.size() - 1)->GetEntity() = FrgMakeSharedPtr(AutLib::Leg_Model_DuctNo1)();

	FrgBaseTreeItem* DuctGeometryTreeItem = theGeometryTreeItems_.at(theGeometryTreeItems_.size() - 1);
	FrgSharedPtr<AutLib::Leg_Model_DuctNo1> patch = std::dynamic_pointer_cast<AutLib::Leg_Model_DuctNo1>(theGeometryTreeItems_.at(theGeometryTreeItems_.size() - 1)->GetEntity());

	auto DuctProperties = DuctGeometryTreeItem->GetProperties();

	DuctProperties->AddTopProperty("Dimensions");
	const auto& dimensions = patch->Parameters()->Dimensions();
	DuctProperties->AddProperty<double>("Dimensions", "Height outlet", dimensions.HeightAtOutlet()->Value(), FrgString::number(dimensions.HeightAtOutlet()->Index()), 0.0, 50.0, 0.5);
	DuctProperties->AddProperty<double>("Dimensions", "Overal length", dimensions.OveralLength()->Value(), FrgString::number(dimensions.OveralLength()->Index()), 0.0, 200.0, 1.0);
	DuctProperties->AddProperty<double>("Dimensions", "Breadth at inlet", dimensions.BreadthAtInlet()->Value(), FrgString::number(dimensions.BreadthAtInlet()->Index()), 0.0, 50.0, 0.5);
	DuctProperties->AddProperty<double>("Dimensions", "Breadth at outlet", dimensions.BreadthAtOutlet()->Value(), FrgString::number(dimensions.BreadthAtOutlet()->Index()), 0.0, 50.0, 0.5);
	DuctProperties->AddProperty<double>("Dimensions", "Depth at inlet", dimensions.DepthAtInlet()->Value(), FrgString::number(dimensions.DepthAtInlet()->Index()), 0.0, 50.0, 0.5);
	DuctProperties->AddProperty<double>("Dimensions", "Depth at outlet", dimensions.DepthAtOutlet()->Value(), FrgString::number(dimensions.DepthAtOutlet()->Index()), 0.0, 50.0, 0.5);
	DuctProperties->AddProperty<int>("Dimensions", "Number of sections", dimensions.NbSections(), FrgString::number(DuctNBSectionsID), 3, 40);

	DuctProperties->AddTopProperty("Hull Parameters");
	const auto& hull = patch->Parameters()->Hull();
	DuctProperties->AddTopProperty("Inlet", "Hull Parameters");
	DuctProperties->AddProperty<double>("Inlet", "Side slope", hull.Inlet().SideSlope()->Value(), FrgString::number(hull.Inlet().SideSlope()->Index()));
	DuctProperties->AddProperty<double>("Inlet", "Upper tightness", hull.Inlet().UpperTightness()->Value(), FrgString::number(hull.Inlet().UpperTightness()->Index()));
	DuctProperties->AddProperty<double>("Inlet", "Lower tightness", hull.Inlet().LowerTightness()->Value(), FrgString::number(hull.Inlet().LowerTightness()->Index()));
	DuctProperties->AddProperty<double>("Inlet", "Width", hull.Inlet().Width()->Value(), FrgString::number(hull.Inlet().Width()->Index()));
	DuctProperties->SetExpanded("Inlet", FrgFalse);

	DuctProperties->AddTopProperty("Middle", "Hull Parameters");
	DuctProperties->AddProperty<double>("Middle", "Side slope", hull.Mid().SideSlope()->Value(), FrgString::number(hull.Mid().SideSlope()->Index()));
	DuctProperties->AddProperty<double>("Middle", "Upper tightness", hull.Mid().UpperTightness()->Value(), FrgString::number(hull.Mid().UpperTightness()->Index()));
	DuctProperties->AddProperty<double>("Middle", "Lower tightness", hull.Mid().LowerTightness()->Value(), FrgString::number(hull.Mid().LowerTightness()->Index()));
	DuctProperties->AddProperty<double>("Middle", "Width", hull.Mid().Width()->Value(), FrgString::number(hull.Mid().Width()->Index()));
	DuctProperties->SetExpanded("Middle", FrgFalse);

	DuctProperties->AddTopProperty("Outlet", "Hull Parameters");
	DuctProperties->AddProperty<double>("Outlet", "Side slope", hull.Outlet().SideSlope()->Value(), FrgString::number(hull.Outlet().SideSlope()->Index()));
	DuctProperties->AddProperty<double>("Outlet", "Upper tightness", hull.Outlet().UpperTightness()->Value(), FrgString::number(hull.Outlet().UpperTightness()->Index()));
	DuctProperties->AddProperty<double>("Outlet", "Lower tightness", hull.Outlet().LowerTightness()->Value(), FrgString::number(hull.Outlet().LowerTightness()->Index()));
	DuctProperties->AddProperty<double>("Outlet", "Width", hull.Outlet().Width()->Value(), FrgString::number(hull.Outlet().Width()->Index()));
	DuctProperties->SetExpanded("Outlet", FrgFalse);

	DuctProperties->AddProperty<double>("Hull Parameters", "Middle location", hull.MidLocation()->Value(), FrgString::number(hull.MidLocation()->Index()));

	DuctProperties->AddTopProperty("Generator Parameters");
	const auto& generator = patch->Parameters()->Generator();
	DuctProperties->AddProperty<double>("Generator Parameters", "Position", generator.Position()->Value(), FrgString::number(generator.Position()->Index()));
	DuctProperties->AddProperty<double>("Generator Parameters", "Rise point", generator.RisePoint()->Value(), FrgString::number(generator.RisePoint()->Index()));
	DuctProperties->AddProperty<double>("Generator Parameters", "Rise tangent", generator.RiseTangent()->Value(), FrgString::number(generator.RiseTangent()->Index()));
	DuctProperties->AddProperty<double>("Generator Parameters", "Outlet tangent", generator.OutletTangent()->Value(), FrgString::number(generator.OutletTangent()->Index()));

	DuctProperties->AddTopProperty("Breadth Parameters");
	const auto& breadth = patch->Parameters()->Breadth();
	DuctProperties->AddProperty<double>("Breadth Parameters", "Middle width", breadth.MidWidth()->Value(), FrgString::number(breadth.MidWidth()->Index()));
	DuctProperties->AddProperty<double>("Breadth Parameters", "Middle offset", breadth.MidOffset()->Value(), FrgString::number(breadth.MidOffset()->Index()));
	DuctProperties->AddProperty<double>("Breadth Parameters", "Inlet offset", breadth.InletOffset()->Value(), FrgString::number(breadth.InletOffset()->Index()));
	DuctProperties->AddProperty<double>("Breadth Parameters", "Outlet offset", breadth.OutletOffset()->Value(), FrgString::number(breadth.OutletOffset()->Index()));
	DuctProperties->AddProperty<double>("Breadth Parameters", "Left turning position", breadth.LeftTurningPosition()->Value(), FrgString::number(breadth.LeftTurningPosition()->Index()));
	DuctProperties->AddProperty<double>("Breadth Parameters", "Right turning position", breadth.RightTurningPosition()->Value(), FrgString::number(breadth.RightTurningPosition()->Index()));
	DuctProperties->AddProperty<double>("Breadth Parameters", "Inlet rise weight", breadth.InletRiseWeight()->Value(), FrgString::number(breadth.InletRiseWeight()->Index()));
	DuctProperties->AddProperty<double>("Breadth Parameters", "Outlet rise weight", breadth.OutletRiseWeight()->Value(), FrgString::number(breadth.OutletRiseWeight()->Index()));

	DuctProperties->AddTopProperty("Depth Parameters");
	const auto& depth = patch->Parameters()->Depth();
	DuctProperties->AddProperty<double>("Depth Parameters", "Middle width", depth.MidWidth()->Value(), FrgString::number(depth.MidWidth()->Index()));
	DuctProperties->AddProperty<double>("Depth Parameters", "Middle offset", depth.MidOffset()->Value(), FrgString::number(depth.MidOffset()->Index()));
	DuctProperties->AddProperty<double>("Depth Parameters", "Inlet offset", depth.InletOffset()->Value(), FrgString::number(depth.InletOffset()->Index()));
	DuctProperties->AddProperty<double>("Depth Parameters", "Outlet offset", depth.OutletOffset()->Value(), FrgString::number(depth.OutletOffset()->Index()));
	DuctProperties->AddProperty<double>("Depth Parameters", "Left turning position", depth.LeftTurningPosition()->Value(), FrgString::number(depth.LeftTurningPosition()->Index()));
	DuctProperties->AddProperty<double>("Depth Parameters", "Right turning position", depth.RightTurningPosition()->Value(), FrgString::number(depth.RightTurningPosition()->Index()));
	DuctProperties->AddProperty<double>("Depth Parameters", "Inlet rise weight", depth.InletRiseWeight()->Value(), FrgString::number(depth.InletRiseWeight()->Index()));
	DuctProperties->AddProperty<double>("Depth Parameters", "Outlet rise weight", depth.OutletRiseWeight()->Value(), FrgString::number(depth.OutletRiseWeight()->Index()));

	connect
	(
		DuctGeometryTreeItem->GetProperties()->GetPropertyManager()
		, SIGNAL(valueChanged(QtProperty*, const QVariant&))
		, this
		, SLOT(GeometryPropertyValueChangedSlot(QtProperty*, const QVariant&))
	);

	FrgString CreatePartFromGeometryMenu = "&Create Part from Geometry";
	GetTreeItem(DuctGeometryTreeItem->text(0))->GetContextMenu()->AddItem(CreatePartFromGeometryMenu);
	connect
	(
		GetTreeItem(DuctGeometryTreeItem->text(0))->GetContextMenu()->GetItem(CreatePartFromGeometryMenu.remove('&'))
		, SIGNAL(triggered(bool))
		, this
		, SLOT(CreatePartFromGeometryClickedSlot(bool))
	);

	GetParentMainWindow()->ParseInfoToConsole("\"" + DuctGeometryTreeItem->text(0) + "\" geometry successfully created.");

	FrgString GeometryPreviewMenu = "&Preview";
	GetTreeItem(DuctGeometryTreeItem->text(0))->GetContextMenu()->AddItem(GeometryPreviewMenu);
	connect(GetTreeItem(DuctGeometryTreeItem->text(0))->GetContextMenu()->GetItem(GeometryPreviewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(PreviewGeometryClickedSlot(bool)));

	ScrollToItem(DuctGeometryTreeItem);
}

void ForgBaseLib::NihadTree::NewSceneClickedSlot(bool b)
{
	theSceneTreeItems_.push_back(FrgNew NihadVesselScenePartTreeItem(CorrectName<FrgBaseTreeItem>(GetTreeItem("Scenes"), "Scene"), GetTreeItem("Scenes")));
	theSceneTreeItems_.at(theSceneTreeItems_.size() - 1)->DoAfterConstruct();

	ScrollToItem(theSceneTreeItems_.at(theSceneTreeItems_.size() - 1));
}

#define SetNihadParametersWithProperty(patch, parameter, ID, value)\
if (FrgString::number(patch->parameter->Index()) == ID)\
{\
	if (value.type() == QVariant::Type::Double) \
		patch->parameter->SetValue(value.toDouble());\
	if (value.type() == QVariant::Type::Int) \
		patch->parameter->SetValue(value.toInt());\
}

void ForgBaseLib::NihadTree::GeometryPropertyValueChangedSlot(QtProperty* property, const QVariant& value)
{
	for (int i = 0; i < theGeometryTreeItems_.size(); i++)
	{
		if (theGeometryTreeItems_.at(i)->GetProperties() == ((FrgBaseTreeItem*)theLastLeftClicked_)->GetProperties())
		{
			FrgSharedPtr<AutLib::Leg_Nihad2_BareHull> patchNihad = std::dynamic_pointer_cast<AutLib::Leg_Nihad2_BareHull>(theGeometryTreeItems_.at(i)->GetEntity());
			FrgSharedPtr<AutLib::Leg_Model_PropNo1> patchPropeller = std::dynamic_pointer_cast<AutLib::Leg_Model_PropNo1>(theGeometryTreeItems_.at(i)->GetEntity());
			FrgSharedPtr<AutLib::Leg_Model_DuctNo1> patchDuct = std::dynamic_pointer_cast<AutLib::Leg_Model_DuctNo1>(theGeometryTreeItems_.at(i)->GetEntity());

			if (patchNihad)
			{
				if (FrgString::number(NbNetColumnsID) == property->propertyId())
					patchNihad->SetNbNetColumns(value.toInt());

				SetNihadParametersWithProperty(patchNihad, Dimensions().LengthOnDeck(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, Dimensions().BeamOnDeck(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, Dimensions().DepthAtBow(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, Dimensions().DepthAtTransom(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, Dimensions().TransomHeight(), property->propertyId(), value);
											   
				SetNihadParametersWithProperty(patchNihad, MaxAreaLocation(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, AftFullness(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, FwdFullness(), property->propertyId(), value);
											   
				SetNihadParametersWithProperty(patchNihad, AftSection().Deadrise(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, AftSection().SideSlope(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, AftSection().Trim0(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, AftSection().Trim1(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, AftSection().Tightness0(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, AftSection().Tightness1(), property->propertyId(), value);
											   
				SetNihadParametersWithProperty(patchNihad, MidSection().Deadrise(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, MidSection().SideSlope(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, MidSection().Trim0(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, MidSection().Trim1(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, MidSection().Tightness0(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, MidSection().Tightness1(), property->propertyId(), value);
											   
				SetNihadParametersWithProperty(patchNihad, FwdSection().Deadrise(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, FwdSection().SideSlope(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, FwdSection().Trim0(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, FwdSection().Trim1(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, FwdSection().Tightness0(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, FwdSection().Tightness1(), property->propertyId(), value);
											   
				SetNihadParametersWithProperty(patchNihad, Position(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, RisePoint(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, RiseSlope(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, TransomSlope(), property->propertyId(), value);
											   
				SetNihadParametersWithProperty(patchNihad, Rake(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, Width(), property->propertyId(), value);
											   
				SetNihadParametersWithProperty(patchNihad, BowRounding(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, StemRake(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchNihad, ForeFootShape(), property->propertyId(), value);
			}

			if (patchPropeller)
			{
				if (FrgString::number(PropellerNbBladesID) == property->propertyId())
					patchPropeller->Parameters()->SetNbBlades(value.toInt());
				if (FrgString::number(PropellerNbNSectionsID) == property->propertyId())
					patchPropeller->Parameters()->SetNbSections(value.toInt());
				if (FrgString::number(PropellerNbSpansID) == property->propertyId())
					patchPropeller->Parameters()->SetNbSpans(value.toInt());
				if (FrgString::number(PropellerRemoveHubApex) == property->propertyId())
					patchPropeller->Parameters()->SetToRemoveHubApex(value.toBool());

				SetNihadParametersWithProperty(patchPropeller, Parameters()->Diameter(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->HubRadius(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->TipGap(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->TEGap(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Pitch().RootPitch(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Pitch().RootSteep(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Pitch().TipPitch(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Pitch().TipSteep(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Chord().RootChord(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Chord().TipChord(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Chord().MaxChord(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Chord().MaxChordLocation(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Chord().RootWeight(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Chord().TipWeight(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Camber().RootCamber(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Camber().TipCamber(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Camber().MaxCamber(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Camber().MaxCamberLocation(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Camber().RootWeight(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Camber().TipWeight(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Skew().TipSkew(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Skew().TipSteep(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Skew().RootSteep(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Thickness().RootThickness(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Thickness().TipThickness(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Thickness().RootSteep(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Thickness().TipSteep(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchPropeller, Parameters()->Blade().Rake().TipRake(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchPropeller, Parameters()->Hub().HubLength(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Hub().HubWeight(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Hub().ShaftRadius(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Hub().ShaftOffset(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchPropeller, Parameters()->Hub().ShaftLength(), property->propertyId(), value);

			}

			if (patchDuct)
			{
				if (FrgString::number(DuctNBSectionsID) == property->propertyId())
					patchDuct->Parameters()->Dimensions().SetNbSections(value.toInt());

				SetNihadParametersWithProperty(patchDuct, Parameters()->Dimensions().HeightAtOutlet(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Dimensions().OveralLength(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Dimensions().BreadthAtInlet(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Dimensions().BreadthAtOutlet(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Dimensions().DepthAtInlet(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Dimensions().DepthAtOutlet(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Inlet().SideSlope(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Inlet().UpperTightness(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Inlet().LowerTightness(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Inlet().Width(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Mid().SideSlope(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Mid().UpperTightness(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Mid().LowerTightness(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Mid().Width(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Outlet().SideSlope(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Outlet().UpperTightness(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Outlet().LowerTightness(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().Outlet().Width(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchDuct, Parameters()->Hull().MidLocation(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchDuct, Parameters()->Generator().Position(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Generator().RisePoint(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Generator().RiseTangent(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Generator().OutletTangent(), property->propertyId(), value);

				SetNihadParametersWithProperty(patchDuct, Parameters()->Breadth().MidWidth(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Breadth().MidOffset(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Breadth().InletOffset(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Breadth().OutletOffset(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Breadth().LeftTurningPosition(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Breadth().RightTurningPosition(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Breadth().InletRiseWeight(), property->propertyId(), value);
				SetNihadParametersWithProperty(patchDuct, Parameters()->Breadth().OutletRiseWeight(), property->propertyId(), value);
			}
		}
	}

	auto geometry = dynamic_cast<NihadVesselGeometryTreeItem*>(theLastLeftClicked_);
	if (geometry)
	{
		auto previewScene = dynamic_cast<NihadVesselScenePreviewTreeItem*>(geometry->GetPointerToPreview());
		if (previewScene)
		{
			geometry->GetEntity()->PerformToPreview();
			auto shape = geometry->GetEntity()->PreviewEntity();
			previewScene->GetEntitiesTriangulation() = AutLib::Cad_Tools::PreviewUnMergedPatchCurves(shape, NbSegments_U, NbSegments_V);
			previewScene->RenderSceneSlot();
		}
	}
}

void ForgBaseLib::NihadTree::CreatePartFromGeometryClickedSlot(bool b)
{
	if(std::dynamic_pointer_cast<AutLib::Leg_Nihad2_BareHull>(((NihadVesselGeometryTreeItem*)theLastRightClicked_)->GetEntity()))
		std::dynamic_pointer_cast<AutLib::Leg_Nihad2_BareHull>(((NihadVesselGeometryTreeItem*)theLastRightClicked_)->GetEntity())->Perform();

	if (std::dynamic_pointer_cast<AutLib::Leg_Model_PropNo1>(((NihadVesselGeometryTreeItem*)theLastRightClicked_)->GetEntity()))
		std::dynamic_pointer_cast<AutLib::Leg_Model_PropNo1>(((NihadVesselGeometryTreeItem*)theLastRightClicked_)->GetEntity())->Perform();

	if (std::dynamic_pointer_cast<AutLib::Leg_Model_DuctNo1>(((NihadVesselGeometryTreeItem*)theLastRightClicked_)->GetEntity()))
		std::dynamic_pointer_cast<AutLib::Leg_Model_DuctNo1>(((NihadVesselGeometryTreeItem*)theLastRightClicked_)->GetEntity())->Perform();

	auto solid = AutLib::Cad3d_TModel::MakeSolid((dynamic_cast<NihadVesselGeometryTreeItem*>(theLastRightClicked_))->GetTopoDS_Shape(), 1.0e-6);

	/*thePartTreeItems_.push_back
	(FrgNew NihadVesselPartTreeItem
	(
		theLastRightClicked_->text(0),
		GetTreeItem("Parts"),
		solid
	)
	);*/

	thePartTreeItems_.push_back
	(FrgNew CADPartItem<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>, AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>
	(
		theLastRightClicked_->text(0),
		GetTreeItem("Parts"),
		solid
	)
	);

	ScrollToItem(thePartTreeItems_.at(thePartTreeItems_.size() - 1));
}

void ForgBaseLib::NihadTree::ExportPartSlot(bool b)
{
	QList<QString> QfileTypes;
	QfileTypes.push_back("IGES (*.igs)");
	QfileTypes.push_back("STEP (*.stp; *.step)");
	QfileTypes.push_back("Tecplot (*.plt)");

	QString fileTypes;
	for (int i = 0; i < QfileTypes.size() - 1; i++)
	{
		fileTypes += QfileTypes.at(i);
		fileTypes += ";;";
	}
	fileTypes += QfileTypes.at(QfileTypes.size() - 1);

	QString* ext = new QString("IGES");
	QString fileName = QFileDialog::getSaveFileName(GetParentMainWindow(),
		QMainWindow::tr("Export Part"), "",
		fileTypes, ext);

	if (fileName.isEmpty())
		return;
	else
	{
		if (*ext == "IGES (*.igs)")
		{
			AutLib::Cad_Tools::ExportToIGES("MM", ((NihadVesselPartTreeItem*)(theLastRightClicked_))->GetModel()->Shape(), fileName.toStdString());
		}
		else if (*ext == "STEP (*.stp; *.step)")
		{
			AutLib::Cad_Tools::ExportToSTEP(((NihadVesselPartTreeItem*)(theLastRightClicked_))->GetModel()->Shape(), fileName.toStdString());
		}
		else if (*ext == "Tecplot (*.plt)")
		{

		}
	}

	GetParentMainWindow()->ParseInfoToConsole("\"" + theLastRightClicked_->text(0) + "\" saved successfully at\"" + fileName + "\"");
}

void ForgBaseLib::NihadTree::SplitByPatchPartSlot(bool)
{

}

ForgBaseLib::NihadVesselGeometryTreeItem* ForgBaseLib::NihadTree::GetGeometryTreeItem(FrgBaseTreeItem* item)
{
	for (int i = 0; i < theGeometryTreeItems_.size(); i++)
	{
		if (theGeometryTreeItems_.at(i) == item)
			return theGeometryTreeItems_.at(i);
	}
}

ForgBaseLib::FrgBaseCADPart_Entity* ForgBaseLib::NihadTree::GetPartTreeItem(FrgBaseTreeItem* item)
{
	for (int i = 0; i < thePartTreeItems_.size(); i++)
	{
		if (thePartTreeItems_.at(i) == item)
			return thePartTreeItems_.at(i);
	}
}

void ForgBaseLib::NihadTree::UpdateTree()
{
	for (int i = 0; i < GetItems().size(); i++)
	{
		if (GetItems().at(i)->childCount() != 0)
			GetItems().at(i)->setExpanded(FrgTrue);
	}
	FrgBaseTreeItem* item = GetTreeItem("Scenes");
}

void ForgBaseLib::NihadTree::ObjectsSelectedUpdateInSceneSlot(QList<QTreeWidgetItem*> selectedItems)
{
	QList<FrgBaseCADPart_Entity*> output;

	for (int i = 0; i < selectedItems.size(); i++)
	{
		output.push_back(dynamic_cast<FrgBaseCADPart_Entity*>(selectedItems.at(i)));
	}

	auto scene = (dynamic_cast<NihadVesselScenePartTreeItem*>(theLastLeftClicked_));

	if (scene)
	{
		scene->GetPartsPointer() = output;
		scene->RenderSceneSlot();

		GetParentMainWindow()->GetTabWidget()->addTab(scene->GetViewPorts(), scene->text(0));
		GetParentMainWindow()->GetTabWidget()->setCurrentWidget(scene->GetViewPorts());
	}
}

void ForgBaseLib::NihadTree::PreviewGeometryClickedSlot(bool)
{
	auto geometry = dynamic_cast<NihadVesselGeometryTreeItem*>(theLastRightClicked_);
	geometry->GetEntity()->PerformToPreview();
	auto shape = geometry->GetEntity()->PreviewEntity();
	geometry->GetPointerToPreview() = FrgNew NihadVesselScenePreviewTreeItem(theLastRightClicked_->text(0) + " Preview", theLastRightClicked_);
	geometry->GetContextMenu()->GetItem("Preview")->setDisabled(FrgTrue);


	NihadVesselScenePreviewTreeItem* NihadPreviewScene = geometry->GetPointerToPreview();

	NihadPreviewScene->GetEntitiesTriangulation() = AutLib::Cad_Tools::PreviewUnMergedPatchCurves(shape, NbSegments_U, NbSegments_V);

	NihadPreviewScene->RenderSceneSlot();

	NihadPreviewScene->GetViewPorts()->RenderScenes();

	GetParentMainWindow()->GetTabWidget()->addTab(NihadPreviewScene->GetViewPorts(), NihadPreviewScene->text(0));
	GetParentMainWindow()->GetTabWidget()->setCurrentWidget(NihadPreviewScene->GetViewPorts());

	/*GetParentMainWindow()->GetTabWidget()->addTab(NihadPreviewScene, NihadPreviewScene->text(0));
	GetParentMainWindow()->GetTabWidget()->setCurrentWidget(NihadPreviewScene);*/
}

void ForgBaseLib::NihadTree::NewPlotClickedSlot(bool)
{
	thePlotsItems_.push_back(FrgNew FrgBasePlot2D(CorrectName<FrgBaseTreeItem>(theLastRightClicked_, "Plot"), theLastRightClicked_, this, GetParentMainWindow()));
	FrgBasePlot2D* lastPlotAdded = thePlotsItems_.last();
	GetParentMainWindow()->GetTabWidget()->setCurrentWidget(lastPlotAdded);

	ScrollToItem(lastPlotAdded);
}

void ForgBaseLib::NihadTree::TabBarClickedSlot(int index)
{
	//scrollTo(this->indexFromItem((FrgBaseTreeItem*)(GetParentMainWindow()->GetTabWidget()->widget(index)), 0));
}

void ForgBaseLib::NihadTree::itemDoubleClickedSlot(QTreeWidgetItem* item, int column)
{
	if (dynamic_cast<NihadVesselScenePartTreeItem*>(item))
	{
		auto& tab = GetParentMainWindow()->GetTabWidget();
		tab->setCurrentIndex(tab->indexOf(dynamic_cast<NihadVesselScenePartTreeItem*>(item)->GetViewPorts()));
	}
	if (dynamic_cast<FrgBasePlot2D*>(item))
	{
		auto& tab = GetParentMainWindow()->GetTabWidget();
		tab->setCurrentIndex(tab->indexOf(dynamic_cast<FrgBasePlot2D*>(item)));
	}
}