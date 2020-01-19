#include <FrgBase_PrptsVrntDouble.hxx>

ForgBaseLib::FrgBase_PrptsVrntDouble::FrgBase_PrptsVrntDouble
(
	double value,
	double min,
	double max,
	double step,
	const char * prefix,
	const char * suffix
)
	: FrgBase_PrptsVrntOneValue<double>(value, min, max, step, prefix, suffix)
{
}