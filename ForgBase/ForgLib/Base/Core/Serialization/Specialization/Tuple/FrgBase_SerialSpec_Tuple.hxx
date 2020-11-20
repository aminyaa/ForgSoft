#pragma once
#ifndef _FrgBase_SerialSpec_Tuple_Header
#define _FrgBase_SerialSpec_Tuple_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>
//
//#include <tuple>
//
//namespace boost
//{
//	namespace serialization
//	{
//		template<uint N>
//		struct Serialize
//		{
//			template<class Archive, typename... Args>
//			static void serialize(Archive & ar, std::tuple<Args...> & t, const unsigned int version)
//			{
//				ar & std::get<N - 1>(t);
//				Serialize<N - 1>::serialize(ar, t, version);
//			}
//		};
//
//		template<>
//		struct Serialize<0>
//		{
//			template<class Archive, typename... Args>
//			static void serialize(Archive & ar, std::tuple<Args...> & t, const unsigned int version)
//			{
//				(void)ar;
//				(void)t;
//				(void)version;
//			}
//		};
//
//		template<class Archive, typename... Args>
//		void serialize(Archive & ar, std::tuple<Args...> & t, const unsigned int version);
//	}
//}
//
//// namespace boost
//// {
//// 	namespace serialization
//// 	{
//// 		template<class Archive, typename... Args>
//// 		inline void serialize(Archive & ar, std::tuple<Args...> & t, const unsigned int file_version)
//// 		{
//// 			split_free(ar, t, file_version);
//// 		}
//// 	}//
//// }//
//
//// namespace boost
//// {
//// 	namespace serialization
//// 	{
//// 		template<class Archive, typename... Args>
//// 		void save(Archive& ar, const std::tuple<Args...>& m, const unsigned int version);
//// 		template<class Archive, typename... Args>
//// 		void load(Archive& ar, std::tuple<Args...>& m, const unsigned int version);
//// 	}
//// }
//
//
//// boost export key for std::tuple
//
//namespace boost
//{
//	namespace serialization
//	{
//		template<typename ...Args>
//		struct guid_defined<std::tuple<Args...>> : boost::mpl::true_ {};
//
//		/*template<typename ...Args>
//		inline const char * guid<std::tuple<Args...>>()
//		{
//			return BOOST_PP_STRINGIZE(std::tuple<Args...>);
//		}*/
//	}
//}


namespace boost
{
	namespace serialization
	{

		template<uint N>
		struct Serialize
		{
			template<class Archive, typename... Args>
			static void serialize(Archive& ar, std::tuple<Args...>& t, const unsigned int version)
			{
				ar& std::get<N - 1>(t);
				Serialize<N - 1>::serialize(ar, t, version);
			}
		};

		template<>
		struct Serialize<0>
		{
			template<class Archive, typename... Args>
			static void serialize(Archive& ar, std::tuple<Args...>& t, const unsigned int version)
			{
				(void)ar;
				(void)t;
				(void)version;
			}
		};

		template<class Archive, typename... Args>
		void serialize(Archive& ar, std::tuple<Args...>& t, const unsigned int version)
		{
			Serialize<sizeof...(Args)>::serialize(ar, t, version);
		}

	}
}

#endif // !_FrgBase_SerialSpec_Tuple_Header
