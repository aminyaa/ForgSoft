#pragma once
#ifndef _FrgBase_Serialization_Global_Header
#define _FrgBase_Serialization_Global_Header

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/export.hpp>

#include <boost/serialization/list.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <FrgBase_Serialization_IO.hxx>

#include <tuple>

#define VOID_CAST_REGISTER(Derived, Base)											\
boost::serialization::void_cast_register<Derived, Base>								\
(																					\
	static_cast<Derived*>(NULL),													\
	static_cast<Base*>(NULL)														\
	);

#define DECLARE_SAVE_LOAD_HEADER(Export)	 												\
	friend class boost::serialization::access;										\
	template<class Archive>															\
	void Export save(Archive & ar, const unsigned int version) const;						\
	template<class Archive>															\
	void Export load(Archive & ar, const unsigned int version);							\
	BOOST_SERIALIZATION_SPLIT_MEMBER()												

#define DECLARE_SAVE_LOAD_HEADER_SPEC(C) 											\
namespace boost																		\
{																					\
	namespace serialization															\
	{																				\
		template<class Archive>														\
		void save(Archive& ar, const C& m, const unsigned int version);				\
		template<class Archive>														\
		void load(Archive& ar, C& m, const unsigned int version);					\
	}																				\
}

#define DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(C, Export) 														\
namespace boost																						\
{																									\
	namespace serialization																			\
	{																								\
		template<class Archive>																		\
		void Export save_construct_data(Archive& ar, const C* m, const unsigned int version);				\
		template<class Archive>																		\
		void Export load_construct_data(Archive& ar, C* m, const unsigned int version);					\
	}																								\
}

#define DECLARE_SAVE_IMP(C)															\
template<class Archive>																\
void C::save(Archive & ar, const unsigned int version) const						

#define DECLARE_SAVE_IMP_SPEC(C)													   \
template<class Archive>																   \
void boost::serialization::save(Archive & ar, const C& m, const unsigned int version)

#define DECLARE_SAVE_IMP_CONSTRUCT(C)																	  \
template<class Archive>																					  \
void boost::serialization::save_construct_data(Archive & ar, const C* t, const unsigned int version)

#define DECLARE_LOAD_IMP(C) 									\
template<class Archive>											\
void C::load(Archive & ar, const unsigned int version)		

#define DECLARE_LOAD_IMP_SPEC(C)													   \
template<class Archive>																   \
void boost::serialization::load(Archive & ar, C& m, const unsigned int version)

#define DECLARE_LOAD_IMP_CONSTRUCT(C)																	  \
template<class Archive>																					  \
void boost::serialization::load_construct_data(Archive & ar, C* t, const unsigned int version)

#define DECLARE_SAVE_CONSTRUCT_DATA(C, Export) \
template<class Archive>\
void Export save_construct_data\
(\
	Archive & ar, const C* t, const unsigned int file_version\
)\

#define DECLARE_LOAD_CONSTRUCT_DATA(C, Export) \
template<class Archive>\
void load_construct_data\
(\
	Archive & ar, C* t, const unsigned int file_version\
)\

#define DECLARE_BOOST_DATA_TYPES(C)																					\
template __declspec(dllexport) void C::load<boost::archive::text_iarchive>											\
(boost::archive::text_iarchive & ar, const unsigned int version);													\
template __declspec(dllexport) void C::save<boost::archive::text_oarchive>											\
(boost::archive::text_oarchive & ar, const unsigned int version) const;												\
template __declspec(dllexport) void C::load<boost::archive::binary_iarchive>										\
(boost::archive::binary_iarchive& ar, const unsigned int version);													\
template __declspec(dllexport) void C::save<boost::archive::binary_oarchive>										\
(boost::archive::binary_oarchive & ar, const unsigned int version) const;											\
template __declspec(dllexport) void C::load<boost::archive::polymorphic_iarchive>									\
(boost::archive::polymorphic_iarchive& ar, const unsigned int version);												\
template __declspec(dllexport) void C::save<boost::archive::polymorphic_oarchive>									\
(boost::archive::polymorphic_oarchive & ar, const unsigned int version) const;										\
template __declspec(dllexport) void C::load<boost::archive::polymorphic_text_iarchive>								\
(boost::archive::polymorphic_text_iarchive& ar, const unsigned int version);										\
template __declspec(dllexport) void C::save<boost::archive::polymorphic_text_oarchive>								\
(boost::archive::polymorphic_text_oarchive & ar, const unsigned int version) const;									\
template __declspec(dllexport) void C::load<boost::archive::polymorphic_binary_iarchive>							\
(boost::archive::polymorphic_binary_iarchive& ar, const unsigned int version);										\
template __declspec(dllexport) void C::save<boost::archive::polymorphic_binary_oarchive>							\
(boost::archive::polymorphic_binary_oarchive & ar, const unsigned int version) const;								\

#define DECLARE_BOOST_DATA_TYPES_SPEC(C)																			\
namespace boost																										\
{																													\
	namespace serialization																							\
	{																												\
	template __declspec(dllexport) void load<boost::archive::text_iarchive>											\
		(boost::archive::text_iarchive & ar, C& m, const unsigned int version);										\
	template __declspec(dllexport) void save<boost::archive::text_oarchive>											\
		(boost::archive::text_oarchive & ar, const C& m, const unsigned int version);								\
	template __declspec(dllexport) void load<boost::archive::binary_iarchive>										\
		(boost::archive::binary_iarchive& ar, C& m, const unsigned int version);									\
	template __declspec(dllexport) void save<boost::archive::binary_oarchive>										\
		(boost::archive::binary_oarchive & ar, const C& m, const unsigned int version);								\
	template __declspec(dllexport) void load<boost::archive::polymorphic_iarchive>									\
		(boost::archive::polymorphic_iarchive& ar, C& m, const unsigned int version);								\
	template __declspec(dllexport) void save<boost::archive::polymorphic_oarchive>									\
		(boost::archive::polymorphic_oarchive & ar, const C& m, const unsigned int version);						\
	template __declspec(dllexport) void load<boost::archive::polymorphic_text_iarchive>								\
		(boost::archive::polymorphic_text_iarchive& ar, C& m, const unsigned int version);							\
	template __declspec(dllexport) void save<boost::archive::polymorphic_text_oarchive>								\
		(boost::archive::polymorphic_text_oarchive & ar, const C& m, const unsigned int version);					\
	template __declspec(dllexport) void load<boost::archive::polymorphic_binary_iarchive>							\
		(boost::archive::polymorphic_binary_iarchive& ar, C& m, const unsigned int version);						\
	template __declspec(dllexport) void save<boost::archive::polymorphic_binary_oarchive>							\
		(boost::archive::polymorphic_binary_oarchive & ar, const C& m, const unsigned int version);					\
}																													\
}

#define BOOST_CLASS_EXPORT_CXX_SPEC_STDTUPLE 																						   \
namespace boost																														   \
{																																	   \
	namespace serialization																											   \
	{																																   \
		template __declspec(dllexport) void serialize<boost::archive::text_iarchive>												   \
		(boost::archive::text_iarchive & ar, std::tuple<>& t, const unsigned int version);											   \
		template __declspec(dllexport) void serialize<boost::archive::text_oarchive>									 			   \
		(boost::archive::text_oarchive & ar, std::tuple<>& t, const unsigned int version);											   \
		template __declspec(dllexport) void serialize<boost::archive::binary_iarchive>												   \
		(boost::archive::binary_iarchive & ar, std::tuple<>& t, const unsigned int version);										   \
		template __declspec(dllexport) void serialize<boost::archive::binary_oarchive>												   \
		(boost::archive::binary_oarchive & ar, std::tuple<>& t, const unsigned int version);										   \
		template __declspec(dllexport) void serialize<boost::archive::polymorphic_iarchive>											   \
		(boost::archive::polymorphic_iarchive & ar, std::tuple<>& t, const unsigned int version);									   \
		template __declspec(dllexport) void serialize<boost::archive::polymorphic_oarchive>											   \
		(boost::archive::polymorphic_oarchive & ar, std::tuple<>& t, const unsigned int version);									   \
		template __declspec(dllexport) void serialize<boost::archive::polymorphic_text_iarchive>									   \
		(boost::archive::polymorphic_text_iarchive & ar, std::tuple<>& t, const unsigned int version);								   \
		template __declspec(dllexport) void serialize<boost::archive::polymorphic_text_oarchive>									   \
		(boost::archive::polymorphic_text_oarchive & ar, std::tuple<>& t, const unsigned int version);								   \
		template __declspec(dllexport) void serialize<boost::archive::polymorphic_binary_iarchive>									   \
		(boost::archive::polymorphic_binary_iarchive & ar, std::tuple<>& t, const unsigned int version);							   \
		template __declspec(dllexport) void serialize<boost::archive::polymorphic_binary_oarchive>									   \
		(boost::archive::polymorphic_binary_oarchive & ar, std::tuple<>& t, const unsigned int version);							   \
	}																																   \
}

#define DECLARE_BOOST_DATA_TYPES_CONSTRUCT(C)																		\
namespace boost																										\
{																													\
namespace serialization																								\
{																													\
	template __declspec(dllexport) void load_construct_data<boost::archive::text_iarchive>							\
		(boost::archive::text_iarchive & ar, C* m, const unsigned int version);										\
	template __declspec(dllexport) void save_construct_data<boost::archive::text_oarchive>							\
		(boost::archive::text_oarchive & ar, const C* m, const unsigned int version);								\
	template __declspec(dllexport) void load_construct_data<boost::archive::binary_iarchive>						\
		(boost::archive::binary_iarchive& ar, C* m, const unsigned int version);									\
	template __declspec(dllexport) void save_construct_data<boost::archive::binary_oarchive>						\
		(boost::archive::binary_oarchive & ar, const C* m, const unsigned int version);  							\
	template __declspec(dllexport) void load_construct_data<boost::archive::polymorphic_iarchive>					\
		(boost::archive::polymorphic_iarchive& ar, C* m, const unsigned int version);								\
	template __declspec(dllexport) void save_construct_data<boost::archive::polymorphic_oarchive>					\
		(boost::archive::polymorphic_oarchive & ar, const C* m, const unsigned int version);  						\
	template __declspec(dllexport) void load_construct_data<boost::archive::polymorphic_text_iarchive>				\
		(boost::archive::polymorphic_text_iarchive& ar, C* m, const unsigned int version);							\
	template __declspec(dllexport) void save_construct_data<boost::archive::polymorphic_text_oarchive>				\
		(boost::archive::polymorphic_text_oarchive & ar, const C* m, const unsigned int version);  					\
	template __declspec(dllexport) void load_construct_data<boost::archive::polymorphic_binary_iarchive>			\
		(boost::archive::polymorphic_binary_iarchive& ar, C* m, const unsigned int version);						\
	template __declspec(dllexport) void save_construct_data<boost::archive::polymorphic_binary_oarchive>			\
		(boost::archive::polymorphic_binary_oarchive & ar, const C* m, const unsigned int version);  				\
}																													\
}

#define BOOST_CLASS_EXPORT_CXX(C)				   \
DECLARE_BOOST_DATA_TYPES(C)						   \
BOOST_CLASS_EXPORT_IMPLEMENT(C)

#define BOOST_CLASS_EXPORT_CXX_SPEC(C)				   \
DECLARE_BOOST_DATA_TYPES_SPEC(C)

#define BOOST_CLASS_EXPORT_CXX_CONSTRUCT(C)				   \
DECLARE_BOOST_DATA_TYPES_CONSTRUCT(C)

#define BOOST_CLASS_EXPORT_CXX_AND_CXX_CONSTRUCT(C)  \
BOOST_CLASS_EXPORT_CXX_CONSTRUCT(C)					 \
BOOST_CLASS_EXPORT_CXX(C)

// override for non-default constructor
#define SAVE_CONSTRUCT_DATA_TITEM(Archive, Class)													 \
{																									 \
	QString myTItemTitle = t->text(0);																 \
	Archive & myTItemTitle;																			 \
																									 \
	QString parentTItemIsNull;																		 \
	ForgBaseLib::FrgBase_TreeItem* parentTItem = 													 \
		dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(((QTreeWidgetItem*)t)->parent());				 \
																									 \
	if (!parentTItem)																				 \
	{																								 \
		parentTItemIsNull = "PARENT_TITEM_IS_NULL";													 \
																									 \
		Archive & parentTItemIsNull;																 \
	}																								 \
	else																							 \
	{																								 \
		parentTItemIsNull = "PARENT_TITEM_IS_NOT_NULL";												 \
																									 \
		Archive & parentTItemIsNull;																 \
		Archive & const_cast<ForgBaseLib::FrgBase_TreeItem*>(parentTItem);							 \
	}																								 \
																									 \
	QString parentTreeIsNull;																		 \
	ForgBaseLib::FrgBase_Tree* parentTree = (t->GetParentTree());									 \
																									 \
	if (!parentTree)																				 \
	{																								 \
		parentTreeIsNull = "PARENT_TREE_IS_NULL";													 \
																									 \
		Archive & parentTreeIsNull;																	 \
	}																								 \
	else																							 \
	{																								 \
		parentTreeIsNull = "PARENT_TREE_IS_NOT_NULL";												 \
																									 \
		Archive & parentTreeIsNull;																	 \
		Archive & const_cast<ForgBaseLib::FrgBase_Tree*>(parentTree);								 \
	}																								 \
}
																									 

#define LOAD_CONSTRUCT_DATA_TITEM(Archive, Class)													 \
{																									 \
	QString myTItemTitle;																			 \
	Archive & myTItemTitle;																			 \
																									 \
	QString parentTItemIsNull;																		 \
	ForgBaseLib::FrgBase_TreeItem* parentTItem;														 \
																									 \
	Archive & parentTItemIsNull;																	 \
																									 \
	if (parentTItemIsNull == "PARENT_TITEM_IS_NULL")												 \
		parentTItem = nullptr;																		 \
	else if (parentTItemIsNull == "PARENT_TITEM_IS_NOT_NULL")										 \
		Archive & parentTItem;																		 \
																									 \
	QString parentTreeIsNull;																		 \
	ForgBaseLib::FrgBase_Tree* parentTree;															 \
																									 \
	Archive & parentTreeIsNull;																		 \
																									 \
	if (parentTreeIsNull == "PARENT_TREE_IS_NULL")													 \
		parentTree = nullptr;																		 \
	else if (parentTreeIsNull == "PARENT_TREE_IS_NOT_NULL")											 \
		Archive & parentTree;																		 \
																									 \
	::new(t)Class(myTItemTitle, parentTItem, parentTree);											 \
}

//// override for non-default constructor
//namespace ForgBaseLib
//{
//	template<class Archive, class T>
//	inline void save_construct_data_TItem
//	(
//		Archive & ar, const T * t, const unsigned int file_version
//	)
//	{
//		// ============================================
//		// store FrgBase_TreeItem title
//		// ============================================
//		QString myTItemTitle = t->text(0);
//		ar << myTItemTitle;
//
//		// ============================================
//		// store FrgBase_TreeItem parentTItem
//		// ============================================
//		QString parentTItemIsNull;
//		ForgBaseLib::FrgBase_TreeItem* parentTItem = dynamic_cast<ForgBaseLib::FrgBase_TreeItem*>(((QTreeWidgetItem*)t)->parent());
//
//		if (!parentTItem)
//		{
//			parentTItemIsNull = "PARENT_TITEM_IS_NULL";
//
//			ar << parentTItemIsNull;
//		}
//		else
//		{
//			parentTItemIsNull = "PARENT_TITEM_IS_NOT_NULL";
//
//			ar << parentTItemIsNull;
//			ar << parentTItem;
//		}
//
//		// ============================================
//		// store FrgBase_TreeItem parentTree
//		// ============================================
//		QString parentTreeIsNull;
//		ForgBaseLib::FrgBase_Tree* parentTree = (t->GetParentTree());
//
//		if (!parentTree)
//		{
//			parentTreeIsNull = "PARENT_TREE_IS_NULL";
//
//			ar << parentTreeIsNull;
//		}
//		else
//		{
//			parentTreeIsNull = "PARENT_TREE_IS_NOT_NULL";
//
//			ar << parentTreeIsNull;
//			ar << parentTree;
//		}
//
//	}
//
//	template<class Archive, class T>
//	inline void load_construct_data_TItem
//	(
//		Archive & ar, T * t, const unsigned int file_version
//	)
//	{
//		// ============================================
//		// load FrgBase_TreeItem title
//		// ============================================
//		QString myTItemTitle;;
//		ar >> myTItemTitle;
//
//		// ============================================
//		// load FrgBase_TreeItem parentTItem
//		// ============================================
//		QString parentTItemIsNull;
//		ForgBaseLib::FrgBase_TreeItem* parentTItem;
//
//		ar >> parentTItemIsNull;
//
//		if (parentTItemIsNull == "PARENT_TITEM_IS_NULL")
//			parentTItem = nullptr;
//		else if (parentTItemIsNull == "PARENT_TITEM_IS_NOT_NULL")
//			ar >> parentTItem;
//
//		// ============================================
//		// load FrgBase_TreeItem parentTree
//		// ============================================
//		QString parentTreeIsNull;
//		ForgBaseLib::FrgBase_Tree* parentTree;
//
//		ar >> parentTreeIsNull;
//
//		if (parentTreeIsNull == "PARENT_TREE_IS_NULL")
//			parentTree = nullptr;
//		else if (parentTreeIsNull == "PARENT_TREE_IS_NOT_NULL")
//			ar >> parentTree;
//
//		// =============================================================
//		// invoke inplace constructor to initialize instance of my_class
//		// =============================================================
//		::new(t)T(myTItemTitle, parentTItem, parentTree);
//	}
//}

#endif // !_FrgBase_Serialization_Global_Header
