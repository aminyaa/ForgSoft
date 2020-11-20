#include <FrgVisual_SceneAttBackColorSolid_TItem.hxx>

#include <FrgBase_PropertiesPanel.hxx>

#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem::FrgVisual_SceneAttBackColorSolid_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}

void ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem::FormTItem()
{
	theColor_ = new ForgBaseLib::FrgBase_PrptsVrntColor("Color", QColor(255, 255, 255));

	connect(theColor_, SIGNAL(ValueChangedSignal(const QColor&)), this, SIGNAL(ColorChangedSignal(const QColor&)));

	thePropertiesPanel_->AddRow(theColor_);
}

const QColor& ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem::GetColor() const
{
	if (theColor_)
		return theColor_->GetValue();

	return QColor(255, 255, 255);
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theColor_;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theColor_;

	connect(theColor_, SIGNAL(ValueChangedSignal(const QColor&)), this, SIGNAL(ColorChangedSignal(const QColor&)));

	thePropertiesPanel_->AddRow(theColor_);
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColorSolid_TItem)