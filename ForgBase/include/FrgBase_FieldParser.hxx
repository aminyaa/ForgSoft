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
		std::vector<std::shared_ptr<FrgBase_Field_Entity>> theFields_;
	};

	static std::shared_ptr<exprtk::expression<double>> CompileExpression
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field
	);

	static std::shared_ptr<exprtk::expression<double>> CompileExpression
	(
		const std::string& expression,
		const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
	);

	// This method will throw the suitable exception
	static void CheckRecursiveLoop
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field,
		const std::string& expression
	);

	static double CalcValueScalar
	(
		const std::shared_ptr<FrgBase_ScalarField>& field,
		const std::shared_ptr<Calculated>& calculated = nullptr
	);

	static std::vector<double> CalcValueVector
	(
		const std::shared_ptr<FrgBase_VectorField_Entity>& field,
		const std::shared_ptr<Calculated>& calculated = nullptr
	);

	static std::shared_ptr<FrgBase_Field_Entity> RetrieveFieldUsingFullName
	(
		const std::string& variableFullName,
		const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
	);

	static std::vector<std::shared_ptr<FrgBase_Field_Entity>> RetrieveFieldsUsingFullName
	(
		const std::vector<std::string>& variablesFullName,
		const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
	);

	static std::shared_ptr<FrgBase_Field_Entity> RetrieveFieldUsingFullPresentationName
	(
		const std::string& variableFullPresentationName,
		const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
	);

	static std::vector<std::shared_ptr<FrgBase_Field_Entity>> RetrieveFieldsUsingFullPresentationName
	(
		const std::vector<std::string>& variablesFullPresentationName,
		const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables
	);

	static std::vector<std::shared_ptr<FrgBase_Field_Entity>> RetrieveDependentFields
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field,
		const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables,
		const bool recursively = false
	);

	static std::vector<std::shared_ptr<FrgBase_Field_Entity>> RetrieveFieldsUsingThisField
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field,
		const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& symbolTables,
		const bool recursively = false
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
		const std::shared_ptr<FrgBase_Field_Entity>& field
	);

	static std::string CreateFieldExpressionReadyToCompile
	(
		const std::string& expression,
		const bool isVector
	);
	
	static std::string CreateFieldExpressionReadyToCompile
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field
	);	

	static std::vector<std::string> CollectVariablesFullName
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field
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

	static std::shared_ptr<FrgBase_Field_Entity> ContainsThisInFields
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field,
		const std::vector<std::shared_ptr<FrgBase_Field_Entity>>& fields
	);

protected:

	static std::shared_ptr<exprtk::expression<double>> CalcValueEntity
	(
		const std::shared_ptr<FrgBase_Field_Entity>& field,
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
