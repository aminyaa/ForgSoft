//#include <FrgBase_SerialSpec_Tuple.hxx>
//
//template<class Archive, typename ...Args>
//void boost::serialization::serialize(Archive & ar, std::tuple<Args...>& t, const unsigned int version)
//{
//	Serialize<sizeof...(Args)>::serialize(ar, t, version);
//}
//
////BOOST_CLASS_EXPORT_CXX_SPEC_STDTUPLE
//
//namespace boost
//{
//	namespace serialization
//	{
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::text_iarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::text_oarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::binary_iarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::binary_oarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::polymorphic_iarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::polymorphic_oarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::polymorphic_text_iarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::polymorphic_text_oarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::polymorphic_binary_iarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//		template<typename ...Args> __declspec(dllexport) void serialize
//			(boost::archive::polymorphic_binary_oarchive & ar, std::tuple<Args...>& t, const unsigned int version);
//
//			/*template __declspec(dllexport) void serialize<boost::archive::text_iarchive>
//				(boost::archive::text_iarchive & ar, std::tuple<>& t, const unsigned int version);*/
//	}
//}