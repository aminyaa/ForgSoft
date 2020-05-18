#pragma once
#ifndef _FrgVisual_Serialization_Global_Header
#define _FrgVisual_Serialization_Global_Header

#include <FrgBase_Serialization_Global.hxx>

#include <vtkSmartPointer.h>

#define SERIALIZE_VTKSMARTPOINTER(T) \
BOOST_SERIALIZATION_SPLIT_FREE(vtkSmartPointer<T>) \
namespace boost{\
namespace serialization{\
template<class Archive, class T>\
inline void save\
(\
	Archive & ar, const vtkSmartPointer<T>& t, const unsigned int file_version\
)\
{\
ar & m.GetPointer();\
}\
template<class Archive, class T>\
inline void load\
(\
	Archive & ar, vtkSmartPointer<T>& t, const unsigned int file_version\
)\
{\
T* myRawPointer;\
ar & myRawPointer;\
}\
}\
}\
	template<class Archive, class T>\
	inline void save_construct_data\
	(\
		Archive & ar, const vtkSmartPointer<T> t, const unsigned int file_version\
	)\
	{\
ar & m.GetPointer();\
	}\
	template<class Archive, class T>\
	inline void load_construct_data\
	(\
		Archive & ar, T t, const unsigned int file_version\
	)\
	{\
		T* myRawPointer;\
ar & myRawPointer;\
::new(t)vtkSmartPointer<T>(myRawPointer);\
	}\

#endif // !_FrgVisual_Serialization_Global_Header
