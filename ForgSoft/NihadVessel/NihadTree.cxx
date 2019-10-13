#include <NihadTree.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseMenu.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTreeItemProperties.hxx>
#include <FrgBaseTreeItemPropertiesBrowser.hxx>

#include <NihadVesselSceneTreeItem.hxx>

#include <Pnt2d.hxx>
#include <Entity2d_Box.hxx>
#include <FastDiscrete_Params.hxx>
#include <Leg_Vessel_Nihad2.hxx>
#include <IO_IGES.hxx>

#include <QtWidgets/QAction>

#define NbNetColumnsID 222
#define NbNetRowsID 223

ForgBaseLib::NihadTree::NihadTree(FrgBaseMainWindow* parent)
	: FrgBaseTree(parent)
{
}

void ForgBaseLib::NihadTree::FormTree()
{
	FrgString GeometryItem = "Geometry";
	FrgString PartsItem = "Parts";
	FrgString ScenesItem = "Scenes";
	FrgString PlotsItem = "Plots";

	GetItems().push_back(FrgNew FrgBaseTreeItem(GeometryItem, FrgNullPtr, this, GetParentMainWindow()));

	GetItems().push_back(FrgNew FrgBaseTreeItem(PartsItem, FrgNullPtr, this, GetParentMainWindow()));

	GetItems().push_back(FrgNew FrgBaseTreeItem(ScenesItem, FrgNullPtr, this, GetParentMainWindow()));

	GetItems().push_back(FrgNew FrgBaseTreeItem(PlotsItem, FrgNullPtr, this, GetParentMainWindow()));

	FrgString GeometryNewMenu = "&New Geometry";
	GetTreeItem(GeometryItem)->GetContextMenu()->AddItem(GeometryNewMenu);
	connect(GetTreeItem(GeometryItem)->GetContextMenu()->GetItem(GeometryNewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(NewGeometryClickedSlot(bool)));

	FrgString ScenesNewMenu = "&New Scene";
	GetTreeItem(ScenesItem)->GetContextMenu()->AddItem(ScenesNewMenu);
	connect(GetTreeItem(ScenesItem)->GetContextMenu()->GetItem(ScenesNewMenu.remove('&')), SIGNAL(triggered(bool)), this, SLOT(NewSceneClickedSlot(bool)));
}

void ForgBaseLib::NihadTree::NewGeometryClickedSlot(bool)
{
	theNihadGeometryTreeItems_.push_back(FrgNew NihadGeometryTreeItemStruct);

	theNihadGeometryTreeItems_.at(theNihadGeometryTreeItems_.size() - 1)->theTreeItem_ =
		FrgNew FrgBaseTreeItem(CorrectName<FrgBaseTreeItem>(GetTreeItem("Geometry"), "Nihad"), GetTreeItem("Geometry"), GetParentMainWindow()->GetTree(), GetParentMainWindow());

	theNihadGeometryTreeItems_.at(theNihadGeometryTreeItems_.size() - 1)->thePatch_ = FrgNew AutLib::Leg_Nihad2_HullPatch;

	FrgBaseTreeItem* NihadGeometryTreeItem = theNihadGeometryTreeItems_.at(theNihadGeometryTreeItems_.size() - 1)->theTreeItem_;
	AutLib::Leg_Nihad2_HullPatch* patch = theNihadGeometryTreeItems_.at(theNihadGeometryTreeItems_.size() - 1)->thePatch_;

	GetItems().push_back(FrgNew FrgBaseTreeItem(NihadGeometryTreeItem->text(0), FrgNullPtr, this, GetParentMainWindow()));

	patch->FwdSection().Tightness0()->SetValue(0.9);
	patch->FwdSection().Tightness1()->SetValue(0.9);

	patch->AftSection().Trim()->SetValue(0.1);
	patch->MidSection().Trim()->SetValue(0.1);
	patch->FwdSection().Trim()->SetValue(0.1);

	NihadGeometryTreeItem->GetProperties()->AddTopProperty("Dimensions");
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Dimensions", "Length on deck", patch->Dimensions().LengthOnDeck()->Value(), FrgString::number(patch->Dimensions().LengthOnDeck()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Dimensions", "Beam on deck", patch->Dimensions().BeamOnDeck()->Value(), FrgString::number(patch->Dimensions().BeamOnDeck()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Dimensions", "Depth at bow", patch->Dimensions().DepthAtBow()->Value(), FrgString::number(patch->Dimensions().DepthAtBow()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Dimensions", "Depth at transom", patch->Dimensions().DepthAtTransom()->Value(), FrgString::number(patch->Dimensions().DepthAtTransom()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Dimensions", "Transom height", patch->Dimensions().TransomHeight()->Value(), FrgString::number(patch->Dimensions().TransomHeight()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyInt("Dimensions", "Number of sections", patch->Dimensions().NbNetColumns(), FrgString::number(NbNetColumnsID));
	NihadGeometryTreeItem->GetProperties()->AddPropertyInt("Dimensions", "Number of rows", patch->Dimensions().NbNetRows(), FrgString::number(NbNetRowsID));
	NihadGeometryTreeItem->GetProperties()->GetProperty("Number of rows")->setEnabled(FrgFalse);

	NihadGeometryTreeItem->GetProperties()->AddTopProperty("Hull Parameters");
	NihadGeometryTreeItem->GetProperties()->AddPropertyInt("Hull Parameters", "Max area location", patch->MaxAreaLocation()->Value(), FrgString::number(patch->MaxAreaLocation()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyInt("Hull Parameters", "Aft fullness", patch->AftFullness()->Value(), FrgString::number(patch->AftFullness()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyInt("Hull Parameters", "Fwd fullness", patch->FwdFullness()->Value(), FrgString::number(patch->FwdFullness()->Index()));
	
	NihadGeometryTreeItem->GetProperties()->AddTopProperty("Aft Parameters", "Hull Parameters");
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Aft Parameters", "Deadrise", patch->AftSection().Deadrise()->Value(), FrgString::number(patch->AftSection().Deadrise()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Aft Parameters", "Side slope", patch->AftSection().SideSlope()->Value(), FrgString::number(patch->AftSection().SideSlope()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Aft Parameters", "Trim", patch->AftSection().Trim()->Value(), FrgString::number(patch->AftSection().Trim()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Aft Parameters", "Tightness0", patch->AftSection().Tightness0()->Value(), FrgString::number(patch->AftSection().Tightness0()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Aft Parameters", "Tightness1", patch->AftSection().Tightness1()->Value(), FrgString::number(patch->AftSection().Tightness1()->Index()));
	
	NihadGeometryTreeItem->GetProperties()->AddTopProperty("Mid Parameters", "Hull Parameters");
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Mid Parameters", "Deadrise", patch->MidSection().Deadrise()->Value(), FrgString::number(patch->MidSection().Deadrise()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Mid Parameters", "Side slope", patch->MidSection().SideSlope()->Value(), FrgString::number(patch->MidSection().SideSlope()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Mid Parameters", "Trim", patch->MidSection().Trim()->Value(), FrgString::number(patch->MidSection().Trim()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Mid Parameters", "Tightness0", patch->MidSection().Tightness0()->Value(), FrgString::number(patch->MidSection().Tightness0()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Mid Parameters", "Tightness1", patch->MidSection().Tightness1()->Value(), FrgString::number(patch->MidSection().Tightness1()->Index()));

	NihadGeometryTreeItem->GetProperties()->AddTopProperty("Fwd Parameters", "Hull Parameters");
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Fwd Parameters", "Deadrise", patch->FwdSection().Deadrise()->Value(), FrgString::number(patch->FwdSection().Deadrise()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Fwd Parameters", "Side slope", patch->FwdSection().SideSlope()->Value(), FrgString::number(patch->FwdSection().SideSlope()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Fwd Parameters", "Trim", patch->FwdSection().Trim()->Value(), FrgString::number(patch->FwdSection().Trim()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Fwd Parameters", "Tightness0", patch->FwdSection().Tightness0()->Value(), FrgString::number(patch->FwdSection().Tightness0()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Fwd Parameters", "Tightness1", patch->FwdSection().Tightness1()->Value(), FrgString::number(patch->FwdSection().Tightness1()->Index()));

	NihadGeometryTreeItem->GetProperties()->AddTopProperty("Keel Parameters");
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Keel Parameters", "Position", patch->Position()->Value(), FrgString::number(patch->Position()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Keel Parameters", "Rise point", patch->RisePoint()->Value(), FrgString::number(patch->RisePoint()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Keel Parameters", "Rise slope", patch->RiseSlope()->Value(), FrgString::number(patch->RiseSlope()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Keel Parameters", "Transom slope", patch->TransomSlope()->Value(), FrgString::number(patch->TransomSlope()->Index()));
	
	NihadGeometryTreeItem->GetProperties()->AddTopProperty("Transom Parameters");
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Transom Parameters", "Rake", patch->Rake()->Value(), FrgString::number(patch->Rake()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Transom Parameters", "Width", patch->Width()->Value(), FrgString::number(patch->Width()->Index()));

	NihadGeometryTreeItem->GetProperties()->AddTopProperty("Stem Parameters");
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Stem Parameters", "Bow rounding", patch->BowRounding()->Value(), FrgString::number(patch->BowRounding()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Stem Parameters", "Stem rake", patch->StemRake()->Value(), FrgString::number(patch->StemRake()->Index()));
	NihadGeometryTreeItem->GetProperties()->AddPropertyDouble("Stem Parameters", "Fore foot shape", patch->ForeFootShape()->Value(), FrgString::number(patch->ForeFootShape()->Index()));

	NihadGeometryTreeItem->GetProperties()->SetExpanded("Aft Parameters", FrgFalse);
	NihadGeometryTreeItem->GetProperties()->SetExpanded("Fwd Parameters", FrgFalse);
	NihadGeometryTreeItem->GetProperties()->SetExpanded("Mid Parameters", FrgFalse);
	NihadGeometryTreeItem->GetProperties()->SetExpanded("Keel Parameters", FrgFalse);
	NihadGeometryTreeItem->GetProperties()->SetExpanded("Transom Parameters", FrgFalse);
	NihadGeometryTreeItem->GetProperties()->SetExpanded("Stem Parameters", FrgFalse);

	connect
	(
		NihadGeometryTreeItem->GetProperties()->GetPropertyManager()
		, SIGNAL(valueChanged(QtProperty*, const QVariant&))
		, this
		, SLOT(PropertyValueChangedSlot(QtProperty*, const QVariant&))
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
}

void ForgBaseLib::NihadTree::NewSceneClickedSlot(bool b)
{
	NihadVesselSceneTreeItem* NihadSceneItem =
		FrgNew NihadVesselSceneTreeItem(CorrectName<FrgBaseTreeItem>(GetTreeItem("Scenes"), "Scene"), GetTreeItem("Scenes"), GetParentMainWindow()->GetTree(), GetParentMainWindow());
}

#define SetNihadParametersWithProperty(patch, parameter, ID, value)\
if (FrgString::number(patch->parameter->Index()) == ID)\
{\
	if (value.type() == QVariant::Type::Double) \
		patch->parameter->SetValue(value.toDouble());\
	if (value.type() == QVariant::Type::Int) \
		patch->parameter->SetValue(value.toInt());\
}

void ForgBaseLib::NihadTree::PropertyValueChangedSlot(QtProperty* property, const QVariant& value)
{
	for (int i = 0; i < theNihadGeometryTreeItems_.size(); i++)
	{
		if (theNihadGeometryTreeItems_.at(i)->theTreeItem_->GetProperties() == (GetParentMainWindow()->GetPropertyWidget()->theProperty_->GetParentProperties()))
		{
			AutLib::Leg_Nihad2_HullPatch* patch = theNihadGeometryTreeItems_.at(i)->thePatch_;

			if (NbNetColumnsID == property->propertyId())
				patch->SetNbNetColumns(value.toInt());

			SetNihadParametersWithProperty(patch, Dimensions().LengthOnDeck(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, Dimensions().BeamOnDeck(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, Dimensions().DepthAtBow(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, Dimensions().DepthAtTransom(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, Dimensions().TransomHeight(), property->propertyId(), value);

			SetNihadParametersWithProperty(patch, MaxAreaLocation(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, AftFullness(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, FwdFullness(), property->propertyId(), value);

			SetNihadParametersWithProperty(patch, AftSection().Deadrise(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, AftSection().SideSlope(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, AftSection().Trim(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, AftSection().Tightness0(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, AftSection().Tightness1(), property->propertyId(), value);

			SetNihadParametersWithProperty(patch, MidSection().Deadrise(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, MidSection().SideSlope(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, MidSection().Trim(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, MidSection().Tightness0(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, MidSection().Tightness1(), property->propertyId(), value);

			SetNihadParametersWithProperty(patch, FwdSection().Deadrise(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, FwdSection().SideSlope(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, FwdSection().Trim(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, FwdSection().Tightness0(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, FwdSection().Tightness1(), property->propertyId(), value);

			SetNihadParametersWithProperty(patch, Position(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, RisePoint(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, RiseSlope(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, TransomSlope(), property->propertyId(), value);

			SetNihadParametersWithProperty(patch, Rake(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, Width(), property->propertyId(), value);

			SetNihadParametersWithProperty(patch, BowRounding(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, StemRake(), property->propertyId(), value);
			SetNihadParametersWithProperty(patch, ForeFootShape(), property->propertyId(), value);

			patch->Perform();

			patch->FileFormat() = AutLib::Leg_EntityIO_Format::IGES;
			patch->ExportToFile();
		}
	}
}

void ForgBaseLib::NihadTree::CreatePartFromGeometryClickedSlot(bool b)
{
	theNihadPartTreeItems_.push_back(FrgNew NihadPartTreeItemStruct);

	theNihadPartTreeItems_.at(theNihadPartTreeItems_.size() - 1)->theTreeItem_ =
		FrgNew FrgBaseTreeItem(CorrectName<FrgBaseTreeItem>(GetTreeItem("Parts"), theLastRightClicked_->text(0)), GetTreeItem("Parts"), GetParentMainWindow()->GetTree(), GetParentMainWindow());

	FrgBaseTreeItem* NihadPartTreeItem = theNihadPartTreeItems_.at(theNihadPartTreeItems_.size() - 1)->theTreeItem_;

	GetItems().push_back(FrgNew FrgBaseTreeItem(NihadPartTreeItem->text(0), FrgNullPtr, this, GetParentMainWindow()));
}