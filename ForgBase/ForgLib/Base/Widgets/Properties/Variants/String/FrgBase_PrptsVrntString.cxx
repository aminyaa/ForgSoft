#include <FrgBase_PrptsVrntString.hxx>

ForgBaseLib::FrgBase_PrptsVrntString::FrgBase_PrptsVrntString
(
	const char* displayName,
	const QString & value,
	const char * prefix,
	const char * suffix
)
	: FrgBase_PrptsVrntOneValue<QString, false>(displayName, value, prefix, suffix)
{

}