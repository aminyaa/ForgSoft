#pragma once
#ifndef _FrgBase_ToolsParameterScalar_TItem_Header
#define _FrgBase_ToolsParameterScalar_TItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_ToolsParameter_TItem.hxx>

BeginForgBaseLib

class FrgBase_PrptsVrntFieldScalar;

class FORGBASE_EXPORT FrgBase_ToolsParameterScalar_TItem
	: public ForgBaseLib::FrgBase_ToolsParameter_TItem
{

	Q_OBJECT

public:

	FrgBase_ToolsParameterScalar_TItem
	(
		const QString& itemTitle,
		FrgBase_TreeItem* parentItem,
		FrgBase_Tree* parentTree
	);

	~FrgBase_ToolsParameterScalar_TItem();

	void FormTItem() override;

	void Update() override;

	FrgBase_PrptsVrntFieldScalar* GetValueVariant() const { return theValue_; }
	void SetValueVariant(FrgBase_PrptsVrntFieldScalar* valueVariant) { theValue_ = valueVariant; }

	double GetValue() const;
	double& GetValueRef();

	void AddVariableToSymbolTable(const QString& s) override;

protected:

	FrgBase_PrptsVrntFieldScalar* theValue_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_ToolsParameterScalar_TItem_Header
