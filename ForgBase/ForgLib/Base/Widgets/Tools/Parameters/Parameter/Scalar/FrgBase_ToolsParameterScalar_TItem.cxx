#include <FrgBase_ToolsParameterScalar_TItem.hxx>
#include <FrgBase_PrptsVrntFieldScalar.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_ToolsParameters_TItem.hxx>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_ToolsParameterScalar_TItem::FrgBase_ToolsParameterScalar_TItem
(
	const QString& itemTitle,
	FrgBase_TreeItem* parentItem,
	FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_ToolsParameter_TItem(itemTitle, parentItem, parentTree)
{
	connect
	(
		this,
		&FrgBase_TreeItem::TItemNameChanged,
		[this](const QString&)
		{
			theSymbolTableT_->remove_variable(theVariableName_.toStdString(), true);

			AddVariableToSymbolTable(this->text(0));
		}
	);

	/*connect
	(
		theValue_,
		&FrgBase_PrptsVrntFieldScalar::ValueChangedSignal,
		[this](const double&)
		{
			theSymbolTableT_->variable_ref(theVariableName_.toStdString()) = theValue_->GetValue();
		}
	);*/
}

ForgBaseLib::FrgBase_ToolsParameterScalar_TItem::~FrgBase_ToolsParameterScalar_TItem()
{
	FreePointer(theValue_);

	theSymbolTableT_->remove_variable(theVariableName_.toStdString());
}

void ForgBaseLib::FrgBase_ToolsParameterScalar_TItem::FormTItem()
{
	ForgBaseLib::FrgBase_ToolsParameter_TItem::FormTItem();

	theValue_ = new FrgBase_PrptsVrntFieldScalar("Value", 0.0);
	thePropertiesPanel_->AddRow(theValue_);

	/*connect(theValue_, &FrgBase_PrptsVrntFieldScalar::ValueChangedSignal, [this](const double& value)
		{
			const auto& myWidget = thePropertiesPanel_->GetWidgetFromVariant(theValue_);
			if (myWidget)
				myWidget->SetValueString(QString::number(value, 'G'));
		}
	);*/

	AddVariableToSymbolTable(this->text(0));
}

void ForgBaseLib::FrgBase_ToolsParameterScalar_TItem::Update()
{
	FrgBase_ToolsParameter_TItem::Update();

	auto myWidget = thePropertiesPanel_->GetWidgetFromVariant(theValue_);
	if (myWidget)
	{
		QString command = myWidget->GetValueString();
		if (command.size() > 2 && command.at(0) == '[' && command.at(command.size() - 1) == ']')
			command = "return " + command;

		exprtk::expression<double> myExpression;
		myExpression.register_symbol_table(*theSymbolTableT_);

		exprtk::parser<double> myParser;
		bool compiled = myParser.compile(command.toStdString(), myExpression);

		double& valueRef = theValue_->GetValueRef();

		if (compiled)
		{
			valueRef = myExpression.value();

			emit theValue_->ValueChangedSignal(theValue_->GetValue());
		}
		else
		{
			std::exception myException(("Cannot update \"" + this->text(0) + "\"").toStdString().c_str());
			throw myException;
		}
	}
}

double ForgBaseLib::FrgBase_ToolsParameterScalar_TItem::GetValue() const
{
	return theValue_->GetValue();
}

double& ForgBaseLib::FrgBase_ToolsParameterScalar_TItem::GetValueRef()
{
	return theValue_->GetValueRef();
}

void ForgBaseLib::FrgBase_ToolsParameterScalar_TItem::AddVariableToSymbolTable(const QString& s)
{
	if (!theSymbolTableT_)
		return;

	QString newName = GetCorrectedVariableName(s);
	bool isAdded = false;
	int i = 0;
	while (!isAdded)
	{
		if (i > 0)
			newName += "_";
		isAdded = theSymbolTableT_->add_variable(newName.toStdString(), theValue_->GetValueRef());

		i++;
	}

	if (theParentToolsParametersTItem_)
	{
		auto parameters = theParentToolsParametersTItem_->GetAllChildrenToTheRoot();
		for (const auto& x : parameters)
		{
			const auto& scalarParameter = dynamic_cast<FrgBase_ToolsParameterScalar_TItem*>(x);
			if (scalarParameter)
			{
				const auto& scalarWidget =
					scalarParameter->GetPropertiesPanel()->GetWidgetFromVariant(scalarParameter->GetValueVariant());
				if (scalarWidget)
				{
					QString code = scalarWidget->GetValueString();
					code.replace(theVariableName_, newName);
					scalarWidget->SetValueString(code);
				}
			}
		}
	}

	theVariableName_ = newName;
}