#pragma once
#ifndef _FrgBase_FieldParser_Header
#define _FrgBase_FieldParser_Header

#include <FrgBase_Object.hxx>

namespace exprtk
{
	template <typename T>
	class expression;
}

BeginForgBaseLib

class FrgBase_SymbolTable;
class FrgBase_Field_Entity;
class FrgBase_ScalarField;

class FORGBASE_EXPORT FrgBase_FieldParser
	: public FrgBase_Object
{

public:

	struct Calculated
	{
		std::vector<FrgBase_Field_Entity*> theFields_;
	};

	static std::shared_ptr<exprtk::expression<double>> CompileExpression
	(
		const std::string& expression,
		const std::vector<FrgBase_SymbolTable*>& symbolTables
	);

	static double CalcValue
	(
		FrgBase_ScalarField* field,
		const std::shared_ptr<Calculated>& calculated = nullptr
	);

	/*static std::vector<double> CalcValues
	(
		const std::string& expression,
		std::vector<FrgBase_SymbolTable*> symbolTables
	);*/

	static FrgBase_Field_Entity* RetrieveFieldUsingFullName
	(
		const std::string& variableFullName,
		const std::vector<FrgBase_SymbolTable*>& symbolTables
	);

	static std::vector<FrgBase_Field_Entity*> RetrieveFieldsUsingFullName
	(
		const std::vector<std::string>& variablesFullName,
		const std::vector<FrgBase_SymbolTable*>& symbolTables
	);

	/*static std::vector<FrgBase_Field_Entity*> RetrieveDependentFields
	(
		FrgBase_Field_Entity* field
	);

	static std::vector<FrgBase_Field_Entity*> RetrieveDependentFields
	(
		const std::string& fieldFullName,
		const std::vector<FrgBase_SymbolTable*>& symbolTables
	);*/

protected:

	static std::shared_ptr<Calculated> InitCalculated();
	//static void ClearCalculated(const std::shared_ptr<Calculated>& calculated);

	static bool ContainFieldInCalculated(const std::shared_ptr<Calculated>& calculated, FrgBase_Field_Entity* field);
};

EndForgBaseLib

#include <FrgBase_FieldParserI.hxx>

#endif // !_FrgBase_FieldParser_Header
