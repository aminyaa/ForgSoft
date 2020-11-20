#include <FrgBase_PrptsVrntColor.hxx>
#include <FrgBase_SerialSpec_QColor.hxx>

ForgBaseLib::FrgBase_PrptsVrntColor::FrgBase_PrptsVrntColor
(
	const QString& displayName,
	QColor value,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue(displayName, value, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntColor::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntColor::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntColor::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntColor::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntColor)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<QColor, false>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntColor)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_PrptsVrntOneValue<QColor, false>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntColor)