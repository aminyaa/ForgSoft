#include <FrgBase_PrptsWdgStringDouble.hxx>
#include <FrgBase_PrptsVrntStringDouble.hxx>
#include <FrgBase_PrptsVrntFieldVector.hxx>
#include <FrgBase_PrptsVrntFieldScalar.hxx>
#include <FrgBase_PrptsWdgField.hxx>
#include <FrgBase_ToolsParameter_TItem.hxx>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QRegExpValidator>
#include <QtCore/QEvent>
#include <QtGui/QKeyEvent>
#include <QtCore/QTimer>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_PrptsWdgStringDouble::FrgBase_PrptsWdgStringDouble
(
	QWidget* parent,
	FrgBase_PrptsVrnt* variant
)
	: FrgBase_PrptsWdgOneValue<double, false>(parent, variant)
{

}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::FormWidget()
{
	if (!theVariant_)
	{
		std::cout << "theVariant_ is null in ForgBaseLib::FrgBase_PrptsWdgPnt2d::FormWidget()\n";
		return;
	}

	auto myVariant = dynamic_cast<FrgBase_PrptsVrntStringDouble*>(theVariant_);
	if (myVariant)
	{
		/*std::cout << "myVariant is not the type of ForgBaseLib::FrgBase_PrptsVrntStringDouble\n";
		return;*/

		connect(myVariant, SIGNAL(DisplayNameChangedSignal(const QString&)), this, SLOT(DisplayNameChangedSlot(const QString&)));
		connect(myVariant, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(ValueChangedSlot(const double&)));
		connect(myVariant, SIGNAL(PrefixChangedSignal(const QString&)), this, SLOT(PrefixChangedSlot(const QString&)));
		connect(myVariant, SIGNAL(SuffixChangedSignal(const QString&)), this, SLOT(SuffixChangedSlot(const QString&)));

		connect(myVariant, SIGNAL(LimitedChangedSignal(const bool&)), this, SLOT(LimitedChangedSlot(const bool&)));
		connect(myVariant, SIGNAL(MinimumValueChangedSignal(const double&)), this, SLOT(MinimumValueChangedSlot(const double&)));
		connect(myVariant, SIGNAL(MaximumValueChangedSignal(const double&)), this, SLOT(MaximumValueChangedSlot(const double&)));
	}

	QHBoxLayout* myHLayout = new QHBoxLayout;

	myHLayout->setMargin(0);
	myHLayout->setSpacing(0);
	myHLayout->setContentsMargins(0, 2, 0, 2);

	if (GetPrefix() != "")
	{
		SetPrefix(GetPrefix());
		myHLayout->addWidget(thePrefixLabel_);
	}

	theLineEdit_ = new QLineEdit;
	theLineEdit_->setText(QString::number(GetValue(), 'G'));
	theLineEdit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	theLineEdit_->setMinimumWidth(70);

	if (myVariant)
	{
		theDoubleValidator_ = new QDoubleValidator(theLineEdit_);
		if (myVariant)
		{
			if (myVariant->IsLimited())
			{
				theDoubleValidator_->setBottom(myVariant->GetMinimumValue());
				theDoubleValidator_->setTop(myVariant->GetMaximumValue());
			}
		}

		theLineEdit_->setValidator(theDoubleValidator_);
	}

	theLineEdit_->installEventFilter(this);

	myHLayout->addWidget(theLineEdit_);

	if (GetSuffix() != "")
	{
		SetSuffix(GetSuffix());
		myHLayout->addWidget(theSuffixLabel_);
	}

	this->setLayout(myHLayout);

	connect(this, SIGNAL(EditingFinishedSignal()), this, SLOT(WdgValueChangedSlot()));
}

ForgBaseLib::FrgBase_PrptsWdgStringDouble::~FrgBase_PrptsWdgStringDouble()
{
	FreePointer(thePrefixLabel_);
	FreePointer(theSuffixLabel_);
	FreePointer(theLineEdit_);
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::SetValue(const double& value)
{
	FrgBase_PrptsWdgOneValue::SetValue(value);
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::SetPrefix(const QString& prefix)
{
	FrgBase_PrptsWdgOneValue::SetPrefix(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::SetSuffix(const QString& suffix)
{
	FrgBase_PrptsWdgOneValue::SetSuffix(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::SetVariant(const ForgBaseLib::FrgBase_PrptsVrntOneValue<double, false>& variant)
{
	FrgBase_PrptsWdgOneValue::SetVariant(variant);
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::DisplayNameChangedSlot(const QString& displayName)
{

}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::ValueChangedSlot(const double& value)
{
	if (theLineEdit_->text().toDouble() != value)
	{
		auto myVariant = dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntOneValue<double, false>*>(theVariant_);
		if (myVariant)
		{
			auto myStringDoubleVariant = dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntStringDouble*>(theVariant_);
			if (myStringDoubleVariant)
			{
				if (myStringDoubleVariant->IsLimited())
				{
					if (value < myStringDoubleVariant->GetMinimumValue() || value > myStringDoubleVariant->GetMaximumValue())
					{
						myStringDoubleVariant->SetValue(theLineEdit_->text().toDouble());

						return;
					}
				}
			}

			theLineEdit_->setText(QString::number(value, 'G'));
		}

		auto myVectorVariant =
			dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntFieldVector*>(theVariant_);
		if (myVectorVariant)
		{
			auto values = myVectorVariant->GetValue();
			QString output;

			int iter = 0;
			for (const auto& x : values)
			{
				if (iter == 0)
					output += ("[" + QString::number(x, 'G') + ", ");
				else if (iter == values.size() - 1)
					output += (QString::number(x, 'G') + "]");
				else
					output += (QString::number(x, 'G') + ", ");

				iter++;
			}

			theLineEdit_->setText(output);
		}

		auto parentParameterTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(GetParentTItem());
		if (parentParameterTItem)
			parentParameterTItem->RemoveAllDependentParameters();
	}
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::PrefixChangedSlot(const QString& prefix)
{
	if (!thePrefixLabel_)
		thePrefixLabel_ = new QLabel(prefix + " ");
	else
		thePrefixLabel_->setText(prefix);
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::SuffixChangedSlot(const QString& suffix)
{
	if (!theSuffixLabel_)
		theSuffixLabel_ = new QLabel(" " + suffix);
	else
		theSuffixLabel_->setText(suffix);
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::WdgValueChangedSlot()
{
	auto myVariant = dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntOneValue<double, false>*>(theVariant_);
	if (myVariant)
	{
		double value = myVariant->GetValue();

		auto myStringDoubleVariant = dynamic_cast<FrgBase_PrptsVrntStringDouble*>(theVariant_);
		if (myStringDoubleVariant)
		{
			if (myStringDoubleVariant->IsLimited())
			{
				if
					(
						theLineEdit_->text().toDouble() < myStringDoubleVariant->GetMinimumValue()
						|| theLineEdit_->text().toDouble() > myStringDoubleVariant->GetMaximumValue()
						)
				{
					theLineEdit_->setText(QString::number(value, 'G'));

					theLineEdit_->blockSignals(true);
					theLineEdit_->clearFocus();
					theLineEdit_->blockSignals(false);

					return;
				}
			}
		}

		double outputValue = 0.0;

		auto myScalarVariant = dynamic_cast<FrgBase_PrptsVrntFieldScalar*>(theVariant_);
		if (myScalarVariant)
		{
			auto parentParameterTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(GetParentTItem());
			if (parentParameterTItem)
			{
				exprtk::expression<double> myExpression;
				myExpression.register_symbol_table(*parentParameterTItem->GetSymbolTableT());

				exprtk::parser<double> myParser;
				bool compiled = myParser.compile((theLineEdit_->text()).toStdString(), myExpression);

				if (compiled)
				{
					outputValue = myExpression.value();

					auto myScalarWidget = dynamic_cast<FrgBase_PrptsWdgField*>(this);
					if (myScalarWidget)
						myScalarWidget->SetValueString(theLineEdit_->text());

					parentParameterTItem->RemoveAllDependentParameters();
				}
				else
					outputValue = myVariant->GetValue();
			}
		}
		else
			outputValue = theLineEdit_->text().toDouble();

		if (myStringDoubleVariant)
			disconnect(myStringDoubleVariant, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(ValueChangedSlot(const double&)));

		myVariant->SetValue(outputValue);

		if (myStringDoubleVariant)
			connect(myStringDoubleVariant, SIGNAL(ValueChangedSignal(const double&)), this, SLOT(ValueChangedSlot(const double&)));

		theLineEdit_->blockSignals(true);
		theLineEdit_->setText(QString::number(theLineEdit_->text().toDouble(), 'G'));
		theLineEdit_->clearFocus();
		theLineEdit_->blockSignals(false);

	}

	auto myVectorVariant =
		dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntFieldVector*>(theVariant_);
	if (myVectorVariant)
	{
		auto values = myVectorVariant->GetValue();
		QString output;

		int iter = 0;
		for (const auto& x : values)
		{
			if (iter == 0)
				output += ("[" + QString::number(x, 'G') + ", ");
			else if (iter == values.size() - 1)
				output += (QString::number(x, 'G') + "]");
			else
				output += (QString::number(x, 'G') + ", ");

			iter++;
		}

		auto parentParameterTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(GetParentTItem());
		if (parentParameterTItem)
		{
			if (myVectorVariant)
				myVectorVariant->blockSignals(true);

			exprtk::expression<double> myExpression;
			myExpression.register_symbol_table(*parentParameterTItem->GetSymbolTableT());

			exprtk::parser<double> myParser;
			bool compiled = myParser.compile(("return " + theLineEdit_->text()).toStdString(), myExpression);

			if (compiled)
			{
				myExpression.value();
				auto results = myExpression.results();
				std::vector<double>& values = myVectorVariant->GetValueRef();

				bool areValuesNumber = true;
				for (std::size_t iter = 0; iter < results.count(); iter++)
				{
					auto t = results[iter];

					if (t.type == exprtk::type_store<double>::e_scalar)
					{
						auto value = exprtk::results_context<double>::type_store_t::scalar_view(t);
						if (std::isinf(value()) || std::isnan(value()))
						{
							areValuesNumber = false;
							break;
						}
					}
				}

				if (areValuesNumber)
				{
					for (std::size_t iter = 0; iter < results.count(); iter++)
					{
						auto t = results[iter];
						if (t.type == exprtk::type_store<double>::e_scalar)
						{
							auto value = exprtk::results_context<double>::type_store_t::scalar_view(t);
							values[iter] = value();
						}
					}
				}

				auto myVectorWidget = dynamic_cast<FrgBase_PrptsWdgField*>(this);
				if (myVectorWidget)
					myVectorWidget->SetValueString(theLineEdit_->text());

				if (myVectorVariant)
					myVectorVariant->blockSignals(false);

				auto newValues = myVectorVariant->GetValue();

				output = "";
				int iter = 0;
				for (const auto& x : newValues)
				{
					if (iter == 0)
						output += ("[" + QString::number(x, 'G') + ", ");
					else if (iter == newValues.size() - 1)
						output += (QString::number(x, 'G') + "]");
					else
						output += (QString::number(x, 'G') + ", ");

					iter++;
				}

				parentParameterTItem->RemoveAllDependentParameters();
			}
		}

		theLineEdit_->blockSignals(true);
		theLineEdit_->setText(output);
		theLineEdit_->clearFocus();
		theLineEdit_->blockSignals(false);
	}
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::LimitedChangedSlot(const bool& limited)
{
	if (theLineEdit_ && theDoubleValidator_)
	{
		auto myVariant = dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntStringDouble*>(theVariant_);
		if (myVariant)
		{
			if (myVariant->IsLimited() == limited)
				return;

			if (limited)
			{
				double myValue = myVariant->GetValue();
				double min = myVariant->GetMinimumValue();
				double max = myVariant->GetMaximumValue();

				if (myValue <= min)
					min = myValue;
				else if (myValue >= max)
					max = myValue;

				theDoubleValidator_->setBottom(min);
				theDoubleValidator_->setTop(max);
			}
			else
			{
				delete theDoubleValidator_;
				theDoubleValidator_ = nullptr;

				theDoubleValidator_ = new QDoubleValidator(theLineEdit_);
			}
		}

	}
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::MinimumValueChangedSlot(const double& minimumValue)
{
	if (theLineEdit_ && theDoubleValidator_)
	{
		auto myVariant = dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntStringDouble*>(theVariant_);
		if (myVariant)
		{
			if (!myVariant->IsLimited())
				return;

			if (myVariant->GetValue() < minimumValue)
				myVariant->SetValue(minimumValue);

			theDoubleValidator_->setBottom(minimumValue);
		}
	}
}

void ForgBaseLib::FrgBase_PrptsWdgStringDouble::MaximumValueChangedSlot(const double& maximumValue)
{
	if (theLineEdit_ && theDoubleValidator_)
	{
		auto myVariant = dynamic_cast<ForgBaseLib::FrgBase_PrptsVrntStringDouble*>(theVariant_);
		if (myVariant)
		{
			if (!myVariant->IsLimited())
				return;

			if (myVariant->GetValue() > maximumValue)
				myVariant->SetValue(maximumValue);

			theDoubleValidator_->setTop(maximumValue);
		}
	}
}

bool ForgBaseLib::FrgBase_PrptsWdgStringDouble::eventFilter(QObject* watched, QEvent* event)
{
	if (event->type() == QEvent::FocusIn)
	{
		if (watched == theLineEdit_)
			QTimer::singleShot(0, theLineEdit_, &QLineEdit::selectAll);
		else
			return false;
	}
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

		if (keyEvent)
		{
			if (keyEvent->key() == Qt::Key_Escape)
			{
				if (watched == theLineEdit_)
				{
					auto myVariant = dynamic_cast<FrgBase_PrptsWdgStringDouble*>(theVariant_);
					if (myVariant)
						theLineEdit_->setText(QString::number(myVariant->GetValue(), 'G'));

					auto myFieldWidget = dynamic_cast<FrgBase_PrptsWdgField*>(this);
					if (myFieldWidget)
						theLineEdit_->setText(myFieldWidget->GetValueString());

					emit EditingFinishedSignal();
					//theLineEdit_->clearFocus();
					return false;
				}
			}
			if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Tab || keyEvent->key() == Qt::Key_Backtab)
			{
				if (watched == theLineEdit_)
				{
					emit EditingFinishedSignal();//theLineEdit_->editingFinished();

					return true;
				}
			}
			if (keyEvent->key() == Qt::Key_Up)
			{
				if (watched == theLineEdit_)
				{
					auto myVariant = dynamic_cast<FrgBase_PrptsVrntStringDouble*>(theVariant_);
					if (myVariant)
					{
						if (myVariant->IsStepped())
						{
							double value = myVariant->GetValue() + myVariant->GetStepValue();

							theLineEdit_->setText(QString::number(value, 'G'));
							emit EditingFinishedSignal();//theLineEdit_->editingFinished();
						}

						return true;
					}
				}
			}
			if (keyEvent->key() == Qt::Key_Down)
			{
				if (watched == theLineEdit_)
				{
					auto myVariant = dynamic_cast<FrgBase_PrptsVrntStringDouble*>(theVariant_);
					if (myVariant)
					{
						if (myVariant->IsStepped())
						{
							double value = myVariant->GetValue() - myVariant->GetStepValue();

							theLineEdit_->setText(QString::number(value, 'G'));

							emit EditingFinishedSignal();//theLineEdit_->editingFinished();
						}

						return true;
					}
				}
			}
		}
	}
	if (event->type() == QEvent::Wheel)
	{
		if (watched == theLineEdit_)
		{
			auto myVariant = dynamic_cast<FrgBase_PrptsVrntStringDouble*>(theVariant_);
			if (myVariant)
			{
				if (myVariant->IsStepped())
				{
					QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);

					if (wheelEvent)
					{
						if (watched == theLineEdit_)
						{
							if (theLineEdit_->isEnabled())
							{
								if (myVariant->IsStepped())
								{
									double value;

									if (wheelEvent->delta() >= 0.0)
										value = myVariant->GetValue() + myVariant->GetStepValue();
									else
										value = myVariant->GetValue() - myVariant->GetStepValue();

									theLineEdit_->setText(QString::number(value, 'G'));

									emit EditingFinishedSignal();//theLineEdit_->editingFinished();
								}

								return true;
							}
						}
					}
				}
			}
		}
	}

	return FrgBase_PrptsWdgOneValue::eventFilter(watched, event);
}