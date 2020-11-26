#pragma once
#ifndef _demandDrivenData_Header
#define _demandDrivenData_Header

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class DataPtr>
	void deleteDemandDrivenData(DataPtr& dataPtr)
	{
		if (dataPtr)
		{
			delete dataPtr;
			dataPtr = 0;
		}
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_demandDrivenData_Header
