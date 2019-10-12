#pragma once
#ifndef _Global_Done_Header
#define _Global_Done_Header

#include <Standard_TypeDef.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace AutLib
{

	class Global_Done
	{

		friend class boost::serialization::access;

		/*Private Data*/

		Standard_Boolean IsDone_;

		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar& IsDone_;
		}

	protected:

		Standard_Boolean& Change_IsDone()
		{
			return IsDone_;
		}

	public:

		Global_Done()
			: IsDone_(Standard_False)
		{}

		Standard_Boolean IsDone() const
		{
			return IsDone_;
		}
	};
}

#endif // !_Global_Done_Header
