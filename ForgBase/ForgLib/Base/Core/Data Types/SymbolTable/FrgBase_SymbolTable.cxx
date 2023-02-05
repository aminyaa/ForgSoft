#include <FrgBase_SymbolTable.hxx>
#include <FrgBase_SymbolTableRegistry.hxx>
#include <FrgBase_ScalarField.hxx>
#include <FrgBase_VectorField.hxx>
#include <FrgBase_FieldParser.hxx>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_SymbolTable::FrgBase_SymbolTable()
	: FrgBase_Object()
{
	theSymbolTable_ = std::make_shared<exprtk::symbol_table<double>>();
}

ForgBaseLib::FrgBase_SymbolTable::~FrgBase_SymbolTable()
{
	//FreePointer(theSymbolTable_);

	/*for (const auto& f : theFields_)
		delete f;*/

	theExternalSymbolTables_.clear();
	theFields_.clear();
}

std::string ForgBaseLib::FrgBase_SymbolTable::GetFullPresentationName
(
	const std::string& delimiter
) const
{
	if (theParentSymbolTable_)
		return theParentSymbolTable_->GetFullPresentationName(delimiter) + delimiter + thePresentationName_;

	return thePresentationName_;
}

void ForgBaseLib::FrgBase_SymbolTable::AddExternalSymbolTable
(
	const std::shared_ptr<FrgBase_SymbolTable>& est
)
{
	if (!est)
		return;

	if (est == this->shared_from_this())
		return;

	for (const auto& t : theExternalSymbolTables_)
	{
		if (t == est)
			return;
	}

	theExternalSymbolTables_.push_back(est);
}

void ForgBaseLib::FrgBase_SymbolTable::RemoveExternalSymbolTable
(
	const std::shared_ptr<FrgBase_SymbolTable>& est
)
{
	if (!est)
		return;

	std::vector<std::shared_ptr<FrgBase_SymbolTable>> result;

	for (const auto& t : theExternalSymbolTables_)
	{
		if (t == est)
			continue;

		result.push_back(t);
	}

	theExternalSymbolTables_ = result;
}

void ForgBaseLib::FrgBase_SymbolTable::AddExternalSymbolTables
(
	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& tables
)
{
	for (const auto& table : tables)
		AddExternalSymbolTable(table);
}

std::string ForgBaseLib::FrgBase_SymbolTable::GetFullName
(
	const std::string& delimiter
) const
{
	if (theParentSymbolTable_)
		return theParentSymbolTable_->GetFullName(delimiter) + delimiter + theName_;

	return theRegistry_->GetName() + delimiter + theName_;
}

std::shared_ptr<ForgBaseLib::FrgBase_ScalarField>
ForgBaseLib::FrgBase_SymbolTable::AddVariable
(
	const std::string& presentationName
)
{
	if (theSymbolTable_)
	{
		std::string variableName =
			"Value" + std::to_string(theVariableIndex_);

		std::string variableFullName =
			GetFullName() + "_" + variableName;

		auto field =
			std::make_shared<FrgBase_ScalarField>();

		field->SetSymbolTable(this->shared_from_this());
		field->SetRegistry(theRegistry_);
		field->SetName(variableName);
		field->SetIndex(theVariableIndex_);
		field->SetPresentationName(presentationName);
		field->SetExpression("0.0");

		const bool added = AddScalarToSymbolTable
		(
			theSymbolTable_,
			variableFullName,
			field->GetValueRef()
		);

		if (added)
		{
			theFields_.push_back(field);

			theVariableIndex_++;

			return field;
		}
	}

	return nullptr;
}

std::shared_ptr<ForgBaseLib::FrgBase_VectorField>
ForgBaseLib::FrgBase_SymbolTable::AddVector
(
	const std::string& presentationName,
	const int size
)
{
	if (theSymbolTable_)
	{
		std::string variableName =
			"Value" + std::to_string(theVariableIndex_);

		std::string variableFullName =
			GetFullName() + "_" + variableName;

		auto field =
			std::make_shared<FrgBase_VectorField>(size);

		field->SetSymbolTable(this->shared_from_this());
		field->SetRegistry(theRegistry_);
		field->SetName(variableName);
		field->SetIndex(theVariableIndex_);
		field->SetPresentationName(presentationName);

		std::string expression = "[";
		for (int i = 0; i < field->GetSize(); i++)
		{
			if (i == field->GetSize() - 1)
				expression += "0.0";
			else
				expression += "0.0, ";
		}
		expression += "]";

		field->SetExpression(expression);

		const bool added =
			AddVectorToSymbolTable
			(
				theSymbolTable_,
				variableFullName,
				field->GetValueRef()
			);

		if (added)
		{
			theFields_.push_back(field);

			theVariableIndex_++;

			return field;
		}
	}

	return nullptr;
}

bool ForgBaseLib::FrgBase_SymbolTable::DeleteField
(
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	if (!field)
		return false;

	if (!ContainsField(field))
		return false;

	if (!field->IsDeletable())
	{
		auto uFields =
			FrgBase_FieldParser::RetrieveFieldsUsingThisField
			(
				field,
				theRegistry_->GetTables()
			);

		std::vector<std::string> uFieldsString;
		for (const auto& x : uFields)
			uFieldsString.push_back(x->GetPresentationName());

		std::string meassage = "Cannot delete the field due to dependency.\n Variables: " +
			FrgBase_FieldParser::CombineString(uFieldsString);

		std::exception ex(meassage.c_str());
		throw ex;
	}

	RemoveFieldFromSymbolTable(field);

	std::vector<std::shared_ptr<FrgBase_Field_Entity>> finalFields;
	for (const auto& f : theFields_)
	{
		if (f != field)
			finalFields.push_back(f);
	}

	theFields_ = finalFields;

	//delete field;

	return true;
}

bool ForgBaseLib::FrgBase_SymbolTable::ContainsField
(
	const std::shared_ptr<FrgBase_Field_Entity>& field
) const
{
	for (const auto& f : theFields_)
	{
		if (f == field)
			return true;
	}

	return nullptr;
}

std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>
ForgBaseLib::FrgBase_SymbolTable::ContainsField
(
	const std::string& fieldFullName
) const
{
	for (const auto& f : theFields_)
	{
		if (f->GetFullName() == fieldFullName)
			return f;
	}

	return nullptr;
}

std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>
ForgBaseLib::FrgBase_SymbolTable::ContainsFieldFullPresentationName
(
	const std::string& fieldFullPresentationName
) const
{
	for (const auto& f : theFields_)
	{
		if (f->GetFullPresentationName() == fieldFullPresentationName)
			return f;
	}

	return nullptr;
}

std::shared_ptr<ForgBaseLib::FrgBase_Field_Entity>
ForgBaseLib::FrgBase_SymbolTable::GetFieldUsingPresentationName
(
	const std::string& presentationName
) const
{
	for (const auto& f : theFields_)
	{
		if (f->GetPresentationName() == presentationName)
			return f;
	}

	return nullptr;
}

std::shared_ptr<ForgBaseLib::FrgBase_ScalarField>
ForgBaseLib::FrgBase_SymbolTable::GetScalarFieldUsingPresentationName
(
	const std::string& presentationName
) const
{
	return std::dynamic_pointer_cast<FrgBase_ScalarField>(GetFieldUsingPresentationName(presentationName));
}

std::shared_ptr<ForgBaseLib::FrgBase_VectorField>
ForgBaseLib::FrgBase_SymbolTable::GetVectorFieldUsingPresentationName
(
	const std::string& presentationName
) const
{
	return std::dynamic_pointer_cast<FrgBase_VectorField>(GetFieldUsingPresentationName(presentationName));
}

#define PRINT_ONELINE_CHAR(myString, margin, ss, myChar) \
for (int i = 0; i < myString.size() + margin; i++) \
ss << myChar; \
ss << std::endl;

void ForgBaseLib::FrgBase_SymbolTable::PrintField
(
	std::ostringstream& ss,
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	if (!field)
		return;

	if (field->IsScalar())
	{
		auto scalarField =
			std::dynamic_pointer_cast<FrgBase_ScalarField>(field);

		auto value = scalarField->GetValue();

		auto valueString =
			FrgBase_FieldParser::CombineValues
			(
				{ "Value" },
				{ value }
		);

		ss << FrgBase_FieldParser::CombineString
		(
			{
				scalarField->GetPresentationName(),
				scalarField->GetName(),
				valueString
			}
		)
			<< std::endl;
	}
	else if (field->IsVector())
	{
		auto vectorField =
			std::dynamic_pointer_cast<FrgBase_VectorField_Entity>(field);

		auto value = vectorField->GetValue();

		if (value.empty())
			return;

		std::vector<std::string> headerString;
		for (const auto& v : value)
			headerString.push_back(std::to_string(v));

		auto valueString =
			FrgBase_FieldParser::CombineValues
			(
				headerString,
				value
			);

		ss <<
			FrgBase_FieldParser::CombineString
			(
				{
					vectorField->GetPresentationName(),
					vectorField->GetName(),
					"[" + valueString + "]"
				}
			)
			<< std::endl;
	}
}

std::string ForgBaseLib::FrgBase_SymbolTable::PrintField
(
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	std::ostringstream ss;
	PrintField(ss, field);

	return ss.str();
}

void ForgBaseLib::FrgBase_SymbolTable::PrintField
(
	std::ostream& out,
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	auto str = PrintField(field);

	out << str;
}

void ForgBaseLib::FrgBase_SymbolTable::Print
(
	std::ostringstream& ss,
	bool calcValue
)
{
	auto pName = GetPresentationName();

	if (theFields_.empty())
	{
		ss << "The table \"" + pName + "\" is empty.\n";
		return;
	}

	int margin = 2;

	ss << std::endl;
	PRINT_ONELINE_CHAR(pName, margin + 2, ss, "=");
	ss << pName << std::endl;
	PRINT_ONELINE_CHAR(pName, margin + 2, ss, "=");

	std::vector<std::string> headers = { "Name", "Real Name", "Value" };

	auto headersInLine =
		FrgBase_FieldParser::CombineString(headers);

	ss << headersInLine << std::endl;

	PRINT_ONELINE_CHAR(headersInLine, margin, ss, "-");

	if (calcValue)
		CalcValue(FrgBase_FieldParser::InitCalculated());

	for (const auto& field : theFields_)
		PrintField(ss, field);
}

std::string ForgBaseLib::FrgBase_SymbolTable::Print
(
	bool calcValue
)
{
	std::ostringstream ss;
	Print(ss, calcValue);

	return ss.str();
}

void ForgBaseLib::FrgBase_SymbolTable::Print
(
	std::ostream& out,
	bool calcValue
)
{
	auto str = Print(calcValue);

	out << str;
}

void ForgBaseLib::FrgBase_SymbolTable::CalcValue
(
	const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated
)
{
	std::shared_ptr<FrgBase_FieldParser::Calculated> myCalculated;
	if (!calculated)
		myCalculated = FrgBase_FieldParser::InitCalculated();
	else
		myCalculated = calculated;

	for (const auto& field : theFields_)
		field->CalcValue(myCalculated);
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_ScalarField>>
ForgBaseLib::FrgBase_SymbolTable::GetScalarFields() const
{
	std::vector<std::shared_ptr<FrgBase_ScalarField>> result;

	for (const auto& field : theFields_)
	{
		const auto& scalarField =
			std::dynamic_pointer_cast<FrgBase_ScalarField>(field);
		if (scalarField)
			result.push_back(scalarField);
	}

	return result;
}

std::vector<std::shared_ptr<ForgBaseLib::FrgBase_VectorField>>
ForgBaseLib::FrgBase_SymbolTable::GetVectorFields() const
{
	std::vector<std::shared_ptr<FrgBase_VectorField>> result;

	for (const auto& field : theFields_)
	{
		const auto& vectorField =
			std::dynamic_pointer_cast<FrgBase_VectorField>(field);
		if (vectorField)
			result.push_back(vectorField);
	}

	return result;
}

bool ForgBaseLib::FrgBase_SymbolTable::AddScalarToSymbolTable
(
	const std::shared_ptr<exprtk::symbol_table<double>>& table,
	const std::string& variableFullName,
	double& value
)
{
	if (table)
	{
		return table->add_variable
		(
			variableFullName,
			value
		);
	}

	return false;
}

bool ForgBaseLib::FrgBase_SymbolTable::AddVectorToSymbolTable
(
	const std::shared_ptr<exprtk::symbol_table<double>>& table,
	const std::string& variableFullName,
	std::vector<double>& value
)
{
	if (table)
	{
		return table->add_vector
		(
			variableFullName,
			value
		);
	}

	return false;
}

bool ForgBaseLib::FrgBase_SymbolTable::RemoveFieldFromSymbolTable
(
	const std::shared_ptr<FrgBase_Field_Entity>& field
)
{
	if (field)
	{
		const auto& table =
			field->GetSymbolTable()->GetSymbolTable();
		if (!table)
			return false;
		
		if (field->IsScalar())
		{
			return table->remove_variable
			(
				field->GetFullName()
			);
		}
		else if (field->IsVector())
		{
			return table->remove_vector
			(
				field->GetFullName()
			);
		}
	}

	return false;
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_SymbolTable)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& thePresentationName_;
	ar& theVariableIndex_;

	ar& theRegistry_;
	ar& theParentSymbolTable_;
	ar& theExternalSymbolTables_;
	ar& theFields_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_SymbolTable)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& thePresentationName_;
	ar& theVariableIndex_;

	ar& theRegistry_;
	ar& theParentSymbolTable_;
	ar& theExternalSymbolTables_;
	ar& theFields_;

	for (auto field : theFields_)
	{
		if (field->IsScalar())
		{
			auto myField =
				std::dynamic_pointer_cast<FrgBase_ScalarField>(field);

			AddScalarToSymbolTable
			(
				theSymbolTable_,
				field->GetFullName(),
				myField->GetValueRef()
			);
		}
		else if (field->IsVector())
		{
			auto myField =
				std::dynamic_pointer_cast<FrgBase_VectorField_Entity>(field);

			AddVectorToSymbolTable
			(
				theSymbolTable_,
				field->GetFullName(),
				myField->GetValueRef()
			);
		}
	}
	
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_SymbolTable)