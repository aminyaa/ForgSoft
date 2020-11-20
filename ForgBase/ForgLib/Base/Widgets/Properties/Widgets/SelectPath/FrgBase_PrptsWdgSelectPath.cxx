#include <FrgBase_PrptsWdgSelectPath.hxx>
#include <FrgBase_PrptsVrntSelectPath.hxx>

#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QFileDialog>

ForgBaseLib::FrgBase_PrptsWdgSelectPath::FrgBase_PrptsWdgSelectPath
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: ForgBaseLib::FrgBase_PrptsWdgOneValue<QString, false>(parent, variant)
	, theParent_(parent)
{

}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgSelectPath::FormWidget()\n";
		return;
	}

	const auto& myVariant = dynamic_cast<FrgBase_PrptsVrntSelectPath_Base*>(theVariant_);

	connect(myVariant, SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
	connect(myVariant, SIGNAL(ValueChangedSignal(const QString&)), this, SLOT(ValueChangedSlot(const QString&)));
	connect(myVariant, SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
	connect(myVariant, SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

	QHBoxLayout* myLayout = new QHBoxLayout;
	myLayout->setMargin(0);
	myLayout->setSpacing(0);
	myLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
		myLayout->addWidget(thePrefixLabel_);
	}

	theSelectedPathLabel_ = new QLineEdit(myVariant->GetValue());
	theSelectedPathLabel_->setReadOnly(true);
	theSelectedPathLabel_->setToolTip(theSelectedPathLabel_->text());
	theSelectedPathLabel_->setStyleSheet("QLineEdit { qproperty-cursorPosition: 0; }");
	myLayout->addWidget(theSelectedPathLabel_);

	theButton_ = new QToolButton;
	theButton_->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred));
	theButton_->setText(QLatin1String("..."));

	//myLayout->addStretch(1);
	myLayout->addWidget(theButton_);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myLayout->addWidget(theSuffixLabel_);
	}

	connect(theButton_, SIGNAL(clicked()), this, SLOT(OnButtonClickedSlot()));
	this->setLayout(myLayout);
}

ForgBaseLib::FrgBase_PrptsWdgSelectPath::~FrgBase_PrptsWdgSelectPath()
{

}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::SetValue(const QString& value)
{
	FrgBase_PrptsWdgOneValue::SetValue(value);

	theSelectedPathLabel_->setText(value);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::SetVariant(const FrgBase_PrptsVrntOneValue<QString, false>& variant)
{
	FrgBase_PrptsWdgOneValue::SetVariant(variant);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::ValueChangedSlot(const QString& value)
{
	theSelectedPathLabel_->setText(" " + value);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgSelectPath::OnButtonClickedSlot()
{
	const auto& myVariant = dynamic_cast<FrgBase_PrptsVrntSelectPath_Base*>(theVariant_);
	if (myVariant)
	{
		QFileDialog dialog;
		//dialog.setOption(QFileDialog::DontUseNativeDialog, true);
		dialog.setOption(QFileDialog::DontResolveSymlinks);
		dialog.setNameFilterDetailsVisible(true);
		dialog.setViewMode(QFileDialog::Detail);

		QStringList filters;

		const auto& myVariantFile = dynamic_cast<FrgBase_PrptsVrntSelectPath<PathType::File>*>(theVariant_);
		if (!myVariantFile)
		{

			dialog.setFileMode(QFileDialog::DirectoryOnly);
		}
		else
		{
			if (myVariantFile->IsOpenType())
			{
				dialog.setFileMode(QFileDialog::ExistingFile);
				dialog.setAcceptMode(QFileDialog::AcceptOpen);
			}
			else
			{
				dialog.setFileMode(QFileDialog::AnyFile);
				dialog.setAcceptMode(QFileDialog::AcceptSave);
			}

			const auto& titlesAndFileTypes = myVariantFile->GetTitlesAndFileTypes();
			for (const auto& x : titlesAndFileTypes)
			{
				QString s;

				s += (x.first + " (");
				int i = 0;
				for (const auto& y : x.second)
				{
					s += ("*." + y);
					if (i < x.second.size() - 1)
						s += " ";
					i++;
				}
				s += ")";

				filters << s;
			}
		}

		dialog.setOption(QFileDialog::HideNameFilterDetails, false);
		dialog.setNameFilters(filters);
		int res = dialog.exec();

		if (res)
		{
			theSelectedPathLabel_->setText(dialog.selectedFiles()[0]);
			myVariant->SetValue(dialog.selectedFiles()[0]);

			if (myVariantFile)
			{
				myVariantFile->SetSelectdFileType(dialog.selectedNameFilter());
			}
		}
	}

	theSelectedPathLabel_->setToolTip(theSelectedPathLabel_->text());
	theSelectedPathLabel_->setStyleSheet("QLineEdit { qproperty-cursorPosition: 0; }");
}