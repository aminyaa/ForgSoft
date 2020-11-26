#pragma once
#ifndef _FrgBase_SerialSpec_Thread_Header
#define _FrgBase_SerialSpec_Thread_Header

#include <FrgBase_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_Thread;
}

namespace boost
{
	namespace serialization
	{
		template<class Archive>
		void save(Archive& ar, const ForgBaseLib::FrgBase_Thread& thread, const unsigned int version)
		{
			
		}

		template<class Archive>
		void load(Archive& ar, ForgBaseLib::FrgBase_Thread& thread, const unsigned int version)
		{

		}
	}
}

#endif // !_FrgBase_SerialSpec_Thread_Header
