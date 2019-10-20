#pragma once
#ifndef _Marine_VesselParamM_Header
#define _Marine_VesselParamM_Header

#include <Marine_VesselParam.hxx>

#define MARINE_VESSELPARAM(CLASS_NAME, PARAM_NAME, PARAM_DIM)			\
	class CLASS_NAME													\
		: public Marine_VesselParam										\
	{																	\
																		\
	public:																\
		explicit CLASS_NAME(const Standard_Real theValue)				\
			: Marine_VesselParam(PARAM_NAME, PARAM_DIM, theValue) {}	\
	};

#endif // !_Marine_VesselParamM_Header
