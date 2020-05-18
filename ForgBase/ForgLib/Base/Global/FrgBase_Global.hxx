#pragma once
#ifndef _FrgBase_Global_Header
#define _FrgBase_Global_Header

#include <FrgBase_Global_Build.hxx>
#include <FrgBase_Global_Type.hxx>

#include <iostream>
#include <vector>
#include <list>
#include <map>

#define FrgGetMacro(type, name, object)\
type Get##name##() const {return object;}
//type& Get##name##() {return object;}

template<typename T>
using StdVector = std::vector<T>;

template<typename T>
using StdList = std::list<T>;

template<typename T, typename U>
using StdMap = std::map<T, U>;

template<typename T>
using StdSharedPtr = std::shared_ptr<T>;

#define StdMakeSharedPtr(type) std::make_shared<type>
#define StdDynamicPtrCast(type) std::dynamic_pointer_cast<type>
#define StdStaticPtrCast(type) std::static_pointer_cast<type>

#define NullPtr nullptr

#define FrgCout std::cout <<
#define FrgEndL << std::endl
#define FrgSpace << "  " <<
#define FrgTab << "\t" <<

#define BeginForgBaseLib namespace ForgBaseLib {
#define EndForgBaseLib } 

template<class T>
FrgString CorrectName(T* parentItem, const FrgString& name)\
{\
if (parentItem->childCount() == 0)\
return name;\
parentItem->sortChildren(0, Qt::AscendingOrder); \
for (int i = 0; i < parentItem->childCount(); i++)\
{if (parentItem->child(i)->text(0) == name)\
{break; }\
else\
{return name; }\
}\
FrgString output; \
int nameNumber = 2; \
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
return output; \
}

#define FreePointer(ptr)\
if(ptr)\
{\
delete ptr;\
ptr = NullPtr;\
}

#define FreeVectorOfPointers(vec)\
for(int iPointer=0; iPointer < vec.size(); iPointer++)\
FreePointer(vec[iPointer]);

#define AreSameType(listOfItems, Type, result)\
if(listOfItems.size() == 1)\
result = False;\
else\
{for (int iSameType = 0; iSameType < listOfItems.size(); iSameType++)\
{\
if (!dynamic_cast<Type*>(listOfItems[iSameType]))\
{result = False; break;}\
else\
{result = True; }\
}}

#endif // !_FrgBase_Global_Header
