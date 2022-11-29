#pragma once
#ifndef _FrgBase_SymbolTableTools_Header
#define _FrgBase_SymbolTableTools_Header

#include <FrgBase_Object.hxx>

BeginForgBaseLib

class FrgBase_SymbolTable;

class FORGBASE_EXPORT FrgBase_SymbolTableRegistry
	: public FrgBase_Object
{

public:

	FrgBase_SymbolTableRegistry();

	~FrgBase_SymbolTableRegistry();

	FrgBase_SymbolTable* CreateTable(const std::string& presentationName);

	void AddTable(FrgBase_SymbolTable* table);

	// This method just removes the table from the registry and the user
	// is responsible to delete the table
	void RemoveTable(FrgBase_SymbolTable* table);

	bool ContainsTable(FrgBase_SymbolTable* table);

	const std::vector<FrgBase_SymbolTable*> GetTables() const { return theTables_; }

	void Print(std::ostringstream& ss, bool calcValue = true);

	std::string Print(bool calcValue = true);

	void Print(std::ostream& out, bool calcValue = true);

protected:

	unsigned int theTableIndex_ = 0;

	std::vector<FrgBase_SymbolTable*> theTables_;

	static unsigned int theRegistryIndex_;
};

EndForgBaseLib

#endif // !_FrgBase_SymbolTableTools_Header
