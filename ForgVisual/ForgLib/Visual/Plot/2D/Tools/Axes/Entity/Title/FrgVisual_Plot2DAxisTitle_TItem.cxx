#include <FrgVisual_Plot2DAxisTitle_TItem.hxx>
#include <FrgVisual_Plot2D_TItem.hxx>
#include <FrgVisual_Plot2DBtmAxis_TItem.hxx>
#include <FrgVisual_Plot2DLeftAxis_TItem.hxx>
#include <FrgBase_Global_Icons.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_Plot2D.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgVisual_Plot2DAxes_TItem.hxx>

//BOOST_CLASS_EXPORT_GUID(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem, "ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem")
//BOOST_CLASS_EXPORT_IMPLEMENT(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)

#define ROTATION_0_TEXT QString("0")
#define ROTATION_45_TEXT QString("45")
#define ROTATION_90_TEXT QString("90")
#define ROTATION_135_TEXT QString("135")
#define ROTATION_180_TEXT QString("180")
#define ROTATION_225_TEXT QString("225")
#define ROTATION_270_TEXT QString("270")
#define ROTATION_315_TEXT QString("315")

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

	auto btmAxis = dynamic_cast<FrgVisual_Plot2DBtmAxis_TItem*>(parentItem);
	auto leftAxis = dynamic_cast<FrgVisual_Plot2DLeftAxis_TItem*>(parentItem);

	if (btmAxis)
	{
		theTitle_ = new ForgBaseLib::FrgBase_PrptsVrntString("Title", thePlot2DTItem_ ? thePlot2DTItem_->GetBottomAxisTitle() : "X Axis");
		theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", thePlot2DTItem_ ? thePlot2DTItem_->GetBottomAxisTitleVisible() : true);
	}
	else if (leftAxis)
	{
		theTitle_ = new ForgBaseLib::FrgBase_PrptsVrntString("Title", thePlot2DTItem_ ? thePlot2DTItem_->GetLeftAxisTitle() : "Y Axis");
		theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", thePlot2DTItem_ ? thePlot2DTItem_->GetLeftAxisTitleVisible() : true);
	}
	else
	{
		theTitle_ = new ForgBaseLib::FrgBase_PrptsVrntString("Title", "");
		theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", true);
	}

	std::vector<QString> items;
	items.push_back(ROTATION_0_TEXT);
	items.push_back(ROTATION_45_TEXT);
	items.push_back(ROTATION_90_TEXT);
	items.push_back(ROTATION_135_TEXT);
	items.push_back(ROTATION_180_TEXT);
	items.push_back(ROTATION_225_TEXT);
	items.push_back(ROTATION_270_TEXT);
	items.push_back(ROTATION_315_TEXT);

	if (btmAxis)
		theRotation_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Rotation", GetRotationFromPlot2DTItem(), "", "degrees");
	else if (leftAxis)
		theRotation_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Rotation", GetRotationFromPlot2DTItem(), "", "degrees");
	else
		theRotation_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Rotation", GetRotationFromPlot2DTItem(), "", "degrees");

	thePropertiesPanel_->AddRow(theVisible_);
	thePropertiesPanel_->AddRow(theTitle_);
	thePropertiesPanel_->AddRow(theRotation_);

	connect(theVisible_, SIGNAL(ValueChangedSignal(const bool&)), this, SLOT(VisibilityChangedSlot(const bool&)));
	connect(theTitle_, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(TitleChangedSlot(const QString&)));
	connect(theRotation_, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(RotationChangedSlot(const QString&)));
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

	if (thePlot2DTItem_)
	{
		if (btmAxis)
			thePlot2DTItem_->SetBottomAxisTitle(title.toStdString().c_str());
		else if (leftAxis)
			thePlot2DTItem_->SetLeftAxisTitle(title.toStdString().c_str());
	}
}

void ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem::RotationChangedSlot(const QString& degreeChar)
{
	auto btmAxis = dynamic_cast<FrgVisual_Plot2DBtmAxis_TItem*>(QTreeWidgetItem::parent());
	auto leftAxis = dynamic_cast<FrgVisual_Plot2DLeftAxis_TItem*>(QTreeWidgetItem::parent());

	int degree = degreeChar.toInt();

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

QString ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem::GetRotationFromPlot2DTItem() const
{
	auto btmAxis = dynamic_cast<FrgVisual_Plot2DBtmAxis_TItem*>(QTreeWidgetItem::parent());
	auto leftAxis = dynamic_cast<FrgVisual_Plot2DLeftAxis_TItem*>(QTreeWidgetItem::parent());

	if (thePlot2DTItem_)
	{
		int myRotation;

		if (btmAxis)
			myRotation = thePlot2DTItem_->GetBottomAxisTitleRotation();
		else if (leftAxis)
			myRotation = thePlot2DTItem_->GetLeftAxisTitleRotation();
		else
			myRotation = 0;

		if (myRotation == 0)
			return ROTATION_0_TEXT;
		else if (myRotation == 45)
			return ROTATION_45_TEXT;
		else if (myRotation == 90)
			return ROTATION_90_TEXT;
		else if (myRotation == 135)
			return ROTATION_135_TEXT;
		else if (myRotation == 180)
			return ROTATION_180_TEXT;
		else if (myRotation == 225)
			return ROTATION_225_TEXT;
		else if (myRotation == 270)
			return ROTATION_270_TEXT;
		else if (myRotation == 315)
			return ROTATION_315_TEXT;
		else
			return ROTATION_0_TEXT;
	}
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)
{

}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)
{

}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)

		ForgVisualLib::FrgVisual_Plot2D_TItem* myPlot2DTItem = t->GetPlot2DTItem();

	ar & myPlot2DTItem;
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)
{
	// ============================================
			// load FrgBase_TreeItem title
			// ============================================
	QString myTItemTitle;;
	ar & myTItemTitle;

	// ============================================
	// load FrgBase_TreeItem parentTItem
	// ============================================
	QString parentTItemIsNull;
	ForgBaseLib::FrgBase_TreeItem* parentTItem;

	ar & parentTItemIsNull;

	if (parentTItemIsNull == "PARENT_TITEM_IS_NULL")
		parentTItem = nullptr;
	else if (parentTItemIsNull == "PARENT_TITEM_IS_NOT_NULL")
		ar & parentTItem;

	// ============================================
	// load FrgBase_TreeItem parentTree
	// ============================================
	QString parentTreeIsNull;
	ForgBaseLib::FrgBase_Tree* parentTree;

	ar & parentTreeIsNull;

	if (parentTreeIsNull == "PARENT_TREE_IS_NULL")
		parentTree = nullptr;
	else if (parentTreeIsNull == "PARENT_TREE_IS_NOT_NULL")
		ar & parentTree;

	// =============================================================
	// invoke inplace constructor to initialize instance of my_class
	// =============================================================
	ForgVisualLib::FrgVisual_Plot2D_TItem* myPlot2DTItem;

	ar & myPlot2DTItem;

	::new(t)ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem(myTItemTitle, parentTItem, parentTree, myPlot2DTItem);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_Plot2DAxisTitle_TItem)