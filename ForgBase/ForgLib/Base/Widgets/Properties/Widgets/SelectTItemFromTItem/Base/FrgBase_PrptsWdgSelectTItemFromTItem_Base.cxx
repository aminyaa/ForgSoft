#include <FrgBase_PrptsWdgSelectTItemFromTItem_Base.hxx>
#include <FrgBase_PrptsVrntSelectTItemFromTItem.hxx>
#include <FrgBase_PrptsWdgSelectTItemFromTItem_Dlg.hxx>

#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QToolButton>

ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::FrgBase_PrptsWdgSelectTItemFromTItem_Base
(
	QWidget* parent /*= nullptr*/,
	FrgBase_PrptsVrnt* variant /*= nullptr */
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
	, theParent_(parent)
{

}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgInt::FormWidget()\n";
		return;
	}

	const auto& myVariant = dynamic_cast<FrgBase_PrptsVrntSelectTItemFromTItem_Base*>(theVariant_);
	if (myVariant)
	{
		connect(myVariant, SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
		connect(myVariant, SIGNAL(ValueChangedSignal(FrgBase_TreeItem*)), this, SLOT(ValueChangedSlot(FrgBase_TreeItem*)));
		connect(myVariant, SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
		connect(myVariant, SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));
	}

	QHBoxLayout* myLayout = new QHBoxLayout;
	myLayout->setMargin(0);
	myLayout->setSpacing(0);
	myLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
		myLayout->addWidget(thePrefixLabel_);
	}

	theSelectedTItemLabel_ = new QLabel("");
	myLayout->addWidget(theSelectedTItemLabel_);

	if (myVariant)
	{
		if (myVariant->GetValue())
		{
			theSelectedTItemLabel_->setText(myVariant->GetValue()->text(0));
		}
	}

	theButton_ = new QToolButton;
	theButton_->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred));
	theButton_->setText(QLatin1String("..."));

	myLayout->addStretch(1);
	myLayout->addWidget(theButton_);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	connect(theButton_, SIGNAL(clicked()), this, SLOT(OnButtonClickedSlot()));
	this->setLayout(myLayout);
}

ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::~FrgBase_PrptsWdgSelectTItemFromTItem_Base()
{

}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::SetValue(FrgBase_TreeItem* const& value)
{
	FrgBase_PrptsWdgOneValue::SetValue(value);

	theSelectedTItemLabel_->setText(value->text(0));
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::SetVariant(const FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false>& variant)
{
	FrgBase_PrptsWdgOneValue::SetVariant(variant);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::ValueChangedSlot(FrgBase_TreeItem* item)
{
	if (!item)
	{
		theSelectedTItemLabel_->setText("");

		return;
	}

	theSelectedTItemLabel_->setText(" " + item->text(0));

	connect(item, SIGNAL(TItemNameChanged(const QString&)), theSelectedTItemLabel_, SLOT(setText(const QString&)));
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItemFromTItem_Base::OnButtonClickedSlot()
{
	OnButtonClicked();
}