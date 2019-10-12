#pragma once
#ifndef _Leg_Model_ManipParams_Header
#define _Leg_Model_ManipParams_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Leg_Model_ManipParams
	{

		/*Private Data*/

		Standard_Boolean IsManipulated_;

	protected:

		Leg_Model_ManipParams()
			: IsManipulated_(Standard_False)
		{}

		Standard_Boolean& ChangeManipulated()
		{
			return IsManipulated_;
		}

	public:

		Standard_Boolean IsManipulated() const
		{
			return IsManipulated_;
		}
	};
}

#endif // !_Leg_Model_ManipParams_Header
