#pragma once
#ifndef _LegModel_ManipParams_Header
#define _LegModel_ManipParams_Header

#include <Standard_TypeDef.hxx>

namespace tnbLib
{

	class LegModel_ManipParams
	{

		/*Private Data*/

		Standard_Boolean IsManipulated_;

	protected:

		LegModel_ManipParams()
			: IsManipulated_(Standard_False)
		{}

		auto& ChangeManipulated()
		{
			return IsManipulated_;
		}

	public:

		auto IsManipulated() const
		{
			return IsManipulated_;
		}
	};
}

#endif // !_LegModel_ManipParams_Header
