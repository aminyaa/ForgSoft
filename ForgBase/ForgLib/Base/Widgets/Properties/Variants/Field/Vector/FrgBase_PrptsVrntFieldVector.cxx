#include <FrgBase_PrptsVrntFieldVector.hxx>

ForgBaseLib::FrgBase_PrptsVrntFieldVector::FrgBase_PrptsVrntFieldVector
(
	const QString& displayName,
	std::vector<double> values,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<std::vector<double>, false>(displayName, values, prefix, suffix)
{
	theShowNonParentalParameters_ = true;
}

void ForgBaseLib::FrgBase_PrptsVrntFieldVector::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntFieldVector::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntFieldVector::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntFieldVector::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntFieldVector)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<std::vector<double>, false>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntFieldVector)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<std::vector<double>, false>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntFieldVector)