#include <FrgBase_PrptsVrntString.hxx>

ForgBaseLib::FrgBase_PrptsVrntString::FrgBase_PrptsVrntString
(
	const QString& displayName,
	const QString & value,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<QString, false>(displayName, value, prefix, suffix)
{
	
}

void ForgBaseLib::FrgBase_PrptsVrntString::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntString::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntString::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntString::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntString)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<QString, false>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntString)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<QString, false>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntString)