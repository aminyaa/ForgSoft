#include <FrgBase_PrptsVrntTextEdit.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

ForgBaseLib::FrgBase_PrptsVrntTextEdit::FrgBase_PrptsVrntTextEdit
(
	const QString& displayName,
	const QString& value,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<QString, false>(displayName, value, prefix, suffix)
{

}

void ForgBaseLib::FrgBase_PrptsVrntTextEdit::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

void ForgBaseLib::FrgBase_PrptsVrntTextEdit::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

void ForgBaseLib::FrgBase_PrptsVrntTextEdit::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

void ForgBaseLib::FrgBase_PrptsVrntTextEdit::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_PrptsVrntTextEdit)
{
	ar& boost::serialization::base_object<FrgBase_PrptsVrntOneValue<QString, false>>(*this);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_PrptsVrntTextEdit)
{
	ar& boost::serialization::base_object<FrgBase_PrptsVrntOneValue<QString, false>>(*this);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_PrptsVrntTextEdit)