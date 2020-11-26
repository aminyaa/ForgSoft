#pragma once
#ifndef _FrgBase_ToolsParameter_TItem_Header
#define _FrgBase_ToolsParameter_TItem_Header

#define exprtk_disable_caseinsensitivity 

#include <FrgBase_Global.hxx>
#include <FrgBase_TreeItem.hxx>

namespace exprtk
{
	template<typename T>
	class symbol_table;
}

typedef exprtk::symbol_table<double> symbol_table_t;

BeginForgBaseLib

class FrgBase_ToolsParameters_TItem;

class FORGBASE_EXPORT FrgBase_ToolsParameter_TItem
	: public ForgBaseLib::FrgBase_TreeItem
{

	Q_OBJECT

public:

	FrgBase_ToolsParameter_TItem
	(
		const QString& itemTitle,
		FrgBase_TreeItem* parentItem,
		FrgBase_Tree* parentTree
	);

	~FrgBase_ToolsParameter_TItem();

	void FormTItem() override;

	void SetSymbolTableT(symbol_table_t* symbolTableT) { theSymbolTableT_ = symbolTableT; }
	symbol_table_t* GetSymbolTableT() const { return theSymbolTableT_; }

	FrgBase_ToolsParameters_TItem* GetParentToolsParametersTItem() const { return theParentToolsParametersTItem_; }
	void SetParentToolsParametersTItem(FrgBase_ToolsParameters_TItem* parentToolsParametersTItem)
	{
		theParentToolsParametersTItem_ = parentToolsParametersTItem;
	}

	const QString& GetVariableName() const { return theVariableName_; }

	virtual void Update();

	void AddDependentParameter(FrgBase_ToolsParameter_TItem* dependentParameter);
	void RemoveDependentParameter(FrgBase_ToolsParameter_TItem* dependentParameter);
	void RemoveAllDependentParameters();

	virtual bool IsInDependent() const { return theDependentParameters_.isEmpty() ? true : false; }

	QList<FrgBase_ToolsParameter_TItem*> GetDependentParameters() const { return theDependentParameters_; }

	bool IsDeletable() const override;

public:

	QString GetCorrectedVariableName(const QString& s) const;
	virtual void AddVariableToSymbolTable(const QString& s) {}

protected:

	symbol_table_t* theSymbolTableT_ = nullptr;
	QString theVariableName_;

	FrgBase_ToolsParameters_TItem* theParentToolsParametersTItem_ = nullptr;
	QList<FrgBase_ToolsParameter_TItem*> theDependentParameters_;
};

EndForgBaseLib

#endif // !_FrgBase_ToolsParameter_TItem_Header
