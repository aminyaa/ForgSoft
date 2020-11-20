#include <FrgBase_PrptsWdgSelectTItems.hxx>
#include <FrgBase_PrptsVrntSelectTItems.hxx>
#include <FrgBase_TreeItem.hxx>
#include <FrgBase_PrptsWdgSelectTItems_Dlg.hxx>

#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QToolButton>
#include <QtCore/QObject>

ForgBaseLib::FrgBase_PrptsWdgSelectTItems::FrgBase_PrptsWdgSelectTItems
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdgOneValue(parent, variant)
{
	
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgInt::FormWidget()\n";
		return;
	}

	connect(dynamic_cast<FrgBase_PrptsVrntSelectTItems*>(theVariant_), SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntSelectTItems*>(theVariant_), SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
	connect(dynamic_cast<FrgBase_PrptsVrntSelectTItems*>(theVariant_), SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

	QHBoxLayout* myLayout = new QHBoxLayout;
	myLayout->setMargin(0);
	myLayout->setSpacing(0);
	myLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
		myLayout->addWidget(thePrefixLabel_);
	}

	theListOfSelectedTItemsLabel_ = new QLabel("");
	myLayout->addWidget(theListOfSelectedTItemsLabel_);

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

ForgBaseLib::FrgBase_PrptsWdgSelectTItems::~FrgBase_PrptsWdgSelectTItems()
{

}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems::SetValue(FrgBase_TreeItem* const & value)
{
	FrgBase_PrptsWdgOneValue::SetValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems::SetVariant(const FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false> & variant)
{
	FrgBase_PrptsWdgOneValue::SetVariant(variant);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectTItems::OnButtonClickedSlot()
{

	std::shared_ptr<FrgBase_PrptsWdgSelectTItems_Dlg> selectTItemsDlg = std::make_shared<FrgBase_PrptsWdgSelectTItems_Dlg>
		(
			"Select Items",
			dynamic_cast<FrgBase_PrptsVrntSelectTItems*>(theVariant_)->GetValue()->GetParentMainWindow(),
			dynamic_cast<FrgBase_PrptsVrntSelectTItems*>(theVariant_)->GetValue(),
			dynamic_cast<FrgBase_PrptsVrntSelectTItems*>(theVariant_)->GetSelectedTItems()
			);

	if (selectTItemsDlg->exec() == QDialog::Accepted)
	{
		auto myVariant = dynamic_cast<FrgBase_PrptsVrntSelectTItems*>(theVariant_);
		if (!myVariant)
		{
			std::cout << "theVariant_ is not a type of FrgBase_PrptsVrntSelectTItems* in ForgBaseLib::FrgBase_PrptsWdgSelectTItems::OnButtonClickedSlot()\n";
			return;
		}

		myVariant->SetSelectedTItems(selectTItemsDlg->GetListOfSelectedTItems());

		QString strList = "";
		if (selectTItemsDlg->GetListOfSelectedTItems().size() > 0)
		{
			for (int i = 0; i < selectTItemsDlg->GetListOfSelectedTItems().size() - 1; i++)
				strList += (selectTItemsDlg->GetListOfSelectedTItems()[i]->text(0) + " | ");
			strList += selectTItemsDlg->GetListOfSelectedTItems()[selectTItemsDlg->GetListOfSelectedTItems().size() - 1]->text(0);
		}
		theListOfSelectedTItemsLabel_->setText(strList);
	}
}