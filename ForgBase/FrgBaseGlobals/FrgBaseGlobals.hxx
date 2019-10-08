#pragma once
#ifndef _FrgBaseGlobals_Header
#define _FrgBaseGlobals_Header

#include <FrgBaseGlobalsBuild.hxx>
#include <FrgBaseGlobalsTypes.hxx>

#include <iostream>
#include <vector>
#include <list>
#include <map>

#define FrgGetMacro(type, name, object)\
type Get##name##() const {return object;}\
type& Get##name##() {return object;}

template<typename T>
using FrgVector = std::vector<T>;

template<typename T>
using FrgList = std::list<T>;

template<typename T, typename U>
using FrgMap = std::map<T, U>;

template<typename T>
using FrgSharedPtr = std::shared_ptr<T>;

#define FrgMakeSharedPtr(type) std::make_shared<type>
#define FrgDynamicPtrCast(type) std::dynamic_pointer_cast<type>
#define FrgStaticPtrCast(type) std::static_pointer_cast<type>

#define FrgNullPtr nullptr

#define FrgPrint std::cout <<
#define FrgEndL << std::endl
#define FrgSpace << "  " <<
#define FrgTab << "\t" <<

#define BeginFrgBaseLib namespace ForgBaseLib {
#define EndFrgBaseLib }

#endif // !_FrgBaseGlobals_Header