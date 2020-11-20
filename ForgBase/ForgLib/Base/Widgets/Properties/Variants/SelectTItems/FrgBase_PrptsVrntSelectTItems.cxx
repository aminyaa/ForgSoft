#include <FrgBase_PrptsVrntSelectTItems.hxx>
#include <FrgBase_TreeItem.hxx>

ForgBaseLib::FrgBase_PrptsVrntSelectTItems::FrgBase_PrptsVrntSelectTItems
(
	const QString& displayName,
	FrgBase_TreeItem* parentOfTItems,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue(displayName, parentOfTItems, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItems::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItems::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItems::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItems::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItems::SelectedTItemsChanged()
{
	emit SelectedTItemsChangedSignal(theListOfTItems_);
}

void ForgBaseLib::FrgBase_PrptsVrntSelectTItems::SetSelectedTItems(std::vector<QTreeWidgetItem*> selectedTItems)
{
	theListOfTItems_.clear();

	for (int i = 0; i < selectedTItems.size(); i++)
		theListOfTItems_.push_back(selectedTItems[i]);

	SelectedTItemsChanged();
}