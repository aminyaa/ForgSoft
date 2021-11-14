#include <FrgBase_ToolsParameterVector_TItem.hxx>
#include <FrgBase_PrptsVrntFieldVector.hxx>
#include <FrgBase_PropertiesPanel.hxx>
#include <FrgBase_ToolsParameters_TItem.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_PrptsWdgFieldDialog.hxx>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_ToolsParameterVector_TItem::FrgBase_ToolsParameterVector_TItem
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
			theSymbolTableT_->remove_vector(theVariableName_.toStdString());

			AddVariableToSymbolTable(this->text(0));
		}
	);
}

ForgBaseLib::FrgBase_ToolsParameterVector_TItem::~FrgBase_ToolsParameterVector_TItem()
{
	//FreePointer(theValues_);

	theSymbolTableT_->remove_vector(theVariableName_.toStdString());
}

void ForgBaseLib::FrgBase_ToolsParameterVector_TItem::FormTItem()
{
	ForgBaseLib::FrgBase_ToolsParameter_TItem::FormTItem();

	std::vector<double> values;
	values.reserve(3);
	values.push_back(0.0);
	values.push_back(0.0);
	values.push_back(0.0);

	theValues_ = new FrgBase_PrptsVrntFieldVector("Value", values);
	thePropertiesPanel_->AddRow(theValues_);

	AddVariableToSymbolTable(this->text(0), true);

	/*if (theSymbolTableT_)
		theSymbolTableT_->add_vector(this->text(0).replace(' ', '_').toStdString(), theValues_->GetValueRef());*/
}

void ForgBaseLib::FrgBase_ToolsParameterVector_TItem::Update()
{
	FrgBase_ToolsParameter_TItem::Update();

	auto myWidget = thePropertiesPanel_->GetWidgetFromVariant(theValues_);
	if (myWidget)
	{
		QString command = FrgBase_PrptsWdgFieldDialog::RemoveVariablesDecorations(myWidget->GetValueString());
		if (command.size() > 2 && command.at(0) == '[' && command.at(command.size() - 1) == ']')
			command = "return " + command;

		exprtk::expression<double> myExpression;
		myExpression.register_symbol_table(*theSymbolTableT_);

		exprtk::parser<double> myParser;
		bool compiled = myParser.compile(command.toStdString(), myExpression);

		if (compiled)
		{
			myExpression.value();
			auto results = myExpression.results();
			std::vector<double>& values = theValues_->GetValueRef();

			for (std::size_t iter = 0; iter < results.count(); iter++)
			{
				auto t = results[iter];

				if (t.type == exprtk::type_store<double>::e_scalar)
				{
					auto value = exprtk::results_context<double>::type_store_t::scalar_view(t);
					values[iter] = value();
				}

			}

			emit theValues_->ValueChangedSignal(theValues_->GetValue());
		}
		else
		{
			std::exception myException(("Cannot update \"" + this->text(0) + "\"").toStdString().c_str());
			throw myException;
		}
	}
}

const std::vector<double>& ForgBaseLib::FrgBase_ToolsParameterVector_TItem::GetValues() const
{
	return theValues_->GetValue();
}

std::vector<double>& ForgBaseLib::FrgBase_ToolsParameterVector_TItem::GetValuesRef()
{
	return theValues_->GetValueRef();
}

void ForgBaseLib::FrgBase_ToolsParameterVector_TItem::AddVariableToSymbolTable(const QString& s,bool isConstructing)
{
	if (!theSymbolTableT_)
		return;

	auto newName = GetCorrectedVariableName(s);
	bool isAdded = false;
	int i = 0;
	while (!isAdded)
	{
		if (i > 0)
			newName += "_";
		isAdded = theSymbolTableT_->add_vector(newName.toStdString(), theValues_->GetValueRef());

		i++;
	}

	if (theParentToolsParametersTItem_ && !isConstructing)
	{
		auto parameters = theParentToolsParametersTItem_->GetAllChildrenToTheRoot();
		for (const auto& x : parameters)
		{
			const auto& scalarParameter = dynamic_cast<FrgBase_ToolsParameterVector_TItem*>(x);
			if (scalarParameter)
			{
				const auto& scalarWidget =
					scalarParameter->GetPropertiesPanel()->GetWidgetFromVariant(scalarParameter->GetValuesVariant());
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

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_ToolsParameterVector_TItem)
{
	ar& boost::serialization::base_object<FrgBase_ToolsParameter_TItem>(*this);

	auto w = thePropertiesPanel_->GetWidgetFromVariant(theValues_);
	QString vs = w->GetValueString();
	bool ish = w->IsButtonHidden();

	ar& theValues_;
	ar& vs;
	ar& ish;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_ToolsParameterVector_TItem)
{
	ar& boost::serialization::base_object<FrgBase_ToolsParameter_TItem>(*this);

	QString vs;
	bool ish;

	ar& theValues_;
	ar& vs;
	ar& ish;

	auto w = thePropertiesPanel_->AddRow(theValues_);
	w->SetValueString(vs);
	w->SetButtonHidden(ish);

	if (theSymbolTableT_)
		theSymbolTableT_->add_vector(this->text(0).replace(' ', '_').toStdString(), theValues_->GetValueRef());
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameterVector_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_ToolsParameterVector_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameterVector_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_ToolsParameterVector_TItem);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameterVector_TItem)