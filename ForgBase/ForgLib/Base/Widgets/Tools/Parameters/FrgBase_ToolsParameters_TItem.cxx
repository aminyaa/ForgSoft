#include <FrgBase_ToolsParameters_TItem.hxx>
#include <FrgBase_ToolsParameterScalar_TItem.hxx>
#include <FrgBase_ToolsParameterVector_TItem.hxx>
#include <FrgBase_Tree.hxx>
#include <FrgBase_SerialSpec_Tuple.hxx>

#include <boost/serialization/map.hpp>

#include <exprtk.hpp>

ForgBaseLib::FrgBase_ToolsParameters_TItem::FrgBase_ToolsParameters_TItem
(
	const QString& itemTitle,
	FrgBase_TreeItem* parentItem,
	FrgBase_Tree* parentTree
)
	: ForgBaseLib::FrgBase_TreeItem(itemTitle, parentItem, parentTree)
{
	theSymbolTableT_ = new symbol_table_t();
}

ForgBaseLib::FrgBase_ToolsParameters_TItem::~FrgBase_ToolsParameters_TItem()
{
	//FreePointer(theSymbolTableT_);
}

void ForgBaseLib::FrgBase_ToolsParameters_TItem::FormTItem()
{
	ForgBaseLib::FrgBase_TreeItem::FormTItem();

	/*for (int i = 0; i < 5; i++)
	{
		auto parameterTItem = new FrgBase_ToolsParameterScalar_TItem("Scalar " + QString::number(i), this, GetParentTree());
		parameterTItem->SetSymbolTableT(theSymbolTableT_);
		parameterTItem->SetParentToolsParametersTItem(this);
		parameterTItem->FormTItem();
	}

	{
		auto parameterTItem = new FrgBase_ToolsParameterVector_TItem("Vector " + QString::number(0), this, GetParentTree());
		parameterTItem->SetSymbolTableT(theSymbolTableT_);
		parameterTItem->SetParentToolsParametersTItem(this);
		parameterTItem->FormTItem();
	}*/
}

void ForgBaseLib::FrgBase_ToolsParameters_TItem::UpdateAllParameters()
{
	auto items = this->GetAllChildrenToTheRoot();
	for (auto x : items)
	{
		auto parameterTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(x);
		if (parameterTItem)
		{
			parameterTItem->GetVariableName();
			parameterTItem->Update();
		}
	}

	emit UpdateAllParametersCalledSignal();
}

ForgBaseLib::FrgBase_ToolsParameter_TItem* ForgBaseLib::FrgBase_ToolsParameters_TItem::GetParamaterTItem(const QString& variableName)
{
	const auto& myChildren = GetAllChildrenToTheRoot();
	for (const auto& myChild : myChildren)
	{
		const auto& parameterTItem = dynamic_cast<FrgBase_ToolsParameter_TItem*>(myChild);
		if (parameterTItem)
		{
			if (parameterTItem->GetVariableName() == variableName)
				return parameterTItem;
		}
	}

	return nullptr;
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_ToolsParameters_TItem)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);

	auto children = GetAllChildrenToTheRoot();
	std::vector<std::pair<std::string, double>> varsList;

	theSymbolTableT_->get_variable_list(varsList);

	ar& children;
	ar& varsList;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_ToolsParameters_TItem)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_TreeItem>(*this);
	std::vector<FrgBase_TreeItem*> children;
	std::vector<std::pair<std::string, double>> varsList;

	ar& children;
	ar& varsList;

	for (auto& var : varsList)
		theSymbolTableT_->add_variable(var.first, var.second);
}

DECLARE_SAVE_IMP_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameters_TItem)
{
	SAVE_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_ToolsParameters_TItem);
}

DECLARE_LOAD_IMP_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameters_TItem)
{
	LOAD_CONSTRUCT_DATA_TITEM(ar, ForgBaseLib::FrgBase_ToolsParameters_TItem);
}

BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(ForgBaseLib::FrgBase_ToolsParameters_TItem)