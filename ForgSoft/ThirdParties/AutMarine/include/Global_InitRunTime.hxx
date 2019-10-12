#pragma once
#ifndef _Global_InitRunTime_Header
#define _Global_InitRunTime_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Global_InitRunTime
	{

		/*Private Data*/

		static Standard_Boolean Init_;

	protected:

		Global_InitRunTime()
		{}

	public:

		Standard_Boolean IsInitiated() const
		{
			return Init_;
		}

		static void SetToInitiated()
		{
			Init_ = Standard_True;
		}
	};
}

#endif // !_Global_InitRunTime_Header
