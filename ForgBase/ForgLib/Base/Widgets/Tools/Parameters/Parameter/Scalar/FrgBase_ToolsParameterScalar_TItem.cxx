#include <FrgBase_ToolsParameterScalar_TItem.hxx>
#include <FrgBase_PrptsVrntFieldScalar.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_ToolsParameters_TItem.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_PrptsWdgFieldDialog.hxx>

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

	AddVariableToSymbolTable(this->text(0), true);
}

void ForgBaseLib::FrgBase_ToolsParameterScalar_TItem::Update()
{
	FrgBase_ToolsParameter_TItem::Update();

	auto myWidget = thePropertiesPanel_->GetWidgetFromVariant(theValue_);
	if (myWidget)
	{
		QString command = FrgBase_PrptsWdgFieldDialog::RemoveVariablesDecorations(myWidget->GetValueString());
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

void ForgBaseLib::FrgBase_ToolsParameterScalar_TItem::AddVariableToSymbolTable(const QString& s, bool isConstructing)
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

	if (theParentToolsParametersTItem_ && !isConstructing)
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
					code.replace("{" + theVariableName_ + "}", "{" + newName + "}");
					scalarWidget->SetValueString(code);
				}
			}
		}
	}

	theVariableName_ = newName;
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_ToolsParameterScalar_TItem)
{
	ar& boost::serialization::base_object<FrgBase_ToolsParameter_TItem>(*this);

	auto w = thePropertiesPanel_->GetWidgetFromVariant(theValue_);
	QString vs = w->GetValueString();
	bool ish = w->IsButtonHidden();

	ar& theValue_;
	ar& vs;
	ar& ish;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_ToolsParameterScalar_TItem)
{
	ar& boost::serialization::base_object<FrgBase_ToolsParameter_TItem>(*this);

	QString vs;
	bool ish;

	ar& theValue_;
	ar& vs;
	ar& ish;

	auto w = thePropertiesPanel_->AddRow(theValue_);
	w->SetValueString(vs);
	w->SetButtonHidden(ish);

	AddVariableToSymbolTable(this->text(0));
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameterScalar_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_ToolsParameterScalar_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameterScalar_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_ToolsParameterScalar_TItem);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameterScalar_TItem)