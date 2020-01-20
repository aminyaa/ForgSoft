#include <FrgBase_PrptsVrntInt.hxx>

ForgBaseLib::FrgBase_PrptsVrntInt::FrgBase_PrptsVrntInt
(
	const char* displayName,
	int value,
	int min, int max,
	int step,
	const char* prefix,
	const char* suffix
)
	: FrgBase_PrptsVrntOneValue<int>(displayName, value, min, max, step, prefix, suffix)
{

}