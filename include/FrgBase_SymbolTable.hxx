#pragma once
#ifndef _FrgBase_SymbolTable_Header
#define _FrgBase_SymbolTable_Header

#include <FrgBase_Object.hxx>
#include <FrgBase_FieldParser.hxx>

namespace exprtk
{
	template <typename T>
	class symbol_table;
}

BeginForgBaseLib

class FrgBase_SymbolTableRegistry;
class FrgBase_ScalarField;
class FrgBase_Field_Entity;

template <int Dim>
class FrgBase_VectorField;

class FORGBASE_EXPORT FrgBase_SymbolTable
	: public FrgBase_Object
	, public std::enable_shared_from_this<FrgBase_SymbolTable>
{

public:

	FrgBase_SymbolTable();
	
	~FrgBase_SymbolTable();

	std::string GetPresentationName() const { return thePresentationName_; }
	std::string GetFullPresentationName(const std::string& delimiter = ".") const;

	void SetPresentationName(const std::string& pn) { thePresentationName_ = pn; }

	const auto& GetRegistry() const { return theRegistry_; }
	void SetRegistry(const std::shared_ptr<FrgBase_SymbolTableRegistry>& registry) { theRegistry_ = registry; }

	const auto& GetParentSymbolTable() const { return theParentSymbolTable_; }
	void SetParentSymbolTable(const std::shared_ptr<FrgBase_SymbolTable>& pst) { theParentSymbolTable_ = pst; }

	const auto& GetExternalSymbolTables() const { return theExternalSymbolTables_; }
	void SetExternalSymbolTables(const std::vector<std::shared_ptr<FrgBase_SymbolTable>> ests) { theExternalSymbolTables_ = ests; }

	void AddExternalSymbolTable(const std::shared_ptr<FrgBase_SymbolTable>& est);
	void RemoveExternalSymbolTable(const std::shared_ptr<FrgBase_SymbolTable>& est);

	const auto& GetSymbolTable() const { return theSymbolTable_; }

	std::string GetFullName(const std::string& delimiter = "_") const;

	std::shared_ptr<FrgBase_ScalarField> AddVariable(const std::string& presentationName);

	template <int Dim>
	std::shared_ptr<FrgBase_VectorField<Dim>> AddVector(const std::string& presentationName);

	bool DeleteField(const std::shared_ptr<FrgBase_Field_Entity>& field);

	bool ContainsField(const std::shared_ptr<FrgBase_Field_Entity>& field) const;
	std::shared_ptr<FrgBase_Field_Entity> ContainsField(const std::string& fieldFullName) const;
	std::shared_ptr<FrgBase_Field_Entity> ContainsFieldFullPresentationName(const std::string& fieldFullPresentationName) const;

	const auto& GetFields() const { return theFields_; }

	static void PrintField(std::ostringstream& ss, const std::shared_ptr<FrgBase_Field_Entity>& field);

	static std::string PrintField(const std::shared_ptr<FrgBase_Field_Entity>& field);

	static void PrintField(std::ostream& out, const std::shared_ptr<FrgBase_Field_Entity>& field);

	void Print(std::ostringstream& ss, bool calcValue = true);

	std::string Print(bool calcValue = true);

	void Print(std::ostream& out, bool calcValue = true);

	void CalcValue(const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = nullptr);

protected:

	static bool AddVectorToSymbolTable
	(
		const std::shared_ptr<exprtk::symbol_table<double>>& table,
		const std::string& variableFullName,
		std::vector<double>& value
	);

protected:

	std::string thePresentationName_ = "";

	std::shared_ptr<FrgBase_SymbolTableRegistry> theRegistry_;

	std::shared_ptr<FrgBase_SymbolTable> theParentSymbolTable_;

	std::vector<std::shared_ptr<FrgBase_SymbolTable>> theExternalSymbolTables_;

	std::shared_ptr<exprtk::symbol_table<double>> theSymbolTable_;

	std::vector<std::shared_ptr<FrgBase_Field_Entity>> theFields_;

	unsigned int theVariableIndex_ = 0;
};

EndForgBaseLib

#include <FrgBase_SymbolTableI.hxx>

#endif // !_FrgBase_SymbolTable_Header
