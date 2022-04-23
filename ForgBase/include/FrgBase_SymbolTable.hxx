#pragma once
#ifndef _FrgBase_SymbolTable_Header
#define _FrgBase_SymbolTable_Header

#include <FrgBase_Object.hxx>

namespace exprtk
{
	template <typename T>
	class symbol_table;
}

BeginForgBaseLib

class FrgBase_ScalarField;
class FrgBase_Field_Entity;

class FORGBASE_EXPORT FrgBase_SymbolTable
	: public FrgBase_Object
{

public:

	FrgBase_SymbolTable();
	
	~FrgBase_SymbolTable();

	std::string GetPresentationName() const { return thePresentationName_; }
	std::string GetFullPresentationName(const std::string& delimiter = ".") const;

	void SetPresentationName(const std::string& pn) { thePresentationName_ = pn; }

	FrgBase_SymbolTable* GetParentSymbolTable() const { return theParentSymbolTable_; }
	void SetParentSymbolTable(FrgBase_SymbolTable* pst) { theParentSymbolTable_ = pst; }

	const std::vector<FrgBase_SymbolTable*>& GetExternalSymbolTables() const { return theExternalSymbolTables_; }
	void SetExternalSymbolTables(const std::vector<FrgBase_SymbolTable*> ests) { theExternalSymbolTables_ = ests; }

	void AddExternalSymbolTable(FrgBase_SymbolTable* est);
	void RemoveExternalSymbolTable(FrgBase_SymbolTable* est);

	exprtk::symbol_table<double>* GetSymbolTable() const { return theSymbolTable_; }

	std::string GetFullName(const std::string& delimiter = "_") const;

	FrgBase_ScalarField* AddVariable(const std::string& presentationName);
	//FrgBase_VectorField* AddVector(const std::string& presentationName);

	bool ContainsField(FrgBase_Field_Entity* field) const;
	FrgBase_Field_Entity* ContainsField(const std::string& fieldFullName) const;

protected:

	std::string thePresentationName_ = "";

	FrgBase_SymbolTable* theParentSymbolTable_ = nullptr;

	std::vector<FrgBase_SymbolTable*> theExternalSymbolTables_;

	exprtk::symbol_table<double>* theSymbolTable_ = nullptr;

	std::vector<FrgBase_Field_Entity*> theFields_;

	unsigned int theVariableIndex_ = 0;
};

EndForgBaseLib

#endif // !_FrgBase_SymbolTable_Header
