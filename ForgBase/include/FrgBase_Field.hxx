#pragma once
#ifndef _FrgBase_Field_Header
#define _FrgBase_Field_Header

#include <FrgBase_Object.hxx>
#include <FrgBase_FieldParser.hxx>

BeginForgBaseLib

class FrgBase_SymbolTable;

class FORGBASE_EXPORT FrgBase_Field_Entity
	: public FrgBase_Object
{

public:

	FrgBase_Field_Entity();

	virtual void CalcValue(const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = false);

	std::string GetPresentationName() const { return thePresentationName_; }
	std::string GetFullPresentationName(const std::string& delimiter = ".") const;

	void SetPresentationName(const std::string& pn) { thePresentationName_ = pn; }

	std::string GetFullName(const std::string& delimiter = "_") const;

	FrgBase_SymbolTable* GetSymbolTable() const { return theSymbolTable_; }
	void SetSymbolTable(FrgBase_SymbolTable* st) { theSymbolTable_ = st; }

	std::string GetExpression() const { return theExpression_; }
	void SetExpression(const std::string& expression) { theExpression_ = expression; }

	virtual bool IsScalar() const { return false; }
	virtual bool IsVector() const { return false; }

	//virtual void Build();

	std::vector<FrgBase_SymbolTable*> RetrieveSymbolTables() const;
	std::vector<FrgBase_SymbolTable*> RetrieveExternalSymbolTables() const;
	std::vector<FrgBase_SymbolTable*> RetrieveSymbolTablesIncludingExternals() const;

protected:

	std::string thePresentationName_ = "";

	FrgBase_SymbolTable* theSymbolTable_ = nullptr;

	std::string theExpression_ = "";

	bool theIsCalculating_ = false;
};

template <typename T>
class FrgBase_Field
	: public FrgBase_Field_Entity
{

public:
	
	FrgBase_Field()
		: FrgBase_Field_Entity()
	{

	}

	T GetValue() const { return theValue_; }

	T& GetValueRef() { return theValue_; }

protected:

	//virtual bool AddVariableToSymbolTable();

	T theValue_;
};

EndForgBaseLib

#include <FrgBase_FieldI.hxx>

#endif // !_FrgBase_Field_Header
