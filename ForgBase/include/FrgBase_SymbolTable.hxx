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
{

public:

	FrgBase_SymbolTable();
	
	~FrgBase_SymbolTable();

	std::string GetPresentationName() const { return thePresentationName_; }
	std::string GetFullPresentationName(const std::string& delimiter = ".") const;

	void SetPresentationName(const std::string& pn) { thePresentationName_ = pn; }

	FrgBase_SymbolTableRegistry* GetRegistry() const { return theRegistry_; }
	void SetRegistry(FrgBase_SymbolTableRegistry* registry) { theRegistry_ = registry; }

	FrgBase_SymbolTable* GetParentSymbolTable() const { return theParentSymbolTable_; }
	void SetParentSymbolTable(FrgBase_SymbolTable* pst) { theParentSymbolTable_ = pst; }

	const std::vector<FrgBase_SymbolTable*>& GetExternalSymbolTables() const { return theExternalSymbolTables_; }
	void SetExternalSymbolTables(const std::vector<FrgBase_SymbolTable*> ests) { theExternalSymbolTables_ = ests; }

	void AddExternalSymbolTable(FrgBase_SymbolTable* est);
	void RemoveExternalSymbolTable(FrgBase_SymbolTable* est);

	exprtk::symbol_table<double>* GetSymbolTable() const { return theSymbolTable_; }

	std::string GetFullName(const std::string& delimiter = "_") const;

	FrgBase_ScalarField* AddVariable(const std::string& presentationName);

	template <int Dim>
	FrgBase_VectorField<Dim>* AddVector(const std::string& presentationName);

	bool DeleteField(FrgBase_Field_Entity* field);

	bool ContainsField(FrgBase_Field_Entity* field) const;
	FrgBase_Field_Entity* ContainsField(const std::string& fieldFullName) const;
	FrgBase_Field_Entity* ContainsFieldFullPresentationName(const std::string& fieldFullPresentationName) const;

	const std::vector<FrgBase_Field_Entity*>& GetFields() const { return theFields_; }

	static void PrintField(std::ostringstream& ss, FrgBase_Field_Entity* field);

	static std::string PrintField(FrgBase_Field_Entity* field);

	static void PrintField(std::ostream& out, FrgBase_Field_Entity* field);

	void Print(std::ostringstream& ss, bool calcValue = true);

	std::string Print(bool calcValue = true);

	void Print(std::ostream& out, bool calcValue = true);

	void CalcValue(const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = nullptr);

protected:

	static bool AddVectorToSymbolTable
	(
		exprtk::symbol_table<double>* table,
		const std::string& variableFullName,
		std::vector<double>& value
	);

protected:

	std::string thePresentationName_ = "";

	FrgBase_SymbolTableRegistry* theRegistry_ = nullptr;

	FrgBase_SymbolTable* theParentSymbolTable_ = nullptr;

	std::vector<FrgBase_SymbolTable*> theExternalSymbolTables_;

	exprtk::symbol_table<double>* theSymbolTable_ = nullptr;

	std::vector<FrgBase_Field_Entity*> theFields_;

	unsigned int theVariableIndex_ = 0;
};

EndForgBaseLib

#include <FrgBase_SymbolTableI.hxx>

#endif // !_FrgBase_SymbolTable_Header
