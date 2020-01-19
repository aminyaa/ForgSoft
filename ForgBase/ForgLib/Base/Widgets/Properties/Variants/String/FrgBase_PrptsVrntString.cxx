#include <FrgBase_PrptsVrntString.hxx>

ForgBaseLib::FrgBase_PrptsVrntString::FrgBase_PrptsVrntString
(
	const QString & text,
	const char * prefix,
	const char * suffix
)
	: FrgBase_PrptsVrntOneValue<QString>(text, prefix, suffix)
{

}