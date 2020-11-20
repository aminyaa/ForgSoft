#include <FrgVisual_SceneAttBackColor_TItem.hxx>

#include <FrgBase_PropertiesPanel.hxx>
#include <FrgVisual_SceneAttBackColorGradient_TItem.hxx>
#include <FrgVisual_SceneAttBackColorSolid_TItem.hxx>

#include <FrgBase_Tree.hxx>

ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity::FrgVisual_SceneAttBackColor_TItem_Entity
(
	const QString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{

}

void ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();
}

template <int Dim>
ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>::FrgVisual_SceneAttBackColor_TItem
(
	const FrgString& itemTitle,
	ForgBaseLib::FrgBase_TreeItem* parentItem,
	ForgBaseLib::FrgBase_Tree* parentTree
)
	: FrgVisual_SceneAttBackColor_TItem_Entity(itemTitle, parentItem, parentTree)
{

}

template <int Dim>
void ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>::FormTItem()
{
	FrgVisual_SceneAttBackColor_TItem_Entity::FormTItem();

	std::vector<QString> items;
	items.push_back("Solid");
	items.push_back("Gradient");

	if constexpr (Dim == 2)
		theBackgroundColorMode_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Background Color Mode", items[0]);
	else if constexpr (Dim == 3)
		theBackgroundColorMode_ = new ForgBaseLib::FrgBase_PrptsVrntCombo(items, "Background Color Mode", items[1]);

	thePropertiesPanel_->AddRow(theBackgroundColorMode_);

	connect(theBackgroundColorMode_, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(BackgroundColorModeChangedSlot(const QString&)));

	theSolidBackground_ = new FrgVisual_SceneAttBackColorSolid_TItem("Solid Background", this, GetParentTree());
	theSolidBackground_->FormTItem();

	theGradientBackground_ = new FrgVisual_SceneAttBackColorGradient_TItem("Gradient Background", this, GetParentTree());
	theGradientBackground_->FormTItem();

	connect(theSolidBackground_, SIGNAL(ColorChangedSignal(const QColor&)), this, SIGNAL(SolidColorChangedSignal(const QColor&)));
	connect(theGradientBackground_, SIGNAL(ModeChangedSignal(const QString&)), this, SIGNAL(GradientModeChangedSignal(const QString&)));
	connect(theGradientBackground_, SIGNAL(Color1ChangedSignal(const QColor&)), this, SIGNAL(GradientColor1ChangedSignal(const QColor&)));
	connect(theGradientBackground_, SIGNAL(Color2ChangedSignal(const QColor&)), this, SIGNAL(GradientColor2ChangedSignal(const QColor&)));

	emit theBackgroundColorMode_->ValueChangedSignal(theBackgroundColorMode_->GetValue());
}

template <int Dim>
void ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>::BackgroundColorModeChangedSlot(const QString& item)
{
	if (item == "Solid")
	{
		this->removeChild(theGradientBackground_);
		this->addChild(theSolidBackground_);

		emit theSolidBackground_->ColorChangedSignal(theSolidBackground_->GetColor());
	}
	else if (item == "Gradient")
	{
		this->removeChild(theSolidBackground_);
		this->addChild(theGradientBackground_);

		emit theGradientBackground_->ModeChangedSignal(theGradientBackground_->GetMode());
		emit theGradientBackground_->Color1ChangedSignal(theGradientBackground_->GetColor1());
		emit theGradientBackground_->Color2ChangedSignal(theGradientBackground_->GetColor2());
	}
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity);
}

template <int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theBackgroundColorMode_;
	ar& theSolidBackground_;
	ar& theGradientBackground_;
}

template <int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	ar& theBackgroundColorMode_;
	ar& theSolidBackground_;
	ar& theGradientBackground_;

	thePropertiesPanel_->AddRow(theBackgroundColorMode_);

	connect(theBackgroundColorMode_, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(BackgroundColorModeChangedSlot(const QString&)));

	connect(theSolidBackground_, SIGNAL(ColorChangedSignal(const QColor&)), this, SIGNAL(SolidColorChangedSignal(const QColor&)));
	connect(theGradientBackground_, SIGNAL(ModeChangedSignal(const QString&)), this, SIGNAL(GradientModeChangedSignal(const QString&)));
	connect(theGradientBackground_, SIGNAL(Color1ChangedSignal(const QColor&)), this, SIGNAL(GradientColor1ChangedSignal(const QColor&)));
	connect(theGradientBackground_, SIGNAL(Color2ChangedSignal(const QColor&)), this, SIGNAL(GradientColor2ChangedSignal(const QColor&)));
}

template<class Archive, int Dim>
void boost::serialization::save_construct_data
(
	Archive& ar,
	const ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>* t,
	const unsigned int version
)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>);
}

template<class Archive, int Dim>
void boost::serialization::load_construct_data
(
	Archive& ar,
	ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>* t,
	const unsigned int version
)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<Dim>);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem_Entity)

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<2>)
BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_SceneAttBackColor_TItem<3>;