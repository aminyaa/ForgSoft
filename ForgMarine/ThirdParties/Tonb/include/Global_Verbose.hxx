#pragma once
#ifndef _Global_Verbose_Header
#define _Global_Verbose_Header

#include <Standard_TypeDef.hxx>

namespace tnbLib
{

	class Global_Verbose
	{

		/*Private Data*/

		Standard_Integer theVerbose_;

	protected:

		Global_Verbose()
			: theVerbose_(0)
		{}

	public:

		Standard_Integer Verbose() const
		{
			return theVerbose_;
		}

		Standard_Integer& Verbose()
		{
			return theVerbose_;
		}

		void SetVerbisity(const Standard_Integer theVerbose)
		{
			theVerbose_ = theVerbose;
		}
	};
}

#endif // !_Global_Verbose_Header
