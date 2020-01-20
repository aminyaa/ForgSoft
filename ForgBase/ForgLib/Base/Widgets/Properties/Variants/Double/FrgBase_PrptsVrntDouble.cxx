#include <FrgBase_PrptsVrntDouble.hxx>

ForgBaseLib::FrgBase_PrptsVrntDouble::FrgBase_PrptsVrntDouble
(
	const char* displayName,
	double value,
	double min,
	double max,
	double step,
	const char * prefix,
	const char * suffix
)
	: FrgBase_PrptsVrntOneValue<double>(displayName, value, min, max, step, prefix, suffix)
{
}