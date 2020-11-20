#include <FrgVisual_SceneAttBackColorGradient_TItem.hxx>

#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem::FrgVisual_SceneAttBackColorGradient_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}

void ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem::FormTItem()
{
	std::vector<QString> items;
	items.push_back("Top-Bottom");
	items.push_back("Bottom-Top");
	items.push_back("Left-Right");
	items.push_back("Right-Left");
	items.push_back("Radial");
	theMode_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Gradient Mode", items[0]);

	theColor1_ = new ForgBaseLib::FrgBase_PrptsVrntColor("Color 1", QColor(255, 255, 255));
	theColor2_ = new ForgBaseLib::FrgBase_PrptsVrntColor("Color 2", QColor(180, 180, 180));

	connect(theMode_, SIGNAL(ValueChangedSignal(const QString&)), this, SIGNAL(ModeChangedSignal(const QString&)));
	connect(theColor1_, SIGNAL(ValueChangedSignal(const QColor&)), this, SIGNAL(Color1ChangedSignal(const QColor&)));
	connect(theColor2_, SIGNAL(ValueChangedSignal(const QColor&)), this, SIGNAL(Color2ChangedSignal(const QColor&)));

	thePropertiesPanel_->AddRow(theMode_);
	thePropertiesPanel_->AddRow(theColor1_);
	thePropertiesPanel_->AddRow(theColor2_);
}

const QString& ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem::GetMode() const
{
	if(theMode_)
		return theMode_->GetValue();

	return "";
}

const QColor& ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem::GetColor1() const
{
	if (theColor1_)
		return theColor1_->GetValue();

	return QColor(255, 255, 255);
}

const QColor& ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem::GetColor2() const
{
	if (theColor2_)
		return theColor2_->GetValue();

	return QColor(255, 255, 255);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theMode_;
	ar& theColor1_;
	ar& theColor2_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theMode_;
	ar& theColor1_;
	ar& theColor2_;

	connect(theMode_, SIGNAL(ValueChangedSignal(const QString&)), this, SIGNAL(ModeChangedSignal(const QString&)));
	connect(theColor1_, SIGNAL(ValueChangedSignal(const QColor&)), this, SIGNAL(Color1ChangedSignal(const QColor&)));
	connect(theColor2_, SIGNAL(ValueChangedSignal(const QColor&)), this, SIGNAL(Color2ChangedSignal(const QColor&)));

	thePropertiesPanel_->AddRow(theMode_);
	thePropertiesPanel_->AddRow(theColor1_);
	thePropertiesPanel_->AddRow(theColor2_);
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColorGradient_TItem)