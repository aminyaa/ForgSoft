#pragma once
#ifndef _Global_Named_Header
#define _Global_Named_Header

#include <word.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace AutLib
{

	class Global_Named
	{

		friend class boost::serialization::access;

		/*Private Data*/

		word theName_;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar& theName_;
		}

	public:

		Global_Named()
		{}

		Global_Named(const word& theName)
			: theName_(theName)
		{}

		const word& Name() const
		{
			return theName_;
		}

		word& Name()
		{
			return theName_;
		}

		void SetName(const word& theName)
		{
			theName_ = theName;
		}
	};
}

#endif // !_Global_Named_Header
