#include <FrgBase_PrptsVrntBool.hxx>

ForgBaseLib::FrgBase_PrptsVrntBool::FrgBase_PrptsVrntBool
(
	const char * displayName,
	bool value,
	const char * prefix,
	const char * suffix
)
	: FrgBase_PrptsVrntOneValue<bool, false>(displayName, value, prefix, suffix)
{

}