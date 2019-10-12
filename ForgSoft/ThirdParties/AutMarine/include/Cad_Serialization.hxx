#pragma once
#ifndef _Cad_Serialization_Header
#define _Cad_Serialization_Header

#include <Standard_Transient.hxx>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace boost
{
	namespace serialization
	{

		template<class Archive>
		void serialize(Archive& ar, Standard_Transient& t, const unsigned int version)
		{
			
		}
	}
}

#endif // !_Cad_Serialization_Header
