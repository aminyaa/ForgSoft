#pragma once
#ifndef _FrgBase_ToolsParameterVector_TItem_Header
#define _FrgBase_ToolsParameterVector_TItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_ToolsParameter_TItem.hxx>

BeginForgBaseLib

class FrgBase_PrptsVrntFieldVector;

class FORGBASE_EXPORT FrgBase_ToolsParameterVector_TItem
	: public ForgBaseLib::FrgBase_ToolsParameter_TItem
{

	Q_OBJECT

public:

	FrgBase_ToolsParameterVector_TItem
	(
		const QString& itemTitle,
		FrgBase_TreeItem* parentItem,
		FrgBase_Tree* parentTree
	);

	~FrgBase_ToolsParameterVector_TItem();

	void FormTItem() override;

	void Update() override;

	FrgBase_PrptsVrntFieldVector* GetValuesVariant() const { return theValues_; }
	void SetValuesVariant(FrgBase_PrptsVrntFieldVector* valuesVariant) { theValues_ = valuesVariant; }

	const std::vector<double>& GetValues() const;
	std::vector<double>& GetValuesRef();

	void AddVariableToSymbolTable(const QString& s, bool isConstructing = false) override;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

private:

	FrgBase_PrptsVrntFieldVector* theValues_ = nullptr;
};

EndForgBaseLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameterVector_TItem, FORGBASE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_ToolsParameterVector_TItem)

#endif // !_FrgBase_ToolsParameterVector_TItem_Header
