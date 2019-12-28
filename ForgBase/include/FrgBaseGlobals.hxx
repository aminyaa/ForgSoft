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

template<class T>
FrgString CorrectName(T* parentItem, const FrgString& name)\
{\
parentItem->sortChildren(0, Qt::AscendingOrder); \
\
FrgString output; \
\
int nameNumber = 1; \
for (int i = 0; i < parentItem->childCount(); i++)\
{\
if (nameNumber < 10)\
{\
if (parentItem->child(i)->text(0) == (name + " 0" + QString::number(nameNumber)))\
{nameNumber++; }\
}\
else\
{if (parentItem->child(i)->text(0) == (name + " " + QString::number(nameNumber)))\
{nameNumber++; }\
}\
}\
if (nameNumber < 10)\
{output = name + " 0" + QString::number(nameNumber); }\
else \
{output = name + " " + QString::number(nameNumber); }\
\
return output;\
}

#define FreePointer(ptr)\
if(ptr)\
{\
delete ptr;\
ptr = FrgNullPtr;\
}

#define FreeVectorOfPointers(vec)\
for(int iPointer=0; iPointer < vec.size(); iPointer++)\
FreePointer(vec[iPointer]);

#define FrgAreSameType(listOfItems, Type, result)\
if(listOfItems.size() == 1)\
result = FrgFalse;\
else\
{for (int iSameType = 0; iSameType < listOfItems.size(); iSameType++)\
{\
if (!dynamic_cast<Type*>(listOfItems[iSameType]))\
{result = FrgFalse; break;}\
else\
{result = FrgTrue; }\
}}

#endif // !_FrgBaseGlobals_Header