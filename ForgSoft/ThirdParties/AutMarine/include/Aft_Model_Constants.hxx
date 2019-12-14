#pragma once
#ifndef _Aft_Model_Constants_Header
#define _Aft_Model_Constants_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	struct Aft_Model_Constants
	{
		static const Standard_Integer ALLOWED_MAX_LEVEL_GENERATION;

		static const Standard_Real DEFAULT_LOCALFRONT_FACTOR;
		static const Standard_Real DEFAULT_MIN_DISTANCE_FACTOR;
	};
}

#endif // !_Aft_Model_Constants_Header
