#include <FrgBase_PrptsWdgField.hxx>
#include <FrgBase_ToolsParameter_TItem.hxx>
#include <FrgBase_ToolsParameters_TItem.hxx>
#include <FrgBase_PrptsWdgFieldDialog.hxx>
#include <FrgBase_PrptsWdgFieldScalar.hxx>
#include <FrgBase_PrptsWdgFieldVector.hxx>
#include <FrgBase_PrptsVrntFieldScalar.hxx>
#include <FrgBase_PrptsVrntFieldVector.hxx>

#include <QtWidgets/QToolButton>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_PrptsWdgField::FrgBase_PrptsWdgField
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: ForgBaseLib::FrgBase_PrptsWdgStringDouble(parent, variant)
{

}

ForgBaseLib::FrgBase_PrptsWdgField::~FrgBase_PrptsWdgField()
{

}

void ForgBaseLib::FrgBase_PrptsWdgField::FormWidget()
{
	if (!theSymbolTableT_)
	{
		auto myParentTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(GetParentTItem());
		if (myParentTItem)
		{
			auto symbolTableT = myParentTItem->GetSymbolTableT();
			if (symbolTableT)
			{
				theSymbolTableT_ = symbolTableT;
			}
		}
	}

	FrgBase_PrptsWdgStringDouble::FormWidget();

	theButton_ = new QToolButton;
	theButton_->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred));
	theButton_->setText(QLatin1String("..."));

	this->layout()->addWidget(theButton_);

	auto scalarVariant = dynamic_cast<FrgBase_PrptsVrntFieldScalar*>(GetVariantBasePtr());
	auto vectorVariant = dynamic_cast<FrgBase_PrptsVrntFieldVector*>(GetVariantBasePtr());

	if (scalarVariant)
	{
		connect(scalarVariant, SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
		connect(scalarVariant, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(ValueChangedSlot(const double&)));
		connect(scalarVariant, SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
		connect(scalarVariant, SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));
	}
	else if (vectorVariant)
	{
		connect(vectorVariant, SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
		connect(vectorVariant, SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
		connect(vectorVariant, SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

		auto vectorWidget = dynamic_cast<FrgBase_PrptsWdgFieldVector*>(this);
		if (vectorWidget)
		{
			connect(vectorVariant, &FrgBase_PrptsVrntFieldVector::ValueChangedSignal, vectorWidget, &FrgBase_PrptsWdgFieldVector::ValueChangedSlot);

			emit vectorVariant->ValueChangedSignal(vectorVariant->GetValue());
		}
	}

	connect(theButton_, SIGNAL(clicked()), this, SLOT(ButtonClickedSlot()));

	theValueString_ = theLineEdit_->text();
}

void ForgBaseLib::FrgBase_PrptsWdgField::ButtonClickedSlot()
{
	std::vector<double> values;

	auto scalarVariant = dynamic_cast<FrgBase_PrptsVrntFieldScalar*>(GetVariantBasePtr());
	auto vectorVariant = dynamic_cast<FrgBase_PrptsVrntFieldVector*>(GetVariantBasePtr());
	if (scalarVariant)
		values.push_back(scalarVariant->GetValue());
	else if (vectorVariant)
		values = vectorVariant->GetValue();

	std::shared_ptr<FrgBase_PrptsWdgFieldDialog> dialog = std::make_shared<FrgBase_PrptsWdgFieldDialog>(this, Qt::Window | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);
	dialog->SetSymbolTableT(theSymbolTableT_);
	dialog->SetValues(values);
	dialog->FormWidget();

	if (dialog->exec())
	{
		//theLineEdit_->setEnabled(false);
		SetLineEditValueForPreview();
		UpdateAllParameters();
	}
}

void ForgBaseLib::FrgBase_PrptsWdgField::SetLineEditValueForPreview()
{
	auto vectorVariant = dynamic_cast<FrgBase_PrptsVrntFieldVector*>(GetVariantBasePtr());
	if (vectorVariant)
	{
		auto values = vectorVariant->GetValue();
		QString output;

		int iter = 0;
		for (const auto& x : values)
		{
			if (iter == 0)
				output += ("[" + QString::number(x) + ", ");
			else if (iter == values.size() - 1)
				output += (QString::number(x) + "]");
			else
				output += (QString::number(x) + ", ");

			iter++;
		}

		theLineEdit_->setText(output);
	}
}

void ForgBaseLib::FrgBase_PrptsWdgField::UpdateAllParameters() const
{
	auto parentTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(GetParentTItem());
	if (parentTItem)
	{
		auto toolsParametersTItem = parentTItem->GetParentToolsParametersTItem();
		if (toolsParametersTItem)
		{
			parentTItem->RemoveAllDependentParameters();
			QString strForTest = theValueString_;
			if (strForTest.size() > 2 && strForTest.at(0) == '[' && strForTest.at(strForTest.size() - 1) == ']')
			{
				strForTest = "return " + strForTest;
			}
			std::vector<std::string> variable_list;
			if (exprtk::collect_variables(strForTest.toStdString(), variable_list))
			{
				for (const auto& var : variable_list)
					parentTItem->AddDependentParameter(toolsParametersTItem->GetParamaterTItem(QString::fromStdString(var)));
			}
			/*const auto& myChildren = toolsParametersTItem->GetAllChildrenToTheRoot();
			for (const auto& myChild : myChildren)
			{
				const auto& parameterTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(myChild);
				if (parameterTItem)
				{
					if (theValueString_.contains(parameterTItem->GetVariableName()))
					{
						if (parentTItem->GetVariableName() == parameterTItem->GetVariableName())
							continue;

						parentTItem->AddDependentParameter(parameterTItem);
					}
				}
			}*/

			toolsParametersTItem->UpdateAllParameters();
		}
	}
}

bool ForgBaseLib::FrgBase_PrptsWdgField::IsButtonHidden() const
{
	return theButton_->isHidden();
}

bool ForgBaseLib::FrgBase_PrptsWdgField::eventFilter(QObject* watched, QEvent* event)
{
	bool result = FrgBase_PrptsWdgStringDouble::eventFilter(watched, event);

	if (result)
	{
		theValueString_ = theLineEdit_->text();

		UpdateAllParameters();

		return true;
	}

	return result;
}

void ForgBaseLib::FrgBase_PrptsWdgField::SetButtonHidden(bool condition)
{
	if (theButton_)
	{
		theButton_->setHidden(condition);
	}
}