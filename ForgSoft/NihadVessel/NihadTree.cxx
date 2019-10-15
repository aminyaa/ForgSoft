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
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>

#include <qtpropertymanager.h>

#define NbNetColumnsID 222
#define NbNetRowsID 223
#define PartsListID 1285

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

	AddItemToTree(FrgNew FrgBaseTreeItem(GeometryItem, FrgNullPtr, this, GetParentMainWindow()));

	AddItemToTree(FrgNew FrgBaseTreeItem(PartsItem, FrgNullPtr, this, GetParentMainWindow()));

	AddItemToTree(FrgNew FrgBaseTreeItem(ScenesItem, FrgNullPtr, this, GetParentMainWindow()));

	AddItemToTree(FrgNew FrgBaseTreeItem(PlotsItem, FrgNullPtr, this, GetParentMainWindow()));

	FrgString GeometryNewMenu = "&New Geometry Nihad";
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

	AddItemToTree(NihadGeometryTreeItem);

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
}

void ForgBaseLib::NihadTree::NewSceneClickedSlot(bool b)
{
	theNihadSceneTreeItems_.push_back(FrgNew NihadSceneTreeItemStruct);

	theNihadSceneTreeItems_.at(theNihadSceneTreeItems_.size() - 1)->theTreeItem_ =
		FrgNew NihadVesselSceneTreeItem(CorrectName<FrgBaseTreeItem>(GetTreeItem("Scenes"), "Scene"), GetTreeItem("Scenes"), GetParentMainWindow()->GetTree(), GetParentMainWindow());

	NihadVesselSceneTreeItem* NihadSceneItem =
		theNihadSceneTreeItems_.at(theNihadSceneTreeItems_.size() - 1)->theTreeItem_;

	AddItemToTree(NihadSceneItem);

	NihadSceneItem->GetProperties()->AddPropertyFlagType("Properties", "Parts List", thePartsNamesList_, FrgString::number(PartsListID));

	connect
	(
		NihadSceneItem->GetProperties()->GetPropertyManager()
		, SIGNAL(valueChanged(QtProperty*, const QVariant&))
		, this
		, SLOT(GeometryPropertyValueChangedSlot(QtProperty*, const QVariant&))
	);

	NihadSceneItem->GetProperties()->GetPropertyBrowser()->layout()->addWidget(NihadSceneItem->GetOKButton());

	theNihadSceneTreeItems_.at(theNihadSceneTreeItems_.size() - 1)->thePartPointer_ = theNihadPartTreeItems_.at(0);

	NihadSceneItem->GetPartsPointer().push_back(theNihadSceneTreeItems_.at(theNihadSceneTreeItems_.size() - 1)->thePartPointer_);

	GetParentMainWindow()->ParseInfoToConsole("\"" + NihadSceneItem->text(0) + "\" scene successfully created.");
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
		}
	}

	for (int i = 0; i < theNihadSceneTreeItems_.size(); i++)
	{
		if (theNihadSceneTreeItems_.at(i)->theTreeItem_->GetProperties() == (GetParentMainWindow()->GetPropertyWidget()->theProperty_->GetParentProperties()))
		{
			if (FrgString::number(PartsListID) == property->propertyId())
			{
				GetParentMainWindow()->ParseErrorToConsole(value.toString());
			}
		}
	}
}

void ForgBaseLib::NihadTree::CreatePartFromGeometryClickedSlot(bool b)
{
	theNihadPartTreeItems_.push_back(FrgNew NihadPartTreeItemStruct);

	theNihadPartTreeItems_.at(theNihadPartTreeItems_.size() - 1)->theTreeItem_ =
		FrgNew FrgBaseTreeItem(theLastRightClicked_->text(0), GetTreeItem("Parts"), GetParentMainWindow()->GetTree(), GetParentMainWindow());

	FrgBaseTreeItem* NihadPartTreeItem = theNihadPartTreeItems_.at(theNihadPartTreeItems_.size() - 1)->theTreeItem_;

	theNihadPartTreeItems_.at(theNihadPartTreeItems_.size() - 1)->theGeometryPointer_ = GetGeometryTreeItem(theLastRightClicked_);

	AddItemToTree(NihadPartTreeItem);

	theNihadPartTreeItems_.at(theNihadPartTreeItems_.size() - 1)->theGeometryPointer_->thePatch_->Perform();

	FrgString ExportPartString = "&Export";
	NihadPartTreeItem->GetContextMenu()->AddItem(ExportPartString);
	connect
	(
		NihadPartTreeItem->GetContextMenu()->GetItem(ExportPartString.remove('&'))
		, SIGNAL(triggered(bool))
		, this
		, SLOT(ExportPartSlot(bool))
	);

	thePartsNamesList_ << NihadPartTreeItem->text(0);

	UpdateTree();

	GetParentMainWindow()->ParseInfoToConsole("\"" + NihadPartTreeItem->text(0) + "\" part successfully created.");
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
			GetPartTreeItem(theLastRightClicked_)->theGeometryPointer_->thePatch_->SetFileName(fileName.toStdString());
			GetPartTreeItem(theLastRightClicked_)->theGeometryPointer_->thePatch_->SetFileFormat(AutLib::Leg_EntityIO_Format::IGES);
			GetPartTreeItem(theLastRightClicked_)->theGeometryPointer_->thePatch_->ExportToFile();
		}
		else if (*ext == "STEP (*.stp; *.step)")
		{
			GetPartTreeItem(theLastRightClicked_)->theGeometryPointer_->thePatch_->SetFileName(fileName.toStdString());
			GetPartTreeItem(theLastRightClicked_)->theGeometryPointer_->thePatch_->SetFileFormat(AutLib::Leg_EntityIO_Format::STEP);
			GetPartTreeItem(theLastRightClicked_)->theGeometryPointer_->thePatch_->ExportToFile();
		}
		else if (*ext == "Tecplot (*.plt)")
		{
			GetPartTreeItem(theLastRightClicked_)->theGeometryPointer_->thePatch_->SetFileName(fileName.toStdString());
			GetPartTreeItem(theLastRightClicked_)->theGeometryPointer_->thePatch_->SetFileFormat(AutLib::Leg_EntityIO_Format::TecPlot);
			GetPartTreeItem(theLastRightClicked_)->theGeometryPointer_->thePatch_->ExportToFile();
		}
	}

	GetParentMainWindow()->ParseInfoToConsole("\"" + theLastRightClicked_->text(0) + "\" saved successfully at\"" + fileName + "\"");
}

ForgBaseLib::NihadGeometryTreeItemStruct* ForgBaseLib::NihadTree::GetGeometryTreeItem(FrgBaseTreeItem* item)
{
	for (int i = 0; i < theNihadGeometryTreeItems_.size(); i++)
	{
		if (theNihadGeometryTreeItems_.at(i)->theTreeItem_ == item)
			return theNihadGeometryTreeItems_.at(i);
	}
}

ForgBaseLib::NihadPartTreeItemStruct* ForgBaseLib::NihadTree::GetPartTreeItem(FrgBaseTreeItem* item)
{
	for (int i = 0; i < theNihadPartTreeItems_.size(); i++)
	{
		if (theNihadPartTreeItems_.at(i)->theTreeItem_ == item)
			return theNihadPartTreeItems_.at(i);
	}
}

void ForgBaseLib::NihadTree::UpdateTree()
{
	for (int i = 0; i< GetItems().size(); i++)
	{
		if (GetItems().at(i)->childCount() != 0)
			GetItems().at(i)->setExpanded(FrgTrue);
	}
	FrgBaseTreeItem* item = GetTreeItem("Scenes");

	if (item)
	{
		for (int i = 0; i < item->childCount(); i++)
		{
			FrgBaseTreeItemProperties* itemProperties = ((FrgBaseTreeItem*)(item->child(i)))->GetProperties();
			itemProperties->GetPropertyManager()->setAttribute(itemProperties->GetProperty("Parts List"), "flagNames", thePartsNamesList_);
		}
	}
}

void ForgBaseLib::NihadTree::AddItemToTree(FrgBaseTreeItem* item)
{
	GetItems().push_back(item);

	UpdateTree();
}