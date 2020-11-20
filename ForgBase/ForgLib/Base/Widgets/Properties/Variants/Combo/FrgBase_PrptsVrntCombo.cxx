#include <FrgBase_PrptsVrntCombo.hxx>

ForgBaseLib::FrgBase_PrptsVrntCombo::FrgBase_PrptsVrntCombo
(
	const QString& displayName,
	const QString& value,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue(displayName, value, prefix, suffix)
{

}

ForgBaseLib::FrgBase_PrptsVrntCombo::FrgBase_PrptsVrntCombo
(
	std::vector<QString> items,
	const QString& displayName,
	const QString& value,
	const QString& prefix,
	const QString& suffix
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

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntCombo)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<QString, false>>(*this);

	ar& theItems_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntCombo)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<QString, false>>(*this);

	ar& theItems_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntCombo)