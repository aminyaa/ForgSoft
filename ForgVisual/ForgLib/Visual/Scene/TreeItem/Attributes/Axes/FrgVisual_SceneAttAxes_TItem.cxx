#include <FrgVisual_SceneAttAxes_TItem.hxx>

#include <FrgBase_PropertiesPanel.hxx>

ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity::FrgVisual_SceneAttAxes_TItem_Entity
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}

void ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();
}

template <int Dim>
ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>::FrgVisual_SceneAttAxes_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_SceneAttAxes_TItem_Entity(itemTitle, parentItem, parentTree)
{

}

template <int Dim>
void ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>::FormTItem()
{
	FrgVisual_SceneAttAxes_TItem_Entity::FormTItem();

	theTextColor_ = new ForgBaseLib::FrgBase_PrptsVrntColor("Text Color", QColor(255, 255, 255));
	theVisible_ = new ForgBaseLib::FrgBase_PrptsVrntBool("Visible", true);
	theXLabel_ = new ForgBaseLib::FrgBase_PrptsVrntString("Axis 1 Label", "X");
	theYLabel_ = new ForgBaseLib::FrgBase_PrptsVrntString("Axis 2 Label", "Y");
	theZLabel_ = new ForgBaseLib::FrgBase_PrptsVrntString("Axis 3 Label", "Z");

	thePropertiesPanel_->AddRow(theTextColor_);
	thePropertiesPanel_->AddRow(theVisible_);
	thePropertiesPanel_->AddRow(theXLabel_);
	thePropertiesPanel_->AddRow(theYLabel_);
	thePropertiesPanel_->AddRow(theZLabel_);

	connect(theTextColor_, SIGNAL(ValueChangedSignal(const QColor&)), this, SIGNAL(TextColorChangedSignal(const QColor&)));
	connect(theVisible_, SIGNAL(ValueChangedSignal(const bool&)), this, SIGNAL(VisibleChangedSignal(const bool&)));
	connect(theXLabel_, SIGNAL(ValueChangedSignal(const QString&)), this, SIGNAL(XLabelChangedSignal(const QString&)));
	connect(theYLabel_, SIGNAL(ValueChangedSignal(const QString&)), this, SIGNAL(YLabelChangedSignal(const QString&)));
	connect(theZLabel_, SIGNAL(ValueChangedSignal(const QString&)), this, SIGNAL(ZLabelChangedSignal(const QString&)));
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity);
}

template <int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_SceneAttAxes_TItem_Entity>(*this);

	ar& theTextColor_;
	ar& theVisible_;
	ar& theXLabel_;
	ar& theYLabel_;
	ar& theZLabel_;
}

template <int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>)
{
	ar& boost::serialization::base_object<FrgVisual_SceneAttAxes_TItem_Entity>(*this);

	ar& theTextColor_;
	ar& theVisible_;
	ar& theXLabel_;
	ar& theYLabel_;
	ar& theZLabel_;

	thePropertiesPanel_->AddRow(theTextColor_);
	thePropertiesPanel_->AddRow(theVisible_);
	thePropertiesPanel_->AddRow(theXLabel_);
	thePropertiesPanel_->AddRow(theYLabel_);
	thePropertiesPanel_->AddRow(theZLabel_);

	connect(theTextColor_, SIGNAL(ValueChangedSignal(const QColor&)), this, SIGNAL(TextColorChangedSignal(const QColor&)));
	connect(theVisible_, SIGNAL(ValueChangedSignal(const bool&)), this, SIGNAL(VisibleChangedSignal(const bool&)));
	connect(theXLabel_, SIGNAL(ValueChangedSignal(const QString&)), this, SIGNAL(XLabelChangedSignal(const QString&)));
	connect(theYLabel_, SIGNAL(ValueChangedSignal(const QString&)), this, SIGNAL(YLabelChangedSignal(const QString&)));
	connect(theZLabel_, SIGNAL(ValueChangedSignal(const QString&)), this, SIGNAL(ZLabelChangedSignal(const QString&)));

	emit theTextColor_->ValueChangedSignal(theTextColor_->GetValue());
	emit theVisible_->ValueChangedSignal(theVisible_->GetValue());
	emit theXLabel_->ValueChangedSignal(theXLabel_->GetValue());
	emit theYLabel_->ValueChangedSignal(theYLabel_->GetValue());
	emit theZLabel_->ValueChangedSignal(theZLabel_->GetValue());
}

template<class Archive, int Dim>
void boost::serialization::save_construct_data
(
	Archive& ar,
	const ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>* t,
	const unsigned int version
)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>);
}

template<class Archive, int Dim>
void boost::serialization::load_construct_data
(
	Archive& ar,
	ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>* t,
	const unsigned int version
)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttAxes_TItem<Dim>);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttAxes_TItem_Entity)

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttAxes_TItem<2>)
BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttAxes_TItem<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SceneAttAxes_TItem<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SceneAttAxes_TItem<3>;