#pragma once
#ifndef _FrgBase_Field_Entity_Header
#define _FrgBase_Field_Entity_Header

#include <FrgBase_Object.hxx>
#include <FrgBase_FieldParser.hxx>

#include<FrgBase_Serialization_Global.hxx>

BeginForgBaseLib

class FrgBase_SymbolTable;
class FrgBase_SymbolTableRegistry;

class FORGBASE_EXPORT FrgBase_Field_Entity
	: public FrgBase_Object
	, public std::enable_shared_from_this<FrgBase_Field_Entity>
{

public:

	FrgBase_Field_Entity();

	~FrgBase_Field_Entity();

	const auto& GetSymbolTable() const { return theSymbolTable_; }
	void SetSymbolTable(const std::shared_ptr<FrgBase_SymbolTable>& st) { theSymbolTable_ = st; }

	const auto& GetRegistry() const { return theRegistry_; }
	void SetRegistry(const std::shared_ptr<FrgBase_SymbolTableRegistry>& reg) { theRegistry_ = reg; }

	virtual void CalcValue
	(
		const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = nullptr
	) = 0;

	std::string GetPresentationName() const { return thePresentationName_; }
	std::string GetFullPresentationName
	(
		const std::string& delimiter = ".",
		const bool pure = true
	) const;

	void SetPresentationName(const std::string& pn) { thePresentationName_ = pn; }

	std::string GetFullName(const std::string& delimiter = "_") const;

	std::string GetExpression() const { return theExpression_; }
	void SetExpression(const std::string& expression) { theExpression_ = expression; }

	virtual bool IsScalar() const { return false; }
	virtual bool IsVector() const { return false; }

	virtual std::string GetTypeAsString() const = 0;

	std::vector<std::shared_ptr<FrgBase_SymbolTable>> RetrieveSymbolTables() const;
	std::vector<std::shared_ptr<FrgBase_SymbolTable>> RetrieveExternalSymbolTables() const;
	std::vector<std::shared_ptr<FrgBase_SymbolTable>> RetrieveSymbolTablesIncludingExternals() const;

	virtual bool IsDeletable() const;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	std::string thePresentationName_ = "";

	std::shared_ptr<FrgBase_SymbolTable> theSymbolTable_;
	std::shared_ptr<FrgBase_SymbolTableRegistry> theRegistry_;

	std::string theExpression_ = "";
	std::string thePresentationExpression_ = "";

	bool theIsCalculating_ = false;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Field_Entity)

#endif // !_FrgBase_Field_Entity_Header
