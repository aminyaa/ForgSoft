#pragma once
#ifndef _Global_AccessMethod_Header
#define _Global_AccessMethod_Header

#define GLOBAL_ACCESS_ONLY_SINGLE(PARAM_TYPE, PARAM_NAME)													\
	const PARAM_TYPE& PARAM_NAME() const {return the##PARAM_NAME##_;}										\

#define GLOBAL_ACCESS_SINGLE(PARAM_TYPE, PARAM_NAME)														\
	const PARAM_TYPE& PARAM_NAME() const {return the##PARAM_NAME##_;}										\
	PARAM_TYPE& PARAM_NAME() {return the##PARAM_NAME##_;}													\
	void Set##PARAM_NAME(const PARAM_TYPE& the##PARAM_NAME) {the##PARAM_NAME##_ = the##PARAM_NAME;}

#define GLOBAL_ACCESS_PRIM_SINGLE(PARAM_TYPE, PARAM_NAME)													\
	PARAM_TYPE PARAM_NAME() const {return the##PARAM_NAME##_;}												\
	PARAM_TYPE& PARAM_NAME() {return the##PARAM_NAME##_;}													\
	void Set##PARAM_NAME(const PARAM_TYPE the##PARAM_NAME) {the##PARAM_NAME##_ = the##PARAM_NAME;}

#define GLOBAL_ACCESS_VECTOR(PARAM_TYPE, PARAM_NAME, INDEX)																							\
	const PARAM_TYPE& PARAM_NAME##INDEX() const {return the##PARAM_NAME##s_[INDEX];}																\
	PARAM_TYPE& PARAM_NAME##INDEX() {return the##PARAM_NAME##s_[INDEX];}																			\
	void Set##PARAM_NAME##INDEX(const PARAM_TYPE& the##PARAM_NAME) {the##PARAM_NAME##s_[INDEX] = the##PARAM_NAME;}

#define GLOBAL_ACCESS_VECTOR_INDEX(PARAM_TYPE, PARAM_NAME)																						\
	void Set##PARAM_NAME(const Standard_Integer theIndex, const PARAM_TYPE& the##PARAM_NAME) {the##PARAM_NAME##s_[theIndex] = the##PARAM_NAME;}	\
	const PARAM_TYPE& PARAM_NAME(const Standard_Integer theIndex) const {return the##PARAM_NAME##s_[theIndex];}									\
	PARAM_TYPE& PARAM_NAME(const Standard_Integer theIndex) {return the##PARAM_NAME##s_[theIndex];}


#endif // !_Global_AccessMethod_Header
