#include <FrgBase_PrptsVrntCombo.hxx>

ForgBaseLib::FrgBase_PrptsVrntCombo::FrgBase_PrptsVrntCombo
(
	const char* displayName,
	const QString& value,
	const char* prefix,
	const char* suffix
)
	: FrgBase_PrptsVrntOneValue(displayName, value, prefix, suffix)
{

}

ForgBaseLib::FrgBase_PrptsVrntCombo::FrgBase_PrptsVrntCombo
(
	std::vector<QString> items,
	const char* displayName,
	const QString& value,
	const char* prefix,
	const char* suffix
)
	: FrgBase_PrptsVrntOneValue(displayName, value, prefix, suffix)
{
	for (int i = 0; i < items.size(); i++)
		theItems_.push_back(items[i]);
}

void ForgBaseLib::FrgBase_PrptsVrntCombo::AddItem(const QString& item)
{
	for (int i = 0; i < theItems_.size(); i++)
		if(theItems_[i] == item)
			return;

	theItems_.push_back(item);
}

void ForgBaseLib::FrgBase_PrptsVrntCombo::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntCombo::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntCombo::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntCombo::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}