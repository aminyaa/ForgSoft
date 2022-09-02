#pragma once

#include <FrgBase_VectorField.hxx>

template<int Dim>
inline ForgBaseLib::FrgBase_VectorField<Dim>* ForgBaseLib::FrgBase_SymbolTable::AddVector
(
	const std::string& presentationName
)
{
	if (theSymbolTable_)
	{
		std::string variableName = "Value" + std::to_string(theVariableIndex_);
		std::string variableFullName = GetFullName() + "_" + variableName;

		auto field = new FrgBase_VectorField<Dim>();
		field->SetSymbolTable(this);
		field->SetName(variableName);
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

		//field->SetPresentationExpression(expression);

		bool added = AddVectorToSymbolTable(theSymbolTable_, variableFullName, field->GetValueRef());

		if (added)
		{
			theFields_.push_back(field);

			theVariableIndex_++;

			return field;
		}

		FreePointer(field);
	}

	return nullptr;
}