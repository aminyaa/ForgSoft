#pragma once
#ifndef _FrgBase_SymbolTableTools_Header
#define _FrgBase_SymbolTableTools_Header

#include <FrgBase_Object.hxx>

BeginForgBaseLib

class FrgBase_SymbolTableRegistries;
class FrgBase_SymbolTable;
class FrgBase_Field_Entity;
class FrgBase_ScalarField;
class FrgBase_VectorField;

class FORGBASE_EXPORT FrgBase_SymbolTableRegistry
	: public FrgBase_Object
	, public std::enable_shared_from_this<FrgBase_SymbolTableRegistry>
{

public:

	FrgBase_SymbolTableRegistry();

	~FrgBase_SymbolTableRegistry();

	const std::vector<std::shared_ptr<FrgBase_SymbolTable>>& GetTables() const { return theTables_; }

	const auto& GetParentRegistries() const { return theParentRegistries_; }
	void SetParentRegistries(const std::shared_ptr<FrgBase_SymbolTableRegistries>& pr) { theParentRegistries_ = pr; }

	std::shared_ptr<FrgBase_SymbolTable>
		CreateTable
		(
			const std::string& presentationName
		);

	void AddTable
	(
		const std::shared_ptr<FrgBase_SymbolTable>& table
	);

	void ClearTables();

	// This method just removes the table from the registry and the user
	// is responsible to delete the table
	void RemoveTable(const std::shared_ptr<FrgBase_SymbolTable>& table);

	bool ContainsTable(const std::shared_ptr<FrgBase_SymbolTable>& table);

	void Print(std::ostringstream& ss, bool calcValue = true);

	std::string Print(bool calcValue = true);

	void Print(std::ostream& out, bool calcValue = true);

	std::vector<std::shared_ptr<FrgBase_Field_Entity>> GetAllFields() const;
	std::vector<std::shared_ptr<FrgBase_ScalarField>> GetAllScalarFields() const;
	std::vector<std::shared_ptr<FrgBase_VectorField>> GetAllVectorFields() const;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	std::shared_ptr<FrgBase_SymbolTableRegistries> theParentRegistries_;

	std::vector<std::shared_ptr<FrgBase_SymbolTable>> theTables_;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_SymbolTableRegistry)

#endif // !_FrgBase_SymbolTableTools_Header
