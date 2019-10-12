#pragma once
#ifndef _Global_Verbose_Header
#define _Global_Verbose_Header

#include <Standard_TypeDef.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace AutLib
{


	class Global_Verbose
	{

		friend class boost::serialization::access;

		/*Private Data*/

		Standard_Integer theVerbose_;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar& theVerbose_;
		}

	public:

		Global_Verbose()
			: theVerbose_(0)
		{}

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
