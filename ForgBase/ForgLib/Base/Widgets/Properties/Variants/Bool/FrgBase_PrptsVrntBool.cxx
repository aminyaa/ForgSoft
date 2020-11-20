#include <FrgBase_PrptsVrntBool.hxx>

ForgBaseLib::FrgBase_PrptsVrntBool::FrgBase_PrptsVrntBool
(
	const QString& displayName,
	bool value,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<bool, false>(displayName, value, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntBool::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntBool::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntBool::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntBool::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntBool)
{
	ar& boost::serialization::base_object<FrgBase_PrptsVrntOneValue<bool, false>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntBool)
{
	ar& boost::serialization::base_object<FrgBase_PrptsVrntOneValue<bool, false>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntBool)