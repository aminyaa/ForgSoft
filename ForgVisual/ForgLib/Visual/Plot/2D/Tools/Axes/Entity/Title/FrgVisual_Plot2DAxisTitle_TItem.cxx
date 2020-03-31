#include <FrgVisual_Plot2DAxisTitle_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2DBtmAxis_TItem.hxx>
#include <FrgVisual_Plot2DLeftAxis_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem::FrgVisual_Plot2DAxisTitle_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree,
	FrgVisual_Plot2D_TItem* plot2DTItem
)
	: FrgBase_TreeItem(itemTitle, parentItem, parentTree)
	, thePlot2DTItem_(plot2DTItem)
{
	this->setIcon(0, QIcon(ICONTreeItemCircle));

	theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", true);

	auto btmAxis = dynamic_cast<FrgVisual_Plot2DBtmAxis_TItem*>(parentItem);
	auto leftAxis = dynamic_cast<FrgVisual_Plot2DLeftAxis_TItem*>(parentItem);

	if (btmAxis)
		theTitle_ = new ForgBaseLib::FrgBase_PrptsVrntString("Title", "X Axis");
	else if (leftAxis)
		theTitle_ = new ForgBaseLib::FrgBase_PrptsVrntString("Title", "Y Axis");
	else
		theTitle_ = new ForgBaseLib::FrgBase_PrptsVrntString("Title", "");

	std::vector<const char*> items;
	items.push_back("0");
	items.push_back("45");
	items.push_back("90");
	items.push_back("135");
	items.push_back("180");
	items.push_back("225");
	items.push_back("270");
	items.push_back("315");
	if (btmAxis)
		theRotation_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Rotation", "0", "", "degrees");
	else if (leftAxis)
		theRotation_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Rotation", "90", "", "degrees");
	else
		theRotation_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Rotation", "0", "", "degrees");

	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntBool>(theVisible_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntString>(theTitle_);
	thePropertiesPanel_->AddRow<ForgBaseLib::FrgBase_PrptsVrntCombo>(theRotation_);

	connect(theVisible_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(VisibilityChangedSlot(const bool&)));
	connect(theTitle_, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(TitleChangedSlot(const QString&)));
	connect(theRotation_, SIGNAL(ValueChangedSignal(const char*)), this, SLOT(RotationChangedSlot(const char*)));
}

void ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem::VisibilityChangedSlot(const bool & condition)
{
	auto btmAxis = dynamic_cast<FrgVisual_Plot2DBtmAxis_TItem*>(QTreeWidgetItem::parent());
	auto leftAxis = dynamic_cast<FrgVisual_Plot2DLeftAxis_TItem*>(QTreeWidgetItem::parent());
	auto plot2D = thePlot2DTItem_->GetPlot2D();
	if (plot2D)
	{
		if (btmAxis)
			plot2D->SetBottomAxisTitleVisible(condition);
		else if (leftAxis)
			plot2D->SetLeftAxisTitleVisible(condition);
	}
}

void ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem::TitleChangedSlot(const QString & title)
{
	auto btmAxis = dynamic_cast<FrgVisual_Plot2DBtmAxis_TItem*>(QTreeWidgetItem::parent());
	auto leftAxis = dynamic_cast<FrgVisual_Plot2DLeftAxis_TItem*>(QTreeWidgetItem::parent());
	auto plot2D = thePlot2DTItem_->GetPlot2D();
	if (plot2D)
	{
		if (btmAxis)
			plot2D->SetBottomAxisTitle(title.toStdString().c_str());
		else if (leftAxis)
			plot2D->SetLeftAxisTitle(title.toStdString().c_str());
	}
}

void ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem::RotationChangedSlot(const char * degreeChar)
{
	auto btmAxis = dynamic_cast<FrgVisual_Plot2DBtmAxis_TItem*>(QTreeWidgetItem::parent());
	auto leftAxis = dynamic_cast<FrgVisual_Plot2DLeftAxis_TItem*>(QTreeWidgetItem::parent());

	int degree = std::atoi(degreeChar);

	auto plot2D = thePlot2DTItem_->GetPlot2D();
	if (plot2D)
	{
		if (btmAxis)
			plot2D->SetBottomAxisTitleRotation(degree);
		else if (leftAxis)
			plot2D->SetLeftAxisTitleRotation(degree);
	}
}

void ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem::TItemClickedSlot()
{
	auto btmAxis = dynamic_cast<FrgVisual_Plot2DBtmAxis_TItem*>(QTreeWidgetItem::parent());
	auto leftAxis = dynamic_cast<FrgVisual_Plot2DLeftAxis_TItem*>(QTreeWidgetItem::parent());

	auto plot2D = thePlot2DTItem_->GetPlot2D();
	if (plot2D)
	{
		if (btmAxis)
			plot2D->HighlightBottomAxisTitle(true);
		else if (leftAxis)
			plot2D->HighlightLeftAxisTitle(true);
	}
}

void ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem::TItemNotClickedSlot()
{
	if (theParentTree_->isItemSelected(this))
		return;
	/*if (theParentTree_->isItemSelected(QTreeWidgetItem::parent()))
		return;*/

	auto btmAxis = dynamic_cast<FrgVisual_Plot2DBtmAxis_TItem*>(QTreeWidgetItem::parent());
	auto leftAxis = dynamic_cast<FrgVisual_Plot2DLeftAxis_TItem*>(QTreeWidgetItem::parent());

	auto plot2D = thePlot2DTItem_->GetPlot2D();
	if (plot2D)
	{
		if (btmAxis)
			plot2D->HighlightBottomAxisTitle(false);
		else if (leftAxis)
			plot2D->HighlightLeftAxisTitle(false);
	}
}