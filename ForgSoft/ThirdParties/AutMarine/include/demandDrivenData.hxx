#pragma once
#ifndef _demandDrivenData_Header
#define _demandDrivenData_Header

namespace AutLib
{
	template<class DataPtr>
	inline void deleteDemandDrivenData(DataPtr& dataPtr)
	{
		if (dataPtr)
		{
			delete dataPtr;
			dataPtr = 0;
		}
	}
}

#endif // !_demandDrivenData_Header
