#pragma once
#ifndef _FrgBase_Field_Entity_Header
#define _FrgBase_Field_Entity_Header

#include <FrgBase_Object.hxx>
#include <FrgBase_FieldParser.hxx>

#include<FrgBase_Serialization_Global.hxx>

BeginForgBaseLib

class FrgBase_SymbolTable;

class FORGBASE_EXPORT FrgBase_Field_Entity
	: public FrgBase_Object
{

public:

	FrgBase_Field_Entity();

	~FrgBase_Field_Entity();

	virtual void CalcValue(const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = false) = 0;

	std::string GetPresentationName() const { return thePresentationName_; }
	std::string GetFullPresentationName
	(
		const std::string& delimiter = ".",
		const bool pure = false
	) const;

	void SetPresentationName(const std::string& pn) { thePresentationName_ = pn; }

	std::string GetFullName(const std::string& delimiter = "_") const;

	FrgBase_SymbolTable* GetSymbolTable() const { return theSymbolTable_; }
	void SetSymbolTable(FrgBase_SymbolTable* st) { theSymbolTable_ = st; }

	std::string GetExpression() const { return theExpression_; }
	void SetExpression(const std::string& expression) { theExpression_ = expression; }

	virtual bool IsScalar() const { return false; }
	virtual bool IsVector() const { return false; }

	std::vector<FrgBase_SymbolTable*> RetrieveSymbolTables() const;
	std::vector<FrgBase_SymbolTable*> RetrieveExternalSymbolTables() const;
	std::vector<FrgBase_SymbolTable*> RetrieveSymbolTablesIncludingExternals() const;

	virtual bool IsDeletable() const;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	std::string thePresentationName_ = "";

	FrgBase_SymbolTable* theSymbolTable_ = nullptr;

	std::string theExpression_ = "";
	std::string thePresentationExpression_ = "";

	bool theIsCalculating_ = false;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Field_Entity)

#endif // !_FrgBase_Field_Entity_Header
