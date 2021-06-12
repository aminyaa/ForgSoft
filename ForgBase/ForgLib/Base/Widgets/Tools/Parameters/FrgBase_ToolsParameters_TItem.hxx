#pragma once
#ifndef _FrgBase_ToolsParameters_TItem_Header
#define _FrgBase_ToolsParameters_TItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_TreeItem.hxx>

namespace exprtk
{
	template<typename T>
	class symbol_table;
}

typedef exprtk::symbol_table<double> symbol_table_t;

BeginForgBaseLib

class FrgBase_ToolsParameter_TItem;

class FORGBASE_EXPORT FrgBase_ToolsParameters_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{

	Q_OBJECT

public:

	FrgBase_ToolsParameters_TItem
	(
		const QString& itemTitle,
		FrgBase_TreeItem* parentItem,
		FrgBase_Tree* parentTree
	);

	~FrgBase_ToolsParameters_TItem();

	void FormTItem() override;

	void SetSymbolTableT(symbol_table_t* symbolTableT) { theSymbolTableT_ = symbolTableT; }
	symbol_table_t* GetSymbolTableT() const { return theSymbolTableT_; }

	void UpdateAllParameters();

	FrgBase_ToolsParameter_TItem* GetParamaterTItem(const QString& variableName);

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

Q_SIGNALS:

	void UpdateAllParametersCalledSignal();

protected:

	symbol_table_t* theSymbolTableT_ = nullptr;
};

EndForgBaseLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameters_TItem, FORGBASE_EXPORT)

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_ToolsParameters_TItem)

#endif // !_FrgBase_ToolsParameters_TItem_Header
