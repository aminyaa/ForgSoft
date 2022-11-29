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
class FrgBase_VectorField_Entity;

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

	static double CalcValueScalar
	(
		FrgBase_ScalarField* field,
		const std::shared_ptr<Calculated>& calculated = nullptr
	);

	static std::vector<double> CalcValueVector
	(
		FrgBase_VectorField_Entity* field,
		const std::shared_ptr<Calculated>& calculated = nullptr
	);

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

	static FrgBase_Field_Entity* RetrieveFieldUsingFullPresentationName
	(
		const std::string& variableFullPresentationName,
		const std::vector<FrgBase_SymbolTable*>& symbolTables
	);

	static std::vector<FrgBase_Field_Entity*> RetrieveFieldsUsingFullPresentationName
	(
		const std::vector<std::string>& variablesFullPresentationName,
		const std::vector<FrgBase_SymbolTable*>& symbolTables
	);

	static std::vector<FrgBase_Field_Entity*> RetrieveDependentFields
	(
		FrgBase_Field_Entity* field,
		const std::vector<FrgBase_SymbolTable*>& symbolTables
	);

	static std::vector<FrgBase_Field_Entity*> RetrieveFieldsUsingThisField
	(
		FrgBase_Field_Entity* field,
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

	static std::shared_ptr<Calculated> InitCalculated();
	//static void ClearCalculated(const std::shared_ptr<Calculated>& calculated);

	static bool ContainFieldInCalculated
	(
		const std::shared_ptr<Calculated>& calculated,
		FrgBase_Field_Entity* field
	);

	static std::string CreateFieldExpressionReadyToCompile
	(
		FrgBase_Field_Entity* field
	);

	static std::vector<std::string> CollectVariablesFullName
	(
		FrgBase_Field_Entity* field
	);

	static std::string CombineString
	(
		const std::vector<std::string>& strs
	);

	static std::string CombineValues
	(
		const std::vector<std::string>& headers,
		const std::vector<double>& values
	);

protected:

	static std::shared_ptr<exprtk::expression<double>> CalcValueEntity
	(
		FrgBase_Field_Entity* field,
		const std::shared_ptr<Calculated>& calculated = nullptr
	);

	static std::vector<double> RetrieveValuesFromExpression
	(
		const size_t size,
		const std::shared_ptr<exprtk::expression<double>>& expression
	);
};

EndForgBaseLib

#include <FrgBase_FieldParserI.hxx>

#endif // !_FrgBase_FieldParser_Header
