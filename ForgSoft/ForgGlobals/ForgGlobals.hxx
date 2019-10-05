#pragma once
#ifndef _ForgGlobals_Header
#define _ForgGlobals_Header

#include <iostream>
#include <vector>
#include <list>
#include <map>

#define ForgGetMacro(type, name, object)\
type Get##name##() const {return object;}\
type& Get##name##() {return object;}

template<typename T>
using ForgVector = std::vector<T>;

template<typename T>
using ForgList = std::list<T>;

template<typename T, typename U>
using ForgMap = std::map<T, U>;

template<typename T>
using ForgSharedPtr = std::shared_ptr<T>;

#define ForgMakeSharedPtr(type) std::make_shared<type>
#define ForgDynamicPtrCast(type) std::dynamic_pointer_cast<type>
#define ForgStaticPtrCast(type) std::static_pointer_cast<type>

#define ForgNullPtr nullptr

#define ForgPrint std::cout <<
#define ForgEndL << std::endl
#define ForgSpace << "  " <<
#define ForgTab << "\t" <<

#endif // !_ForgGlobals_Header
