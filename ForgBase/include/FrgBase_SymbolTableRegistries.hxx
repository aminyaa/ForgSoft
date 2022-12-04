#pragma once
#ifndef _FrgBase_SymbolTableRegistries_Header
#define _FrgBase_SymbolTableRegistries_Header

#include <FrgBase_Object.hxx>

BeginForgBaseLib

class FrgBase_SymbolTableRegistry;

class FORGBASE_EXPORT FrgBase_SymbolTableRegistries
	: public FrgBase_Object
	, public std::enable_shared_from_this<FrgBase_SymbolTableRegistries>
{

public:

	FrgBase_SymbolTableRegistries();

	const auto& GetRegistries() const { return theRegistries_; }
	void SetRegistries(const std::vector<std::shared_ptr<FrgBase_SymbolTableRegistry>>& regs) { theRegistries_ = regs; }

	std::shared_ptr<FrgBase_SymbolTableRegistry>
		CreateRegistry();

	void AddRegistry
	(
		const std::shared_ptr<FrgBase_SymbolTableRegistry>& registry
	);
	
	// This method just removes the table from the registry and the user
	// is responsible to delete the table
	void RemoveRegistry(const std::shared_ptr<FrgBase_SymbolTableRegistry>& registry);

	bool ContainsRegistry(const std::shared_ptr<FrgBase_SymbolTableRegistry>& registry);

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	std::vector<std::shared_ptr<FrgBase_SymbolTableRegistry>> theRegistries_;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_SymbolTableRegistries)

#endif // !_FrgBase_SymbolTableRegistries_Header
