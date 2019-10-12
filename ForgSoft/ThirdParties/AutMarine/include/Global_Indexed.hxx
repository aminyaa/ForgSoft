#pragma once
#ifndef _Global_Indexed_Header
#define _Global_Indexed_Header

#include <Standard_Integer.hxx>

namespace AutLib
{

	class Global_Indexed
	{

		/*Private Data*/

		Standard_Integer theIndex_;

	public:

		Global_Indexed()
			:theIndex_(0)
		{}

		Global_Indexed(const Standard_Integer theIndex)
			: theIndex_(theIndex)
		{}


		Standard_Integer Index() const
		{
			return theIndex_;
		}

		Standard_Integer& Index()
		{
			return theIndex_;
		}

		void SetIndex(const Standard_Integer theIndex)
		{
			theIndex_ = theIndex;
		}
	};
}

#endif // !_Global_Indexed_Header
